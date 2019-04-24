#!/usr/bin/perl

use strict;
use warnings;

my $symbolsname;
my $ver = '0.44.12';
$symbolsname = "v$ver SDL win64" if $win;
$symbolsname = "v$ver linux64" if $linux;
$symbolsname = "v$ver osx64" if $osx;

#XXX: using __thiscall prevents from applying the correct type for this pointer ??
my $callconv = '__stdcall';
$callconv = '__fastcall' if $win;

my $input1 = 'codegen/codegen.out.xml';
my $input2 = 'symbols.xml';
my $output = $ARGV[1] || 'df_ghidra.java';

use XML::LibXML;

my @lines_full;
our @lines;
my %seen_class;
my %fwd_decl_class;
my %global_types;
my %global_types_orig;
my %global_objects;
my @calls;


sub emit_label {
    my ($name, $addr, $type) = @_;

    # print "$name @ $addr -> $type\n";
    print 'createGlobal(toAddr('.$addr.'L), "'.$name.'", "'.$type.'");', "\n";
}

sub emit_vmethod {
    my ($addr, $pos, $class, $name, $type, $basevtaddr) = @_;

    my $k = $basevtaddr && "toAddr(${basevtaddr}L)" || 'null';

    # print "$pos: $name -> $type\n";
    print "applyVmethodType(toAddr(${addr}L), $pos, \"$class\", \"$name\", \"$type\", $k);\n";
}

sub get_vt_name {
    my ($typename) = @_;

    my $type = $global_types_orig{$typename};

    if (not $type) {
        if ($typename =~ /^renderer_/) {
            return 'renderer';
        }

        return;
    }

    return if not $type;
    my $vt;
    while (not $vt = $type->findnodes('child::virtual-methods')->[0]) {
        my $parentname = $type->getAttribute('inherits-from');
        if (not $parentname) {
            last;
        }
        $type = $global_types{$parentname};
    }

    return $type->getAttribute('original-name') || $type->getAttribute('type-name');
}

sub get_full_vtable {
    my ($name, $vtname) = @_;

    my @vms_all;

    my $type = $global_types_orig{$vtname};
    if ($type) {
        my $base = $type->getAttribute('inherits-from');
        if ($base) {
            my $basetype = $global_types{$base};
            my $basevms = $basetype->findnodes('child::virtual-methods')->[0];
            push @vms_all, $basevms->findnodes('child::vmethod');
        }

        my $vms = $type->findnodes('child::virtual-methods')->[0];
        push @vms_all, $vms->findnodes('child::vmethod');
    }

    if ($name ne $vtname) {
        my $self = $global_types_orig{$name};
        if ($self) {
            my $selfvms = $self->findnodes('child::virtual-methods')->[0];
            if ($selfvms) {
                push @vms_all, $selfvms->findnodes('child::vmethod');   
            }
        }
    }

    return @vms_all
}

sub process_globals {
    my ($symbols) = @_;

    my @globals = $symbols->findnodes('global-address');
    for my $n (@globals) {
        my $name = $n->getAttribute('name');
        my $addr = $n->getAttribute('value');

        my $globaldef = $global_objects{$name};
        my $typename = '';
        if ($globaldef) {
            $typename = $globaldef->getAttribute('type-name') || '';
            if ($typename) {
                my $type = $global_types{$typename};
                if ($type and $type->getAttribute('original-name')) {
                    $typename = $type->getAttribute('original-name');
                }
            }
        }

        emit_label('_'.$name, $addr, $typename);
    }
}

sub process_vtables {
    my ($symbols) = @_;

    my @vtables = $symbols->findnodes('vtable-address');
    for my $n (@vtables) {
        my $typename = $n->getAttribute('name');

        my $name = '_vtable_'.$typename;
        my $addr = $n->getAttribute('value');

        next if not $addr;

        my $vtname = get_vt_name($typename);

        if ($vtname) {
            emit_label($name, $addr, 'vtable_'.$vtname);
        } else {
            emit_label($name, $addr, '');
        }
    }
}

sub process_vmethods {
    my ($symbols) = @_;

    my @vtables = $symbols->findnodes('vtable-address');
    for my $n (@vtables) {
        my $typename = $n->getAttribute('name');

        my $name = '_vtable_'.$typename;
        my $addr = $n->getAttribute('value');

        next if not $addr;

        my $vtname = get_vt_name($typename);

        if ($vtname) {
            my $type = $global_types_orig{$typename};
            my $basevtaddr;
            # print $type;
            if ($type) {
                while (1) {
                    my $base = $type->getAttribute('inherits-from');
                    if ($base) {
                        my $basetype = $global_types{$base};
                        my $basename = $basetype->getAttribute('original-name') || $base;
                        my $basevt = $symbols->findnodes('vtable-address[@name="'.$basename.'"]')->[0];
                        if ($basevt) {
                            $basevtaddr = $basevt->getAttribute('value');
                            last;
                        } else {
                            $type = $basetype;
                        }
                    } else {
                        last;
                    }
                }
            }            

            my $k = $basevtaddr && "toAddr(${basevtaddr}L)" || 'null';
            print "applyVmethodTypes(toAddr(${addr}L), \"$typename\", \"vtable_$vtname\", $k);\n";            

            # my @vms = get_full_vtable($typename, $vtname);
            # my $pos = 0;
            # for my $vm (@vms) {
            #     if ($vm->getAttribute('is-destructor')) {
            #         #todo: this
            #     } else {
            #         my $vmname = $vm->getAttribute('name') || $vm->getAttribute('ld:anon-name');
            #         emit_vmethod($addr, $pos, $typename, $typename.'_'.$vmname, 'vm_'.$vtname.'_'.$vmname, $basevtaddr);
            #     }
            #     $pos++;
            # }
        }
    }
}

