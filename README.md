# df-ghidra-scripts

## codegen_c_hdr_ghidra.pl

generates C headers from df-structures codegen.out.xml

invocation:

    perl codegen_c_hdr_ghidra.pl [--linux] [--32] <codegen.out.xml>

will output `codegen.h`, and the name should not be changed when importing into Ghidra

## symbols_to_ghidra.pl

generates a Ghidra script to create globals and vmethods, apply their types, etc.

invocation:
    
    perl symbols_to_ghidra.pl <symbol-table name> <codegen.out.xml> <symbols.xml> > ghidra_scripts_folder/df_ghidra.java