my $parser = XML::LibXML->new();
$parser->set_options({line_numbers=>1});

my $doc1 = $parser->parse_file($input1);
$global_types{$_->getAttribute('type-name')} = $_ foreach $doc1->findnodes('/ld:data-definition/ld:global-type');
$global_types_orig{$_->getAttribute('original-name') || $_->getAttribute('type-name')} = $_ foreach $doc1->findnodes('/ld:data-definition/ld:global-type');
$global_objects{$_->getAttribute('name')} = $_ foreach $doc1->findnodes('/ld:data-definition/ld:global-object');

my $doc2 = $parser->parse_file($input2);
my $symbols = ($doc2->findnodes('/data-definition/symbol-table[@name="'.$symbolsname.'"]'))[-1];


print <<END
import java.util.*;
import ghidra.app.script.GhidraScript;
import ghidra.app.services.DataTypeManagerService;
import ghidra.framework.plugintool.PluginTool;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;

public class df_ghidra extends GhidraScript {

    DataTypeManager manager;
    Address vmeth_nullptr;

    void applyFunctionType(Address addr, String fnName, FunctionDefinition fnDataType, DataType thisType) throws Exception
    {
        Function fn = getFunctionAt(addr);
        if (fn == null)
            fn = createFunction(addr, fnName);

        fn.setName(fnName, SourceType.USER_DEFINED);

        fn.setCallingConvention("$callconv");
        fn.setReturnType(fnDataType.getReturnType(), SourceType.USER_DEFINED);

        List params = new ArrayList();
        ParameterDefinition[] typeParams = fnDataType.getArguments();
        for (int i = 0; i < typeParams.length; i++)
        {
            ParameterDefinition p = typeParams[i];
            DataType t = "this".equals(p.getName()) ? thisType : p.getDataType();
            params.add(new ParameterImpl(p.getName(), t, currentProgram));
        }
        fn.replaceParameters(params, FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS, true, SourceType.USER_DEFINED);
    }

    void applyVmethodType(Address vtableAddr, int pos, String className, String fnName, FunctionDefinition fnDataType, Address parentVtableAddr) throws Exception
    {
        Data d = getDataAt(vtableAddr).getComponent(pos);

        if (d.getValue().equals(vmeth_nullptr))
            return;

        if (parentVtableAddr != null)
        {
            Data dParent = getDataAt(parentVtableAddr).getComponent(pos);
            if (dParent.getValue().equals(d.getValue()))
            {
                println("skipping "+fnName);
                return;
            }
        }

        DataType dataType = manager.getDataType("/codegen.h/"+className);
        DataType thisType = new PointerDataType(dataType);

        applyFunctionType((Address)d.getValue(), fnName, fnDataType, thisType);
    }

    void applyVmethodTypes(Address vtableAddr, String className, String vtTypeName, Address parentVtableAddr) throws Exception
    {
        println("processing vtable for " + className+ " "+parentVtableAddr);

        try {
            currentProgram.getSymbolTable().createClass(currentProgram.getGlobalNamespace(), className, SourceType.USER_DEFINED);
        } catch (ghidra.util.exception.DuplicateNameException e) {}

        Structure vtType = (Structure) manager.getDataType("/codegen.h/"+vtTypeName);
        for (int i = 0; i < vtType.getNumComponents(); i++) {
            DataTypeComponent dc = vtType.getComponent(i);
            String fnName = className + "_" + dc.getFieldName();
            DataType fieldType = dc.getDataType();
            if (fieldType instanceof TypeDef)
            {
                Pointer ptrDataType = (Pointer) ((TypeDef)fieldType).getBaseDataType();
                FunctionDefinition fnDataType = (FunctionDefinition) ptrDataType.getDataType();
                applyVmethodType(vtableAddr, i, className, fnName, fnDataType, parentVtableAddr);
            }
        }
    }

    void createVtable(Address vtableAddr, String className) throws Exception
    {
        DataType dataType = manager.getDataType("/codegen.h/vtable_"+className);
        
        clearListing(vtableAddr, vtableAddr.add(dataType.getLength()-1));
        createData(vtableAddr, dataType);
        createLabel(vtableAddr, "_vtable_"+className, true, SourceType.USER_DEFINED);
    }

    void createGlobal(Address addr, String name, String typeName) throws Exception
    {
        if (typeName != null && !typeName.equals(""))
        {
            DataType dataType = getDataTypes(typeName)[0];//manager.getDataType("/codegen.h/"+typeName);
        
            clearListing(addr, addr.add(dataType.getLength()-1));
            createData(addr, dataType);
        }

        createLabel(addr, name, true, SourceType.USER_DEFINED);
    }
END
;

print <<END
    void globals() throws Exception {
END
;
process_globals($symbols);
print "}\n";
push @calls, "globals";

print <<END
    void vtables() throws Exception {
END
;
process_vtables($symbols);
print "}\n";
push @calls, "vtables";

print <<END
    void vmethods() throws Exception {
END
;
process_vmethods($symbols);
print "}\n";
push @calls, "vmethods";

print <<END
    protected void run() throws Exception {
        manager = currentProgram.getDataTypeManager();
        Function fn = getFunction("_guard_check_icall");
        vmeth_nullptr = (fn != null) ? fn.getEntryPoint() : toAddr(0);
END
;
for my $call (@calls) {
    print "$call();\n";
}
print <<END
    }
}
END
;
