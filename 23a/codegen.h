typedef char      int8_t;
typedef short     int16_t;
typedef int       int32_t;
typedef long long int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

// Windows STL
struct stl_string {
    union {
        char buf[16];
        char *ptr;
    };
    int32_t len;
    int32_t capa;
};
struct stl_deque {
    void *proxy;
    void *map;
    int32_t map_size;
    int32_t off;
    int32_t size;
    int32_t pad;
};
struct stl_vector_bool {
    char *ptr;
    char *endptr;
    char *endalloc;
    int size;
};
struct stl_vector_ptr {
    void **ptr;
    void **endptr;
    void **endalloc;
    int32_t pad;
};

struct stl_vector_strptr {
    struct stl_string **ptr;
    struct stl_string **endptr;
    struct stl_string **endalloc;
    int32_t pad;
};

struct stl_vector_int32_t {
    int32_t *ptr;
    int32_t *endptr;
    int32_t *endalloc;
    int32_t pad;
};

struct stl_vector_uint32_t {
    uint32_t *ptr;
    uint32_t *endptr;
    uint32_t *endalloc;
    int32_t pad;
};

struct stl_vector_int16_t {
    int16_t *ptr;
    int16_t *endptr;
    int16_t *endalloc;
    int32_t pad;
};

struct stl_vector_uint16_t {
    uint16_t *ptr;
    uint16_t *endptr;
    uint16_t *endalloc;
    int32_t pad;
};

struct stl_vector_int8_t {
    int8_t *ptr;
    int8_t *endptr;
    int8_t *endalloc;
    int32_t pad;
};

struct stl_vector_uint8_t {
    uint8_t *ptr;
    uint8_t *endptr;
    uint8_t *endalloc;
    int32_t pad;
};

struct df_linked_list {
    void *item;
    void *prev;
    void *next;
};

struct df_array {
    void *ptr;
    uint16_t len;
};

struct df_flagarray {
    uint8_t *ptr;
    uint32_t len;
};
struct abstract_building {
    int16_t type;
    int16_t param;
    int32_t id;
};

enum abstract_building_type {
    abstract_building_type_STORE_CRAFT,
    abstract_building_type_STORE_WEAPON,
    abstract_building_type_STORE_ARMOR,
    abstract_building_type_STORE_CLOTHING,
    abstract_building_type_STORE_FOOD,
    abstract_building_type_MEAD_HALL,
    abstract_building_type_KEEP,
    abstract_building_type_CAVE_RIVER,
    abstract_building_type_CAVE_MAGMA,
    abstract_building_type_RUIN_PILLARS,
    abstract_building_type_RUIN_PYRAMID,
    abstract_building_type_RUIN_TOWER,
    abstract_building_type_HOME_RANDOM,
    abstract_building_type_HOME_SINGLE,
    abstract_building_type_HOME_APARTMENT,
    abstract_building_type_HOME_APARTMENT_ROOM
};

struct active_script_varst;
typedef void (*vm_active_script_varst_setColor)(active_script_varst* this);
typedef void (*vm_active_script_varst_formatString)(active_script_varst* this,void* output,void* format);
typedef void (*vm_active_script_varst_getValue)(active_script_varst* this,void* int_value,void* ref_value);
typedef void (*vm_active_script_varst_setValue)(active_script_varst* this,void* var);
typedef void (*vm_active_script_varst_removeUnit)(active_script_varst* this,void* ref_value);
typedef void (*vm_active_script_varst_write_file)(active_script_varst* this,void*);
typedef void (*vm_active_script_varst_read_file)(active_script_varst* this,void*);
struct vtable_active_script_varst {
    vm_active_script_varst_setColor setColor;
    vm_active_script_varst_formatString formatString;
    vm_active_script_varst_getValue getValue;
    vm_active_script_varst_setValue setValue;
    vm_active_script_varst_removeUnit removeUnit;
    vm_active_script_varst_write_file write_file;
    vm_active_script_varst_read_file read_file;
};
struct active_script_varst {
    struct vtable_active_script_varst *vtable;
    struct stl_string name;
};

struct active_script_var_longst {
        struct vtable_active_script_varst *vtable;
        struct stl_string name;
    int32_t value;
};

struct unit;
struct active_script_var_unitst {
        struct vtable_active_script_varst *vtable;
        struct stl_string name;
    struct unit *unit;
};

struct buildingst;
enum T_flags_8226_enum {
    T_flags_8226_next_step=0x01,
    T_flags_8226_checked_building=0x02,
    T_flags_8226_add_delay=0x04,
    T_flags_8226_topic_discussed=0x08,
    T_flags_8226_meeting_done=0x10
};

struct activity_info {
    int32_t id;
    struct unit *unit_actor;
    struct unit *unit_noble;
    struct buildingst *place;
    struct T_flags_8226 {
        uint16_t bitfield;
    } activity_info_flags;
    int8_t state;
    int16_t delay;
    int32_t tree_quota;
};

struct quest_list_link;
struct coord2d32 {
    int32_t x;
    int32_t y;
};

struct vtable_taskst {
    void *dummy;
};
struct taskst {
    struct quest_list_link *link;
    int32_t id;
    int32_t giver_hf;
    int32_t giver_site;
    int32_t giver_entity;
    int32_t recipient_hf;
    int32_t adv_task_anon_1;
    struct coord2d32 target_pos;
    struct coord2d32 giver_pos;
};

enum armor_flags {
    armor_flags_METAL_ARMOR_LEVELS = 1
};

enum armor_general_flags {
    armor_general_flags_SOFT,
    armor_general_flags_HARD,
    armor_general_flags_METAL,
    armor_general_flags_BARRED,
    armor_general_flags_SCALED,
    armor_general_flags_LEATHER,
    armor_general_flags_SHAPED
};

struct armor_properties {
    struct df_flagarray armor_properties_flags;
    int32_t layer;
    int16_t layer_size;
    int16_t layer_permit;
    int16_t coverage;
};

struct art_image_elementst;
typedef void (*vm_art_image_elementst_write_file)(art_image_elementst* this,void*);
typedef void (*vm_art_image_elementst_read_file)(art_image_elementst* this,void*,int32_t loadversion);
enum art_image_element_type {
    art_image_element_type_CREATURE,
    art_image_element_type_PLANT,
    art_image_element_type_TREE,
    art_image_element_type_SHAPE,
    art_image_element_type_ITEM
};

typedef art_image_element_type (*vm_art_image_elementst_getType)(art_image_elementst* this);
typedef void (*vm_art_image_elementst_setID)(art_image_elementst* this,int32_t ID);
typedef void (*vm_art_image_elementst_vmeth_16)(art_image_elementst* this);
typedef void* (*vm_art_image_elementst_clone)(art_image_elementst* this);
typedef void (*vm_art_image_elementst_getSymbol)(art_image_elementst* this,void* tile,void* size);
typedef void (*vm_art_image_elementst_getName)(art_image_elementst* this,void* string,bool useThe,bool useName);
typedef void (*vm_art_image_elementst_markDiscovered)(art_image_elementst* this);
typedef void (*vm_art_image_elementst_getColorAndShape)(art_image_elementst* this,void* colors,void* shapes);
struct vtable_art_image_elementst {
    vm_art_image_elementst_write_file write_file;
    vm_art_image_elementst_read_file read_file;
    vm_art_image_elementst_getType getType;
    vm_art_image_elementst_setID setID;
    vm_art_image_elementst_vmeth_16 vmeth_16;
    vm_art_image_elementst_clone clone;
    vm_art_image_elementst_getSymbol getSymbol;
    vm_art_image_elementst_getName getName;
    vm_art_image_elementst_markDiscovered markDiscovered;
    vm_art_image_elementst_getColorAndShape getColorAndShape;
};
struct art_image_elementst {
    struct vtable_art_image_elementst *vtable;
    int32_t count;
};

struct stl_vector_ptr_art_image_elementst {
struct art_image_elementst **ptr;
void *endptr;
void *endalloc;
};
struct art_image_propertyst;
typedef void (*vm_art_image_propertyst_write_file)(art_image_propertyst* this,void*);
typedef void (*vm_art_image_propertyst_read_file)(art_image_propertyst* this,void*,int32_t loadversion);
enum art_image_property_type {
    art_image_property_type_transitive_verb,
    art_image_property_type_intransitive_verb
};

typedef art_image_property_type (*vm_art_image_propertyst_getType)(art_image_propertyst* this);
typedef void (*vm_art_image_propertyst_vmeth_12)(art_image_propertyst* this);
typedef void* (*vm_art_image_propertyst_clone)(art_image_propertyst* this);
typedef void (*vm_art_image_propertyst_getName)(art_image_propertyst* this,void* str,void* image,bool useName);
struct vtable_art_image_propertyst {
    vm_art_image_propertyst_write_file write_file;
    vm_art_image_propertyst_read_file read_file;
    vm_art_image_propertyst_getType getType;
    vm_art_image_propertyst_vmeth_12 vmeth_12;
    vm_art_image_propertyst_clone clone;
    vm_art_image_propertyst_getName getName;
};
struct art_image_propertyst {
    struct vtable_art_image_propertyst *vtable;
    struct df_flagarray art_image_propertyst_flags;
};

struct stl_vector_ptr_art_image_propertyst {
struct art_image_propertyst **ptr;
void *endptr;
void *endalloc;
};
struct language_name {
    struct stl_string first_name;
    struct stl_string nickname;
    struct T_parts_7176 {
        int32_t word;
        int32_t part_of_speech;
    } parts[7];
    int32_t language;
    int16_t unknown;
    int8_t has_name;
};

struct general_refst;
struct art_image {
    struct stl_vector_ptr_art_image_elementst elements;
    struct stl_vector_ptr_art_image_propertyst properties;
    int32_t event;
    struct language_name name;
    int32_t spec_ref_type;
    int16_t material;
    int16_t matgloss;
    int16_t quality;
    int32_t artist;
    int32_t site;
    struct general_refst *general_ref;
    int32_t year;
    int8_t season;
    int16_t season_ticks;
    int32_t id;
    int16_t subid;
};

struct art_image_chunk {
    int32_t id;
    struct art_image *images[500];
};

struct art_image_elementst;
typedef void (*vm_art_image_elementst_write_file)(art_image_elementst* this,void*);
typedef void (*vm_art_image_elementst_read_file)(art_image_elementst* this,void*,int32_t loadversion);
typedef art_image_element_type (*vm_art_image_elementst_getType)(art_image_elementst* this);
typedef void (*vm_art_image_elementst_setID)(art_image_elementst* this,int32_t ID);
typedef void (*vm_art_image_elementst_vmeth_16)(art_image_elementst* this);
typedef void* (*vm_art_image_elementst_clone)(art_image_elementst* this);
typedef void (*vm_art_image_elementst_getSymbol)(art_image_elementst* this,void* tile,void* size);
typedef void (*vm_art_image_elementst_getName)(art_image_elementst* this,void* string,bool useThe,bool useName);
typedef void (*vm_art_image_elementst_markDiscovered)(art_image_elementst* this);
typedef void (*vm_art_image_elementst_getColorAndShape)(art_image_elementst* this,void* colors,void* shapes);
struct vtable_art_image_elementst {
    vm_art_image_elementst_write_file write_file;
    vm_art_image_elementst_read_file read_file;
    vm_art_image_elementst_getType getType;
    vm_art_image_elementst_setID setID;
    vm_art_image_elementst_vmeth_16 vmeth_16;
    vm_art_image_elementst_clone clone;
    vm_art_image_elementst_getSymbol getSymbol;
    vm_art_image_elementst_getName getName;
    vm_art_image_elementst_markDiscovered markDiscovered;
    vm_art_image_elementst_getColorAndShape getColorAndShape;
};
struct art_image_elementst {
    struct vtable_art_image_elementst *vtable;
    int32_t count;
};

struct art_image_element_creaturest {
        struct vtable_art_image_elementst *vtable;
        int32_t count;
    int32_t race;
    int32_t histfig;
};

enum item_flags_enum {
    item_flags_on_ground=0x01,
    item_flags_in_job=0x02,
    item_flags_hostile=0x04,
    item_flags_in_inventory=0x08,
    item_flags_removed=0x10,
    item_flags_in_building=0x20,
    item_flags_container=0x40,
    item_flags_dead_dwarf=0x80,
    item_flags_rotten=0x100,
    item_flags_spider_web=0x200,
    item_flags_construction=0x400,
    item_flags_encased=0x800,
    item_flags_bound_artifact=0x1000,
    item_flags_murder=0x2000,
    item_flags_foreign=0x4000,
    item_flags_trader=0x8000,
    item_flags_owned=0x10000,
    item_flags_garbage_collect=0x20000,
    item_flags_artifact=0x40000,
    item_flags_forbid=0x80000,
    item_flags_already_uncategorized=0x100000,
    item_flags_dump=0x200000,
    item_flags_on_fire=0x400000
};

struct item_flags {
    int32_t bitfield;
};

struct art_image_element_itemst {
        struct vtable_art_image_elementst *vtable;
        int32_t count;
    int16_t item_type;
    int16_t item_subtype;
    int16_t material;
    int16_t matgloss;
    struct item_flags art_image_element_itemst_flags;
    int32_t item_id;
};

struct art_image_element_plantst {
        struct vtable_art_image_elementst *vtable;
        int32_t count;
    int32_t plant_id;
};

struct art_image_element_shapest {
        struct vtable_art_image_elementst *vtable;
        int32_t count;
    int32_t shape_id;
    int16_t shape_adj;
};

struct art_image_element_treest {
        struct vtable_art_image_elementst *vtable;
        int32_t count;
    int32_t wood_id;
};

struct art_image_propertyst;
typedef void (*vm_art_image_propertyst_write_file)(art_image_propertyst* this,void*);
typedef void (*vm_art_image_propertyst_read_file)(art_image_propertyst* this,void*,int32_t loadversion);
typedef art_image_property_type (*vm_art_image_propertyst_getType)(art_image_propertyst* this);
typedef void (*vm_art_image_propertyst_vmeth_12)(art_image_propertyst* this);
typedef void* (*vm_art_image_propertyst_clone)(art_image_propertyst* this);
typedef void (*vm_art_image_propertyst_getName)(art_image_propertyst* this,void* str,void* image,bool useName);
struct vtable_art_image_propertyst {
    vm_art_image_propertyst_write_file write_file;
    vm_art_image_propertyst_read_file read_file;
    vm_art_image_propertyst_getType getType;
    vm_art_image_propertyst_vmeth_12 vmeth_12;
    vm_art_image_propertyst_clone clone;
    vm_art_image_propertyst_getName getName;
};
struct art_image_propertyst {
    struct vtable_art_image_propertyst *vtable;
    struct df_flagarray art_image_property_flags;
};

struct art_image_property_intransitive_verbst {
        struct vtable_art_image_propertyst *vtable;
        struct df_flagarray art_image_propertyst_flags;
    int32_t subject;
    int16_t verb;
};

struct art_image_property_transitive_verbst {
        struct vtable_art_image_propertyst *vtable;
        struct df_flagarray art_image_propertyst_flags;
    int32_t subject;
    int32_t object;
    int16_t verb;
};

enum art_image_property_verb {
    art_image_property_verb_Withering,
    art_image_property_verb_SurroundedBy,
    art_image_property_verb_Massacring,
    art_image_property_verb_Fighting,
    art_image_property_verb_Laboring,
    art_image_property_verb_Greeting,
    art_image_property_verb_Refusing,
    art_image_property_verb_Speaking,
    art_image_property_verb_Embracing,
    art_image_property_verb_StrikingDown,
    art_image_property_verb_MenacingPose,
    art_image_property_verb_Traveling,
    art_image_property_verb_Raising,
    art_image_property_verb_Hiding,
    art_image_property_verb_LookingConfused,
    art_image_property_verb_LookingTerrified,
    art_image_property_verb_Devouring,
    art_image_property_verb_Admiring,
    art_image_property_verb_Burning,
    art_image_property_verb_Weeping,
    art_image_property_verb_LookingDejected,
    art_image_property_verb_Cringing,
    art_image_property_verb_Screaming,
    art_image_property_verb_SubmissiveGesture,
    art_image_property_verb_FetalPosition,
    art_image_property_verb_SmearedIntoSpiral,
    art_image_property_verb_Falling,
    art_image_property_verb_Dead,
    art_image_property_verb_Laughing,
    art_image_property_verb_LookingOffended,
    art_image_property_verb_BeingShot,
    art_image_property_verb_PlaintiveGesture,
    art_image_property_verb_Melting,
    art_image_property_verb_Shooting
};

struct art_image_ref {
    int32_t id;
    int16_t subid;
};

enum artifact_flags {
    artifact_flags_Discovered
};

struct itemst;
struct artifact_record {
    int32_t id;
    struct language_name name;
    int16_t action_timer;
    struct df_flagarray artifact_record_flags;
    struct itemst *item;
};

enum T_status_14932 {
    T_status_14932_RemoveTrading = -2,
    T_status_14932_RemovePending,
    T_status_14932_None,
    T_status_14932_AddPending,
    T_status_14932_Pending,
    T_status_14932_Trading
};

struct assign_trade_status {
    struct itemst *item;
    int8_t status;
};

enum biome_type {
    biome_type_MOUNTAIN,
    biome_type_GLACIER,
    biome_type_TUNDRA,
    biome_type_SWAMP_TEMPERATE_FRESHWATER,
    biome_type_SWAMP_TEMPERATE_SALTWATER,
    biome_type_MARSH_TEMPERATE_FRESHWATER,
    biome_type_MARSH_TEMPERATE_SALTWATER,
    biome_type_SWAMP_TROPICAL_FRESHWATER,
    biome_type_SWAMP_TROPICAL_SALTWATER,
    biome_type_SWAMP_MANGROVE,
    biome_type_MARSH_TROPICAL_FRESHWATER,
    biome_type_MARSH_TROPICAL_SALTWATER,
    biome_type_FOREST_TAIGA,
    biome_type_FOREST_TEMPERATE_CONIFER,
    biome_type_FOREST_TEMPERATE_BROADLEAF,
    biome_type_FOREST_TROPICAL_CONIFER,
    biome_type_FOREST_TROPICAL_DRY_BROADLEAF,
    biome_type_FOREST_TROPICAL_MOIST_BROADLEAF,
    biome_type_GRASSLAND_TEMPERATE,
    biome_type_SAVANNA_TEMPERATE,
    biome_type_SHRUBLAND_TEMPERATE,
    biome_type_GRASSLAND_TROPICAL,
    biome_type_SAVANNA_TROPICAL,
    biome_type_SHRUBLAND_TROPICAL,
    biome_type_DESERT_BADLAND,
    biome_type_DESERT_ROCK,
    biome_type_DESERT_SAND,
    biome_type_OCEAN,
    biome_type_INLAND_FRESHWATER,
    biome_type_INLAND_BRACKISHWATER,
    biome_type_INLAND_SALTWATER,
    biome_type_SUBTERRANEAN_RIVER,
    biome_type_SUBTERRANEAN_CHASM,
    biome_type_SUBTERRANEAN_LAVA
};

enum block_flags {
    block_flags_designated,
    block_flags_update_temperature
};

struct body_part_raw {
    struct stl_string token;
    struct stl_string name;
    int16_t con_part_id;
    // TODO in body_part_raw: container_notg df_static_flagarray body_part_raw_flags;
};

struct stl_vector_ptr_body_part_raw {
struct body_part_raw **ptr;
void *endptr;
void *endalloc;
};
enum T_flags_1486_enum {
    T_flags_1486_with=0x01,
    T_flags_1486_latch=0x02,
    T_flags_1486_main=0x04
};

struct creature_attack {
    int32_t min_damage;
    int32_t max_damage;
    int16_t damage_type;
    struct stl_string verb_3rd;
    struct stl_string verb_2nd;
    struct T_flags_1486 {
        uint16_t bitfield;
    } creature_attack_flags;
    struct stl_vector_int32_t specialattack_type;
    struct stl_vector_int16_t specialattack_material;
    struct stl_vector_int32_t specialattack_min;
    struct stl_vector_int32_t specialattack_max;
    struct stl_vector_int16_t by_token;
    struct stl_vector_int16_t by_type;
};

struct stl_vector_ptr_creature_attack {
struct creature_attack **ptr;
void *endptr;
void *endalloc;
};
struct body_info {
    struct stl_vector_ptr_body_part_raw body_parts;
    struct stl_vector_ptr_creature_attack attacks;
};

enum body_part_raw_flags {
    body_part_raw_flags_HEAD,
    body_part_raw_flags_UPPERBODY,
    body_part_raw_flags_LOWERBODY,
    body_part_raw_flags_SIGHT,
    body_part_raw_flags_EMBEDDED,
    body_part_raw_flags_INTERNAL,
    body_part_raw_flags_CIRCULATION,
    body_part_raw_flags_LIMB = 8,
    body_part_raw_flags_GRASP,
    body_part_raw_flags_STANCE,
    body_part_raw_flags_GUTS,
    body_part_raw_flags_BREATHE,
    body_part_raw_flags_SMALL,
    body_part_raw_flags_THROAT,
    body_part_raw_flags_JOINT,
    body_part_raw_flags_THOUGHT,
    body_part_raw_flags_NERVOUS,
    body_part_raw_flags_RIGHT,
    body_part_raw_flags_LEFT,
    body_part_raw_flags_HEAR,
    body_part_raw_flags_SMELL,
    body_part_raw_flags_FLIER,
    body_part_raw_flags_DIGIT,
    body_part_raw_flags_MOUTH,
    body_part_raw_flags_APERTURE
};

struct body_part_template {
    struct stl_string id;
    struct stl_string name;
    struct stl_string con;
    int16_t contype;
    // TODO in body_part_template: container_notg df_static_flagarray body_part_template_flags;
};

enum body_part_template_contype {
    body_part_template_contype_UPPERBODY,
    body_part_template_contype_LOWERBODY,
    body_part_template_contype_HEAD,
    body_part_template_contype_GRASP,
    body_part_template_contype_STANCE
};

enum body_part_template_flags {
    body_part_template_flags_HEAD,
    body_part_template_flags_UPPERBODY,
    body_part_template_flags_LOWERBODY,
    body_part_template_flags_SIGHT,
    body_part_template_flags_EMBEDDED,
    body_part_template_flags_INTERNAL,
    body_part_template_flags_CIRCULATION,
    body_part_template_flags_LIMB = 8,
    body_part_template_flags_GRASP,
    body_part_template_flags_STANCE,
    body_part_template_flags_GUTS,
    body_part_template_flags_BREATHE,
    body_part_template_flags_SMALL,
    body_part_template_flags_THROAT,
    body_part_template_flags_JOINT,
    body_part_template_flags_THOUGHT,
    body_part_template_flags_NERVOUS,
    body_part_template_flags_RIGHT,
    body_part_template_flags_LEFT,
    body_part_template_flags_HEAR,
    body_part_template_flags_SMELL,
    body_part_template_flags_FLIER,
    body_part_template_flags_DIGIT,
    body_part_template_flags_MOUTH,
    body_part_template_flags_APERTURE
};

struct stl_vector_ptr_body_part_template {
struct body_part_template **ptr;
void *endptr;
void *endalloc;
};
struct body_template {
    struct stl_string id;
    struct stl_vector_ptr_body_part_template parts;
};

struct buildingst;
enum job_type {
    job_type_CarveFortification,
    job_type_DetailWall,
    job_type_DetailFloor,
    job_type_Dig,
    job_type_FellTree,
    job_type_GatherPlants,
    job_type_CollectWebs,
    job_type_BringItemToDepot,
    job_type_BringItemToShop,
    job_type_Eat,
    job_type_GetProvisions,
    job_type_Drink,
    job_type_Drink2,
    job_type_FillWaterskin,
    job_type_Sleep,
    job_type_CollectSand,
    job_type_Fish,
    job_type_Hunt,
    job_type_HuntVermin,
    job_type_Kidnap,
    job_type_BeatCriminal,
    job_type_StartingFistFight,
    job_type_CollectTaxes,
    job_type_GuardTaxCollector,
    job_type_CatchLiveLandAnimal,
    job_type_CatchLiveFish,
    job_type_ReturnKill,
    job_type_CheckChest,
    job_type_StoreOwnedItem,
    job_type_PlaceItemInTomb,
    job_type_StoreItemInStockpile,
    job_type_StoreItemInBag,
    job_type_StoreItemInChest,
    job_type_StoreItemInCabinet,
    job_type_StoreWeapon,
    job_type_StoreArmor,
    job_type_StoreItemInBarrel,
    job_type_StoreItemInBin,
    job_type_SeekArtifact,
    job_type_SeekInfant,
    job_type_AttendParty,
    job_type_ArcheryPractice,
    job_type_Sparring,
    job_type_GoShopping,
    job_type_GoShopping2,
    job_type_Clean,
    job_type_Rest,
    job_type_PickupEquipment,
    job_type_ChasmItem,
    job_type_StrangeMoodCrafter,
    job_type_StrangeMoodJeweller,
    job_type_StrangeMoodForge,
    job_type_StrangeMoodMagmaForge,
    job_type_StrangeMoodBrooding,
    job_type_StrangeMoodFell,
    job_type_StrangeMoodCarpenter,
    job_type_StrangeMoodMason,
    job_type_StrangeMoodBowyer,
    job_type_StrangeMoodTanner,
    job_type_StrangeMoodWeaver,
    job_type_StrangeMoodGlassmaker,
    job_type_StrangeMoodMechanics,
    job_type_ConstructBuilding,
    job_type_ConstructDoor,
    job_type_ConstructFloodgate,
    job_type_ConstructBed,
    job_type_ConstructThrone,
    job_type_ConstructCoffin,
    job_type_ConstructTable,
    job_type_ConstructChest,
    job_type_ConstructBin,
    job_type_ConstructArmorStand,
    job_type_ConstructWeaponRack,
    job_type_ConstructCabinet,
    job_type_ConstructStatue,
    job_type_ConstructBlocks,
    job_type_MakeRawGlass,
    job_type_MakeCrafts,
    job_type_MintCoins,
    job_type_CutGems,
    job_type_CutGlass,
    job_type_EncrustWithGems,
    job_type_EncrustWithGlass,
    job_type_DestroyBuilding,
    job_type_MakeBars,
    job_type_MeltMetalObject,
    job_type_ExtractStrands,
    job_type_TanAHide,
    job_type_PlantSeeds,
    job_type_HarvestPlants,
    job_type_TrainHuntingAnimal,
    job_type_TrainWarAnimal,
    job_type_MakeWeapon,
    job_type_ForgeAnvil,
    job_type_ConstructCatapultParts,
    job_type_ConstructBallistaParts,
    job_type_MakeArmor,
    job_type_MakeHelm,
    job_type_MakePants,
    job_type_StudWith,
    job_type_ButcherAnimal,
    job_type_PrepareRawFish,
    job_type_MillPlants,
    job_type_BaitTrap,
    job_type_MilkCreature,
    job_type_MakeCheese,
    job_type_ProcessPlants,
    job_type_ProcessPlantsBag,
    job_type_ProcessPlantsVial,
    job_type_ProcessPlantsBarrel,
    job_type_PrepareMeal,
    job_type_WeaveCloth,
    job_type_MakeGloves,
    job_type_MakeShoes,
    job_type_MakeShield,
    job_type_MakeShirt,
    job_type_MakeCloak,
    job_type_MakeCage,
    job_type_MakeChain,
    job_type_MakeFlask,
    job_type_MakeGoblet,
    job_type_MakeInstrument,
    job_type_MakeToy,
    job_type_MakeAnimalTrap,
    job_type_MakeBarrel,
    job_type_MakeBucket,
    job_type_MakeWindow,
    job_type_MakeTotem,
    job_type_MakeAmmo,
    job_type_DecorateWith,
    job_type_MakeBackpack,
    job_type_MakeQuiver,
    job_type_MakeBallistaArrowHead,
    job_type_AssembleSiegeAmmo,
    job_type_LoadCatapult,
    job_type_LoadBallista,
    job_type_FireCatapult,
    job_type_FireBallista,
    job_type_ConstructMechanisms,
    job_type_MakeTrapComponent,
    job_type_LoadCageTrap,
    job_type_LoadStoneTrap,
    job_type_LoadWeaponTrap,
    job_type_CleanTrap,
    job_type_CastSpell,
    job_type_LinkBuildingToTrigger,
    job_type_PullLever,
    job_type_BrewDrink,
    job_type_ExtractFromPlants = 149,
    job_type_ExtractFromRawFish,
    job_type_ExtractFromLandAnimal,
    job_type_TameVermin,
    job_type_TameAnimal,
    job_type_ChainAnimal,
    job_type_UnchainAnimal,
    job_type_UnchainPet,
    job_type_ReleaseLargeCreature,
    job_type_ReleasePet,
    job_type_ReleaseSmallCreature,
    job_type_HandleSmallCreature,
    job_type_HandleLargeCreature,
    job_type_CageLargeCreature,
    job_type_CageSmallCreature,
    job_type_RecoverWounded,
    job_type_DrainAquarium,
    job_type_FillAquarium,
    job_type_DrainPond,
    job_type_FillPond,
    job_type_GiveWater,
    job_type_GiveFood,
    job_type_GiveWater2,
    job_type_GiveFood2,
    job_type_RecoverPet,
    job_type_UnpondSmallAnimal,
    job_type_PondSmallAnimal,
    job_type_SlaughterAnimal,
    job_type_MakeCharcoal,
    job_type_MakeAsh,
    job_type_MakeLye,
    job_type_MakePotashFromLye,
    job_type_MakePearlash,
    job_type_RenderFat,
    job_type_MakeSoap,
    job_type_FertilizeField,
    job_type_MakePotashFromAsh,
    job_type_DyeThread,
    job_type_DyeCloth,
    job_type_SewImage
};

typedef void (*vm_buildingst_setJobTimer)(buildingst* this,job_type,int16_t timer);
typedef bool (*vm_buildingst_isOnFire)(buildingst* this);
typedef void (*vm_buildingst_updateFromWeather)(buildingst* this);
typedef void (*vm_buildingst_updateTemperature)(buildingst* this);
typedef void (*vm_buildingst_updateItems)(buildingst* this);
typedef void (*vm_buildingst_updateTempFromTile)(buildingst* this,uint16_t temp,bool doAdjust);
typedef bool (*vm_buildingst_isColoredByMaterial)(buildingst* this);
typedef bool (*vm_buildingst_isFarmPlot)(buildingst* this);
typedef void* (*vm_buildingst_getWorkshopProfile)(buildingst* this);
enum building_type {
    building_type_NONE = -1,
    building_type_Chair,
    building_type_Bed,
    building_type_Table,
    building_type_Coffin,
    building_type_FarmPlot,
    building_type_Furnace,
    building_type_TradeDepot,
    building_type_Shop,
    building_type_Door,
    building_type_Floodgate,
    building_type_Box,
    building_type_Weaponrack,
    building_type_Armorstand,
    building_type_Workshop,
    building_type_Cabinet,
    building_type_Statue,
    building_type_Window,
    building_type_Well,
    building_type_Bridge,
    building_type_Aqueduct,
    building_type_Road,
    building_type_Channel,
    building_type_SiegeEngine,
    building_type_Trap,
    building_type_AnimalTrap,
    building_type_Support,
    building_type_ArcheryTarget,
    building_type_Chain,
    building_type_Cage,
    building_type_Stockpile,
    building_type_Civzone,
    building_type_Weapon,
    building_type_Wagon
};

typedef building_type (*vm_buildingst_getType)(buildingst* this);
typedef int16_t (*vm_buildingst_getSubtype)(buildingst* this);
typedef void (*vm_buildingst_setSubtype)(buildingst* this,int16_t subtype);
typedef bool (*vm_buildingst_isActual)(buildingst* this);
typedef int32_t (*vm_buildingst_getStorageType)(buildingst* this);
typedef bool (*vm_buildingst_isCoffin2)(buildingst* this);
typedef void (*vm_buildingst_updateAction)(buildingst* this);
typedef bool (*vm_buildingst_isStatueOrRestraint)(buildingst* this);
typedef void (*vm_buildingst_setMaterialAmount)(buildingst* this,int32_t amount);
typedef void (*vm_buildingst_setBuildStage)(buildingst* this,int16_t stage);
typedef int32_t (*vm_buildingst_getBuildStage)(buildingst* this);
typedef int32_t (*vm_buildingst_getMaxBuildStage)(buildingst* this);
typedef int32_t (*vm_buildingst_getArchitectureValue)(buildingst* this);
typedef bool (*vm_buildingst_isSettingOccupancy)(buildingst* this);
typedef bool (*vm_buildingst_isExtentShaped)(buildingst* this);
typedef void (*vm_buildingst_updateOccupancy)(buildingst* this,int32_t abs_x,int32_t abs_y);
typedef int32_t (*vm_buildingst_getRoomValue)(buildingst* this,void*);
typedef int32_t (*vm_buildingst_getPersonalValue)(buildingst* this,void*);
typedef bool (*vm_buildingst_canBeRoom)(buildingst* this);
typedef int32_t (*vm_buildingst_getConstructionValue)(buildingst* this);
typedef void (*vm_buildingst_queueDestroy)(buildingst* this);
typedef bool (*vm_buildingst_isImpassableTile)(buildingst* this,int32_t rel_x,int32_t rel_y);
typedef int32_t (*vm_buildingst_getFreeCapacity)(buildingst* this,bool exclude_in_room,bool include_pending_jobs);
typedef bool (*vm_buildingst_canStoreItem)(buildingst* this,void*,bool ignore_available_space,bool include_pending_jobs);
typedef void (*vm_buildingst_getName)(buildingst* this,void* name);
typedef void (*vm_buildingst_getNameColor)(buildingst* this);
typedef void (*vm_buildingst_initSettingsEnable)(buildingst* this,int8_t mode);
typedef void (*vm_buildingst_initSettingsDisable)(buildingst* this,int8_t mode);
typedef void (*vm_buildingst_initBurialFlags)(buildingst* this);
typedef void (*vm_buildingst_clearBurialFlags)(buildingst* this);
typedef void (*vm_buildingst_clearBurialFlags2)(buildingst* this);
typedef int32_t (*vm_buildingst_getClutterLevel)(buildingst* this);
typedef bool (*vm_buildingst_needsDesign)(buildingst* this);
typedef bool (*vm_buildingst_canUseForMood)(buildingst* this,job_type);
typedef bool (*vm_buildingst_canBeRoomSubset)(buildingst* this);
typedef bool (*vm_buildingst_isCoffin)(buildingst* this);
typedef bool (*vm_buildingst_canUseSpouseRoom)(buildingst* this);
typedef bool (*vm_buildingst_canMakeRoom)(buildingst* this);
typedef void (*vm_buildingst_setContainedItems)(buildingst* this);
typedef bool (*vm_buildingst_isJustice)(buildingst* this);
typedef void (*vm_buildingst_detachUnit)(buildingst* this,void*);
typedef void (*vm_buildingst_write_file)(buildingst* this,void*);
typedef void (*vm_buildingst_read_file)(buildingst* this,void*,int32_t loadversion);
typedef bool (*vm_buildingst_isBuiltFromSide)(buildingst* this);
typedef void (*vm_buildingst_categorize)(buildingst* this,bool on_map);
typedef void (*vm_buildingst_uncategorize)(buildingst* this);
typedef int32_t (*vm_buildingst_getBaseValue)(buildingst* this);
typedef void (*vm_buildingst_setMachineState)(buildingst* this,int32_t new_state);
typedef void (*vm_buildingst_AdventurerInteract)(buildingst* this);
typedef bool (*vm_buildingst_needsMagma)(buildingst* this);
typedef void (*vm_buildingst_removeUses)(buildingst* this,bool noscatter,bool lost);
typedef void (*vm_buildingst_deconstructItems)(buildingst* this,bool noscatter,bool lost);
typedef void (*vm_buildingst_updatePathfinding)(buildingst* this);
typedef bool (*vm_buildingst_takesFireDamage)(buildingst* this,int8_t fire_type);
typedef void (*vm_buildingst_populateSettingsMenu)(buildingst* this);
typedef void (*vm_buildingst_populateTaskList)(buildingst* this);
typedef bool (*vm_buildingst_isForbidden)(buildingst* this);
typedef bool (*vm_buildingst_isVisibleInLookList)(buildingst* this);
typedef bool (*vm_buildingst_isVisible)(buildingst* this);
typedef void (*vm_buildingst_getDrawExtents)(buildingst* this,void* buffer);
typedef void (*vm_buildingst_drawBuilding)(buildingst* this,void* buffer);
typedef void (*vm_buildingst_vmeth_280)(buildingst* this);
enum building_flags_enum {
    building_flags_exists=0x01,
    building_flags_site_blocked=0x02,
    building_flags_room_collision=0x04,
    building_flags__unk_3=0x08,
    building_flags_justice=0x10
};

struct building_flags {
    int32_t bitfield;
};

struct building_extents {
    uint8_t *extents;
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
};

struct job_list_link;
struct coord32 {
    int32_t x;
    int32_t y;
    int32_t z;
};

enum job_flags_enum {
    job_flags_repeat=0x01,
    job_flags_suspend=0x02,
    job_flags_working=0x04,
    job_flags_fetching=0x08,
    job_flags_special=0x10,
    job_flags_bringing=0x20,
    job_flags_item_lost=0x40,
    job_flags_noise=0x180,
    job_flags_by_manager=0x200,
    job_flags_store_item=0x400,
    job_flags_quality=0x3800,
    job_flags_specific_dropoff=0x4000
};

struct job_flags {
    uint16_t bitfield;
};

enum item_category_enum {
    item_category_animals=0x01,
    item_category_food=0x02,
    item_category_furniture=0x04,
    item_category_graveyard=0x08,
    item_category_refuse=0x10,
    item_category_stone=0x20,
    item_category_ore=0x40,
    item_category_ammo=0x80,
    item_category_coins=0x100,
    item_category_bars=0x200,
    item_category_gems=0x400,
    item_category_finished_goods=0x800,
    item_category_leather=0x1000,
    item_category_cloth=0x2000,
    item_category_wood=0x4000,
    item_category_weapons=0x8000,
    item_category_armor=0x10000
};

struct item_category {
    uint32_t bitfield;
};

enum T_role_6281 {
    T_role_6281_Reagent = 1,
    T_role_6281_Hauled,
    T_role_6281_TargetContainer = 6
};

struct job_item_ref {
    struct itemst *item;
    int32_t role;
    int32_t is_fetching;
};

struct stl_vector_ptr_job_item_ref {
struct job_item_ref **ptr;
void *endptr;
void *endalloc;
};
struct party_info;
struct historical_entity;
struct effect_info;
struct drink_area;
struct pet_info;
struct vermin;
struct viewscreenst;
struct nemesis_record;
struct specific_ref {
    int32_t type;
    union {
        void *object;
        struct unit *unit;
        struct job *job;
        struct party_info *party;
        struct historical_entity *entity;
        struct activity_info *activity;
        struct itemst *item;
        struct effect_info *effect;
        struct drink_area *drink_area;
        struct pet_info *pet;
        struct vermin *vermin;
        struct viewscreenst *screen;
        struct nemesis_record *nemesis;
        struct artifact_record *artifact;
    };
    union {
        void *wrestle;
    } arg2;
};

struct stl_vector_ptr_specific_ref {
struct specific_ref **ptr;
void *endptr;
void *endalloc;
};
struct general_refst;
typedef void (*vm_general_refst_write_file)(general_refst* this,void*);
typedef void (*vm_general_refst_read_file)(general_refst* this,void*,int32_t loadversion);
enum general_ref_type {
    general_ref_type_ARTIFACT,
    general_ref_type_ITEM_TYPE,
    general_ref_type_COINBATCH,
    general_ref_type_MAPSQUARE,
    general_ref_type_ENTITY_ART_IMAGE,
    general_ref_type_UNIT,
    general_ref_type_CONTAINS_UNIT,
    general_ref_type_ITEM,
    general_ref_type_CONTAINS_ITEM,
    general_ref_type_PROJECTILE,
    general_ref_type_UNIT_TRAINEE,
    general_ref_type_UNIT_ITEMOWNER,
    general_ref_type_UNIT_TRADEBRINGER,
    general_ref_type_CONTAINED_IN_ITEM,
    general_ref_type_UNIT_HOLDER,
    general_ref_type_UNIT_WORKER,
    general_ref_type_BUILDING,
    general_ref_type_BUILDING_CIVZONE_ASSIGNED,
    general_ref_type_BUILDING_TRIGGER,
    general_ref_type_BUILDING_TRIGGERTARGET,
    general_ref_type_BUILDING_CHAIN,
    general_ref_type_BUILDING_CAGED,
    general_ref_type_BUILDING_CHANNELED,
    general_ref_type_BUILDING_HOLDER
};

typedef general_ref_type (*vm_general_refst_getType)(general_refst* this);
typedef void* (*vm_general_refst_getItem)(general_refst* this);
typedef void* (*vm_general_refst_getUnit)(general_refst* this);
typedef void* (*vm_general_refst_getProjectile)(general_refst* this);
typedef void* (*vm_general_refst_getBuilding)(general_refst* this);
typedef void (*vm_general_refst_setID)(general_refst* this,int32_t);
typedef int32_t (*vm_general_refst_getID)(general_refst* this);
typedef void (*vm_general_refst_vmeth_36)(general_refst* this);
typedef void* (*vm_general_refst_clone)(general_refst* this);
struct vtable_general_refst {
    vm_general_refst_write_file write_file;
    vm_general_refst_read_file read_file;
    vm_general_refst_getType getType;
    vm_general_refst_getItem getItem;
    vm_general_refst_getUnit getUnit;
    vm_general_refst_getProjectile getProjectile;
    vm_general_refst_getBuilding getBuilding;
    vm_general_refst_setID setID;
    vm_general_refst_getID getID;
    vm_general_refst_vmeth_36 vmeth_36;
    vm_general_refst_clone clone;
};
struct general_refst {
    struct vtable_general_refst *vtable;
};

struct stl_vector_ptr_general_refst {
struct general_refst **ptr;
void *endptr;
void *endalloc;
};
struct job {
    int32_t id;
    struct job_list_link *list_link;
    int32_t job_type;
    struct coord32 pos;
    int32_t completion_timer;
    uint16_t unk4a;
    uint16_t unk4b;
    struct job_flags job_flags;
    int16_t material;
    int16_t matgloss;
    int16_t item_subtype;
    struct item_category item_category;
    struct stl_string ammo_class;
    int16_t job_anon_1;
    struct stl_vector_ptr_job_item_ref items;
    struct stl_vector_ptr_specific_ref specific_refs;
    struct stl_vector_ptr_general_refst general_refs;
};

struct stl_vector_ptr_job {
struct job **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_buildingst {
struct buildingst **ptr;
void *endptr;
void *endalloc;
};
struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct vtable_buildingst {
    vm_buildingst_setJobTimer setJobTimer;
    vm_buildingst_isOnFire isOnFire;
    vm_buildingst_updateFromWeather updateFromWeather;
    vm_buildingst_updateTemperature updateTemperature;
    vm_buildingst_updateItems updateItems;
    vm_buildingst_updateTempFromTile updateTempFromTile;
    vm_buildingst_isColoredByMaterial isColoredByMaterial;
    vm_buildingst_isFarmPlot isFarmPlot;
    vm_buildingst_getWorkshopProfile getWorkshopProfile;
    vm_buildingst_getType getType;
    vm_buildingst_getSubtype getSubtype;
    vm_buildingst_setSubtype setSubtype;
    vm_buildingst_isActual isActual;
    vm_buildingst_getStorageType getStorageType;
    vm_buildingst_isCoffin2 isCoffin2;
    vm_buildingst_updateAction updateAction;
    vm_buildingst_isStatueOrRestraint isStatueOrRestraint;
    vm_buildingst_setMaterialAmount setMaterialAmount;
    vm_buildingst_setBuildStage setBuildStage;
    vm_buildingst_getBuildStage getBuildStage;
    vm_buildingst_getMaxBuildStage getMaxBuildStage;
    vm_buildingst_getArchitectureValue getArchitectureValue;
    vm_buildingst_isSettingOccupancy isSettingOccupancy;
    vm_buildingst_isExtentShaped isExtentShaped;
    vm_buildingst_updateOccupancy updateOccupancy;
    vm_buildingst_getRoomValue getRoomValue;
    vm_buildingst_getPersonalValue getPersonalValue;
    vm_buildingst_canBeRoom canBeRoom;
    vm_buildingst_getConstructionValue getConstructionValue;
    vm_buildingst_queueDestroy queueDestroy;
    vm_buildingst_isImpassableTile isImpassableTile;
    vm_buildingst_getFreeCapacity getFreeCapacity;
    vm_buildingst_canStoreItem canStoreItem;
    vm_buildingst_getName getName;
    vm_buildingst_getNameColor getNameColor;
    vm_buildingst_initSettingsEnable initSettingsEnable;
    vm_buildingst_initSettingsDisable initSettingsDisable;
    vm_buildingst_initBurialFlags initBurialFlags;
    vm_buildingst_clearBurialFlags clearBurialFlags;
    vm_buildingst_clearBurialFlags2 clearBurialFlags2;
    vm_buildingst_getClutterLevel getClutterLevel;
    vm_buildingst_needsDesign needsDesign;
    vm_buildingst_canUseForMood canUseForMood;
    vm_buildingst_canBeRoomSubset canBeRoomSubset;
    vm_buildingst_isCoffin isCoffin;
    vm_buildingst_canUseSpouseRoom canUseSpouseRoom;
    vm_buildingst_canMakeRoom canMakeRoom;
    vm_buildingst_setContainedItems setContainedItems;
    vm_buildingst_isJustice isJustice;
    vm_buildingst_detachUnit detachUnit;
    vm_buildingst_write_file write_file;
    vm_buildingst_read_file read_file;
    vm_buildingst_isBuiltFromSide isBuiltFromSide;
    vm_buildingst_categorize categorize;
    vm_buildingst_uncategorize uncategorize;
    vm_buildingst_getBaseValue getBaseValue;
    vm_buildingst_setMachineState setMachineState;
    vm_buildingst_AdventurerInteract AdventurerInteract;
    vm_buildingst_needsMagma needsMagma;
    vm_buildingst_removeUses removeUses;
    vm_buildingst_deconstructItems deconstructItems;
    vm_buildingst_updatePathfinding updatePathfinding;
    vm_buildingst_takesFireDamage takesFireDamage;
    vm_buildingst_populateSettingsMenu populateSettingsMenu;
    vm_buildingst_populateTaskList populateTaskList;
    vm_buildingst_isForbidden isForbidden;
    vm_buildingst_isVisibleInLookList isVisibleInLookList;
    vm_buildingst_isVisible isVisible;
    vm_buildingst_getDrawExtents getDrawExtents;
    vm_buildingst_drawBuilding drawBuilding;
    vm_buildingst_vmeth_280 vmeth_280;
};
struct buildingst {
    struct vtable_buildingst *vtable;
    int32_t x1;
    int32_t y1;
    int32_t centerx;
    int32_t x2;
    int32_t y2;
    int32_t centery;
    int32_t z;
    struct building_flags building_flags;
    int16_t material;
    int16_t matgloss;
    struct building_extents room;
    int32_t age;
    int16_t race;
    int32_t id;
    struct stl_vector_ptr_job jobs;
    struct stl_vector_ptr_specific_ref specific_refs;
    struct stl_vector_ptr_general_refst general_refs;
    int8_t is_room;
    struct stl_vector_ptr_buildingst children;
    struct stl_vector_ptr_buildingst parents;
    struct unit *building_owner;
    struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
};

struct building_actualst;
typedef bool (*vm_building_actualst_isDestroyedByItemRemoval)(building_actualst* this);
typedef bool (*vm_building_actualst_willScatterContentsOnReclaim)(building_actualst* this);
typedef bool (*vm_building_actualst_willDeconstructOnAbandon)(building_actualst* this);
struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_design;
struct vtable_building_actualst {
    struct vtable_buildingst super;
    vm_building_actualst_isDestroyedByItemRemoval isDestroyedByItemRemoval;
    vm_building_actualst_willScatterContentsOnReclaim willScatterContentsOnReclaim;
    vm_building_actualst_willDeconstructOnAbandon willDeconstructOnAbandon;
};
struct building_actualst {
    struct vtable_building_actualst *vtable;
        int32_t x1;
        int32_t y1;
        int32_t centerx;
        int32_t x2;
        int32_t y2;
        int32_t centery;
        int32_t z;
        struct building_flags building_flags;
        int16_t material;
        int16_t matgloss;
        struct building_extents room;
        int32_t age;
        int16_t race;
        int32_t id;
        struct stl_vector_ptr_job jobs;
        struct stl_vector_ptr_specific_ref specific_refs;
        struct stl_vector_ptr_general_refst general_refs;
        int8_t is_room;
        struct stl_vector_ptr_buildingst children;
        struct stl_vector_ptr_buildingst parents;
        struct unit *building_owner;
        struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
    int16_t construction_stage;
    struct stl_vector_ptr_T_contained_items_919 contained_items;
    struct building_design *design;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_animaltrapst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t bait_type;
    int16_t timer;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_aqueductst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int32_t material_amount;
    int16_t building_aqueductst_dir_flags;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum T_archery_direction_1177 {
    T_archery_direction_1177_TopToBottom,
    T_archery_direction_1177_BottomToTop,
    T_archery_direction_1177_LeftToRight,
    T_archery_direction_1177_RightToLeft
};

struct building_archerytargetst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int8_t archery_direction;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_armorstandst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct stl_vector_int8_t allowed_armor;
    struct stl_vector_int8_t allowed_helms;
    struct stl_vector_int8_t allowed_shoes;
    struct stl_vector_int8_t allowed_gloves;
    struct stl_vector_int8_t allowed_pants;
    struct stl_vector_int8_t allowed_shields;
    int8_t allowed_materials[64];
    int8_t permit_foreign;
    int16_t building_armorstandst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_bedst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_bedst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_boxst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_boxst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum gate_flags_enum {
    gate_flags_closed=0x01,
    gate_flags_closing=0x02,
    gate_flags_opening=0x04,
    gate_flags_collapsing=0x08,
    gate_flags_has_support=0x10
};

struct gate_flags {
    uint16_t bitfield;
};

enum T_direction_1096 {
    T_direction_1096_Retracting = -1,
    T_direction_1096_Left,
    T_direction_1096_Right,
    T_direction_1096_Up,
    T_direction_1096_Down
};

struct building_bridgest {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct gate_flags building_bridgest_gate_flags;
    int8_t timer;
    int8_t direction;
    int32_t material_amount;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_cabinetst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_cabinetst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_cagest {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct stl_vector_int32_t assigned_creature;
    struct stl_vector_int32_t assigned_vermin;
    int16_t building_cagest_anon_1;
    int16_t building_cagest_anon_2;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_chainst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct unit *assigned;
    struct unit *chained;
    int16_t building_chainst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_chairst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_chairst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum T_pond_flags_1120_enum {
    T_pond_flags_1120_kill_self=0x01,
    T_pond_flags_1120_is_pond=0x02,
    T_pond_flags_1120_needs_refill=0x04
};

struct building_channelst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct buildingst *channel_parent;
    struct stl_vector_ptr_buildingst channel_children;
    struct stl_vector_int32_t ponded_fish;
    struct T_pond_flags_1120 {
        uint32_t bitfield;
    } building_channelst_pond_flags;
    double pond_max;
    double pond_cur;
    int32_t material_amount;
    int16_t fill_timer;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct building_civzonest {
        struct vtable_buildingst *vtable;
        int32_t x1;
        int32_t y1;
        int32_t centerx;
        int32_t x2;
        int32_t y2;
        int32_t centery;
        int32_t z;
        struct building_flags buildingst_flags;
        int16_t material;
        int16_t matgloss;
        struct building_extents room;
        int32_t age;
        int16_t race;
        int32_t id;
        struct stl_vector_ptr_job jobs;
        struct stl_vector_ptr_specific_ref specific_refs;
        struct stl_vector_ptr_general_refst general_refs;
        int8_t is_room;
        struct stl_vector_ptr_buildingst children;
        struct stl_vector_ptr_buildingst parents;
        struct unit *buildingst_owner;
        struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
    struct stl_vector_int32_t assigned_creature;
    struct stl_vector_int32_t assigned_items;
    int32_t type;
    int32_t abstract_building_id;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum T_burial_mode_966_enum {
    T_burial_mode_966_allow_burial=0x01,
    T_burial_mode_966_no_citizens=0x02,
    T_burial_mode_966_no_pets=0x04
};

struct building_coffinst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct T_burial_mode_966 {
        uint16_t bitfield;
    } burial_mode;
};

enum T_flags_946_enum {
    T_flags_946_rough=0x01,
    T_flags_946_built=0x02,
    T_flags_946_designed=0x04
};

struct building_design {
    int32_t architect;
    int16_t design_skill;
    int32_t builder1;
    int16_t build_skill;
    int16_t build_timer1;
    int32_t builder2;
    int16_t build_timer2;
    int16_t design_quality;
    int16_t build_quality;
    struct T_flags_946 {
        uint32_t bitfield;
    } building_design_flags;
    int32_t hitpoints;
    int32_t max_hitpoints;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum door_flags_enum {
    door_flags_forbidden=0x01,
    door_flags_internal=0x02,
    door_flags_taken_by_invaders=0x04,
    door_flags_used_by_intruder=0x08,
    door_flags_closed=0x10,
    door_flags_operated_by_mechanisms=0x20,
    door_flags_pet_passable=0x40
};

struct door_flags {
    uint16_t bitfield;
};

struct building_doorst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct door_flags building_doorst_door_flags;
    int16_t close_timer;
};

struct building_drawbuffer {
    uint8_t tile[31][31];
    int8_t fore[31][31];
    int8_t back[31][31];
    int8_t bright[31][31];
    int16_t x1;
    int16_t x2;
    int16_t y1;
    int16_t y2;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_farmplotst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t plant_id[4];
    int32_t material_amount;
    int32_t seasonal_fertilize;
    int8_t fertilize_season;
    int32_t current_fertilization;
    int32_t max_fertilization;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_floodgatest {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct gate_flags building_floodgatest_gate_flags;
    int8_t timer;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct workshop_profile {
    struct stl_vector_int32_t permitted_workers;
    int16_t min_level;
    int16_t max_level;
};

struct building_furnacest {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t melt_remainder[64];
    int16_t building_furnacest_anon_1;
    int32_t type;
    struct workshop_profile profile;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_roadst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int32_t material_amount;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum T_flags_1009_enum {
    T_flags_1009_for_sale=0x01
};

struct building_shopst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct unit *building_shopst_owner;
    int32_t timer;
    struct T_flags_1009 {
        uint16_t bitfield;
    } building_shopst_flags;
    int32_t type;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum T_facing_1136 {
    T_facing_1136_Left,
    T_facing_1136_Up,
    T_facing_1136_Right,
    T_facing_1136_Down
};

enum T_action_1142 {
    T_action_1142_NotInUse,
    T_action_1142_FireAtWill
};

struct building_siegeenginest {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int32_t type;
    int8_t facing;
    int8_t action;
    int8_t fire_timer;
    int16_t reload_timer;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_statuest {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_statuest_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct stockpile_settings_food {
    struct stl_vector_int8_t meat_fish;
    struct stl_vector_int8_t unprepared_fish;
    struct stl_vector_int8_t plants;
    struct stl_vector_int8_t drink_plant;
    struct stl_vector_int8_t drink_animal;
    struct stl_vector_int8_t cheese_plant;
    struct stl_vector_int8_t cheese_animal;
    struct stl_vector_int8_t seeds;
    struct stl_vector_int8_t leaves;
    struct stl_vector_int8_t powder_plant;
    struct stl_vector_int8_t powder_animal;
    struct stl_vector_int8_t glob;
    struct stl_vector_int8_t extract_plant;
    struct stl_vector_int8_t extract_animal;
    struct stl_vector_int8_t liquid_misc;
};

struct stockpile_settings {
    struct item_category item_categories;
    struct T_animals_9982 {
        int8_t empty_cages;
        int8_t empty_traps;
        struct stl_vector_int8_t enabled;
    } animals;
    struct T_food_9988 {
        struct stockpile_settings_food type;
        int8_t prepared_meals;
    } food;
    struct T_furniture_9993 {
        struct stl_vector_int8_t type;
        struct stl_vector_int8_t mats;
        int8_t sand_bags;
    } furniture;
    int32_t stockpile_settings_anon_1;
    struct T_refuse_10001 {
        struct stl_vector_int8_t type;
    } refuse;
    struct T_stone_10005 {
        struct stl_vector_int8_t mats;
    } stone;
    struct T_ore_10009 {
        struct stl_vector_int8_t mats;
    } ore;
    struct T_ammo_10013 {
        struct stl_vector_int8_t type;
        struct stl_vector_int8_t mats;
    } ammo;
    struct T_coins_10018 {
        struct stl_vector_int8_t mats;
    } coins;
    struct T_bars_blocks_10022 {
        struct stl_vector_int8_t bars_mats;
        struct stl_vector_int8_t blocks_mats;
    } bars_blocks;
    struct T_gems_10027 {
        struct stl_vector_int8_t rough_mats;
        struct stl_vector_int8_t cut_mats;
    } gems;
    struct T_finished_goods_10032 {
        struct stl_vector_int8_t type;
        struct stl_vector_int8_t mats;
    } finished_goods;
    struct T_leather_10037 {
        struct stl_vector_int8_t mats;
    } leather;
    struct T_cloth_10041 {
        struct stl_vector_int8_t thread_silk;
        struct stl_vector_int8_t thread_plant;
        struct stl_vector_int8_t cloth_silk;
        struct stl_vector_int8_t cloth_plant;
        int8_t thread_adamantine;
        int8_t cloth_adamantine;
    } cloth;
    struct T_wood_10050 {
        struct stl_vector_int8_t mats;
    } wood;
    struct T_weapons_10054 {
        struct stl_vector_int8_t weapon_type;
        struct stl_vector_int8_t trapcomp_type;
        struct stl_vector_int8_t mats;
        int8_t local;
        int8_t foreign;
    } weapons;
    struct T_armor_10062 {
        struct stl_vector_int8_t body;
        struct stl_vector_int8_t head;
        struct stl_vector_int8_t feet;
        struct stl_vector_int8_t hands;
        struct stl_vector_int8_t legs;
        struct stl_vector_int8_t shield;
        struct stl_vector_int8_t mats;
        int8_t local;
        int8_t foreign;
    } armor;
};

struct stl_vector_ptr_building_stockpilest {
struct building_stockpilest **ptr;
void *endptr;
void *endalloc;
};
struct building_stockpilest {
        struct vtable_buildingst *vtable;
        int32_t x1;
        int32_t y1;
        int32_t centerx;
        int32_t x2;
        int32_t y2;
        int32_t centery;
        int32_t z;
        struct building_flags buildingst_flags;
        int16_t material;
        int16_t matgloss;
        struct building_extents room;
        int32_t age;
        int16_t race;
        int32_t id;
        struct stl_vector_ptr_job jobs;
        struct stl_vector_ptr_specific_ref specific_refs;
        struct stl_vector_ptr_general_refst general_refs;
        int8_t is_room;
        struct stl_vector_ptr_buildingst children;
        struct stl_vector_ptr_buildingst parents;
        struct unit *buildingst_owner;
        struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
    struct stockpile_settings settings;
    struct T_containers_1202 {
        int16_t max_barrels;
        int16_t max_bins;
        struct stl_vector_int16_t container_type;
        struct stl_vector_int32_t container_item_id;
        struct stl_vector_int16_t container_x;
        struct stl_vector_int16_t container_y;
    } containers;
    struct building_stockpilest *give_to;
    struct stl_vector_ptr_building_stockpilest take_from;
    int32_t stockpile_number;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_supportst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_supportst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum T_flags_961_enum {
    T_flags_961_meeting_hall=0x01
};

struct building_tablest {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct T_flags_961 {
        uint16_t bitfield;
    } building_tablest_flags;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_tradedepotst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct itemst;
enum item_type {
    item_type_NONE = -1,
    item_type_BAR,
    item_type_SMALLGEM,
    item_type_BLOCKS,
    item_type_ORE,
    item_type_ROUGH,
    item_type_STONE,
    item_type_WOOD,
    item_type_DOOR,
    item_type_FLOODGATE,
    item_type_BED,
    item_type_CHAIR,
    item_type_CHAIN,
    item_type_FLASK,
    item_type_GOBLET,
    item_type_INSTRUMENT,
    item_type_TOY,
    item_type_WINDOW,
    item_type_CAGE,
    item_type_BARREL,
    item_type_BUCKET,
    item_type_ANIMALTRAP,
    item_type_TABLE,
    item_type_COFFIN,
    item_type_STATUE,
    item_type_CORPSE,
    item_type_WEAPON,
    item_type_ARMOR,
    item_type_SHOES,
    item_type_SHIELD,
    item_type_HELM,
    item_type_GLOVES,
    item_type_BOX,
    item_type_BIN,
    item_type_SAND,
    item_type_ARMORSTAND,
    item_type_WEAPONRACK,
    item_type_CABINET,
    item_type_FIGURINE,
    item_type_AMULET,
    item_type_SCEPTER,
    item_type_AMMO,
    item_type_CROWN,
    item_type_RING,
    item_type_EARRING,
    item_type_BRACELET,
    item_type_GEM,
    item_type_ANVIL,
    item_type_CORPSEPIECE,
    item_type_REMAINS,
    item_type_MEAT,
    item_type_FISH,
    item_type_FISH_RAW,
    item_type_VERMIN,
    item_type_PET,
    item_type_SEEDS,
    item_type_PLANT,
    item_type_SKIN_RAW,
    item_type_SKIN_TANNED,
    item_type_BONES,
    item_type_SHELL,
    item_type_LEAVES,
    item_type_THREAD,
    item_type_CLOTH,
    item_type_TOTEM,
    item_type_SKULL,
    item_type_SHIRT,
    item_type_PANTS,
    item_type_CLOAK,
    item_type_BACKPACK,
    item_type_QUIVER,
    item_type_CATAPULTPARTS,
    item_type_BALLISTAPARTS,
    item_type_SIEGEAMMO,
    item_type_BALLISTAARROWHEAD,
    item_type_TRAPPARTS,
    item_type_TRAPCOMP,
    item_type_EXTRACT,
    item_type_POTION,
    item_type_DRINK,
    item_type_POWDER_ORGANIC,
    item_type_CHEESE,
    item_type_FOOD,
    item_type_LIQUID_MISC,
    item_type_COIN,
    item_type_GLOB,
    item_type_ROCK
};

typedef item_type (*vm_itemst_getType)(itemst* this);
typedef int16_t (*vm_itemst_getSubtype)(itemst* this);
enum material_type {
    material_type_NONE = -1,
    material_type_WOOD,
    material_type_STONE_GRAY,
    material_type_STONE_LIGHT,
    material_type_STONE_DARK,
    material_type_GOLD,
    material_type_IRON,
    material_type_SILVER,
    material_type_COPPER,
    material_type_GEM_ORNAMENTAL,
    material_type_GEM_SEMI,
    material_type_GEM_PRECIOUS,
    material_type_GEM_RARE,
    material_type_BONE,
    material_type_IVORY,
    material_type_JADE,
    material_type_HORN,
    material_type_AMBER,
    material_type_CORAL,
    material_type_PEARL,
    material_type_SHELL,
    material_type_LEATHER,
    material_type_ADAMANTINE,
    material_type_SILK,
    material_type_PLANT,
    material_type_GLASS_GREEN,
    material_type_GLASS_CLEAR,
    material_type_GLASS_CRYSTAL,
    material_type_SAND,
    material_type_WATER,
    material_type_ZINC,
    material_type_TIN,
    material_type_COAL,
    material_type_BRONZE,
    material_type_BRASS,
    material_type_STEEL,
    material_type_PIGIRON,
    material_type_PLATINUM,
    material_type_ELECTRUM,
    material_type_POTASH,
    material_type_ASH,
    material_type_PEARLASH,
    material_type_LYE,
    material_type_RENDERED_FAT,
    material_type_SOAP_ANIMAL,
    material_type_FAT,
    material_type_MUD,
    material_type_VOMIT,
    material_type_BLOOD,
    material_type_SLIME
};

typedef material_type (*vm_itemst_getMaterial)(itemst* this);
typedef int16_t (*vm_itemst_getMatgloss)(itemst* this);
typedef void (*vm_itemst_setSubtype)(itemst* this,int16_t);
typedef void (*vm_itemst_setMaterial)(itemst* this,material_type material);
typedef void (*vm_itemst_setMatgloss)(itemst* this,int16_t);
typedef material_type (*vm_itemst_getActualMaterial)(itemst* this);
typedef int16_t (*vm_itemst_getActualMatgloss)(itemst* this);
typedef int16_t (*vm_itemst_getRace)(itemst* this);
typedef void (*vm_itemst_clearLastTempUpdateTS)(itemst* this);
typedef uint16_t (*vm_itemst_getSpecHeat)(itemst* this);
typedef uint16_t (*vm_itemst_getIgnitePoint)(itemst* this);
typedef uint16_t (*vm_itemst_getHeatdamPoint)(itemst* this);
typedef uint16_t (*vm_itemst_getColddamPoint)(itemst* this);
typedef uint16_t (*vm_itemst_getBoilingPoint)(itemst* this);
typedef uint16_t (*vm_itemst_getMeltingPoint)(itemst* this);
typedef uint16_t (*vm_itemst_getFixedTemp)(itemst* this);
typedef uint16_t (*vm_itemst_getTemperature)(itemst* this);
typedef bool (*vm_itemst_adjustTemperature)(itemst* this,uint16_t target);
typedef void (*vm_itemst_extinguish)(itemst* this);
typedef int8_t (*vm_itemst_getGloveHandedness)(itemst* this);
typedef void (*vm_itemst_setGloveHandedness)(itemst* this,int8_t);
typedef void (*vm_itemst_pickRandomSubtype)(itemst* this,int32_t entity_id);
typedef int32_t (*vm_itemst_getWeaponSize)(itemst* this);
typedef int16_t (*vm_itemst_getWear)(itemst* this);
typedef void (*vm_itemst_setWear)(itemst* this,int16_t);
typedef int32_t (*vm_itemst_getMaker)(itemst* this);
typedef void (*vm_itemst_setMaker)(itemst* this,int32_t unit_id);
typedef int16_t (*vm_itemst_getCorpseRace)(itemst* this);
typedef void (*vm_itemst_getCorpseInfo)(itemst* this,void* race,void* histfig,void* unit);
typedef void* (*vm_itemst_getGloveFlags)(itemst* this);
typedef void (*vm_itemst_setSeedsPlantSkill)(itemst* this,int32_t level);
typedef void (*vm_itemst_ageItem)(itemst* this,int32_t amount);
typedef int32_t (*vm_itemst_getCritterAirdrownTimer)(itemst* this);
typedef void (*vm_itemst_setCritterAirdrownTimer)(itemst* this,int32_t);
typedef void (*vm_itemst_incrementCritterAirdrownTimer)(itemst* this);
typedef int32_t (*vm_itemst_getRotTimer)(itemst* this);
typedef void (*vm_itemst_setRotTimer)(itemst* this,int32_t val);
typedef void (*vm_itemst_incrementRotTimer)(itemst* this);
typedef void* (*vm_itemst_getAmmoType)(itemst* this,void*);
typedef int16_t (*vm_itemst_getDamageType)(itemst* this);
typedef bool (*vm_itemst_isLiquipowder)(itemst* this);
typedef bool (*vm_itemst_isLiquid)(itemst* this);
typedef bool (*vm_itemst_isCritter1)(itemst* this);
typedef int16_t (*vm_itemst_getStickChance)(itemst* this);
typedef void (*vm_itemst_addImprovementFromJob)(itemst* this,void* job,void* unit,int32_t material,int32_t matgloss,void* entity,void* site);
typedef bool (*vm_itemst_isWeapon)(itemst* this);
typedef bool (*vm_itemst_isArmorNotClothing)(itemst* this);
typedef bool (*vm_itemst_canStoreInWeaponRack)(itemst* this);
typedef bool (*vm_itemst_canStoreInArmorStand)(itemst* this);
typedef bool (*vm_itemst_isMillable)(itemst* this);
typedef bool (*vm_itemst_isProcessableThread)(itemst* this);
typedef bool (*vm_itemst_isProcessableVial)(itemst* this);
typedef bool (*vm_itemst_isProcessableBag)(itemst* this);
typedef bool (*vm_itemst_isProcessableBarrel)(itemst* this);
typedef bool (*vm_itemst_isEdible)(itemst* this);
typedef bool (*vm_itemst_isEdibleRaw)(itemst* this);
typedef bool (*vm_itemst_isEdibleCarnivore)(itemst* this);
typedef bool (*vm_itemst_isEdibleBonecarn)(itemst* this);
typedef bool (*vm_itemst_moveToGround)(itemst* this,int32_t x,int32_t y,int32_t z);
typedef bool (*vm_itemst_isFat)(itemst* this);
typedef bool (*vm_itemst_isAnimal)(itemst* this);
typedef void (*vm_itemst_assignQuality)(itemst* this,void* maker,void* job);
typedef void (*vm_itemst_notifyLostMasterwork)(itemst* this);
typedef void (*vm_itemst_addMagic)(itemst* this,int32_t type,int32_t data,int32_t value);
typedef void (*vm_itemst_magic_unk1)(itemst* this,int32_t,int32_t);
typedef void (*vm_itemst_magic_unk2)(itemst* this,int32_t,int32_t);
typedef void (*vm_itemst_magic_unk3)(itemst* this,int32_t);
typedef void (*vm_itemst_magic_unk4)(itemst* this,int32_t,int32_t,int32_t);
typedef void (*vm_itemst_setDisplayColor)(itemst* this,int16_t bgcolor);
typedef bool (*vm_itemst_isDamagedByHeat)(itemst* this);
typedef bool (*vm_itemst_needTwoHandedWield)(itemst* this,int32_t size);
typedef void* (*vm_itemst_splitStack)(itemst* this,int32_t stack_size,bool preserve_containment);
typedef bool (*vm_itemst_isTameableVermin)(itemst* this);
typedef bool (*vm_itemst_isDistillable)(itemst* this,bool checkKitchenSettings);
typedef bool (*vm_itemst_isDye)(itemst* this);
typedef bool (*vm_itemst_isMilkable)(itemst* this,bool check_contents,bool check_kitchen);
typedef bool (*vm_itemst_isSandBearing)(itemst* this);
typedef bool (*vm_itemst_isLyeBearing)(itemst* this);
typedef bool (*vm_itemst_isAnimalProduct)(itemst* this);
typedef void (*vm_itemst_getStorageInfo)(itemst* this,void* item_type,void* material_category);
typedef bool (*vm_itemst_addWear)(itemst* this,int32_t delta,bool lose_masterwork,bool do_rot);
typedef void (*vm_itemst_addContaminant)(itemst* this,int32_t type,material_type material,int32_t size);
typedef void (*vm_itemst_removeContaminantByIdx)(itemst* this,int32_t index,int32_t amount);
typedef void (*vm_itemst_removeContaminantByType)(itemst* this,int32_t type,material_type material,int32_t amount);
typedef int32_t (*vm_itemst_getClothingCategory)(itemst* this);
typedef void (*vm_itemst_write_file)(itemst* this,void*);
typedef void (*vm_itemst_read_file)(itemst* this,void*,int32_t loadversion);
typedef bool (*vm_itemst_isOnGround)(itemst* this);
typedef bool (*vm_itemst_isSplittable)(itemst* this);
typedef void (*vm_itemst_addRandomDye)(itemst* this);
typedef void (*vm_itemst_addImprovementFromClothOrDye)(itemst* this,void*);
typedef void (*vm_itemst_propagateUnitRefs)(itemst* this);
typedef bool (*vm_itemst_isBag)(itemst* this);
typedef int32_t (*vm_itemst_getStackSize)(itemst* this);
typedef void (*vm_itemst_addStackSize)(itemst* this,int32_t amount);
typedef void (*vm_itemst_setStackSize)(itemst* this,int32_t amount);
typedef bool (*vm_itemst_isAmmoClass)(itemst* this,void*);
typedef bool (*vm_itemst_setTemperatureFromMap)(itemst* this,bool local,bool contained);
typedef bool (*vm_itemst_setTemperature)(itemst* this,uint16_t temp,bool local,bool contained);
typedef bool (*vm_itemst_updateTemperatureFromMap)(itemst* this,bool local,bool contained,bool adjust);
typedef bool (*vm_itemst_updateTemperature)(itemst* this,uint16_t temp,bool local,bool contained,bool adjust);
typedef bool (*vm_itemst_updateFromWeather)(itemst* this);
typedef bool (*vm_itemst_updateContaminants)(itemst* this);
typedef bool (*vm_itemst_checkTemperatureDamage)(itemst* this);
typedef bool (*vm_itemst_checkHeatColdDamage)(itemst* this);
typedef bool (*vm_itemst_checkMeltBoil)(itemst* this);
typedef int32_t (*vm_itemst_getMeleeSkill)(itemst* this);
typedef int32_t (*vm_itemst_getRangedSkill)(itemst* this);
typedef void (*vm_itemst_setQuality)(itemst* this,int16_t quality);
typedef int16_t (*vm_itemst_getQuality)(itemst* this);
typedef int16_t (*vm_itemst_getOverallQuality)(itemst* this);
typedef int16_t (*vm_itemst_getDamage)(itemst* this);
typedef bool (*vm_itemst_isImprovable)(itemst* this,void*,int32_t material,int32_t matgloss);
typedef bool (*vm_itemst_isDyeable)(itemst* this);
typedef bool (*vm_itemst_isNotDyed)(itemst* this);
typedef bool (*vm_itemst_isDyed)(itemst* this);
typedef bool (*vm_itemst_canSewImage)(itemst* this);
typedef bool (*vm_itemst_canAddSewnImage)(itemst* this);
typedef bool (*vm_itemst_isProcessableVialAtStill)(itemst* this);
typedef bool (*vm_itemst_isSimilarToItem)(itemst* this,item_type item_type,int16_t item_subtype,material_type material,int16_t matgloss);
typedef int32_t (*vm_itemst_getBlockChance)(itemst* this);
typedef int32_t (*vm_itemst_getParryChance)(itemst* this);
typedef int16_t (*vm_itemst_getMakerRace)(itemst* this);
typedef void (*vm_itemst_setMakerRace)(itemst* this,int16_t);
typedef int8_t (*vm_itemst_getEffectiveArmorLevel)(itemst* this);
typedef bool (*vm_itemst_isConstructed)(itemst* this);
typedef bool (*vm_itemst_canBeDyed)(itemst* this);
typedef bool (*vm_itemst_isDyeableCloth)(itemst* this);
typedef int32_t (*vm_itemst_getCritBoost)(itemst* this);
typedef void (*vm_itemst_coverWithContaminant)(itemst* this,material_type material);
typedef bool (*vm_itemst_hasImprovements)(itemst* this);
typedef bool (*vm_itemst_isImproved)(itemst* this);
typedef void* (*vm_itemst_getMagic)(itemst* this);
typedef void (*vm_itemst_getItemDescription)(itemst* this,void* str,int8_t mode);
typedef void (*vm_itemst_getItemDescriptionPrefix)(itemst* this,void* str,int8_t mode);
typedef int32_t (*vm_itemst_getImprovementsValue)(itemst* this,void* caravan);
typedef bool (*vm_itemst_isExtractBearingFish)(itemst* this);
typedef bool (*vm_itemst_isExtractBearingVermin)(itemst* this);
typedef int32_t (*vm_itemst_getBaseWeight)(itemst* this);
typedef int32_t (*vm_itemst_getWeightShiftBits)(itemst* this);
typedef bool (*vm_itemst_isCollected)(itemst* this);
typedef int32_t (*vm_itemst_getVolume)(itemst* this);
typedef bool (*vm_itemst_isEdibleVermin)(itemst* this);
typedef int8_t (*vm_itemst_getTile)(itemst* this);
typedef bool (*vm_itemst_isRangedWeapon)(itemst* this);
typedef bool (*vm_itemst_isClothing)(itemst* this);
typedef bool (*vm_itemst_isWet)(itemst* this);
typedef int32_t (*vm_itemst_getCurrencyValue)(itemst* this,void* entity);
typedef bool (*vm_itemst_isAssignedToAnyStockpile)(itemst* this);
typedef bool (*vm_itemst_isAssignedToThisStockpile)(itemst* this,int32_t building);
typedef void (*vm_itemst_removeFromStockpile)(itemst* this);
typedef void (*vm_itemst_clearStockpileAssignment)(itemst* this);
typedef void* (*vm_itemst_getStockpile)(itemst* this);
typedef void (*vm_itemst_addDye)(itemst* this,int16_t material,int16_t matgloss,void* unit,void* job);
typedef void (*vm_itemst_addImage)(itemst* this,int32_t art_chunk_id,int32_t art_subid,int16_t material,int16_t matgloss,int16_t dye_material,int16_t dye_matgloss,void* src_item,int32_t quality,int16_t skill_level,int32_t maker_hfid);
typedef void (*vm_itemst_addImprovementsFromItem)(itemst* this,void* item);
typedef int32_t (*vm_itemst_getThreadDyeValue)(itemst* this,void* caravan);
typedef void (*vm_itemst_getColorAndShape)(itemst* this,void* colors,void* shapes);
typedef bool (*vm_itemst_isCritter2)(itemst* this);
typedef bool (*vm_itemst_isArmorOrClothing)(itemst* this);
typedef void (*vm_itemst_vmeth_648)(itemst* this);
struct vtable_itemst {
    vm_itemst_getType getType;
    vm_itemst_getSubtype getSubtype;
    vm_itemst_getMaterial getMaterial;
    vm_itemst_getMatgloss getMatgloss;
    vm_itemst_setSubtype setSubtype;
    vm_itemst_setMaterial setMaterial;
    vm_itemst_setMatgloss setMatgloss;
    vm_itemst_getActualMaterial getActualMaterial;
    vm_itemst_getActualMatgloss getActualMatgloss;
    vm_itemst_getRace getRace;
    vm_itemst_clearLastTempUpdateTS clearLastTempUpdateTS;
    vm_itemst_getSpecHeat getSpecHeat;
    vm_itemst_getIgnitePoint getIgnitePoint;
    vm_itemst_getHeatdamPoint getHeatdamPoint;
    vm_itemst_getColddamPoint getColddamPoint;
    vm_itemst_getBoilingPoint getBoilingPoint;
    vm_itemst_getMeltingPoint getMeltingPoint;
    vm_itemst_getFixedTemp getFixedTemp;
    vm_itemst_getTemperature getTemperature;
    vm_itemst_adjustTemperature adjustTemperature;
    vm_itemst_extinguish extinguish;
    vm_itemst_getGloveHandedness getGloveHandedness;
    vm_itemst_setGloveHandedness setGloveHandedness;
    vm_itemst_pickRandomSubtype pickRandomSubtype;
    vm_itemst_getWeaponSize getWeaponSize;
    vm_itemst_getWear getWear;
    vm_itemst_setWear setWear;
    vm_itemst_getMaker getMaker;
    vm_itemst_setMaker setMaker;
    vm_itemst_getCorpseRace getCorpseRace;
    vm_itemst_getCorpseInfo getCorpseInfo;
    vm_itemst_getGloveFlags getGloveFlags;
    vm_itemst_setSeedsPlantSkill setSeedsPlantSkill;
    vm_itemst_ageItem ageItem;
    vm_itemst_getCritterAirdrownTimer getCritterAirdrownTimer;
    vm_itemst_setCritterAirdrownTimer setCritterAirdrownTimer;
    vm_itemst_incrementCritterAirdrownTimer incrementCritterAirdrownTimer;
    vm_itemst_getRotTimer getRotTimer;
    vm_itemst_setRotTimer setRotTimer;
    vm_itemst_incrementRotTimer incrementRotTimer;
    vm_itemst_getAmmoType getAmmoType;
    vm_itemst_getDamageType getDamageType;
    vm_itemst_isLiquipowder isLiquipowder;
    vm_itemst_isLiquid isLiquid;
    vm_itemst_isCritter1 isCritter1;
    vm_itemst_getStickChance getStickChance;
    vm_itemst_addImprovementFromJob addImprovementFromJob;
    vm_itemst_isWeapon isWeapon;
    vm_itemst_isArmorNotClothing isArmorNotClothing;
    vm_itemst_canStoreInWeaponRack canStoreInWeaponRack;
    vm_itemst_canStoreInArmorStand canStoreInArmorStand;
    vm_itemst_isMillable isMillable;
    vm_itemst_isProcessableThread isProcessableThread;
    vm_itemst_isProcessableVial isProcessableVial;
    vm_itemst_isProcessableBag isProcessableBag;
    vm_itemst_isProcessableBarrel isProcessableBarrel;
    vm_itemst_isEdible isEdible;
    vm_itemst_isEdibleRaw isEdibleRaw;
    vm_itemst_isEdibleCarnivore isEdibleCarnivore;
    vm_itemst_isEdibleBonecarn isEdibleBonecarn;
    vm_itemst_moveToGround moveToGround;
    vm_itemst_isFat isFat;
    vm_itemst_isAnimal isAnimal;
    vm_itemst_assignQuality assignQuality;
    vm_itemst_notifyLostMasterwork notifyLostMasterwork;
    vm_itemst_addMagic addMagic;
    vm_itemst_magic_unk1 magic_unk1;
    vm_itemst_magic_unk2 magic_unk2;
    vm_itemst_magic_unk3 magic_unk3;
    vm_itemst_magic_unk4 magic_unk4;
    vm_itemst_setDisplayColor setDisplayColor;
    vm_itemst_isDamagedByHeat isDamagedByHeat;
    vm_itemst_needTwoHandedWield needTwoHandedWield;
    vm_itemst_splitStack splitStack;
    vm_itemst_isTameableVermin isTameableVermin;
    vm_itemst_isDistillable isDistillable;
    vm_itemst_isDye isDye;
    vm_itemst_isMilkable isMilkable;
    vm_itemst_isSandBearing isSandBearing;
    vm_itemst_isLyeBearing isLyeBearing;
    vm_itemst_isAnimalProduct isAnimalProduct;
    vm_itemst_getStorageInfo getStorageInfo;
    vm_itemst_addWear addWear;
    vm_itemst_addContaminant addContaminant;
    vm_itemst_removeContaminantByIdx removeContaminantByIdx;
    vm_itemst_removeContaminantByType removeContaminantByType;
    vm_itemst_getClothingCategory getClothingCategory;
    vm_itemst_write_file write_file;
    vm_itemst_read_file read_file;
    vm_itemst_isOnGround isOnGround;
    vm_itemst_isSplittable isSplittable;
    vm_itemst_addRandomDye addRandomDye;
    vm_itemst_addImprovementFromClothOrDye addImprovementFromClothOrDye;
    vm_itemst_propagateUnitRefs propagateUnitRefs;
    vm_itemst_isBag isBag;
    vm_itemst_getStackSize getStackSize;
    vm_itemst_addStackSize addStackSize;
    vm_itemst_setStackSize setStackSize;
    vm_itemst_isAmmoClass isAmmoClass;
    vm_itemst_setTemperatureFromMap setTemperatureFromMap;
    vm_itemst_setTemperature setTemperature;
    vm_itemst_updateTemperatureFromMap updateTemperatureFromMap;
    vm_itemst_updateTemperature updateTemperature;
    vm_itemst_updateFromWeather updateFromWeather;
    vm_itemst_updateContaminants updateContaminants;
    vm_itemst_checkTemperatureDamage checkTemperatureDamage;
    vm_itemst_checkHeatColdDamage checkHeatColdDamage;
    vm_itemst_checkMeltBoil checkMeltBoil;
    vm_itemst_getMeleeSkill getMeleeSkill;
    vm_itemst_getRangedSkill getRangedSkill;
    vm_itemst_setQuality setQuality;
    vm_itemst_getQuality getQuality;
    vm_itemst_getOverallQuality getOverallQuality;
    vm_itemst_getDamage getDamage;
    vm_itemst_isImprovable isImprovable;
    vm_itemst_isDyeable isDyeable;
    vm_itemst_isNotDyed isNotDyed;
    vm_itemst_isDyed isDyed;
    vm_itemst_canSewImage canSewImage;
    vm_itemst_canAddSewnImage canAddSewnImage;
    vm_itemst_isProcessableVialAtStill isProcessableVialAtStill;
    vm_itemst_isSimilarToItem isSimilarToItem;
    vm_itemst_getBlockChance getBlockChance;
    vm_itemst_getParryChance getParryChance;
    vm_itemst_getMakerRace getMakerRace;
    vm_itemst_setMakerRace setMakerRace;
    vm_itemst_getEffectiveArmorLevel getEffectiveArmorLevel;
    vm_itemst_isConstructed isConstructed;
    vm_itemst_canBeDyed canBeDyed;
    vm_itemst_isDyeableCloth isDyeableCloth;
    vm_itemst_getCritBoost getCritBoost;
    vm_itemst_coverWithContaminant coverWithContaminant;
    vm_itemst_hasImprovements hasImprovements;
    vm_itemst_isImproved isImproved;
    vm_itemst_getMagic getMagic;
    vm_itemst_getItemDescription getItemDescription;
    vm_itemst_getItemDescriptionPrefix getItemDescriptionPrefix;
    vm_itemst_getImprovementsValue getImprovementsValue;
    vm_itemst_isExtractBearingFish isExtractBearingFish;
    vm_itemst_isExtractBearingVermin isExtractBearingVermin;
    vm_itemst_getBaseWeight getBaseWeight;
    vm_itemst_getWeightShiftBits getWeightShiftBits;
    vm_itemst_isCollected isCollected;
    vm_itemst_getVolume getVolume;
    vm_itemst_isEdibleVermin isEdibleVermin;
    vm_itemst_getTile getTile;
    vm_itemst_isRangedWeapon isRangedWeapon;
    vm_itemst_isClothing isClothing;
    vm_itemst_isWet isWet;
    vm_itemst_getCurrencyValue getCurrencyValue;
    vm_itemst_isAssignedToAnyStockpile isAssignedToAnyStockpile;
    vm_itemst_isAssignedToThisStockpile isAssignedToThisStockpile;
    vm_itemst_removeFromStockpile removeFromStockpile;
    vm_itemst_clearStockpileAssignment clearStockpileAssignment;
    vm_itemst_getStockpile getStockpile;
    vm_itemst_addDye addDye;
    vm_itemst_addImage addImage;
    vm_itemst_addImprovementsFromItem addImprovementsFromItem;
    vm_itemst_getThreadDyeValue getThreadDyeValue;
    vm_itemst_getColorAndShape getColorAndShape;
    vm_itemst_isCritter2 isCritter2;
    vm_itemst_isArmorOrClothing isArmorOrClothing;
    vm_itemst_vmeth_648 vmeth_648;
};
struct itemst {
    struct vtable_itemst *vtable;
    struct coord32 pos;
    struct item_flags itemst_flags;
    uint32_t age;
    int32_t id;
    struct stl_vector_ptr_specific_ref specific_refs;
    struct stl_vector_ptr_general_refst general_refs;
};

struct stl_vector_ptr_itemst {
struct itemst **ptr;
void *endptr;
void *endalloc;
};
struct building_trapst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int32_t trap_type;
    int8_t state;
    int16_t building_trapst_anon_1;
    int16_t building_trapst_anon_2;
    struct stl_vector_ptr_itemst linked_mechanisms;
    struct stl_vector_int32_t observed_by_civs;
    struct workshop_profile profile;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_wagonst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_weaponrackst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    struct stl_vector_int8_t allowed_weapons;
    struct stl_vector_int8_t allowed_siegeammo;
    int8_t allowed_materials[64];
    int8_t permit_foreign_weapons;
    int8_t permit_foreign_siegeammo;
    int8_t permit_trapcomps;
    int16_t building_weaponrackst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_weaponst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_weaponst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
enum T_dir_flags_1086_enum {
    T_dir_flags_1086_north=0x01,
    T_dir_flags_1086_south=0x02,
    T_dir_flags_1086_east=0x04,
    T_dir_flags_1086_west=0x08
};

struct building_wellst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_wellst_anon_1;
    struct T_dir_flags_1086 {
        uint8_t bitfield;
    } building_wellst_dir_flags;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_windowst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int16_t building_windowst_anon_1;
};

struct T_job_claim_suppress_766 {
    struct unit *unit;
    int32_t timer;
} ;
struct stl_vector_ptr_T_job_claim_suppress_766 {
struct T_job_claim_suppress_766 **ptr;
void *endptr;
void *endalloc;
};
struct T_contained_items_919 {
    struct itemst *item;
    int16_t use_mode;
} ;
struct stl_vector_ptr_T_contained_items_919 {
struct T_contained_items_919 **ptr;
void *endptr;
void *endalloc;
};
struct building_workshopst {
        struct vtable_building_actualst *vtable;
            int32_t x1;
            int32_t y1;
            int32_t centerx;
            int32_t x2;
            int32_t y2;
            int32_t centery;
            int32_t z;
            struct building_flags buildingst_flags;
            int16_t material;
            int16_t matgloss;
            struct building_extents room;
            int32_t age;
            int16_t race;
            int32_t id;
            struct stl_vector_ptr_job jobs;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
            int8_t is_room;
            struct stl_vector_ptr_buildingst children;
            struct stl_vector_ptr_buildingst parents;
            struct unit *buildingst_owner;
            struct stl_vector_ptr_T_job_claim_suppress_766 job_claim_suppress;
        int16_t construction_stage;
        struct stl_vector_ptr_T_contained_items_919 contained_items;
        struct building_design *design;
    int32_t type;
    struct workshop_profile profile;
};

enum buildings_other_id {
    buildings_other_id_ANY = -1,
    buildings_other_id_IN_PLAY,
    buildings_other_id_STOCKPILE,
    buildings_other_id_CIVZONE,
    buildings_other_id_ANY_ACTUAL,
    buildings_other_id_TRAP,
    buildings_other_id_DOOR,
    buildings_other_id_FLOODGATE,
    buildings_other_id_WINDOW,
    buildings_other_id_WELL,
    buildings_other_id_TABLE,
    buildings_other_id_BRIDGE,
    buildings_other_id_AQUEDUCT,
    buildings_other_id_ANY_CIVILIAN_STORAGE,
    buildings_other_id_ANY_NOBLE_STORAGE,
    buildings_other_id_ANY_BARRACKS,
    buildings_other_id_ANY_NOBLE_ROOM,
    buildings_other_id_CHAIR,
    buildings_other_id_TRADE_DEPOT,
    buildings_other_id_WAGON,
    buildings_other_id_SHOP,
    buildings_other_id_BED,
    buildings_other_id_ROAD,
    buildings_other_id_CHANNEL,
    buildings_other_id_FARM_PLOT,
    buildings_other_id_SUPPORT,
    buildings_other_id_ARCHERY_TARGET,
    buildings_other_id_CHAIN,
    buildings_other_id_CAGE,
    buildings_other_id_STATUE,
    buildings_other_id_COFFIN,
    buildings_other_id_WEAPON_RACK,
    buildings_other_id_ARMOR_STAND,
    buildings_other_id_FURNACE_ANY,
    buildings_other_id_FURNACE_WOOD,
    buildings_other_id_FURNACE_SMELTER_ANY,
    buildings_other_id_FURNACE_SMELTER_MAGMA,
    buildings_other_id_FURNACE_KILN_ANY,
    buildings_other_id_FURNACE_GLASS_ANY,
    buildings_other_id_WORKSHOP_ANY,
    buildings_other_id_WORKSHOP_BUTCHER,
    buildings_other_id_WORKSHOP_MASON,
    buildings_other_id_WORKSHOP_KENNEL,
    buildings_other_id_WORKSHOP_FISHERY,
    buildings_other_id_WORKSHOP_JEWELER,
    buildings_other_id_WORKSHOP_LOOM,
    buildings_other_id_WORKSHOP_TANNER,
    buildings_other_id_WORKSHOP_DYER,
    buildings_other_id_WORKSHOP_MILL,
    buildings_other_id_WORKSHOP_KITCHEN,
    buildings_other_id_WORKSHOP_STILL,
    buildings_other_id_WORKSHOP_FARMER,
    buildings_other_id_WORKSHOP_ASHERY,
    buildings_other_id_WORKSHOP_ALCHEMIST,
    buildings_other_id_WORKSHOP_CARPENTER,
    buildings_other_id_WORKSHOP_CRAFTSDWARF,
    buildings_other_id_WORKSHOP_MECHANIC,
    buildings_other_id_WORKSHOP_SIEGE,
    buildings_other_id_WORKSHOP_CLOTHES,
    buildings_other_id_WORKSHOP_LEATHER,
    buildings_other_id_WORKSHOP_BOWYER,
    buildings_other_id_WORKSHOP_FORGE_MAGMA,
    buildings_other_id_WORKSHOP_FORGE_ANY,
    buildings_other_id_WEAPON_UPRIGHT
};

struct campfire {
    struct coord32 pos;
    int32_t timer;
};

struct entity_activity_statistics {
    struct T_food_1773 {
        int32_t total;
        int32_t meat;
        int32_t fish;
        int32_t other;
        int32_t seeds;
        int32_t plant;
        int32_t drink;
    } food;
    int16_t unit_counts[88];
    int16_t population;
    int16_t omnivores;
    int16_t carnivores;
    int16_t trained_animals;
    int16_t other_animals;
    int16_t potential_soldiers;
    int32_t combat_aptitude;
    int32_t item_counts[110];
    struct stl_vector_int32_t created_weapons;
    struct T_wealth_1792 {
        int32_t total;
        int32_t weapons;
        int32_t armor;
        int32_t furniture;
        int32_t other;
        int32_t architecture;
        int32_t displayed;
        int32_t road;
        int32_t held;
        int32_t imported;
        int32_t unused;
        int32_t exported;
    } wealth;
    struct T_recent_jobs_1807 {
        int32_t by_material[64];
        int32_t no_material;
        int32_t total;
    } recent_jobs[202];
    int32_t revealed_tiles;
    int32_t death_history[5];
    int32_t insanity_history[5];
    int32_t execution_history[5];
    int32_t noble_death_history[5];
    int32_t total_deaths;
    int32_t total_insanities;
    int32_t total_executions;
    int32_t num_artifacts;
    int32_t total_siegers;
    int8_t found_gold;
    int8_t found_coal;
    int8_t found_copper;
    int8_t found_silver;
    int8_t found_tin;
    int8_t found_zinc;
    int8_t found_iron;
    int8_t found_platinum;
    int8_t found_adamantine;
    int8_t found_caveriver;
    int8_t found_chasm;
    int8_t found_magma;
    struct stl_vector_int8_t discovered_creature_foods;
    struct stl_vector_int8_t discovered_creatures;
    struct stl_vector_int8_t discovered_plant_foods;
    struct stl_vector_int8_t discovered_plants;
    struct stl_vector_int8_t discovered_trees;
};

enum T_flags_1851_enum {
    T_flags_1851_check_cleanup=0x01,
    T_flags_1851_casualty=0x02,
    T_flags_1851_hardship=0x04,
    T_flags_1851_communicate=0x08,
    T_flags_1851_seized=0x10,
    T_flags_1851_offended=0x20,
    T_flags_1851_announce=0x40
};

struct entity_sell_prices;
struct entity_buy_prices;
struct caravan_state {
    int32_t total_capacity;
    int8_t trade_state;
    int8_t depot_notified;
    int16_t time_remaining;
    int32_t entity;
    struct entity_activity_statistics activity_stats;
    struct T_flags_1851 {
        uint32_t bitfield;
    } caravan_state_flags;
    int32_t import_value;
    int32_t export_value_total;
    int32_t export_value_personal;
    int32_t offer_value;
    struct stl_vector_int32_t units;
    struct entity_sell_prices *sell_prices;
    struct entity_buy_prices *buy_prices;
};

struct coord {
    int16_t x;
    int16_t y;
    int16_t z;
};

struct cavein_region {
    struct coord pos;
    int16_t timer;
};

enum civzone_type {
    civzone_type_Home,
    civzone_type_CraftShop,
    civzone_type_Basement,
    civzone_type_WeaponsmithsShop,
    civzone_type_ArmorsmithsShop,
    civzone_type_GeneralStore,
    civzone_type_FoodShop,
    civzone_type_MeadHall,
    civzone_type_ThroneRoom
};

struct coin_batch {
    int32_t year;
    int16_t material;
    int32_t entity;
    int32_t ruler;
    struct art_image_ref image_front;
    struct art_image_ref image_back;
};

struct contaminant {
    int32_t type;
    union {
        int16_t creature_id;
        int32_t material;
    };
    int32_t amount;
};

enum T_state_35 {
    T_state_35_started,
    T_state_35_active,
    T_state_35_finished,
    T_state_35_quit
};

struct T_speech_47 {
    struct stl_vector_strptr text;
    int32_t speaker;
    int16_t fg;
    int16_t bg;
    int16_t bright;
} ;
struct stl_vector_ptr_T_speech_47 {
struct T_speech_47 **ptr;
void *endptr;
void *endalloc;
};
struct conversation {
    struct stl_string conv_title;
    int32_t state;
    struct stl_vector_int16_t talk_choices;
    int32_t other;
    int32_t self;
    int32_t target;
    struct stl_vector_ptr_T_speech_47 speech;
};

struct coord2d {
    int16_t x;
    int16_t y;
};

struct coord2d32_path {
    struct stl_vector_int32_t x;
    struct stl_vector_int32_t y;
};

struct coord2d_path {
    struct stl_vector_int16_t x;
    struct stl_vector_int16_t y;
};

struct coord32_path {
    struct stl_vector_int32_t x;
    struct stl_vector_int32_t y;
    struct stl_vector_int32_t z;
};

struct coord_path {
    struct stl_vector_int16_t x;
    struct stl_vector_int16_t y;
    struct stl_vector_int16_t z;
};

enum creature_graphics_role {
    creature_graphics_role_DEFAULT,
    creature_graphics_role_GUARD,
    creature_graphics_role_ROYALGUARD,
    creature_graphics_role_CASTLEGUARD,
    creature_graphics_role_ZOMBIE,
    creature_graphics_role_SKELETON,
    creature_graphics_role_ADVENTURER
};

struct creature_raw {
    struct stl_string creature_id;
    struct stl_string name[3];
    struct stl_string remains[2];
    struct stl_string extract_name;
    struct stl_string extract_cheese_name;
    struct stl_string extract_antidote_name;
    struct stl_string vermin_bite_txt;
    struct stl_string gnawer;
    struct stl_string babyname[2];
    struct stl_string childname[2];
    struct stl_string craftsman_name[2];
    struct stl_string fisherman_name[2];
    struct stl_string hammerman_name[2];
    struct stl_string spearman_name[2];
    struct stl_string crossbowman_name[2];
    struct stl_string axeman_name[2];
    struct stl_string swordsman_name[2];
    struct stl_string maceman_name[2];
    struct stl_string pikeman_name[2];
    struct stl_string bowman_name[2];
    struct stl_string specname_male[3];
    struct stl_string specname_female[3];
    uint8_t tile;
    uint8_t alttile;
    int8_t bloodtype;
    uint8_t glowtile;
    struct T_anon_1_1550 {
        uint16_t spec_heat;
        uint16_t heatdam_point;
        uint16_t colddam_point;
        uint16_t ignite_point;
        uint16_t melting_point;
        uint16_t boiling_point;
        uint16_t fixed_temp;
    } creature_raw_anon_1[7];
    uint16_t homeotherm;
    uint16_t min_temp;
    uint16_t max_temp;
    int16_t color[3];
    int16_t population_number[2];
    int16_t cluster_number[2];
    int16_t triggerable_group[2];
    int16_t litter_size[2];
    int16_t genpower;
    int16_t extract_color[3];
    int16_t extract_cheese_color[3];
    int16_t penetratepower;
    int16_t frequency;
    int16_t extract_antidote_color[3];
    int16_t vermin_bite_chance;
    int16_t vermin_bite_use_extract;
    int16_t grasstrample;
    int16_t buildingdestroyer;
    int16_t damblock;
    int16_t itemcorpse_itemtype;
    int16_t itemcorpse_itemsubtype;
    int16_t itemcorpse_material;
    int16_t itemcorpse_matgloss;
    int16_t itemcorpse_quality;
    int16_t has_racegloss;
    int16_t remains_color[3];
    int16_t difficulty;
    int16_t riverattack[6];
    int16_t riverattack_group[2];
    int16_t fat;
    int16_t glowcolor[3];
    int16_t material;
    int16_t layering;
    int32_t speed;
    int32_t modvalue;
    int32_t extract_value;
    int32_t cheese_value;
    int32_t extract_antidote_value;
    int32_t petvalue;
    int32_t extract_size;
    int32_t milkable;
    int32_t viewrange;
    int32_t size;
    int32_t maxage[2];
    int32_t baby;
    int32_t child;
    int32_t add_version;
    // TODO in creature_raw: container_notg df_static_flagarray creature_raw_flags;
    struct stl_vector_strptr prefstring;
    struct body_info body_info;
    struct T_graphics_1632 {
        int32_t texpos[7];
        int32_t texpos_gs[7];
        int32_t profession_texpos[7][88];
        int32_t profession_texpos_gs[7][88];
        int8_t add_color[7];
        int8_t profession_add_color[7][88];
    } graphics;
    struct stl_vector_int8_t speech_1;
    struct stl_vector_int32_t speech_2;
    struct stl_vector_int32_t speech_3;
};

enum creature_raw_flags {
    creature_raw_flags_EQUIPMENT_WAGON_1,
    creature_raw_flags_EQUIPMENT_WAGON_2,
    creature_raw_flags_LOCKPICKER,
    creature_raw_flags_AMPHIBIOUS,
    creature_raw_flags_AQUATIC,
    creature_raw_flags_MISCHIEVIOUS,
    creature_raw_flags_PATTERNFLIER,
    creature_raw_flags_CURIOUSBEAST,
    creature_raw_flags_CURIOUSBEAST_ITEM,
    creature_raw_flags_CURIOUSBEAST_GUZZLER,
    creature_raw_flags_FLEEQUICK,
    creature_raw_flags_VERMINHUNTER,
    creature_raw_flags_VERMIN_EATER,
    creature_raw_flags_VERMIN_GROUNDER,
    creature_raw_flags_VERMIN_FLIES,
    creature_raw_flags_VERMIN_SWAMPER,
    creature_raw_flags_VERMIN_RIVER,
    creature_raw_flags_VERMIN_CAVERIVER,
    creature_raw_flags_VERMIN_CHASM,
    creature_raw_flags_VERMIN_LAVA,
    creature_raw_flags_VERMIN_SOIL,
    creature_raw_flags_VERMIN_SOIL_COLONY,
    creature_raw_flags_SMALLAQUATIC_SWAMP,
    creature_raw_flags_SMALLAQUATIC_RIVER,
    creature_raw_flags_SMALLAQUATIC_CAVERIVER,
    creature_raw_flags_COMMON_DOMESTIC,
    creature_raw_flags_WAGON_PULLER,
    creature_raw_flags_PACK_ANIMAL,
    creature_raw_flags_LARGE_ROAMING,
    creature_raw_flags_LARGE_CAVERIVER,
    creature_raw_flags_LARGE_CHASM,
    creature_raw_flags_LARGE_LAVA,
    creature_raw_flags_SMALLAQUATIC_OCEAN = 33,
    creature_raw_flags_FLIER,
    creature_raw_flags_LARGE_PREDATOR,
    creature_raw_flags_LOOSE_CLUSTERS,
    creature_raw_flags_FIREIMMUNE,
    creature_raw_flags_FIREIMMUNE_SUPER,
    creature_raw_flags_WEBBER,
    creature_raw_flags_WEBIMMUNE,
    creature_raw_flags_FANCIFUL,
    creature_raw_flags_FISHITEM,
    creature_raw_flags_SESSILE_LAND,
    creature_raw_flags_IMMOLATE,
    creature_raw_flags_MILKABLE,
    creature_raw_flags_NO_SPRING,
    creature_raw_flags_NO_SUMMER,
    creature_raw_flags_NO_AUTUMN,
    creature_raw_flags_NO_WINTER,
    creature_raw_flags_BENIGN,
    creature_raw_flags_VERMIN_NOROAM,
    creature_raw_flags_VERMIN_NOTRAP,
    creature_raw_flags_VERMIN_NOFISH,
    creature_raw_flags_EXTRACT_PERMANENT,
    creature_raw_flags_EXTRACT_PARALYZE,
    creature_raw_flags_EXTRACT_STUN,
    creature_raw_flags_EXTRACT_PARALYZE_INTERMITTENT,
    creature_raw_flags_EXTRACT_STUN_INTERMITTENT,
    creature_raw_flags_AMBUSHPREDATOR,
    creature_raw_flags_CHITIN,
    creature_raw_flags_GNAWER,
    creature_raw_flags_NOT_BUTCHERABLE,
    creature_raw_flags_BUTCHERABLE_NONSTANDARD,
    creature_raw_flags_COOKABLE_LIVE,
    creature_raw_flags_EXTRACT_COOKABLE,
    creature_raw_flags_FIREBREATH,
    creature_raw_flags_DRAGONFIREBREATH,
    creature_raw_flags_MEANDERER,
    creature_raw_flags_THICKWEB,
    creature_raw_flags_TRAINABLE,
    creature_raw_flags_PET,
    creature_raw_flags_PET_EXOTIC,
    creature_raw_flags_CAN_CIV,
    creature_raw_flags_CAN_SPEAK,
    creature_raw_flags_CAN_LEARN,
    creature_raw_flags_UTTERANCES,
    creature_raw_flags_BONECARN,
    creature_raw_flags_CARNIVORE,
    creature_raw_flags_UNDERSWIM,
    creature_raw_flags_NOEXERT,
    creature_raw_flags_NOPAIN,
    creature_raw_flags_EXTRAVISION,
    creature_raw_flags_NOBREATHE,
    creature_raw_flags_NOSTUN,
    creature_raw_flags_NONAUSEA,
    creature_raw_flags_NOBLEED,
    creature_raw_flags_TRANCES,
    creature_raw_flags_NOEMOTION,
    creature_raw_flags_RECKLESS,
    creature_raw_flags_NOSTUCKINS,
    creature_raw_flags_SEVERONBREAKS,
    creature_raw_flags_NOSKULL,
    creature_raw_flags_NOSKIN,
    creature_raw_flags_NOBONES,
    creature_raw_flags_NOMEAT,
    creature_raw_flags_PARALYZEIMMUNE,
    creature_raw_flags_NOFEAR,
    creature_raw_flags_CANOPENDOORS,
    creature_raw_flags_ITEMCORPSE,
    creature_raw_flags_ITEMCORPSE_RACEGLOSS,
    creature_raw_flags_ITEMCORPSE_SHARPSTONE,
    creature_raw_flags_NOSMELLYROT,
    creature_raw_flags_REMAINS_UNDETERMINED,
    creature_raw_flags_HASSHELL,
    creature_raw_flags_PEARL,
    creature_raw_flags_IVORY,
    creature_raw_flags_HORN,
    creature_raw_flags_NARROW,
    creature_raw_flags_STOUT,
    creature_raw_flags_LIKES_FIGHTING,
    creature_raw_flags_VERMIN_HATEABLE,
    creature_raw_flags_VEGETATION,
    creature_raw_flags_MAGICAL,
    creature_raw_flags_GOOD,
    creature_raw_flags_NATURAL,
    creature_raw_flags_EVIL,
    creature_raw_flags_SAVAGE,
    creature_raw_flags_BABY,
    creature_raw_flags_CHILD,
    creature_raw_flags_MULTIPLE_LITTER_RARE,
    creature_raw_flags_MOUNT,
    creature_raw_flags_MOUNT_EXOTIC,
    creature_raw_flags_RIVERATTACK_MOUNTS,
    creature_raw_flags_RIVERATTACK_RESIDENT,
    creature_raw_flags_RIVERATTACK_CANUSEWELL,
    creature_raw_flags_EQUIPS,
    creature_raw_flags_ENDING,
    creature_raw_flags_DEFENDER,
    creature_raw_flags_NOTHOUGHT,
    creature_raw_flags_TRAPAVOID,
    creature_raw_flags_CAVE_ADAPT,
    creature_raw_flags_MEGABEAST,
    creature_raw_flags_SEMIMEGABEAST,
    creature_raw_flags_ALL_ACTIVE,
    creature_raw_flags_DIURNAL,
    creature_raw_flags_NOCTURNAL,
    creature_raw_flags_CREPUSCULAR,
    creature_raw_flags_MATUTINAL,
    creature_raw_flags_VESPERTINE,
    creature_raw_flags_LIGHT_GEN,
    creature_raw_flags_BIOME_MOUNTAIN,
    creature_raw_flags_BIOME_GLACIER,
    creature_raw_flags_BIOME_TUNDRA,
    creature_raw_flags_BIOME_SWAMP_TEMPERATE_FRESHWATER,
    creature_raw_flags_BIOME_SWAMP_TEMPERATE_SALTWATER,
    creature_raw_flags_BIOME_MARSH_TEMPERATE_FRESHWATER,
    creature_raw_flags_BIOME_MARSH_TEMPERATE_SALTWATER,
    creature_raw_flags_BIOME_SWAMP_TROPICAL_FRESHWATER,
    creature_raw_flags_BIOME_SWAMP_TROPICAL_SALTWATER,
    creature_raw_flags_BIOME_SWAMP_MANGROVE,
    creature_raw_flags_BIOME_MARSH_TROPICAL_FRESHWATER,
    creature_raw_flags_BIOME_MARSH_TROPICAL_SALTWATER,
    creature_raw_flags_BIOME_FOREST_TAIGA,
    creature_raw_flags_BIOME_FOREST_TEMPERATE_CONIFER,
    creature_raw_flags_BIOME_FOREST_TEMPERATE_BROADLEAF,
    creature_raw_flags_BIOME_FOREST_TROPICAL_CONIFER,
    creature_raw_flags_BIOME_FOREST_TROPICAL_DRY_BROADLEAF,
    creature_raw_flags_BIOME_FOREST_TROPICAL_MOIST_BROADLEAF,
    creature_raw_flags_BIOME_GRASSLAND_TEMPERATE,
    creature_raw_flags_BIOME_SAVANNA_TEMPERATE,
    creature_raw_flags_BIOME_SHRUBLAND_TEMPERATE,
    creature_raw_flags_BIOME_GRASSLAND_TROPICAL,
    creature_raw_flags_BIOME_SAVANNA_TROPICAL,
    creature_raw_flags_BIOME_SHRUBLAND_TROPICAL,
    creature_raw_flags_BIOME_DESERT_BADLAND,
    creature_raw_flags_BIOME_DESERT_ROCK,
    creature_raw_flags_BIOME_DESERT_SAND,
    creature_raw_flags_BIOME_OCEAN,
    creature_raw_flags_BIOME_INLAND_FRESHWATER,
    creature_raw_flags_BIOME_INLAND_BRACKISHWATER,
    creature_raw_flags_BIOME_INLAND_SALTWATER,
    creature_raw_flags_BIOME_SUBTERRANEAN_RIVER,
    creature_raw_flags_BIOME_SUBTERRANEAN_CHASM,
    creature_raw_flags_BIOME_SUBTERRANEAN_LAVA,
    creature_raw_flags_FEMALE,
    creature_raw_flags_MALE,
    creature_raw_flags_NO_GENDER,
    creature_raw_flags_LISP,
    creature_raw_flags_MATERIAL,
    creature_raw_flags_MATERIAL_USE_RACEGLOSS,
    creature_raw_flags_MATERIAL_USE_SHARPSTONE,
    creature_raw_flags_ALCOHOL_DEPENDENT
};

enum T_mode_8276 {
    T_mode_8276_ViolateProductionOrder,
    T_mode_8276_ViolateExportBan,
    T_mode_8276_ViolateJobOrder,
    T_mode_8276_ConspiracyToSlowLabor,
    T_mode_8276_Murder,
    T_mode_8276_DisorderlyConduct,
    T_mode_8276_BuildingDestruction,
    T_mode_8276_Vandalism,
    T_mode_8276_ViolateMiningOrder
};

struct crime_info {
    int16_t mode;
    struct T_punishments_8288 {
        int16_t hammerstrikes;
        int16_t prison;
        int32_t beating;
    } punishments;
    struct unit *criminal;
    struct unit *victim;
    int32_t punishment_assigned;
};

enum cumulus_type {
    cumulus_type_cumulus_none,
    cumulus_type_cumulus_medium,
    cumulus_type_cumulus_multi,
    cumulus_type_cumulus_nimbus
};

enum damage_type {
    damage_type_BLUDGEON,
    damage_type_SLASH,
    damage_type_GORE,
    damage_type_PIERCE,
    damage_type_BURN,
    damage_type_HEAT,
    damage_type_COLD
};

enum death_type {
    death_type_OLD_AGE,
    death_type_HUNGER,
    death_type_THIRST,
    death_type_SHOT,
    death_type_BLEED,
    death_type_DROWN,
    death_type_SUFFOCATE,
    death_type_STRUCK_DOWN,
    death_type_SCUTTLE,
    death_type_COLLISION,
    death_type_MAGMA,
    death_type_MAGMA_MIST,
    death_type_DRAGONFIRE,
    death_type_FIRE,
    death_type_SCALD,
    death_type_CAVEIN,
    death_type_DRAWBRIDGE,
    death_type_FALLING_ROCKS,
    death_type_CHASM,
    death_type_CAGE,
    death_type_MURDER,
    death_type_TRAP,
    death_type_COLLAPSE,
    death_type_QUIT,
    death_type_ABANDON,
    death_type_HEAT,
    death_type_COLD
};

struct descriptor_color {
    struct stl_string id;
    struct stl_vector_strptr words_str;
    struct stl_vector_int32_t words;
    struct stl_string name;
    int8_t fore;
    int8_t bright;
    float red;
    float green;
    float blue;
};

struct descriptor_shape {
    struct stl_string id;
    struct stl_vector_strptr words_str;
    struct stl_vector_int32_t words;
    struct stl_string name;
    struct stl_string name_plural;
    struct stl_vector_strptr adj;
    uint8_t tile;
};

struct script_stepst;
typedef bool (*vm_script_stepst_setNextStep)(script_stepst* this,int32_t idx);
typedef int32_t (*vm_script_stepst_execute)(script_stepst* this,void* context);
typedef int32_t (*vm_script_stepst_skip)(script_stepst* this,void* context);
typedef void (*vm_script_stepst_vmeth_12)(script_stepst* this);
struct vtable_script_stepst {
    vm_script_stepst_setNextStep setNextStep;
    vm_script_stepst_execute execute;
    vm_script_stepst_skip skip;
    vm_script_stepst_vmeth_12 vmeth_12;
};
struct script_stepst {
    struct vtable_script_stepst *vtable;
    int32_t next_step_idx;
};

struct stl_vector_ptr_script_stepst {
struct script_stepst **ptr;
void *endptr;
void *endalloc;
};
struct script_varst;
typedef void* (*vm_script_varst_instantiate)(script_varst* this);
struct vtable_script_varst {
    vm_script_varst_instantiate instantiate;
};
struct script_varst {
    struct vtable_script_varst *vtable;
    struct stl_string name;
};

struct stl_vector_ptr_script_varst {
struct script_varst **ptr;
void *endptr;
void *endalloc;
};
struct dipscript_info {
    int32_t id;
    struct stl_string script_file;
    struct stl_vector_ptr_script_stepst script_steps;
    struct stl_vector_ptr_script_varst script_vars;
    struct stl_string code;
};

enum T_flags_8039_enum {
    T_flags_8039_close_screen=0x01,
    T_flags_8039_new_screen=0x02
};

struct dipscript_popup {
    struct unit *meeting_holder;
    struct activity_info *activity;
    struct T_flags_8039 {
        int32_t bitfield;
    } dipscript_popup_flags;
};

enum T_flags_7632_enum {
    T_flags_7632_in_use=0x01
};

struct drink_area {
    int32_t id;
    struct coord pos;
    int8_t type;
    struct T_flags_7632 {
        uint16_t bitfield;
    } drink_area_flags;
};

struct dye_info {
    int16_t material;
    int16_t matgloss;
    int32_t maker;
    int16_t quality;
    int16_t skill_rating;
    int32_t dye_info_anon_1;
};

struct effect_info {
    int32_t id;
    struct job *effect_info_anon_1;
    int16_t type;
    int16_t foreground;
    int16_t background;
    int8_t bright;
    struct coord32 pos;
    int32_t timer;
    int32_t effect_info_anon_2;
};

struct embark_item {
    int16_t item_type;
    int16_t item_subtype;
    int16_t material;
    int16_t matgloss;
    int8_t count;
};

enum T_flag_2593_enum {
    T_flag_2593_render=0x01,
    T_flag_2593_maxfps=0x02
};

struct text_system_file_info {
    int32_t index;
    struct stl_string filename;
    int8_t file_token;
    int32_t number;
};

struct stl_vector_ptr_text_system_file_info {
struct text_system_file_info **ptr;
void *endptr;
void *endalloc;
};
struct T_overlays_2623 {
    int32_t texpos;
    int32_t anon_1;
    double x1;
    double y1;
    uint32_t flags;
    float red;
    float green;
    float blue;
    float alpha;
    int32_t anon_2;
    double x2;
    double y2;
    double z1;
    double z2;
    int8_t anon_3;
    int32_t anon_4;
    int32_t anon_5;
    int32_t anon_6;
    int32_t anon_7;
    int32_t anon_8;
    double anon_9;
    double anon_10;
    double anon_11;
} ;
struct stl_vector_ptr_T_overlays_2623 {
struct T_overlays_2623 **ptr;
void *endptr;
void *endalloc;
};
struct T_anon_6_2688 {
    void *anon_1;
    int32_t textures[256];
    int32_t anon_2;
    int32_t anon_3;
    int32_t anon_4;
    int32_t anon_5;
    int32_t anon_6;
    int32_t anon_7;
    int32_t anon_8;
    int32_t anon_9;
    int32_t anon_10;
    int32_t anon_11;
    void *anon_12;
    void *anon_13;
    void *anon_14;
    void *anon_15;
    void *anon_16;
    void *anon_17;
} ;
struct stl_vector_ptr_T_anon_6_2688 {
struct T_anon_6_2688 **ptr;
void *endptr;
void *endalloc;
};
struct T_gridrect_2730 {
    int32_t id;
    int32_t dimx;
    int32_t dimy;
    int32_t *buffer_texpos;
    float *buffer_r;
    float *buffer_g;
    float *buffer_b;
    float *buffer_br;
    float *buffer_bg;
    float *buffer_bb;
    float anon_1;
    float anon_2;
    int32_t dispx;
    int32_t dispy;
    int8_t black_space;
} ;
struct stl_vector_ptr_T_gridrect_2730 {
struct T_gridrect_2730 **ptr;
void *endptr;
void *endalloc;
};
struct T_anon_7_2766 {
    int32_t anon_1;
    struct stl_string anon_2;
    int32_t anon_3;
    int32_t anon_4;
    int32_t dimx_1;
    int32_t dimy_1;
    int32_t dimx_2;
    int32_t dimy_2;
    int32_t anon_5;
    int32_t anon_6;
    int32_t anon_7[24];
    int8_t anon_8;
    int8_t anon_9[29];
    int32_t anon_10;
    int32_t anon_11[222];
    int32_t anon_12;
    int32_t anon_13[256];
} ;
struct stl_vector_ptr_T_anon_7_2766 {
struct T_anon_7_2766 **ptr;
void *endptr;
void *endalloc;
};
struct T_texture_2806 {
    void *anon_1;
    struct stl_string name;
    int32_t datapos;
    int8_t alpha_1;
    int8_t alpha_2;
    int16_t dimx;
    int16_t dimy;
    int32_t glTexture;
    int32_t old_glTexture;
} ;
struct stl_vector_ptr_T_texture_2806 {
struct T_texture_2806 **ptr;
void *endptr;
void *endalloc;
};
struct T_texture_data_2830 {
    int8_t *rgb;
    int8_t alpha;
    int16_t dimx;
    int16_t dimy;
} ;
struct stl_vector_ptr_T_texture_data_2830 {
struct T_texture_data_2830 **ptr;
void *endptr;
void *endalloc;
};
struct enabler {
    uint32_t hInstance;
    uint32_t className;
    struct T_windowInfo_2562 {
        void *anon_1;
        uint32_t hWnd;
        uint32_t hDC;
        uint32_t HGLRC;
        void *anon_2;
        uint32_t lpWindowName;
        int32_t dim_x;
        int32_t dim_y;
        int32_t bpp;
        int32_t windowed;
        int32_t anon_3;
        int32_t anon_4;
    } windowInfo;
    int32_t enabler_anon_1[256];
    int32_t enabler_anon_2;
    struct T_MSG_2578 {
        uint32_t hwnd;
        uint32_t message;
        uint32_t wParam;
        uint32_t lParam;
        uint32_t time;
        struct T_pt_2584 {
            int32_t x;
            int32_t y;
        } pt;
    } MSG;
    int32_t desired_windowed_width;
    int32_t desired_windowed_height;
    int32_t desired_fullscreen_width;
    int32_t desired_fullscreen_height;
    struct T_flag_2593 {
        int32_t bitfield;
    } flag;
    int8_t tracking_on;
    struct stl_string command_line;
    int8_t create_full_screen;
    int8_t inactive_mode;
    int64_t qfpr;
    int64_t main_qprate;
    int64_t qprate;
    int64_t qpc;
    int64_t qpc2;
    int32_t enabler_anon_3;
    int32_t oldmouse_x;
    int32_t oldmouse_y;
    int32_t mouse_x;
    int32_t mouse_y;
    int8_t mouse_lbut;
    int8_t mouse_rbut;
    int8_t mouse_lbut_lift;
    int8_t mouse_rbut_lift;
    struct stl_vector_ptr_text_system_file_info file_info;
    float ccolor[16][3];
    int32_t window_x;
    int32_t window_y;
    struct stl_vector_ptr_T_overlays_2623 overlays;
    int32_t enabler_anon_4;
    int32_t enabler_anon_5;
    struct T_input_queue_2676 {
        int32_t vKey;
        int8_t shift;
        int8_t capslock;
    } input_queue[100];
    int8_t is_program_looping;
    struct stl_vector_ptr_T_anon_6_2688 enabler_anon_6;
    struct stl_vector_ptr_T_gridrect_2730 gridrect;
    struct stl_vector_ptr_T_anon_7_2766 enabler_anon_7;
    struct stl_vector_ptr_T_texture_2806 texture;
    struct stl_vector_ptr_T_texture_data_2830 texture_data;
    int32_t enabler_anon_8;
    int32_t next_gridrect_id;
    int32_t enabler_anon_9;
    int32_t enabler_anon_10;
    int32_t enabler_anon_11;
    double locx;
    double locy;
    double locz;
    double center_x;
    double center_y;
    float color_r;
    float color_g;
    float color_b;
    float color_a;
    float clear_r;
    float clear_g;
    float clear_b;
    float clear_a;
    float fade_r;
    float fade_g;
    float fade_b;
    float fade_a;
    float fade_t;
    int8_t buffer_draw;
};

enum engraving_flags_enum {
    engraving_flags_floor=0x01,
    engraving_flags_west=0x02,
    engraving_flags_east=0x04,
    engraving_flags_north=0x08,
    engraving_flags_south=0x10,
    engraving_flags_hidden=0x20
};

struct engraving_flags {
    uint32_t bitfield;
};

struct engraving {
    int32_t artist;
    int16_t skill_rating;
    struct coord pos;
    struct engraving_flags engraving_flags;
    int8_t tile;
    int32_t art_id;
    int16_t art_subid;
    int16_t quality;
};

struct entity_buy_requests;
struct entity_buy_prices {
    struct entity_buy_requests *items;
    struct stl_vector_int32_t price;
};

struct entity_buy_requests {
    struct stl_vector_int16_t item_type;
    struct stl_vector_int16_t item_subtype;
    struct stl_vector_int8_t priority;
};

struct entity_entity_link {
    int16_t type;
    int32_t target;
    int16_t strength;
};

enum entity_entity_link_type {
    entity_entity_link_type_PARENT,
    entity_entity_link_type_CHILD
};

enum entity_material_category {
    entity_material_category_Clothing,
    entity_material_category_Leather,
    entity_material_category_Cloth,
    entity_material_category_LyeWood,
    entity_material_category_CraftMetal,
    entity_material_category_Stone,
    entity_material_category_Improvement,
    entity_material_category_Glass,
    entity_material_category_Wood,
    entity_material_category_Bag,
    entity_material_category_Cage,
    entity_material_category_Weapon,
    entity_material_category_Ammo,
    entity_material_category_Pick,
    entity_material_category_Armor,
    entity_material_category_Gem,
    entity_material_category_Bone,
    entity_material_category_Shell,
    entity_material_category_Pearl,
    entity_material_category_Ivory,
    entity_material_category_Horn,
    entity_material_category_Other
};

enum entity_name_type {
    entity_name_type_OTHER,
    entity_name_type_CIV,
    entity_name_type_SITE
};

struct language_word_table {
    struct stl_vector_int32_t words[6];
    struct stl_vector_int32_t parts[6];
};

struct entity_raw {
    struct stl_string code;
    struct stl_vector_int16_t creature_ids;
    struct stl_vector_strptr creatures;
    struct T_equipment_2202 {
        struct stl_vector_int16_t digger_id;
        struct stl_vector_int16_t weapon_id;
        struct stl_vector_int16_t armor_id;
        struct stl_vector_int16_t ammo_id;
        struct stl_vector_int16_t helm_id;
        struct stl_vector_int16_t gloves_id;
        struct stl_vector_int16_t shoes_id;
        struct stl_vector_int16_t pants_id;
        struct stl_vector_int16_t shield_id;
        struct stl_vector_int16_t trapcomp_id;
        struct stl_vector_int16_t toy_id;
        struct stl_vector_int16_t instrument_id;
        struct stl_vector_int16_t siegeammo_id;
        struct stl_vector_int8_t armor_rarity;
        struct stl_vector_int8_t helm_rarity;
        struct stl_vector_int8_t gloves_rarity;
        struct stl_vector_int8_t shoes_rarity;
        struct stl_vector_int8_t pants_rarity;
        struct stl_vector_strptr digger_str;
        struct stl_vector_strptr weapon_str;
        struct stl_vector_strptr armor_str;
        struct stl_vector_strptr ammo_str;
        struct stl_vector_strptr helm_str;
        struct stl_vector_strptr gloves_str;
        struct stl_vector_strptr shoes_str;
        struct stl_vector_strptr pants_str;
        struct stl_vector_strptr shield_str;
        struct stl_vector_strptr trapcomp_str;
        struct stl_vector_strptr toy_str;
        struct stl_vector_strptr instrument_str;
        struct stl_vector_strptr siegeammo_str;
    } equipment;
    int32_t currency_value[64];
    struct df_flagarray entity_raw_flags;
    struct stl_string translation;
    struct T_symbols_2295 {
        struct language_word_table _word_table_1[3];
        struct language_word_table _word_table_2[3];
        struct stl_vector_strptr select_symbol[3];
        struct stl_vector_strptr cull_symbol[3];
    } symbols;
};

enum entity_raw_flags {
    entity_raw_flags_CIV_CONTROLLABLE,
    entity_raw_flags_INDIV_CONTROLLABLE,
    entity_raw_flags_MOUNTAIN_SETTLEMENTS,
    entity_raw_flags_FOREST_SETTLEMENTS,
    entity_raw_flags_PLAINS_SETTLEMENTS,
    entity_raw_flags_SIEGER,
    entity_raw_flags_AMBUSHER,
    entity_raw_flags_BABYSNATCHER,
    entity_raw_flags_NUISANCE,
    entity_raw_flags_CLOTHING,
    entity_raw_flags_CURRENCY_BY_YEAR,
    entity_raw_flags_METAL_PREF,
    entity_raw_flags_GEM_PREF,
    entity_raw_flags_STONE_PREF,
    entity_raw_flags_WOOD_PREF,
    entity_raw_flags_MINOR_METAL,
    entity_raw_flags_RIVER_PRODUCTS,
    entity_raw_flags_OCEAN_PRODUCTS,
    entity_raw_flags_INDOOR_FARMING,
    entity_raw_flags_OUTDOOR_FARMING,
    entity_raw_flags_USE_CAVE_ANIMALS,
    entity_raw_flags_USE_EVIL_ANIMALS,
    entity_raw_flags_USE_ANIMAL_PRODUCTS,
    entity_raw_flags_COMMON_DOMESTIC_PACK,
    entity_raw_flags_COMMON_DOMESTIC_PULL,
    entity_raw_flags_COMMON_DOMESTIC_MOUNT,
    entity_raw_flags_COMMON_DOMESTIC_PET,
    entity_raw_flags_SUBTERRANEAN_CLOTHING
};

struct entity_recipe {
    int16_t subtype;
    struct stl_vector_int16_t item_type;
    struct stl_vector_int16_t item_subtype;
    struct stl_vector_int16_t material;
    struct stl_vector_int16_t matgloss;
};

enum entity_sell_category {
    entity_sell_category_Leather,
    entity_sell_category_ClothPlant,
    entity_sell_category_ClothSilk,
    entity_sell_category_Crafts,
    entity_sell_category_Pets,
    entity_sell_category_Drinks,
    entity_sell_category_Cheese,
    entity_sell_category_Powders,
    entity_sell_category_Extracts,
    entity_sell_category_MeatFish,
    entity_sell_category_Plants,
    entity_sell_category_MeatFishRecipes,
    entity_sell_category_OtherRecipes
};

struct entity_sell_requests;
struct entity_sell_prices {
    struct entity_sell_requests *items;
    struct stl_vector_int32_t price[13];
};

struct entity_sell_requests {
    struct stl_vector_int8_t priority[13];
};

struct entity_site_link {
    int16_t type;
    int32_t site;
    int16_t strength;
};

enum entity_site_link_type {
    entity_site_link_type_GOV_CAPITAL,
    entity_site_link_type_CIV_CAPITAL
};

struct entity_uniform_item {
    int8_t random_dye;
    int8_t armorlevel;
    int16_t item_color;
    int32_t art_image_id;
    int16_t art_image_subid;
    int16_t image_thread_color;
    int16_t image_material_class;
    int16_t maker_race;
};

struct stl_vector_ptr_entity_uniform_item {
struct entity_uniform_item **ptr;
void *endptr;
void *endalloc;
};
struct entity_uniform {
    int16_t entity_uniform_anon_1;
    struct stl_vector_int16_t uniform_item_types;
    struct stl_vector_int16_t uniform_item_subtypes;
    struct stl_vector_ptr_entity_uniform_item uniform_item_info;
};

struct fire {
    struct coord pos;
    int16_t fire_anon_1;
    uint16_t temperature_1;
    uint16_t fire_anon_2;
    uint16_t temperature_2;
    uint16_t temperature_3;
};

struct flow_info {
    int16_t type;
    int16_t material;
    int16_t matgloss;
    int16_t density;
    struct coord pos;
    struct coord dest;
    int8_t blood_types[10];
    int8_t expanding;
    int8_t reuse;
};

enum T_flags_7613_enum {
    T_flags_7613_active=0x01
};

struct flow_reuse_pool {
    int32_t reuse_idx;
    struct T_flags_7613 {
        int32_t bitfield;
    } flow_reuse_pool_flags;
};

enum flow_type {
    flow_type_Miasma,
    flow_type_Steam,
    flow_type_Mist,
    flow_type_BloodyMist,
    flow_type_Dust,
    flow_type_RiverFlood,
    flow_type_Flood,
    flow_type_Antiflood,
    flow_type_MagmaInitialFlood,
    flow_type_MagmaMist,
    flow_type_Smoke,
    flow_type_Dragonfire,
    flow_type_Fire,
    flow_type_Web,
    flow_type_MaterialGas
};

enum fog_type {
    fog_type_fog_none,
    fog_type_fog_mist,
    fog_type_fog_normal,
    fog_type_fog_thick
};

enum front_type {
    front_type_front_none,
    front_type_front_warm,
    front_type_front_cold,
    front_type_front_occluded
};

enum furnace_type {
    furnace_type_WoodFurnace,
    furnace_type_Smelter,
    furnace_type_GlassFurnace,
    furnace_type_Kiln,
    furnace_type_MagmaSmelter,
    furnace_type_MagmaGlassFurnace,
    furnace_type_MagmaKiln
};

enum game_mode {
    game_mode_DWARF,
    game_mode_ADVENTURE,
    game_mode_num,
    game_mode_NONE
};

enum game_type {
    game_type_DWARF_MAIN,
    game_type_ADVENTURE_MAIN,
    game_type_VIEW_LEGENDS,
    game_type_DWARF_RECLAIM,
    game_type_num,
    game_type_NONE
};

struct general_refst;
typedef void (*vm_general_refst_write_file)(general_refst* this,void*);
typedef void (*vm_general_refst_read_file)(general_refst* this,void*,int32_t loadversion);
typedef general_ref_type (*vm_general_refst_getType)(general_refst* this);
typedef void* (*vm_general_refst_getItem)(general_refst* this);
typedef void* (*vm_general_refst_getUnit)(general_refst* this);
typedef void* (*vm_general_refst_getProjectile)(general_refst* this);
typedef void* (*vm_general_refst_getBuilding)(general_refst* this);
typedef void (*vm_general_refst_setID)(general_refst* this,int32_t);
typedef int32_t (*vm_general_refst_getID)(general_refst* this);
typedef void (*vm_general_refst_vmeth_36)(general_refst* this);
typedef void* (*vm_general_refst_clone)(general_refst* this);
struct vtable_general_refst {
    vm_general_refst_write_file write_file;
    vm_general_refst_read_file read_file;
    vm_general_refst_getType getType;
    vm_general_refst_getItem getItem;
    vm_general_refst_getUnit getUnit;
    vm_general_refst_getProjectile getProjectile;
    vm_general_refst_getBuilding getBuilding;
    vm_general_refst_setID setID;
    vm_general_refst_getID getID;
    vm_general_refst_vmeth_36 vmeth_36;
    vm_general_refst_clone clone;
};
struct general_refst {
    struct vtable_general_refst *vtable;
};

struct general_ref_artifactst {
        struct vtable_general_refst *vtable;
    int32_t artifact_id;
};

struct general_ref_buildingst {
        struct vtable_general_refst *vtable;
    int32_t building_id;
};

struct general_ref_building_cagedst {
            struct vtable_general_refst *vtable;
        int32_t building_id;
};

struct general_ref_building_chainst {
            struct vtable_general_refst *vtable;
        int32_t building_id;
};

struct general_ref_building_channeledst {
            struct vtable_general_refst *vtable;
        int32_t building_id;
};

struct general_ref_building_civzone_assignedst {
            struct vtable_general_refst *vtable;
        int32_t building_id;
};

struct general_ref_building_holderst {
            struct vtable_general_refst *vtable;
        int32_t building_id;
};

struct general_ref_building_triggerst {
            struct vtable_general_refst *vtable;
        int32_t building_id;
};

struct general_ref_building_triggertargetst {
            struct vtable_general_refst *vtable;
        int32_t building_id;
};

struct general_ref_coinbatchst {
        struct vtable_general_refst *vtable;
    int32_t batch;
};

struct general_ref_itemst {
        struct vtable_general_refst *vtable;
    int32_t item_id;
};

struct general_ref_contained_in_itemst {
            struct vtable_general_refst *vtable;
        int32_t item_id;
};

struct general_ref_contains_itemst {
            struct vtable_general_refst *vtable;
        int32_t item_id;
};

struct general_ref_unitst {
        struct vtable_general_refst *vtable;
    int32_t unit_id;
};

struct general_ref_contains_unitst {
            struct vtable_general_refst *vtable;
        int32_t unit_id;
};

struct general_ref_entity_art_imagest {
        struct vtable_general_refst *vtable;
    int32_t entity;
    int32_t index;
};

struct general_ref_item_typest {
        struct vtable_general_refst *vtable;
    int32_t type;
    int32_t subtype;
    int16_t material;
    int16_t matgloss;
};

struct general_ref_mapsquarest {
        struct vtable_general_refst *vtable;
    uint8_t tile;
    int16_t color;
    int16_t material;
    int16_t matgloss;
};

struct general_ref_projectilest {
        struct vtable_general_refst *vtable;
    int32_t projectile_id;
};

struct general_ref_unit_holderst {
            struct vtable_general_refst *vtable;
        int32_t unit_id;
};

struct general_ref_unit_itemownerst {
            struct vtable_general_refst *vtable;
        int32_t unit_id;
};

struct general_ref_unit_tradebringerst {
            struct vtable_general_refst *vtable;
        int32_t unit_id;
};

struct general_ref_unit_traineest {
            struct vtable_general_refst *vtable;
        int32_t unit_id;
};

struct general_ref_unit_workerst {
            struct vtable_general_refst *vtable;
        int32_t unit_id;
};

enum gloves_flags {
    gloves_flags_METAL_ARMOR_LEVELS = 1
};

struct tile_page {
    struct stl_string token;
    struct stl_string filename;
    int16_t tile_dim_x;
    int16_t tile_dim_y;
    int16_t page_dim_x;
    int16_t page_dim_y;
    struct stl_vector_int32_t texpos;
    struct stl_vector_int32_t datapos;
    struct stl_vector_int32_t texpos_gs;
    struct stl_vector_int32_t datapos_gs;
    int8_t loaded;
};

struct stl_vector_ptr_tile_page {
struct tile_page **ptr;
void *endptr;
void *endalloc;
};
enum unit_flags1_enum {
    unit_flags1_move_state=0x01,
    unit_flags1_dead=0x02,
    unit_flags1_has_mood=0x04,
    unit_flags1_had_mood=0x08,
    unit_flags1_marauder=0x10,
    unit_flags1_drowning=0x20,
    unit_flags1_merchant=0x40,
    unit_flags1_forest=0x80,
    unit_flags1_left=0x100,
    unit_flags1_rider=0x200,
    unit_flags1_incoming=0x400,
    unit_flags1_diplomat=0x800,
    unit_flags1_zombie=0x1000,
    unit_flags1_skeleton=0x2000,
    unit_flags1_can_swap=0x4000,
    unit_flags1_on_ground=0x8000,
    unit_flags1_projectile=0x10000,
    unit_flags1_active_invader=0x20000,
    unit_flags1_hidden_in_ambush=0x40000,
    unit_flags1_invader_origin=0x80000,
    unit_flags1_coward=0x100000,
    unit_flags1_hidden_ambusher=0x200000,
    unit_flags1_invades=0x400000,
    unit_flags1_check_flows=0x800000,
    unit_flags1_ridden=0x1000000,
    unit_flags1_caged=0x2000000,
    unit_flags1_tame=0x4000000,
    unit_flags1_chained=0x8000000,
    unit_flags1_royal_guard=0x10000000,
    unit_flags1_fortress_guard=0x20000000,
    unit_flags1_suppress_wield=0x40000000,
    unit_flags1_important_historical_figure=0x80000000
};

struct unit_flags1 {
    uint32_t bitfield;
};

enum unit_flags2_enum {
    unit_flags2_swimming=0x01,
    unit_flags2_sparring=0x02,
    unit_flags2_no_notify=0x04,
    unit_flags2_unused=0x08,
    unit_flags2_calculated_nerves=0x10,
    unit_flags2_calculated_bodyparts=0x20,
    unit_flags2_important_historical_figure=0x40,
    unit_flags2_killed=0x80,
    unit_flags2_cleanup_1=0x100,
    unit_flags2_cleanup_2=0x200,
    unit_flags2_cleanup_3=0x400,
    unit_flags2_for_trade=0x800,
    unit_flags2_trade_resolved=0x1000,
    unit_flags2_has_breaks=0x2000,
    unit_flags2_gutted=0x4000,
    unit_flags2_circulatory_spray=0x8000,
    unit_flags2_locked_in_for_trading=0x10000,
    unit_flags2_slaughter=0x20000,
    unit_flags2_underworld=0x40000,
    unit_flags2_resident=0x80000,
    unit_flags2_cleanup_4=0x100000,
    unit_flags2_calculated_insulation=0x200000,
    unit_flags2_visitor_uninvited=0x400000,
    unit_flags2_visitor=0x800000,
    unit_flags2_calculated_inventory=0x1000000,
    unit_flags2_vision_good=0x2000000,
    unit_flags2_vision_damaged=0x4000000,
    unit_flags2_vision_missing=0x8000000,
    unit_flags2_breathing_good=0x10000000,
    unit_flags2_breathing_problem=0x20000000,
    unit_flags2_roaming_wilderness_population_source=0x40000000,
    unit_flags2_roaming_wilderness_population_source_not_a_map_feature=0x80000000
};

struct unit_flags2 {
    uint32_t bitfield;
};

enum T_state_13936 {
    T_state_13936_SelectNoble,
    T_state_13936_FollowNoble,
    T_state_13936_DoMeeting,
    T_state_13936_LeaveMap
};

enum T_flags_13961_enum {
    T_flags_13961_pickup_food=0x01,
    T_flags_13961_carry_water=0x02,
    T_flags_13961_hold_ground=0x04,
    T_flags_13961_attack_animals=0x08,
    T_flags_13961_stand_down=0x10
};

enum T_mode_14147 {
    T_mode_14147_Hauled,
    T_mode_14147_Weapon,
    T_mode_14147_Worn,
    T_mode_14147_Unk3,
    T_mode_14147_Unk4,
    T_mode_14147_Unk5,
    T_mode_14147_Piercing,
    T_mode_14147_Unk7,
    T_mode_14147_Unk8,
    T_mode_14147_Unk9,
    T_mode_14147_Unk10,
    T_mode_14147_Unk11,
    T_mode_14147_Unk12,
    T_mode_14147_Unk13,
    T_mode_14147_Flask,
    T_mode_14147_StuckIn,
    T_mode_14147_InMouth,
    T_mode_14147_Pet
};

struct unit_inventory_item {
    struct itemst *item;
    int16_t mode;
    int16_t body_part_id;
    int32_t pet_seed;
};

struct stl_vector_ptr_unit_inventory_item {
struct unit_inventory_item **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_artifact_record {
struct artifact_record **ptr;
void *endptr;
void *endalloc;
};
enum T_soldier_mood_14072 {
    T_soldier_mood_14072_None = -1,
    T_soldier_mood_14072_MartialTrance,
    T_soldier_mood_14072_Enranged,
    T_soldier_mood_14072_Tantrum
};

struct unit_contaminant {
    struct contaminant contaminant;
    int16_t body_part_id;
    int16_t _unk_16;
};

struct stl_vector_ptr_unit_contaminant {
struct unit_contaminant **ptr;
void *endptr;
void *endalloc;
};
struct unit_misc_trait {
    int16_t id;
    int32_t value;
};

struct stl_vector_ptr_unit_misc_trait {
struct unit_misc_trait **ptr;
void *endptr;
void *endalloc;
};
struct unit_skill {
    int16_t id;
    int16_t rating;
    uint32_t experience;
};

struct stl_vector_ptr_unit_skill {
struct unit_skill **ptr;
void *endptr;
void *endalloc;
};
enum T_type_14238 {
    T_type_14238_LikeMaterial,
    T_type_14238_LikeCreature,
    T_type_14238_LikeFood,
    T_type_14238_HateCreature,
    T_type_14238_LikeItem,
    T_type_14238_LikePlant,
    T_type_14238_LikeTree,
    T_type_14238_LikeColor,
    T_type_14238_LikeShape
};

struct unit_preference {
    int16_t type;
    union {
        int16_t item_type;
        int16_t creature_id;
        int16_t color_id;
        int16_t shape_id;
        int16_t plant_id;
        int16_t wood_id;
    };
    int16_t item_subtype;
    int16_t material;
    int16_t matgloss;
    int8_t active;
    int32_t prefstring_seed;
};

struct stl_vector_ptr_unit_preference {
struct unit_preference **ptr;
void *endptr;
void *endalloc;
};
enum T_place_6425 {
    T_place_6425_Office,
    T_place_6425_Bedroom,
    T_place_6425_DiningRoom,
    T_place_6425_Tomb
};

struct unit_demand {
    int16_t _unk_0;
    int16_t place;
    int16_t item_type;
    int16_t item_subtype;
    int16_t material;
    int16_t matgloss;
    int32_t timeout_counter;
    int32_t timeout_limit;
};

struct stl_vector_ptr_unit_demand {
struct unit_demand **ptr;
void *endptr;
void *endalloc;
};
struct unit_item_wrestle {
    int32_t unit;
    int32_t self_bp;
    int32_t other_bp;
    int32_t self_bp2;
    int32_t other_bp2;
    int32_t item1;
    int32_t item2;
    int32_t type;
    int8_t direction;
};

struct stl_vector_ptr_unit_item_wrestle {
struct unit_item_wrestle **ptr;
void *endptr;
void *endalloc;
};
struct unit_thought {
    int16_t type;
    int32_t age;
    int16_t subtype;
    int32_t severity;
};

struct stl_vector_ptr_unit_thought {
struct unit_thought **ptr;
void *endptr;
void *endalloc;
};
enum T_type_14268 {
    T_type_14268_SelfUnemployed,
    T_type_14268_GuildUnemployed,
    T_type_14268_NeedWeapons
};

struct unit_complaint {
    int16_t type;
    int16_t guild;
    int32_t age;
};

struct stl_vector_ptr_unit_complaint {
struct unit_complaint **ptr;
void *endptr;
void *endalloc;
};
enum T_type_14277 {
    T_type_14277_DoGuildJobs,
    T_type_14277_MakeWeapons
};

struct unit_request {
    int16_t type;
    int16_t guild;
    int16_t count;
};

struct stl_vector_ptr_unit_request {
struct unit_request **ptr;
void *endptr;
void *endalloc;
};
enum T_flags_14208_enum {
    T_flags_14208_is_friend=0x01
};

struct unit_acquaintance {
    int32_t unit_id;
    int32_t strength;
    int32_t timer;
    struct T_flags_14208 {
        int32_t bitfield;
    } unit_acquaintance_flags;
};

struct stl_vector_ptr_unit_acquaintance {
struct unit_acquaintance **ptr;
void *endptr;
void *endalloc;
};
struct unit_coin_debt {
    int32_t recipient;
    int32_t amount;
};

struct stl_vector_ptr_unit_coin_debt {
struct unit_coin_debt **ptr;
void *endptr;
void *endalloc;
};
struct temperaturest {
    uint16_t whole;
    int16_t fraction;
};

struct stl_vector_ptr_temperaturest {
struct temperaturest **ptr;
void *endptr;
void *endalloc;
};
struct unit {
    struct language_name name;
    struct stl_string custom_profession;
    int32_t profession;
    int32_t profession2;
    int32_t race;
    int32_t race_matgloss;
    struct coord32 pos;
    struct coord32 idle_area;
    int32_t idle_area_threshold;
    int32_t follow_distance;
    struct T_path_13927 {
        struct coord32 dest;
        struct coord32_path path;
    } path;
    struct unit_flags1 unit_flags1;
    struct unit_flags2 unit_flags2;
    struct T_meeting_13935 {
        int8_t state;
        int16_t target_profession;
    } meeting;
    int8_t sex;
    int32_t id;
    int16_t idle_location_type;
    int32_t schedule_id;
    int32_t civ_id;
    struct coord32_path patrol_route;
    int32_t patrol_index;
    struct stl_vector_ptr_specific_ref specific_refs;
    struct stl_vector_ptr_general_refst general_refs;
    struct T_military_13957 {
        struct language_name name;
        int8_t rations;
        int8_t sleep_mode;
        struct T_flags_13961 {
            uint32_t bitfield;
        } flags;
        int32_t patrol_timer;
        int32_t patrol_cooldown;
        struct coord station_pos;
        int32_t pickup_food_cooldown;
    } military;
    struct T_animal_13974 {
        int16_t population;
        int32_t leave_countdown;
        int32_t vanish_countdown;
    } animal;
    int16_t mood;
    int16_t mood_claimedWorkshop;
    struct T_relations_13983 {
        int32_t pregnancy_timer;
        int32_t age_seconds;
        int32_t age_years;
        int32_t age_death;
        struct unit *following;
        int32_t pet_owner_id;
        int32_t spouse_id;
        int32_t mother_id;
        int32_t father_id;
        int32_t last_attacker_id;
        int32_t group_leader_id;
        int32_t draggee_id;
        int32_t dragger_id;
        int32_t rider_mount_id;
    } relations;
    int16_t mount_type;
    int16_t killer_profession;
    struct stl_vector_ptr_unit_inventory_item inventory;
    struct stl_vector_int32_t owned_items;
    struct stl_vector_int32_t traded_items;
    struct stl_vector_ptr_artifact_record owned_artifacts;
    struct stl_vector_ptr_buildingst owned_buildings;
    struct stl_vector_int32_t corpse_items;
    struct T_job_14015 {
        int32_t account;
        int32_t satisfaction;
        struct unit *hunt_target;
        struct buildingst *destroy_target;
        struct coord32 last_attack_dir;
        int16_t siege_morale;
        int16_t morale_recovery_timer;
        struct job *current_job;
        struct stl_vector_int16_t mood_item_type;
        struct stl_vector_int32_t mood_item_subtype;
        struct stl_vector_int16_t mood_material;
        struct stl_vector_int32_t mood_matgloss;
        int32_t mood_skill;
        int32_t anon_1;
        int32_t mood_timeout;
    } job;
    struct T_body_14041 {
        struct stl_vector_int16_t wounds;
        struct stl_vector_int32_t flags;
        struct stl_vector_int8_t nerves;
        struct stl_vector_int8_t bodyparts;
        struct stl_vector_int16_t insulation;
        struct body_info *body_plan;
        int16_t weapon_hand_bp;
        int32_t size;
        int32_t blood_total;
        int32_t blood_remaining;
        int32_t bleed_rate;
    } body;
    struct T_counters_14056 {
        int32_t fame_level;
        int32_t think_counter;
        int32_t job_counter;
        int32_t swap_counter;
        int16_t death_cause;
        int16_t nausea;
        int16_t winded;
        int16_t stunned;
        int16_t unconscious;
        int16_t anon_1;
        int16_t webbed;
        int16_t paralysis;
        struct coord guts_trail1;
        struct coord guts_trail2;
        int16_t soldier_mood_countdown;
        int16_t soldier_mood;
        int32_t pain;
        int32_t exhaustion;
        int32_t hunger_timer;
        int32_t thirst_timer;
        int32_t sleepiness_timer;
        int32_t stomach_content;
    } counters;
    struct stl_vector_ptr_unit_contaminant contaminants;
    struct T_status_14087 {
        struct stl_vector_ptr_unit_misc_trait misc_traits;
        int32_t demand_timeout;
        int32_t mandate_timeout;
        int8_t anon_1;
        struct language_name artifact_name;
        int32_t strength;
        int32_t agility;
        int32_t toughness;
        struct stl_vector_ptr_unit_skill skills;
        struct stl_vector_ptr_unit_preference preferences;
        struct stl_vector_ptr_unit_demand demands;
        int8_t labors[91];
        int32_t total_exp;
        struct stl_vector_ptr_unit_item_wrestle wrestle_items;
        struct stl_vector_int32_t observed_traps;
        struct stl_vector_ptr_unit_thought recent_events;
        struct stl_vector_ptr_unit_thought recent_dreams;
        int32_t happiness;
        int16_t insanity_chance;
        struct stl_vector_ptr_unit_complaint complaints;
        struct stl_vector_ptr_unit_request requests;
        struct stl_vector_ptr_unit_acquaintance acquaintances;
        struct stl_vector_ptr_unit_coin_debt coin_debts;
        int16_t adv_sleep_timer;
        struct coord32 anon_2;
        struct coord32_path anon_3;
    } status;
    int32_t hist_figure_id;
    struct T_status2_14128 {
        int16_t limbs_stand_max;
        int16_t limbs_stand_count;
        int32_t able_breathe;
        int16_t limbs_grasp_max;
        int16_t limbs_grasp_count;
        int16_t limbs_fly_max;
        int16_t limbs_fly_count;
        int32_t specialattack_cooldown;
        struct stl_vector_ptr_temperaturest body_part_temperature;
        int32_t enemy_status_slot;
        int32_t last_temp_update;
    } status2;
};

struct stl_vector_ptr_unit {
struct unit **ptr;
void *endptr;
void *endalloc;
};
struct map_renderer {
    uint8_t entity[80][25];
    struct stl_vector_ptr_unit cursor_units;
    struct unit *cursor_guts;
    int8_t multiple_guts;
    struct itemst *cursor_corpse;
    int32_t cursor_corpse_cnt;
    struct itemst *cursor_corpsepiece;
    int32_t cursor_corpsepiece_cnt;
    struct itemst *cursor_bones;
    int32_t cursor_bones_cnt;
    struct itemst *cursor_skulls;
    int32_t cursor_skulls_cnt;
    struct itemst *cursor_other;
    int32_t cursor_other_cnt;
    int8_t allow_rotate;
    int8_t rotate_mode;
    int32_t cur_tick_count;
    int16_t tick_phase;
    int8_t dim_colors;
};

struct graphic {
    struct T_texture_2516 {
        struct stl_vector_ptr_tile_page page;
        struct stl_vector_int32_t texpos;
        struct stl_vector_int32_t datapos;
    } texture;
    struct map_renderer map_renderer;
    int32_t screenx;
    int32_t screeny;
    int16_t screenf;
    int16_t screenb;
    int8_t screenbright;
    int32_t screentexpos[80][25];
    int8_t screentexpos_addcolor[80][25];
    uint8_t screentexpos_grayscale[80][25];
    uint8_t screentexpos_cf[80][25];
    uint8_t screentexpos_cbr[80][25];
    struct T_screen_2537 {
        int8_t chr;
        int8_t fore;
        int8_t back;
        int8_t bright;
    } screen[80][25];
    int32_t clipx[2];
    int32_t clipy[2];
    int32_t tex_pos[1];
    int32_t rect_id;
    int64_t print_time[100];
    int32_t print_index;
    int8_t display_frames;
};

enum guild_id {
    guild_id_None = -1,
    guild_id_Miners,
    guild_id_Carpenters,
    guild_id_Masons,
    guild_id_Metalsmiths,
    guild_id_Jewelers,
    guild_id_Craftsmen,
    guild_id_HouseFer,
    guild_id_HouseBer,
    guild_id_HouseRash,
    guild_id_OrderAxe,
    guild_id_OrderMace,
    guild_id_OrderSword,
    guild_id_OrderHammer,
    guild_id_OrderCrossbow,
    guild_id_OrderSpear,
    guild_id_Philosophers
};

enum hauler_type {
    hauler_type_Any,
    hauler_type_Stone,
    hauler_type_Wood,
    hauler_type_Item,
    hauler_type_Bin,
    hauler_type_Body,
    hauler_type_Food,
    hauler_type_Refuse,
    hauler_type_Furniture,
    hauler_type_Animal
};

enum helm_flags {
    helm_flags_METAL_ARMOR_LEVELS = 1
};

struct histfig_entity_link {
    int16_t type;
    int32_t entity_id;
    int16_t link_strength;
};

enum histfig_entity_link_type {
    histfig_entity_link_type_LEADER,
    histfig_entity_link_type_GUARD,
    histfig_entity_link_type_MEMBER,
    histfig_entity_link_type_MERCENARY,
    histfig_entity_link_type_ENEMY,
    histfig_entity_link_type_CRIMINAL
};

enum histfig_flags {
    histfig_flags_Discovered
};

struct histfig_hf_link {
    int16_t type;
    int32_t target_hf;
};

enum histfig_hf_link_type {
    histfig_hf_link_type_MOTHER,
    histfig_hf_link_type_FATHER,
    histfig_hf_link_type_SPOUSE,
    histfig_hf_link_type_CHILD
};

struct histfig_site_link {
    int16_t type;
    int32_t site_id;
    int32_t structure_id;
};

enum histfig_site_link_type {
    histfig_site_link_type_SHOPKEEPER,
    histfig_site_link_type_SEAT_OF_POWER,
    histfig_site_link_type_HANGOUT,
    histfig_site_link_type_HOME
};

enum T_flags_1943_enum {
    T_flags_1943_neighbor=0x01,
    T_flags_1943_mountainhome=0x02,
    T_flags_1943_unk2=0x04,
    T_flags_1943_unk3=0x08,
    T_flags_1943_ruin=0x10
};

struct stl_vector_ptr_entity_entity_link {
struct entity_entity_link **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_entity_site_link {
struct entity_site_link **ptr;
void *endptr;
void *endalloc;
};
struct material_vec_ref {
    struct stl_vector_int16_t material;
    struct stl_vector_int16_t matgloss;
};

struct stl_vector_ptr_entity_recipe {
struct entity_recipe **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_entity_uniform {
struct entity_uniform **ptr;
void *endptr;
void *endalloc;
};
struct meeting_event {
    int16_t type;
    union {
        int16_t topic;
        int16_t item_type;
    };
    int16_t topic_parm;
    int32_t quota_total;
    int32_t quota_remaining;
    int32_t year;
    int8_t season;
    int16_t season_tick;
    struct entity_sell_prices *sell_prices;
    struct entity_buy_prices *buy_prices;
};

struct stl_vector_ptr_meeting_event {
struct meeting_event **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_histfig_entity_link {
struct histfig_entity_link **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_histfig_site_link {
struct histfig_site_link **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_histfig_hf_link {
struct histfig_hf_link **ptr;
void *endptr;
void *endalloc;
};
struct historical_figure {
    int32_t profession;
    int16_t race;
    int16_t racegloss;
    int8_t sex;
    int32_t age_death;
    int32_t appeared_year;
    int32_t born_year;
    int32_t died_year;
    struct language_name name;
    struct df_flagarray historical_figure_flags;
    int32_t unit_id;
    int32_t id;
    int32_t historical_figure_anon_1;
    struct stl_vector_ptr_histfig_entity_link entity_links;
    struct stl_vector_ptr_histfig_site_link site_links;
    struct stl_vector_ptr_histfig_hf_link histfig_links;
};

struct stl_vector_ptr_historical_figure {
struct historical_figure **ptr;
void *endptr;
void *endalloc;
};
struct nemesis_record {
    int32_t id;
    int32_t unit_id;
    int32_t save_file_id;
    int16_t member_idx;
    struct historical_figure *figure;
    struct unit *unit;
    int32_t group_leader_id;
    struct stl_vector_int32_t companions;
    int16_t unk10;
    int32_t unk11;
    int32_t unk12;
    struct df_flagarray nemesis_record_flags;
    struct stl_vector_int32_t items;
};

struct stl_vector_ptr_nemesis_record {
struct nemesis_record **ptr;
void *endptr;
void *endalloc;
};
struct historical_entity {
    int16_t type;
    int32_t id;
    struct entity_raw *entity_raw;
    int32_t save_file_id;
    int16_t next_member_idx;
    struct language_name name;
    int16_t race;
    struct T_flags_1943 {
        int32_t bitfield;
    } historical_entity_flags;
    struct stl_vector_ptr_entity_entity_link entity_links;
    struct stl_vector_ptr_entity_site_link site_links;
    struct stl_vector_int32_t histfig_ids;
    struct stl_vector_int32_t nemesis_ids;
    struct T_resources_1957 {
        struct stl_vector_int16_t digger_type;
        struct stl_vector_int16_t weapon_type;
        struct stl_vector_int16_t armor_type;
        struct stl_vector_int16_t ammo_type;
        struct stl_vector_int16_t helm_type;
        struct stl_vector_int16_t gloves_type;
        struct stl_vector_int16_t shoes_type;
        struct stl_vector_int16_t pants_type;
        struct stl_vector_int16_t shield_type;
        struct stl_vector_int16_t trapcomp_type;
        struct stl_vector_int16_t toy_type;
        struct stl_vector_int16_t instrument_type;
        struct stl_vector_int16_t siegeammo_type;
        struct material_vec_ref weapon;
        struct material_vec_ref armor;
        struct stl_vector_int16_t leather;
        struct stl_vector_int16_t cloth;
        struct stl_vector_int16_t silk;
        struct stl_vector_int16_t lye;
        struct stl_vector_int16_t craft_metal;
        struct material_vec_ref stone;
        struct material_vec_ref gem;
        struct stl_vector_int16_t bone;
        struct stl_vector_int16_t shell;
        struct stl_vector_int16_t pearl;
        struct stl_vector_int16_t ivory;
        struct stl_vector_int16_t horn;
        struct material_vec_ref other;
        struct material_vec_ref crafts;
        struct material_vec_ref glass;
        struct material_vec_ref wood;
        struct stl_vector_int16_t pet;
        struct material_vec_ref cage;
        struct material_vec_ref drink;
        struct material_vec_ref cheese;
        struct material_vec_ref mill;
        struct material_vec_ref extract;
        struct stl_vector_int16_t meat_fish;
        struct stl_vector_int16_t plant;
        struct stl_vector_int16_t wagon;
        struct stl_vector_int16_t pack_animal;
        struct stl_vector_int16_t wagon_puller;
        struct stl_vector_int16_t mount;
        struct stl_vector_int16_t minion;
        struct stl_vector_ptr_entity_recipe meat_fish_recipes;
        struct stl_vector_ptr_entity_recipe other_recipes;
        struct T_special_mats_2012 {
            int16_t material;
            int16_t matgloss;
        } special_mats[3];
        struct stl_vector_ptr_itemst owned_items;
        struct stl_vector_int8_t discovered_creature_foods;
        struct stl_vector_int8_t discovered_creatures;
        struct stl_vector_int8_t discovered_plant_foods;
        struct stl_vector_int8_t discovered_plants;
        struct stl_vector_int8_t discovered_trees;
        struct stl_vector_ptr anon_1;
        int16_t min_temperature;
        int16_t max_temperature;
        struct stl_vector_int16_t art_image_types;
        struct stl_vector_int32_t art_image_ids;
        struct stl_vector_int16_t art_image_subids;
        struct stl_vector_ptr_entity_uniform uniforms;
        struct stl_vector_ptr_meeting_event meeting_events;
    } resources;
    struct entity_activity_statistics activity_stats;
    int8_t send_nobles;
    int16_t last_communicate_season;
    int32_t last_communicate_year;
    int32_t imports;
    int32_t exports;
    int32_t offerings_recent;
    int32_t offerings_history[10];
    int32_t hostile_level;
    int32_t siege_count;
    struct stl_vector_ptr historical_entity_anon_1;
    struct stl_vector_ptr_historical_figure hist_figures;
    struct stl_vector_ptr_nemesis_record nemesis;
    struct anon {
        struct material_vec_ref mill_cookable;
        struct material_vec_ref mill_dye;
        struct stl_vector_int16_t armor_leather;
        struct stl_vector_int16_t armor_chain;
        struct stl_vector_int16_t armor_plate;
        struct stl_vector_int16_t armor_under;
        struct stl_vector_int16_t armor_over;
        struct stl_vector_int16_t armor_cover;
        struct stl_vector_int16_t pants_leather;
        struct stl_vector_int16_t pants_chain;
        struct stl_vector_int16_t pants_plate;
        struct stl_vector_int16_t pants_under;
        struct stl_vector_int16_t pants_over;
        struct stl_vector_int16_t pants_cover;
        struct stl_vector_int16_t helm_leather;
        struct stl_vector_int16_t helm_chain;
        struct stl_vector_int16_t helm_plate;
        struct stl_vector_int16_t helm_under;
        struct stl_vector_int16_t helm_over;
        struct stl_vector_int16_t helm_cover;
        struct stl_vector_int16_t shoes_leather;
        struct stl_vector_int16_t shoes_chain;
        struct stl_vector_int16_t shoes_plate;
        struct stl_vector_int16_t shoes_under;
        struct stl_vector_int16_t shoes_over;
        struct stl_vector_int16_t shoes_cover;
        struct stl_vector_int16_t gloves_leather;
        struct stl_vector_int16_t gloves_chain;
        struct stl_vector_int16_t gloves_plate;
        struct stl_vector_int16_t gloves_under;
        struct stl_vector_int16_t gloves_over;
        struct stl_vector_int16_t gloves_cover;
    };
    int32_t num_members;
    int32_t max_members;
};

enum historical_entity_type {
    historical_entity_type_Civilization,
    historical_entity_type_SiteGovernment
};

struct history_eventst;
enum history_event_type {
    history_event_type_WAR_ATTACKED_SITE,
    history_event_type_WAR_DESTROYED_SITE,
    history_event_type_CREATED_SITE,
    history_event_type_HIST_FIGURE_DIED,
    history_event_type_ADD_HF_ENTITY_LINK,
    history_event_type_FIRST_CONTACT,
    history_event_type_FIRST_CONTACT_FAILED,
    history_event_type_TOPICAGREEMENT_CONCLUDED,
    history_event_type_TOPICAGREEMENT_REJECTED,
    history_event_type_TOPICAGREEMENT_MADE,
    history_event_type_WAR_PEACE_ACCEPTED,
    history_event_type_WAR_PEACE_REJECTED,
    history_event_type_DIPLOMAT_LOST,
    history_event_type_AGREEMENTS_VOIDED,
    history_event_type_MERCHANT,
    history_event_type_ARTIFACT_HIDDEN,
    history_event_type_ARTIFACT_POSSESSED,
    history_event_type_ARTIFACT_CREATED,
    history_event_type_ARTIFACT_LOST,
    history_event_type_ARTIFACT_FOUND,
    history_event_type_ARTIFACT_RECOVERED,
    history_event_type_ARTIFACT_DROPPED,
    history_event_type_DEMON_ENCASED,
    history_event_type_DEMON_RELEASED,
    history_event_type_RECLAIM_SITE,
    history_event_type_CONTACT_LOST,
    history_event_type_HF_DESTROYED_SITE,
    history_event_type_SITE_DIED,
    history_event_type_SITE_ABANDONED
};

typedef history_event_type (*vm_history_eventst_getType)(history_eventst* this);
typedef int32_t (*vm_history_eventst_getWarStatus)(history_eventst* this,int32_t entity1,int32_t entity2);
typedef int32_t (*vm_history_eventst_getAngerModifier)(history_eventst* this,int32_t entity1,int32_t entity2);
typedef int32_t (*vm_history_eventst_getHappinessModifier)(history_eventst* this,int32_t entity1,int32_t entity2);
typedef bool (*vm_history_eventst_madeFirstContact)(history_eventst* this,int32_t entity1,int32_t entity2,int32_t site);
typedef bool (*vm_history_eventst_wasArtifactHidden)(history_eventst* this,int32_t artifact);
typedef int32_t (*vm_history_eventst_getArtifactHolderUnitID)(history_eventst* this,int32_t artifact);
typedef bool (*vm_history_eventst_isArtifactPossessedByUnit)(history_eventst* this,int32_t artifact,int32_t unit);
typedef void (*vm_history_eventst_associateArtifactWithUnit)(history_eventst* this);
typedef int32_t (*vm_history_eventst_getKilledHistfigID)(history_eventst* this,int32_t killer);
typedef bool (*vm_history_eventst_wasHistfigKilled)(history_eventst* this,int32_t victim);
typedef int32_t (*vm_history_eventst_getEncasedDemonHistfigID)(history_eventst* this,int32_t region);
typedef int32_t (*vm_history_eventst_getEncasedDemonRegionID)(history_eventst* this,int32_t histfig);
typedef void (*vm_history_eventst_getRelatedHistfigIDs)(history_eventst* this,void* vec);
typedef void (*vm_history_eventst_getRelatedSiteIDs)(history_eventst* this,void* vec);
typedef void (*vm_history_eventst_getRelatedArtifactIDs)(history_eventst* this,void* vec);
typedef void (*vm_history_eventst_getRelatedRegionIDs)(history_eventst* this,void* vec);
typedef void (*vm_history_eventst_getRelatedEntityIDs)(history_eventst* this,void* vec);
typedef bool (*vm_history_eventst_isRelatedToHistfigID)(history_eventst* this,int32_t histfig);
typedef bool (*vm_history_eventst_isRelatedToSiteID)(history_eventst* this,int32_t site);
typedef bool (*vm_history_eventst_isRelatedToArtifactID)(history_eventst* this,int32_t artifact);
typedef bool (*vm_history_eventst_isRelatedToRegionID)(history_eventst* this,int32_t region);
typedef bool (*vm_history_eventst_isRelatedToEntityID)(history_eventst* this,int32_t entity);
typedef void (*vm_history_eventst_getSummary)(history_eventst* this,void*,void*,int32_t ref_id,bool,bool);
typedef void (*vm_history_eventst_getDescription)(history_eventst* this,void*,void*,int32_t ref_id,bool,bool);
typedef void (*vm_history_eventst_populateArtImage)(history_eventst* this,void* image);
typedef void (*vm_history_eventst_write_file)(history_eventst* this,void*);
typedef void (*vm_history_eventst_read_file)(history_eventst* this,void*,int32_t loadversion);
typedef void (*vm_history_eventst_vmeth_112)(history_eventst* this);
struct vtable_history_eventst {
    vm_history_eventst_getType getType;
    vm_history_eventst_getWarStatus getWarStatus;
    vm_history_eventst_getAngerModifier getAngerModifier;
    vm_history_eventst_getHappinessModifier getHappinessModifier;
    vm_history_eventst_madeFirstContact madeFirstContact;
    vm_history_eventst_wasArtifactHidden wasArtifactHidden;
    vm_history_eventst_getArtifactHolderUnitID getArtifactHolderUnitID;
    vm_history_eventst_isArtifactPossessedByUnit isArtifactPossessedByUnit;
    vm_history_eventst_associateArtifactWithUnit associateArtifactWithUnit;
    vm_history_eventst_getKilledHistfigID getKilledHistfigID;
    vm_history_eventst_wasHistfigKilled wasHistfigKilled;
    vm_history_eventst_getEncasedDemonHistfigID getEncasedDemonHistfigID;
    vm_history_eventst_getEncasedDemonRegionID getEncasedDemonRegionID;
    vm_history_eventst_getRelatedHistfigIDs getRelatedHistfigIDs;
    vm_history_eventst_getRelatedSiteIDs getRelatedSiteIDs;
    vm_history_eventst_getRelatedArtifactIDs getRelatedArtifactIDs;
    vm_history_eventst_getRelatedRegionIDs getRelatedRegionIDs;
    vm_history_eventst_getRelatedEntityIDs getRelatedEntityIDs;
    vm_history_eventst_isRelatedToHistfigID isRelatedToHistfigID;
    vm_history_eventst_isRelatedToSiteID isRelatedToSiteID;
    vm_history_eventst_isRelatedToArtifactID isRelatedToArtifactID;
    vm_history_eventst_isRelatedToRegionID isRelatedToRegionID;
    vm_history_eventst_isRelatedToEntityID isRelatedToEntityID;
    vm_history_eventst_getSummary getSummary;
    vm_history_eventst_getDescription getDescription;
    vm_history_eventst_populateArtImage populateArtImage;
    vm_history_eventst_write_file write_file;
    vm_history_eventst_read_file read_file;
    vm_history_eventst_vmeth_112 vmeth_112;
};
struct history_eventst {
    struct vtable_history_eventst *vtable;
    int32_t year;
    int8_t season;
    int16_t season_ticks;
    struct df_flagarray history_event_flags;
    int32_t id;
};

struct history_event_add_hf_entity_linkst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t entity;
    int32_t ruler;
};

struct history_event_agreements_voidedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t source;
    int32_t destination;
};

struct history_event_artifact_createdst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t artifact;
    int32_t unit;
    int32_t histfig;
    int32_t site;
};

enum history_event_artifact_dropped_flags {
};

struct history_event_artifact_droppedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t artifact;
    int32_t unit;
    int32_t histfig;
    int32_t site;
    struct df_flagarray history_event_artifact_droppedst_flags;
};

struct history_event_artifact_foundst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t artifact;
    int32_t unit;
    int32_t histfig;
    int32_t site;
};

struct history_event_artifact_hiddenst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t artifact;
    int32_t unit;
    int32_t histfig;
    int32_t site;
};

struct history_event_artifact_lostst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t artifact;
    int32_t site;
};

struct history_event_artifact_possessedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t artifact;
    int32_t unit;
    int32_t histfig;
    int32_t site;
};

struct history_event_artifact_recoveredst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t artifact;
    int32_t unit;
    int32_t histfig;
    int32_t site;
};

struct history_event_contact_lostst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t civ;
    int32_t group;
    int32_t site;
};

struct history_event_created_sitest {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t civ;
    int32_t group;
    int32_t site;
};

struct history_event_demon_encasedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t demon;
    int32_t region;
};

struct history_event_demon_releasedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t demon;
    int32_t site;
};

struct history_event_diplomat_lostst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t entity;
    int32_t involved;
    int32_t site;
};

struct history_event_first_contact_failedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t source;
    int32_t destination;
    int32_t site;
};

struct history_event_first_contactst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t source;
    int32_t destination;
    int32_t site;
};

enum history_event_flags {
    history_event_flags_Hidden
};

struct history_event_hf_destroyed_sitest {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t histfig;
    int32_t civ;
    int32_t group;
    int32_t site;
};

struct history_event_hist_figure_diedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t victim;
    int32_t killer;
    int32_t site;
    int32_t region;
    int16_t death_cause;
};

enum history_event_merchant_flags {
    history_event_merchant_flags_NeverSeenAgain,
    history_event_merchant_flags_SufferedHardships,
    history_event_merchant_flags_SeizedGoods,
    history_event_merchant_flags_Offended,
    history_event_merchant_flags_MissingGoods
};

struct history_event_merchantst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t source;
    int32_t destination;
    int32_t site;
    struct df_flagarray history_event_merchantst_flags;
};

struct history_event_reclaim_sitest {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t civ;
    int32_t group;
    int32_t site;
};

struct history_event_site_abandonedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t civ;
    int32_t group;
    int32_t site;
};

struct history_event_site_diedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t civ;
    int32_t group;
    int32_t site;
};

struct history_event_topicagreement_concludedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t source;
    int32_t destination;
    int32_t site;
    int16_t topic;
    int32_t result;
};

struct history_event_topicagreement_madest {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int16_t topic;
    int32_t source;
    int32_t destination;
    int32_t site;
};

struct history_event_topicagreement_rejectedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int16_t topic;
    int32_t source;
    int32_t destination;
    int32_t site;
};

struct history_event_war_attacked_sitest {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t attacker;
    int32_t defender_civ;
    int32_t defender_group;
    int32_t site;
};

struct history_event_war_destroyed_sitest {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int32_t attacker;
    int32_t defender_civ;
    int32_t defender_group;
    int32_t site;
};

struct history_event_war_peace_acceptedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int16_t topic;
    int32_t source;
    int32_t destination;
    int32_t site;
};

struct history_event_war_peace_rejectedst {
        struct vtable_history_eventst *vtable;
        int32_t year;
        int8_t season;
        int16_t season_ticks;
        struct df_flagarray history_eventst_flags;
        int32_t id;
    int16_t topic;
    int32_t source;
    int32_t destination;
    int32_t site;
};

enum improvement_type {
    improvement_type_ART_IMAGE,
    improvement_type_COVERED,
    improvement_type_RINGS_HANGING,
    improvement_type_BANDS,
    improvement_type_SPIKES,
    improvement_type_ITEMSPECIFIC,
    improvement_type_THREAD,
    improvement_type_CLOTH,
    improvement_type_SEWN_IMAGE
};

enum T_windowed_3320 {
    T_windowed_3320_True,
    T_windowed_3320_False,
    T_windowed_3320_Prompt
};

struct init_display {
    struct df_flagarray init_display_flags;
    int32_t nickname[4];
    int32_t windowed;
    int32_t init_display_anon_1;
    int32_t fps_cap[2];
};

struct init_adventurer {
    struct df_flagarray init_adventurer_flags;
    int32_t population_cap;
};

struct init_dwarf {
    int32_t population_cap;
};

struct init_media {
    struct df_flagarray flag;
};

struct init_input {
    int32_t key_hold_ms;
    struct df_flagarray flag;
};

struct init_font {
    int32_t small_font_texpos[256];
    int32_t large_font_texpos[256];
    int32_t small_font_datapos[256];
    int32_t large_font_datapos[256];
    float small_font_adjx;
    float small_font_adjy;
    float large_font_adjx;
    float large_font_adjy;
    int32_t small_font_dispx;
    int32_t small_font_dispy;
    int32_t large_font_dispx;
    int32_t large_font_dispy;
};

struct init_game {
    struct df_flagarray init_game_flags;
};

struct init {
    struct init_display display;
    struct init_adventurer adventurer;
    struct init_dwarf dwarf;
    struct init_media media;
    struct init_input input;
    struct init_font font;
    struct init_game game;
};

enum init_adventurer_flags {
    init_adventurer_flags_MORE,
    init_adventurer_flags_ADVENTURER_TRAPS
};

enum init_display_flags {
    init_display_flags_VARIED_GROUND_TILES,
    init_display_flags_ENGRAVINGS_START_OBSCURED,
    init_display_flags_USE_GRAPHICS,
    init_display_flags_BLACK_SPACE
};

enum init_game_flags {
    init_game_flags_TEMPERATURE,
    init_game_flags_WEATHER
};

enum init_input_flags {
    init_input_flags_MOUSE_OFF,
    init_input_flags_MOUSE_PICTURE
};

enum init_media_flags {
    init_media_flags_SOUND_OFF,
    init_media_flags_INTRO_OFF
};

enum init_nickname_mode {
    init_nickname_mode_REPLACE_FIRST,
    init_nickname_mode_CENTRALIZE,
    init_nickname_mode_REPLACE_ALL
};

enum instrument_flags {
    instrument_flags_HARD_MAT
};

enum interface_breakdown_types {
    interface_breakdown_types_NONE,
    interface_breakdown_types_QUIT,
    interface_breakdown_types_STOPSCREEN,
    interface_breakdown_types_TOFIRST
};

struct interface_buttonst;
typedef void (*vm_interface_buttonst_getLabel)(interface_buttonst* this,void* str);
typedef void (*vm_interface_buttonst_click)(interface_buttonst* this);
typedef void (*vm_interface_buttonst_setColor)(interface_buttonst* this,bool selected);
typedef void (*vm_interface_buttonst_hide)(interface_buttonst* this);
typedef void (*vm_interface_buttonst_vmeth_16)(interface_buttonst* this);
struct vtable_interface_buttonst {
    vm_interface_buttonst_getLabel getLabel;
    vm_interface_buttonst_click click;
    vm_interface_buttonst_setColor setColor;
    vm_interface_buttonst_hide hide;
    vm_interface_buttonst_vmeth_16 vmeth_16;
};
struct interface_buttonst {
    struct vtable_interface_buttonst *vtable;
    int32_t hotkey_id;
    int8_t is_hidden;
};

struct interface_button_buildingst {
        struct vtable_interface_buttonst *vtable;
        int32_t hotkey_id;
        int8_t is_hidden;
    struct buildingst *building;
};

struct interface_button_building_category_selectorst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        struct buildingst *building;
    int32_t category_id;
    int8_t interface_button_building_category_selectorst_anon_1;
};

struct interface_button_building_material_selectorst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        struct buildingst *building;
    int32_t material;
    int8_t interface_button_building_material_selectorst_anon_1;
};

struct interface_button_building_new_jobst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        struct buildingst *building;
    int32_t job_type;
    struct stl_string ammo_class;
    int16_t item_subtype;
    int16_t material;
    struct item_category item_category;
};

struct interface_button_building_permit_foreign_armorst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        struct buildingst *building;
    int8_t *permit;
};

struct interface_button_building_permit_foreign_siegeammost {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        struct buildingst *building;
    int8_t *permit;
};

struct interface_button_building_permit_foreign_weaponst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        struct buildingst *building;
    int8_t *permit;
};

struct interface_button_building_permit_itemst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        struct buildingst *building;
    int32_t interface_button_building_permit_itemst_anon_1;
    int32_t item_subtype;
    int8_t *permit;
};

struct interface_button_building_permit_trapcompst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        struct buildingst *building;
    int8_t *permit;
};

struct interface_button_buttonst {
        struct vtable_interface_buttonst *vtable;
        int32_t hotkey_id;
        int8_t is_hidden;
    int8_t interface_button_buttonst_anon_1;
};

struct interface_button_button_designate_selectst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        int8_t interface_button_buttonst_anon_1;
};

struct interface_button_button_donest {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        int8_t interface_button_buttonst_anon_1;
};

struct interface_button_button_light_up_selectorst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        int8_t interface_button_buttonst_anon_1;
    struct stl_string description;
    int16_t *ui_sidebar_mode;
    int16_t new_sidebar_mode;
};

struct interface_button_constructionst {
        struct vtable_interface_buttonst *vtable;
        int32_t hotkey_id;
        int8_t is_hidden;
    void *unused_c;
};

struct interface_button_construction_building_selectorst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        void *unused_c;
    int16_t building_type;
    union {
        int16_t furnace_type;
        int16_t workshop_type;
        int16_t siegeengine_type;
        int16_t trap_type;
    } building_subtype;
};

struct interface_button_construction_category_selectorst {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        void *unused_c;
    int32_t category_id;
};

struct interface_button_construction_donest {
            struct vtable_interface_buttonst *vtable;
            int32_t hotkey_id;
            int8_t is_hidden;
        void *unused_c;
};

enum interface_key {
    interface_key_SELECT,
    interface_key_LEAVESCREEN,
    interface_key_LEAVESCREEN_TEXT,
    interface_key_OPTIONS,
    interface_key_HELP,
    interface_key_TOGGLE_FULLSCREEN,
    interface_key_MOVIES,
    interface_key_CHANGETAB,
    interface_key_STANDARDSCROLL_UP,
    interface_key_STANDARDSCROLL_DOWN,
    interface_key_STANDARDSCROLL_LEFT,
    interface_key_STANDARDSCROLL_RIGHT,
    interface_key_STANDARDSCROLL_PAGEUP,
    interface_key_STANDARDSCROLL_PAGEDOWN,
    interface_key_SECONDSCROLL_UP,
    interface_key_SECONDSCROLL_DOWN,
    interface_key_SECONDSCROLL_PAGEUP,
    interface_key_SECONDSCROLL_PAGEDOWN,
    interface_key_CURSOR_UP,
    interface_key_CURSOR_DOWN,
    interface_key_CURSOR_LEFT,
    interface_key_CURSOR_RIGHT,
    interface_key_CURSOR_UPLEFT,
    interface_key_CURSOR_UPRIGHT,
    interface_key_CURSOR_DOWNLEFT,
    interface_key_CURSOR_DOWNRIGHT,
    interface_key_CURSOR_UP_FAST,
    interface_key_CURSOR_DOWN_FAST,
    interface_key_CURSOR_LEFT_FAST,
    interface_key_CURSOR_RIGHT_FAST,
    interface_key_CURSOR_UPLEFT_FAST,
    interface_key_CURSOR_UPRIGHT_FAST,
    interface_key_CURSOR_DOWNLEFT_FAST,
    interface_key_CURSOR_DOWNRIGHT_FAST,
    interface_key_CURSOR_UP_Z,
    interface_key_CURSOR_DOWN_Z,
    interface_key_WORLDGEN_EXPORT_MAP,
    interface_key_LEGENDS_EXPORT_MAP,
    interface_key_SETUP_EMBARK,
    interface_key_ITEM_DESCRIPTION,
    interface_key_A_COMBAT_ATTACK,
    interface_key_A_COMBAT_DODGE,
    interface_key_A_COMBAT_CHARGEDEF,
    interface_key_A_STATUS,
    interface_key_A_STATUS_WRESTLE,
    interface_key_A_STATUS_CUSTOMIZE,
    interface_key_UNITVIEW_CUSTOMIZE,
    interface_key_CUSTOMIZE_UNIT_NICKNAME,
    interface_key_CUSTOMIZE_UNIT_PROFNAME,
    interface_key_A_SLEEP,
    interface_key_A_WAIT,
    interface_key_A_ATTACK,
    interface_key_A_SAMESQUARE,
    interface_key_A_LOOK,
    interface_key_A_SEARCH,
    interface_key_A_TALK,
    interface_key_A_INTERACT,
    interface_key_A_INV_LOOK,
    interface_key_A_INV_REMOVE,
    interface_key_A_INV_WEAR,
    interface_key_A_INV_EATDRINK,
    interface_key_A_INV_PUTIN,
    interface_key_A_INV_DROP,
    interface_key_A_GROUND,
    interface_key_A_THROW,
    interface_key_A_SHOOT,
    interface_key_A_ANNOUNCEMENTS,
    interface_key_A_COMBAT,
    interface_key_A_SNEAK,
    interface_key_A_CENTER,
    interface_key_A_BUILDING,
    interface_key_A_TRAVEL,
    interface_key_A_DATE,
    interface_key_A_WEATHER,
    interface_key_A_TEMPERATURE,
    interface_key_A_STANCE,
    interface_key_A_OPTION1,
    interface_key_A_OPTION2,
    interface_key_A_OPTION3,
    interface_key_A_OPTION4,
    interface_key_A_OPTION5,
    interface_key_A_OPTION6,
    interface_key_A_OPTION7,
    interface_key_A_OPTION8,
    interface_key_A_OPTION9,
    interface_key_A_OPTION10,
    interface_key_A_OPTION11,
    interface_key_A_OPTION12,
    interface_key_A_OPTION13,
    interface_key_A_OPTION14,
    interface_key_A_OPTION15,
    interface_key_A_OPTION16,
    interface_key_A_OPTION17,
    interface_key_A_OPTION18,
    interface_key_A_OPTION19,
    interface_key_A_OPTION20,
    interface_key_HOTKEY_MAKE_ASH,
    interface_key_HOTKEY_MAKE_CHARCOAL,
    interface_key_HOTKEY_SMELT_COPPER,
    interface_key_HOTKEY_SMELT_TIN,
    interface_key_HOTKEY_SMELT_BRONZE,
    interface_key_HOTKEY_SMELT_BRASS,
    interface_key_HOTKEY_SMELT_IRON,
    interface_key_HOTKEY_SMELT_PIGIRON,
    interface_key_HOTKEY_SMELT_STEEL,
    interface_key_HOTKEY_SMELT_SILVER,
    interface_key_HOTKEY_SMELT_ELECTRUM,
    interface_key_HOTKEY_SMELT_GOLD,
    interface_key_HOTKEY_SMELT_PLATINUM,
    interface_key_HOTKEY_SMELT_COAL,
    interface_key_HOTKEY_MELT_OBJECT,
    interface_key_HOTKEY_GLASS_GREEN,
    interface_key_HOTKEY_GLASS_CLEAR,
    interface_key_HOTKEY_GLASS_CRYSTAL,
    interface_key_HOTKEY_COLLECT_SAND,
    interface_key_HOTKEY_GLASS_ROUGH,
    interface_key_HOTKEY_GLASS_ARMORSTAND,
    interface_key_HOTKEY_GLASS_BOX,
    interface_key_HOTKEY_GLASS_CABINET,
    interface_key_HOTKEY_GLASS_COFFIN,
    interface_key_HOTKEY_GLASS_FLOODGATE,
    interface_key_HOTKEY_GLASS_GOBLET,
    interface_key_HOTKEY_GLASS_TOY,
    interface_key_HOTKEY_GLASS_INSTRUMENT,
    interface_key_HOTKEY_GLASS_DOOR,
    interface_key_HOTKEY_GLASS_STATUE,
    interface_key_HOTKEY_GLASS_TABLE,
    interface_key_HOTKEY_GLASS_CAGE,
    interface_key_HOTKEY_GLASS_CHAIR,
    interface_key_HOTKEY_GLASS_BLOCKS,
    interface_key_HOTKEY_GLASS_FLASK,
    interface_key_HOTKEY_GLASS_WEAPONRACK,
    interface_key_HOTKEY_GLASS_WINDOW,
    interface_key_HOTKEY_MAKE_PEARLASH,
    interface_key_HOTKEY_ASHERY_LYE,
    interface_key_HOTKEY_ASHERY_POTASH,
    interface_key_HOTKEY_ASHERY_POTASH_DIRECT,
    interface_key_HOTKEY_CARPENTER_BARREL,
    interface_key_HOTKEY_CARPENTER_BUCKET,
    interface_key_HOTKEY_CARPENTER_TRAP_ANIMAL,
    interface_key_HOTKEY_CARPENTER_CAGE,
    interface_key_HOTKEY_CARPENTER_ARMORSTAND,
    interface_key_HOTKEY_CARPENTER_BED,
    interface_key_HOTKEY_CARPENTER_CHAIR,
    interface_key_HOTKEY_CARPENTER_COFFIN,
    interface_key_HOTKEY_CARPENTER_DOOR,
    interface_key_HOTKEY_CARPENTER_FLOODGATE,
    interface_key_HOTKEY_CARPENTER_CABINET,
    interface_key_HOTKEY_CARPENTER_BIN,
    interface_key_HOTKEY_CARPENTER_BOX,
    interface_key_HOTKEY_CARPENTER_WEAPONRACK,
    interface_key_HOTKEY_CARPENTER_TABLE,
    interface_key_HOTKEY_SIEGE_BALLISTA,
    interface_key_HOTKEY_SIEGE_CATAPULT,
    interface_key_HOTKEY_LEATHER_BOX,
    interface_key_HOTKEY_LEATHER_FLASK,
    interface_key_HOTKEY_LEATHER_SHIRT,
    interface_key_HOTKEY_LEATHER_CLOAK,
    interface_key_HOTKEY_LEATHER_BACKPACK,
    interface_key_HOTKEY_LEATHER_QUIVER,
    interface_key_HOTKEY_LEATHER_IMAGE,
    interface_key_HOTKEY_CLOTHES_MAT_PLANT,
    interface_key_HOTKEY_CLOTHES_MAT_SILK,
    interface_key_HOTKEY_CLOTHES_SHIRT,
    interface_key_HOTKEY_CLOTHES_CLOAK,
    interface_key_HOTKEY_CLOTHES_BOX,
    interface_key_HOTKEY_CLOTHES_CHAIN,
    interface_key_HOTKEY_CLOTHES_IMAGE,
    interface_key_HOTKEY_CRAFTS_MAT_STONE,
    interface_key_HOTKEY_CRAFTS_MAT_STONE_L,
    interface_key_HOTKEY_CRAFTS_MAT_STONE_D,
    interface_key_HOTKEY_CRAFTS_MAT_WOOD,
    interface_key_HOTKEY_CRAFTS_DEC_BONE,
    interface_key_HOTKEY_CRAFTS_DEC_SHELL,
    interface_key_HOTKEY_CRAFTS_TOTEM,
    interface_key_HOTKEY_CRAFTS_CLOTH,
    interface_key_HOTKEY_CRAFTS_SILK,
    interface_key_HOTKEY_CRAFTS_SHELL,
    interface_key_HOTKEY_CRAFTS_BONE,
    interface_key_HOTKEY_CRAFTS_LEATHER,
    interface_key_HOTKEY_EXTRACT_ADAMANTINE,
    interface_key_HOTKEY_CRAFTS_MAT_CRAFTS,
    interface_key_HOTKEY_CRAFTS_MAT_GOBLET,
    interface_key_HOTKEY_CRAFTS_MAT_INSTRUMENT,
    interface_key_HOTKEY_CRAFTS_MAT_TOY,
    interface_key_HOTKEY_SMITH_WEAPON,
    interface_key_HOTKEY_SMITH_ARMOR,
    interface_key_HOTKEY_SMITH_FURNITURE,
    interface_key_HOTKEY_SMITH_SIEGE,
    interface_key_HOTKEY_SMITH_TRAP,
    interface_key_HOTKEY_SMITH_OTHER,
    interface_key_HOTKEY_SMITH_ADAMANTINE,
    interface_key_HOTKEY_BUILDING_ARMORSTAND,
    interface_key_HOTKEY_BUILDING_BED,
    interface_key_HOTKEY_BUILDING_CHAIR,
    interface_key_HOTKEY_BUILDING_COFFIN,
    interface_key_HOTKEY_BUILDING_DOOR,
    interface_key_HOTKEY_BUILDING_FLOODGATE,
    interface_key_HOTKEY_BUILDING_CABINET,
    interface_key_HOTKEY_BUILDING_BOX,
    interface_key_HOTKEY_BUILDING_KENNEL,
    interface_key_HOTKEY_BUILDING_FARMPLOT,
    interface_key_HOTKEY_BUILDING_WEAPONRACK,
    interface_key_HOTKEY_BUILDING_STATUE,
    interface_key_HOTKEY_BUILDING_TABLE,
    interface_key_HOTKEY_BUILDING_ROAD,
    interface_key_HOTKEY_BUILDING_CHANNEL,
    interface_key_HOTKEY_BUILDING_BRIDGE,
    interface_key_HOTKEY_BUILDING_AQUEDUCT,
    interface_key_HOTKEY_BUILDING_WELL,
    interface_key_HOTKEY_BUILDING_SIEGEENGINE,
    interface_key_HOTKEY_BUILDING_WORKSHOP,
    interface_key_HOTKEY_BUILDING_FURNACE,
    interface_key_HOTKEY_BUILDING_WINDOW,
    interface_key_HOTKEY_BUILDING_SHOP,
    interface_key_HOTKEY_BUILDING_ANIMALTRAP,
    interface_key_HOTKEY_BUILDING_CHAIN,
    interface_key_HOTKEY_BUILDING_CAGE,
    interface_key_HOTKEY_BUILDING_SIEGEENGINE_BALLISTA,
    interface_key_HOTKEY_BUILDING_SIEGEENGINE_CATAPULT,
    interface_key_HOTKEY_BUILDING_TRAP_STONE,
    interface_key_HOTKEY_BUILDING_TRAP_WEAPON,
    interface_key_HOTKEY_BUILDING_TRAP_LEVER,
    interface_key_HOTKEY_BUILDING_TRAP_TRIGGER,
    interface_key_HOTKEY_BUILDING_TRAP_CAGE,
    interface_key_HOTKEY_BUILDING_WORKSHOP_LEATHER,
    interface_key_HOTKEY_BUILDING_WORKSHOP_MILL,
    interface_key_HOTKEY_BUILDING_WORKSHOP_LOOM,
    interface_key_HOTKEY_BUILDING_WORKSHOP_CLOTHES,
    interface_key_HOTKEY_BUILDING_WORKSHOP_BOWYER,
    interface_key_HOTKEY_BUILDING_WORKSHOP_CARPENTER,
    interface_key_HOTKEY_BUILDING_WORKSHOP_METALSMITH,
    interface_key_HOTKEY_BUILDING_WORKSHOP_LAVAMILL,
    interface_key_HOTKEY_BUILDING_WORKSHOP_JEWELER,
    interface_key_HOTKEY_BUILDING_WORKSHOP_MASON,
    interface_key_HOTKEY_BUILDING_WORKSHOP_BUTCHER,
    interface_key_HOTKEY_BUILDING_WORKSHOP_TANNER,
    interface_key_HOTKEY_BUILDING_WORKSHOP_DYER,
    interface_key_HOTKEY_BUILDING_WORKSHOP_CRAFTSMAN,
    interface_key_HOTKEY_BUILDING_WORKSHOP_SIEGE,
    interface_key_HOTKEY_BUILDING_WORKSHOP_MECHANIC,
    interface_key_HOTKEY_BUILDING_WORKSHOP_STILL,
    interface_key_HOTKEY_BUILDING_WORKSHOP_FARMER,
    interface_key_HOTKEY_BUILDING_WORKSHOP_KITCHEN,
    interface_key_HOTKEY_BUILDING_WORKSHOP_FISHERY,
    interface_key_HOTKEY_BUILDING_WORKSHOP_LAB,
    interface_key_HOTKEY_BUILDING_WORKSHOP_ASHERY,
    interface_key_HOTKEY_BUILDING_FURNACE_WOOD,
    interface_key_HOTKEY_BUILDING_FURNACE_SMELTER,
    interface_key_HOTKEY_BUILDING_FURNACE_GLASS,
    interface_key_HOTKEY_BUILDING_FURNACE_KILN,
    interface_key_HOTKEY_BUILDING_FURNACE_SMELTER_LAVA,
    interface_key_HOTKEY_BUILDING_FURNACE_GLASS_LAVA,
    interface_key_HOTKEY_BUILDING_FURNACE_KILN_LAVA,
    interface_key_D_ONESTEP,
    interface_key_D_PAUSE,
    interface_key_D_GATE,
    interface_key_D_ANNOUNCE,
    interface_key_D_BUILDING,
    interface_key_D_CIVLIST,
    interface_key_D_DESIGNATE,
    interface_key_D_ARTLIST,
    interface_key_D_NOBLES,
    interface_key_D_ORDERS,
    interface_key_D_MILITARY,
    interface_key_D_ROOMS,
    interface_key_D_SQUADS,
    interface_key_D_STOCKPILES,
    interface_key_D_VIEWUNIT,
    interface_key_D_JOBLIST,
    interface_key_D_UNITLIST,
    interface_key_D_LOOK,
    interface_key_D_BUILDJOB,
    interface_key_D_STATUS,
    interface_key_D_BUILDITEM,
    interface_key_A_ENTER_NAME,
    interface_key_A_END_TRAVEL,
    interface_key_A_TRAVEL_CLOUDS,
    interface_key_A_LOG,
    interface_key_A_TRAVEL_LOG,
    interface_key_A_LOG_TASKS,
    interface_key_A_LOG_ENTITIES,
    interface_key_A_LOG_SITES,
    interface_key_A_LOG_SUBREGIONS,
    interface_key_A_LOG_ZOOM_CURRENT_LOCATION,
    interface_key_A_LOG_ZOOM_SELECTED,
    interface_key_A_LOG_LINE,
    interface_key_A_LOG_MAP,
    interface_key_ORDERS_REFUSE_GATHER,
    interface_key_ORDERS_REFUSE_OUTSIDE,
    interface_key_ORDERS_REFUSE_CHASM_CORPSE,
    interface_key_ORDERS_REFUSE_CHASM_SKULL,
    interface_key_ORDERS_REFUSE_CHASM_BONE,
    interface_key_ORDERS_REFUSE_CHASM_SHELL,
    interface_key_ORDERS_REFUSE_CHASM_SKIN,
    interface_key_ORDERS_REFUSE_CHASM_OTHER,
    interface_key_ORDERS_GATHER_FURNITURE,
    interface_key_ORDERS_GATHER_ANIMALS,
    interface_key_ORDERS_GATHER_FOOD,
    interface_key_ORDERS_GATHER_BODIES,
    interface_key_ORDERS_REFUSE,
    interface_key_ORDERS_GATHER_STONE,
    interface_key_ORDERS_GATHER_WOOD,
    interface_key_ORDERS_ALL_HARVEST,
    interface_key_ORDERS_INDOORS,
    interface_key_ORDERS_SAMEPILE,
    interface_key_ORDERS_MIXFOODS,
    interface_key_ORDERS_LOOM,
    interface_key_ORDERS_DYED_CLOTH,
    interface_key_ORDERS_EXCEPTIONS,
    interface_key_ORDERS_WORKSHOP,
    interface_key_ORDERS_COLLECT_WEB,
    interface_key_ORDERS_SLAUGHTER,
    interface_key_ORDERS_BUTCHER,
    interface_key_ORDERS_TAN,
    interface_key_DESTROYBUILDING,
    interface_key_SUSPENDBUILDING,
    interface_key_MENU_CONFIRM,
    interface_key_SAVE_BINDINGS,
    interface_key_CHANGE_BINDINGS,
    interface_key_HOTKEY_ALCHEMIST_SOAP,
    interface_key_HOTKEY_STILL_BREW,
    interface_key_HOTKEY_STILL_EXTRACT,
    interface_key_HOTKEY_LOOM_COLLECT_SILK,
    interface_key_HOTKEY_LOOM_WEAVE_CLOTH,
    interface_key_HOTKEY_LOOM_WEAVE_SILK,
    interface_key_HOTKEY_LOOM_WEAVE_ADAMANTINE,
    interface_key_HOTKEY_KITCHEN_COOK_2,
    interface_key_HOTKEY_KITCHEN_COOK_3,
    interface_key_HOTKEY_KITCHEN_COOK_4,
    interface_key_HOTKEY_KITCHEN_RENDER_FAT,
    interface_key_HOTKEY_FARMER_PROCESS,
    interface_key_HOTKEY_FARMER_PROCESS_VIAL,
    interface_key_HOTKEY_FARMER_PROCESS_BAG,
    interface_key_HOTKEY_FARMER_PROCESS_BARREL,
    interface_key_HOTKEY_FARMER_CHEESE,
    interface_key_HOTKEY_FARMER_MILK,
    interface_key_HOTKEY_MILL_MILL,
    interface_key_HOTKEY_KENNEL_TRAIN_HUNT,
    interface_key_HOTKEY_KENNEL_CATCH_VERMIN,
    interface_key_HOTKEY_KENNEL_TAME_VERMIN,
    interface_key_HOTKEY_KENNEL_TAME_UNIT,
    interface_key_HOTKEY_KENNEL_TRAIN_WAR,
    interface_key_HOTKEY_FISHERY_PROCESS,
    interface_key_HOTKEY_FISHERY_EXTRACT,
    interface_key_HOTKEY_FISHERY_CATCH,
    interface_key_HOTKEY_BUTCHER_BUTCHER,
    interface_key_HOTKEY_BUTCHER_EXTRACT,
    interface_key_HOTKEY_BUTCHER_CATCH,
    interface_key_HOTKEY_TANNER_TAN,
    interface_key_HOTKEY_DYER_THREAD,
    interface_key_HOTKEY_DYER_CLOTH,
    interface_key_HOTKEY_JEWELER_FURNITURE,
    interface_key_HOTKEY_JEWELER_FINISHED,
    interface_key_HOTKEY_JEWELER_AMMO,
    interface_key_HOTKEY_JEWELER_CUT,
    interface_key_HOTKEY_JEWELER_ENCRUST,
    interface_key_HOTKEY_MECHANIC_PARTS,
    interface_key_HOTKEY_MASON_MAT_GRAY,
    interface_key_HOTKEY_MASON_MAT_LIGHT,
    interface_key_HOTKEY_MASON_MAT_DARK,
    interface_key_HOTKEY_MASON_ARMORSTAND,
    interface_key_HOTKEY_MASON_BLOCKS,
    interface_key_HOTKEY_MASON_CHAIR,
    interface_key_HOTKEY_MASON_COFFIN,
    interface_key_HOTKEY_MASON_DOOR,
    interface_key_HOTKEY_MASON_FLOODGATE,
    interface_key_HOTKEY_MASON_CABINET,
    interface_key_HOTKEY_MASON_BOX,
    interface_key_HOTKEY_MASON_STATUE,
    interface_key_HOTKEY_MASON_TABLE,
    interface_key_HOTKEY_MASON_WEAPONRACK,
    interface_key_HOTKEY_TRAP_BRIDGE,
    interface_key_HOTKEY_TRAP_DOOR,
    interface_key_HOTKEY_TRAP_FLOODGATE,
    interface_key_HOTKEY_TRAP_SUPPORT,
    interface_key_HOTKEY_TRAP_CHAIN,
    interface_key_HOTKEY_TRAP_CAGE,
    interface_key_HOTKEY_TRAP_PULL_LEVER,
    interface_key_HOTKEY_TRAP_TRIGGERTEMP,
    interface_key_BUILDJOB_ADD,
    interface_key_BUILDJOB_CANCEL,
    interface_key_BUILDJOB_PROMOTE,
    interface_key_BUILDJOB_REPEAT,
    interface_key_BUILDJOB_SUSPEND,
    interface_key_BUILDJOB_WORKSHOP_PROFILE,
    interface_key_BUILDJOB_WELL_FREE,
    interface_key_BUILDJOB_WELL_SIZE,
    interface_key_BUILDJOB_TARGET_FREE,
    interface_key_BUILDJOB_TARGET_SIZE,
    interface_key_BUILDJOB_TARGET_DOWN,
    interface_key_BUILDJOB_TARGET_UP,
    interface_key_BUILDJOB_TARGET_RIGHT,
    interface_key_BUILDJOB_TARGET_LEFT,
    interface_key_BUILDJOB_STATUE_ASSIGN,
    interface_key_BUILDJOB_STATUE_FREE,
    interface_key_BUILDJOB_STATUE_SIZE,
    interface_key_BUILDJOB_CAGE_JUSTICE,
    interface_key_BUILDJOB_CAGE_FREE,
    interface_key_BUILDJOB_CAGE_SIZE,
    interface_key_BUILDJOB_CAGE_ASSIGN_OCC,
    interface_key_BUILDJOB_CAGE_WATER,
    interface_key_BUILDJOB_CAGE_ASSIGN,
    interface_key_BUILDJOB_CHAIN_ASSIGN_OCC,
    interface_key_BUILDJOB_CHAIN_JUSTICE,
    interface_key_BUILDJOB_CHAIN_ASSIGN,
    interface_key_BUILDJOB_CHAIN_FREE,
    interface_key_BUILDJOB_CHAIN_SIZE,
    interface_key_BUILDJOB_SIEGE_FIRING,
    interface_key_BUILDJOB_SIEGE_ORIENT,
    interface_key_BUILDJOB_CHANNEL_ASSIGN_OCC,
    interface_key_BUILDJOB_CHANNEL_WATER,
    interface_key_BUILDJOB_DOOR_INTERNAL,
    interface_key_BUILDJOB_DOOR_LOCK,
    interface_key_BUILDJOB_DOOR_AJAR,
    interface_key_BUILDJOB_COFFIN_ASSIGN,
    interface_key_BUILDJOB_COFFIN_FREE,
    interface_key_BUILDJOB_COFFIN_SIZE,
    interface_key_BUILDJOB_COFFIN_BURIAL,
    interface_key_BUILDJOB_COFFIN_CIV,
    interface_key_BUILDJOB_COFFIN_PET,
    interface_key_BUILDJOB_CHAIR_ASSIGN,
    interface_key_BUILDJOB_CHAIR_FREE,
    interface_key_BUILDJOB_CHAIR_SIZE,
    interface_key_BUILDJOB_TABLE_ASSIGN,
    interface_key_BUILDJOB_TABLE_HALL,
    interface_key_BUILDJOB_TABLE_FREE,
    interface_key_BUILDJOB_TABLE_SIZE,
    interface_key_BUILDJOB_BED_ASSIGN,
    interface_key_BUILDJOB_BED_FREE,
    interface_key_BUILDJOB_BED_BARRACKS,
    interface_key_BUILDJOB_BED_RENT,
    interface_key_BUILDJOB_BED_SIZE,
    interface_key_BUILDJOB_DEPOT_BRING,
    interface_key_BUILDJOB_DEPOT_TRADE,
    interface_key_BUILDJOB_ANIMALTRAP_BAIT_NONE,
    interface_key_BUILDJOB_ANIMALTRAP_BAIT_MEAT,
    interface_key_BUILDJOB_ANIMALTRAP_BAIT_FISH,
    interface_key_BUILDJOB_ANIMALTRAP_BAIT_GEM,
    interface_key_BUILDJOB_FARM_FALLOW,
    interface_key_BUILDJOB_FARM_FERTILIZE,
    interface_key_BUILDJOB_FARM_SEASFERT,
    interface_key_BUILDJOB_FARM_SPRING,
    interface_key_BUILDJOB_FARM_SUMMER,
    interface_key_BUILDJOB_FARM_AUTUMN,
    interface_key_BUILDJOB_STOCKPILE_MASTER,
    interface_key_BUILDJOB_STOCKPILE_DELETE_CHILD,
    interface_key_BUILDJOB_STOCKPILE_SETTINGS,
    interface_key_BUILDJOB_STOCKPILE_BARREL_UP,
    interface_key_BUILDJOB_STOCKPILE_BARREL_DOWN,
    interface_key_BUILDJOB_STOCKPILE_BARREL_ZERO,
    interface_key_BUILDJOB_STOCKPILE_BARREL_MAX,
    interface_key_BUILDJOB_STOCKPILE_BIN_UP,
    interface_key_BUILDJOB_STOCKPILE_BIN_DOWN,
    interface_key_BUILDJOB_STOCKPILE_BIN_ZERO,
    interface_key_BUILDJOB_STOCKPILE_BIN_MAX,
    interface_key_BUILDJOB_RACK_MAT_BONE,
    interface_key_BUILDJOB_RACK_MAT_BRONZE,
    interface_key_BUILDJOB_RACK_MAT_COPPER,
    interface_key_BUILDJOB_RACK_MAT_IRON,
    interface_key_BUILDJOB_RACK_MAT_STEEL,
    interface_key_BUILDJOB_RACK_MAT_WOOD,
    interface_key_BUILDJOB_RACK_MAT_ADAMANTINE,
    interface_key_BUILDJOB_STAND_MAT_BONE,
    interface_key_BUILDJOB_STAND_MAT_LEATHER,
    interface_key_BUILDJOB_STAND_MAT_COPPER,
    interface_key_BUILDJOB_STAND_MAT_BRONZE,
    interface_key_BUILDJOB_STAND_MAT_STEEL,
    interface_key_BUILDJOB_STAND_MAT_IRON,
    interface_key_BUILDJOB_STAND_MAT_WOOD,
    interface_key_BUILDJOB_STAND_MAT_ADAMANTINE,
    interface_key_BUILDJOB_RACKSTAND_ASSIGN,
    interface_key_BUILDJOB_RACKSTAND_FREE,
    interface_key_BUILDJOB_RACKSTAND_SIZE,
    interface_key_BUILDJOB_RACKSTAND_ITEM,
    interface_key_BUILDJOB_RACKSTAND_MAT,
    interface_key_BUILDJOB_RACKSTAND_DEFAULTS1,
    interface_key_BUILDJOB_RACKSTAND_KILL1,
    interface_key_BUILDJOB_RACKSTAND_DEFAULTS2,
    interface_key_BUILDJOB_RACKSTAND_KILL2,
    interface_key_STOCKPILE_SETTINGS_ENABLE,
    interface_key_STOCKPILE_SETTINGS_DISABLE,
    interface_key_STOCKPILE_SETTINGS_PERMIT_ALL,
    interface_key_STOCKPILE_SETTINGS_FORBID_ALL,
    interface_key_STOCKPILE_SETTINGS_PERMIT_SUB,
    interface_key_STOCKPILE_SETTINGS_FORBID_SUB,
    interface_key_STOCKPILE_SETTINGS_SPECIFIC1,
    interface_key_STOCKPILE_SETTINGS_SPECIFIC2,
    interface_key_SQUAD_LOCK,
    interface_key_SQUAD_STATION,
    interface_key_SQUAD_CLEAR_PATROL,
    interface_key_SQUAD_PATROL,
    interface_key_SQUAD_ZOOM,
    interface_key_MOVIE_RECORD,
    interface_key_MOVIE_PLAY,
    interface_key_MOVIE_SAVE,
    interface_key_MOVIE_LOAD,
    interface_key_ASSIGNTRADE_VIEW,
    interface_key_A_BARTER_VIEW,
    interface_key_A_BARTER_CURRENCY_1,
    interface_key_A_BARTER_CURRENCY_2,
    interface_key_A_BARTER_CURRENCY_3,
    interface_key_A_BARTER_CURRENCY_4,
    interface_key_A_BARTER_CURRENCY_5,
    interface_key_A_BARTER_CURRENCY_6,
    interface_key_A_BARTER_CURRENCY_7,
    interface_key_A_BARTER_CURRENCY_8,
    interface_key_A_BARTER_CURRENCY_9,
    interface_key_A_BARTER_TRADE,
    interface_key_TRADE_VIEW,
    interface_key_TRADE_TRADE,
    interface_key_TRADE_OFFER,
    interface_key_TRADE_SEIZE,
    interface_key_STORES_VIEW,
    interface_key_STORES_ZOOM,
    interface_key_STORES_MELT,
    interface_key_STORES_CHASM,
    interface_key_MILITARY_ACTIVATE,
    interface_key_MILITARY_VIEW,
    interface_key_MILITARY_WEAPON,
    interface_key_SQUADINFO_FOOD,
    interface_key_SQUADINFO_SLEEP,
    interface_key_SQUADINFO_WATER,
    interface_key_SQUADINFO_STAYCLOSE,
    interface_key_SQUADINFO_ATTACKWILDS,
    interface_key_SQUADINFO_STANDDOWN,
    interface_key_SQUADINFO_ZOOM,
    interface_key_UNITJOB_REMOVE_CRE,
    interface_key_UNITJOB_ZOOM_CRE,
    interface_key_UNITJOB_ZOOM_BUILD,
    interface_key_UNITJOB_VIEW,
    interface_key_UNITJOB_MANAGER,
    interface_key_MANAGER_NEW_ORDER,
    interface_key_MANAGER_REMOVE,
    interface_key_MANAGER_PROMOTE,
    interface_key_MANAGER_MAX,
    interface_key_MANAGER_WAGES,
    interface_key_PET_BUTCHER,
    interface_key_KITCHEN_COOK,
    interface_key_KITCHEN_BREW,
    interface_key_SETUPGAME_NEW,
    interface_key_SETUPGAME_VIEW,
    interface_key_STOCKPILE_ANIMAL,
    interface_key_STOCKPILE_FOOD,
    interface_key_STOCKPILE_WEAPON,
    interface_key_STOCKPILE_ARMOR,
    interface_key_STOCKPILE_CUSTOM,
    interface_key_STOCKPILE_CUSTOM_SETTINGS,
    interface_key_STOCKPILE_FURNITURE,
    interface_key_STOCKPILE_GRAVEYARD,
    interface_key_STOCKPILE_REFUSE,
    interface_key_STOCKPILE_MINING,
    interface_key_STOCKPILE_WOOD,
    interface_key_STOCKPILE_STONE,
    interface_key_STOCKPILE_ORE,
    interface_key_STOCKPILE_GEM,
    interface_key_STOCKPILE_BARBLOCK,
    interface_key_STOCKPILE_CLOTH,
    interface_key_STOCKPILE_LEATHER,
    interface_key_STOCKPILE_AMMO,
    interface_key_STOCKPILE_COINS,
    interface_key_STOCKPILE_FINISHED,
    interface_key_STOCKPILE_NONE,
    interface_key_DESIGNATE_CLAIM,
    interface_key_DESIGNATE_DIG,
    interface_key_DESIGNATE_CHOP,
    interface_key_DESIGNATE_PLANTS,
    interface_key_DESIGNATE_DETAIL,
    interface_key_DESIGNATE_FORTIFY,
    interface_key_DESIGNATE_TOGGLE_ENGRAVING,
    interface_key_DESIGNATE_UNDO,
    interface_key_BUILDING_DIM_Y_UP,
    interface_key_BUILDING_DIM_Y_DOWN,
    interface_key_BUILDING_DIM_X_UP,
    interface_key_BUILDING_DIM_X_DOWN,
    interface_key_BUILDING_ORIENT_UP,
    interface_key_BUILDING_ORIENT_LEFT,
    interface_key_BUILDING_ORIENT_RIGHT,
    interface_key_BUILDING_ORIENT_DOWN,
    interface_key_BUILDING_ORIENT_NONE,
    interface_key_BUILDING_VIEW_ITEM,
    interface_key_BUILDING_PLACE,
    interface_key_UNITVIEW_GEN,
    interface_key_UNITVIEW_INV,
    interface_key_UNITVIEW_PRF,
    interface_key_UNITVIEW_WND,
    interface_key_UNITVIEW_NEXT,
    interface_key_UNITVIEW_SLAUGHTER,
    interface_key_UNITVIEW_PRF_PROF,
    interface_key_UNITVIEW_PRF_PET,
    interface_key_UNITVIEW_PRF_SOLDIER,
    interface_key_UNITVIEW_PRF_CASTLE,
    interface_key_UNITVIEW_PRF_ROYAL,
    interface_key_UNITVIEW_PRF_TOGGLESQUAD,
    interface_key_UNITVIEW_PRF_PET_HUNT,
    interface_key_UNITVIEW_PRF_PET_WAR,
    interface_key_UNITVIEW_PRF_SOLDIER_UNARMED,
    interface_key_UNITVIEW_PRF_SOLDIER_AXE,
    interface_key_UNITVIEW_PRF_SOLDIER_CROSSBOW,
    interface_key_UNITVIEW_PRF_SOLDIER_HAMMER,
    interface_key_UNITVIEW_PRF_SOLDIER_MACE,
    interface_key_UNITVIEW_PRF_SOLDIER_SPEAR,
    interface_key_UNITVIEW_PRF_SOLDIER_SWORD,
    interface_key_UNITVIEW_PRF_SOLDIER_WEAPONNUM,
    interface_key_UNITVIEW_PRF_SOLDIER_ARMOR,
    interface_key_UNITVIEW_PRF_SOLDIER_SHIELD,
    interface_key_UNITVIEW_PRF_VIEW,
    interface_key_STRING_A,
    interface_key_STRING_B,
    interface_key_STRING_C,
    interface_key_STRING_D,
    interface_key_STRING_E,
    interface_key_STRING_F,
    interface_key_STRING_G,
    interface_key_STRING_H,
    interface_key_STRING_I,
    interface_key_STRING_J,
    interface_key_STRING_K,
    interface_key_STRING_L,
    interface_key_STRING_M,
    interface_key_STRING_N,
    interface_key_STRING_O,
    interface_key_STRING_P,
    interface_key_STRING_Q,
    interface_key_STRING_R,
    interface_key_STRING_S,
    interface_key_STRING_T,
    interface_key_STRING_U,
    interface_key_STRING_V,
    interface_key_STRING_W,
    interface_key_STRING_X,
    interface_key_STRING_Y,
    interface_key_STRING_Z,
    interface_key_STRING_A_CAP,
    interface_key_STRING_B_CAP,
    interface_key_STRING_C_CAP,
    interface_key_STRING_D_CAP,
    interface_key_STRING_E_CAP,
    interface_key_STRING_F_CAP,
    interface_key_STRING_G_CAP,
    interface_key_STRING_H_CAP,
    interface_key_STRING_I_CAP,
    interface_key_STRING_J_CAP,
    interface_key_STRING_K_CAP,
    interface_key_STRING_L_CAP,
    interface_key_STRING_M_CAP,
    interface_key_STRING_N_CAP,
    interface_key_STRING_O_CAP,
    interface_key_STRING_P_CAP,
    interface_key_STRING_Q_CAP,
    interface_key_STRING_R_CAP,
    interface_key_STRING_S_CAP,
    interface_key_STRING_T_CAP,
    interface_key_STRING_U_CAP,
    interface_key_STRING_V_CAP,
    interface_key_STRING_W_CAP,
    interface_key_STRING_X_CAP,
    interface_key_STRING_Y_CAP,
    interface_key_STRING_Z_CAP,
    interface_key_STRING_SPACE,
    interface_key_STRING_BACKSPACE
};

enum T_flags_131_enum {
    T_flags_131_continuation=0x01,
    T_flags_131_unconscious=0x02
};

struct report {
    char text[90];
    int16_t color;
    int8_t bright;
    int32_t duration;
    struct T_flags_131 {
        uint16_t bitfield;
    } report_flags;
    int32_t repeat_count;
};

struct stl_vector_ptr_report {
struct report **ptr;
void *endptr;
void *endalloc;
};
struct viewscreenst;
typedef void (*vm_viewscreenst_view)(viewscreenst* this);
typedef void (*vm_viewscreenst_help)(viewscreenst* this);
typedef int8_t (*vm_viewscreenst_movies_okay)(viewscreenst* this);
typedef int8_t (*vm_viewscreenst_is_option_screen)(viewscreenst* this);
typedef int8_t (*vm_viewscreenst_is_save_screen)(viewscreenst* this);
typedef void (*vm_viewscreenst_vmeth_20)(viewscreenst* this);
struct vtable_viewscreenst {
    vm_viewscreenst_view view;
    vm_viewscreenst_help help;
    vm_viewscreenst_movies_okay movies_okay;
    vm_viewscreenst_is_option_screen is_option_screen;
    vm_viewscreenst_is_save_screen is_save_screen;
    vm_viewscreenst_vmeth_20 vmeth_20;
};
struct viewscreenst {
    struct vtable_viewscreenst *vtable;
    struct viewscreenst *child;
    struct viewscreenst *parent;
    int8_t breakdown_level;
    int8_t option_key_pressed;
};

struct interfacest {
    struct T_announcements_14396 {
        struct stl_vector_ptr_report reports;
        int32_t report_timer;
    } announcements;
    uint8_t current_key;
    int8_t current_shift;
    int8_t interfacest_anon_1;
    int8_t interfacest_anon_2;
    struct T_keyNames_14406 {
        struct stl_string normal;
        struct stl_string shift;
    } keyNames[256];
    struct viewscreenst view;
    int32_t interfacest_anon_3;
    struct stl_vector_ptr interfacest_anon_4;
    struct stl_vector_ptr interfacest_anon_5;
    struct stl_vector_ptr interfacest_anon_6;
    int32_t interfacest_anon_7;
    struct T_keybinds_14422 {
        struct stl_string description;
        struct stl_string token;
        uint8_t key;
        int32_t anon_1;
        int8_t anon_2;
        int8_t is_shift;
    } keybinds[661];
    int8_t interfacest_anon_8[256];
    int8_t supermovie_on;
    int32_t supermovie_pos;
    int32_t supermovie_delayrate;
    int32_t supermovie_delaystep;
    struct stl_vector_strptr supermovie_sound;
    int32_t supermovie_sound_time[16][200];
    int8_t supermoviebuffer[800000];
    int8_t supermoviebuffer_comp[1000000];
    int32_t currentblocksize;
    int32_t nextfilepos;
    int8_t first_movie_write;
    struct stl_string movie_file;
};

struct itemst;
typedef item_type (*vm_itemst_getType)(itemst* this);
typedef int16_t (*vm_itemst_getSubtype)(itemst* this);
typedef material_type (*vm_itemst_getMaterial)(itemst* this);
typedef int16_t (*vm_itemst_getMatgloss)(itemst* this);
typedef void (*vm_itemst_setSubtype)(itemst* this,int16_t);
typedef void (*vm_itemst_setMaterial)(itemst* this,material_type material);
typedef void (*vm_itemst_setMatgloss)(itemst* this,int16_t);
typedef material_type (*vm_itemst_getActualMaterial)(itemst* this);
typedef int16_t (*vm_itemst_getActualMatgloss)(itemst* this);
typedef int16_t (*vm_itemst_getRace)(itemst* this);
typedef void (*vm_itemst_clearLastTempUpdateTS)(itemst* this);
typedef uint16_t (*vm_itemst_getSpecHeat)(itemst* this);
typedef uint16_t (*vm_itemst_getIgnitePoint)(itemst* this);
typedef uint16_t (*vm_itemst_getHeatdamPoint)(itemst* this);
typedef uint16_t (*vm_itemst_getColddamPoint)(itemst* this);
typedef uint16_t (*vm_itemst_getBoilingPoint)(itemst* this);
typedef uint16_t (*vm_itemst_getMeltingPoint)(itemst* this);
typedef uint16_t (*vm_itemst_getFixedTemp)(itemst* this);
typedef uint16_t (*vm_itemst_getTemperature)(itemst* this);
typedef bool (*vm_itemst_adjustTemperature)(itemst* this,uint16_t target);
typedef void (*vm_itemst_extinguish)(itemst* this);
typedef int8_t (*vm_itemst_getGloveHandedness)(itemst* this);
typedef void (*vm_itemst_setGloveHandedness)(itemst* this,int8_t);
typedef void (*vm_itemst_pickRandomSubtype)(itemst* this,int32_t entity_id);
typedef int32_t (*vm_itemst_getWeaponSize)(itemst* this);
typedef int16_t (*vm_itemst_getWear)(itemst* this);
typedef void (*vm_itemst_setWear)(itemst* this,int16_t);
typedef int32_t (*vm_itemst_getMaker)(itemst* this);
typedef void (*vm_itemst_setMaker)(itemst* this,int32_t unit_id);
typedef int16_t (*vm_itemst_getCorpseRace)(itemst* this);
typedef void (*vm_itemst_getCorpseInfo)(itemst* this,void* race,void* histfig,void* unit);
typedef void* (*vm_itemst_getGloveFlags)(itemst* this);
typedef void (*vm_itemst_setSeedsPlantSkill)(itemst* this,int32_t level);
typedef void (*vm_itemst_ageItem)(itemst* this,int32_t amount);
typedef int32_t (*vm_itemst_getCritterAirdrownTimer)(itemst* this);
typedef void (*vm_itemst_setCritterAirdrownTimer)(itemst* this,int32_t);
typedef void (*vm_itemst_incrementCritterAirdrownTimer)(itemst* this);
typedef int32_t (*vm_itemst_getRotTimer)(itemst* this);
typedef void (*vm_itemst_setRotTimer)(itemst* this,int32_t val);
typedef void (*vm_itemst_incrementRotTimer)(itemst* this);
typedef void* (*vm_itemst_getAmmoType)(itemst* this,void*);
typedef int16_t (*vm_itemst_getDamageType)(itemst* this);
typedef bool (*vm_itemst_isLiquipowder)(itemst* this);
typedef bool (*vm_itemst_isLiquid)(itemst* this);
typedef bool (*vm_itemst_isCritter1)(itemst* this);
typedef int16_t (*vm_itemst_getStickChance)(itemst* this);
typedef void (*vm_itemst_addImprovementFromJob)(itemst* this,void* job,void* unit,int32_t material,int32_t matgloss,void* entity,void* site);
typedef bool (*vm_itemst_isWeapon)(itemst* this);
typedef bool (*vm_itemst_isArmorNotClothing)(itemst* this);
typedef bool (*vm_itemst_canStoreInWeaponRack)(itemst* this);
typedef bool (*vm_itemst_canStoreInArmorStand)(itemst* this);
typedef bool (*vm_itemst_isMillable)(itemst* this);
typedef bool (*vm_itemst_isProcessableThread)(itemst* this);
typedef bool (*vm_itemst_isProcessableVial)(itemst* this);
typedef bool (*vm_itemst_isProcessableBag)(itemst* this);
typedef bool (*vm_itemst_isProcessableBarrel)(itemst* this);
typedef bool (*vm_itemst_isEdible)(itemst* this);
typedef bool (*vm_itemst_isEdibleRaw)(itemst* this);
typedef bool (*vm_itemst_isEdibleCarnivore)(itemst* this);
typedef bool (*vm_itemst_isEdibleBonecarn)(itemst* this);
typedef bool (*vm_itemst_moveToGround)(itemst* this,int32_t x,int32_t y,int32_t z);
typedef bool (*vm_itemst_isFat)(itemst* this);
typedef bool (*vm_itemst_isAnimal)(itemst* this);
typedef void (*vm_itemst_assignQuality)(itemst* this,void* maker,void* job);
typedef void (*vm_itemst_notifyLostMasterwork)(itemst* this);
typedef void (*vm_itemst_addMagic)(itemst* this,int32_t type,int32_t data,int32_t value);
typedef void (*vm_itemst_magic_unk1)(itemst* this,int32_t,int32_t);
typedef void (*vm_itemst_magic_unk2)(itemst* this,int32_t,int32_t);
typedef void (*vm_itemst_magic_unk3)(itemst* this,int32_t);
typedef void (*vm_itemst_magic_unk4)(itemst* this,int32_t,int32_t,int32_t);
typedef void (*vm_itemst_setDisplayColor)(itemst* this,int16_t bgcolor);
typedef bool (*vm_itemst_isDamagedByHeat)(itemst* this);
typedef bool (*vm_itemst_needTwoHandedWield)(itemst* this,int32_t size);
typedef void* (*vm_itemst_splitStack)(itemst* this,int32_t stack_size,bool preserve_containment);
typedef bool (*vm_itemst_isTameableVermin)(itemst* this);
typedef bool (*vm_itemst_isDistillable)(itemst* this,bool checkKitchenSettings);
typedef bool (*vm_itemst_isDye)(itemst* this);
typedef bool (*vm_itemst_isMilkable)(itemst* this,bool check_contents,bool check_kitchen);
typedef bool (*vm_itemst_isSandBearing)(itemst* this);
typedef bool (*vm_itemst_isLyeBearing)(itemst* this);
typedef bool (*vm_itemst_isAnimalProduct)(itemst* this);
typedef void (*vm_itemst_getStorageInfo)(itemst* this,void* item_type,void* material_category);
typedef bool (*vm_itemst_addWear)(itemst* this,int32_t delta,bool lose_masterwork,bool do_rot);
typedef void (*vm_itemst_addContaminant)(itemst* this,int32_t type,material_type material,int32_t size);
typedef void (*vm_itemst_removeContaminantByIdx)(itemst* this,int32_t index,int32_t amount);
typedef void (*vm_itemst_removeContaminantByType)(itemst* this,int32_t type,material_type material,int32_t amount);
typedef int32_t (*vm_itemst_getClothingCategory)(itemst* this);
typedef void (*vm_itemst_write_file)(itemst* this,void*);
typedef void (*vm_itemst_read_file)(itemst* this,void*,int32_t loadversion);
typedef bool (*vm_itemst_isOnGround)(itemst* this);
typedef bool (*vm_itemst_isSplittable)(itemst* this);
typedef void (*vm_itemst_addRandomDye)(itemst* this);
typedef void (*vm_itemst_addImprovementFromClothOrDye)(itemst* this,void*);
typedef void (*vm_itemst_propagateUnitRefs)(itemst* this);
typedef bool (*vm_itemst_isBag)(itemst* this);
typedef int32_t (*vm_itemst_getStackSize)(itemst* this);
typedef void (*vm_itemst_addStackSize)(itemst* this,int32_t amount);
typedef void (*vm_itemst_setStackSize)(itemst* this,int32_t amount);
typedef bool (*vm_itemst_isAmmoClass)(itemst* this,void*);
typedef bool (*vm_itemst_setTemperatureFromMap)(itemst* this,bool local,bool contained);
typedef bool (*vm_itemst_setTemperature)(itemst* this,uint16_t temp,bool local,bool contained);
typedef bool (*vm_itemst_updateTemperatureFromMap)(itemst* this,bool local,bool contained,bool adjust);
typedef bool (*vm_itemst_updateTemperature)(itemst* this,uint16_t temp,bool local,bool contained,bool adjust);
typedef bool (*vm_itemst_updateFromWeather)(itemst* this);
typedef bool (*vm_itemst_updateContaminants)(itemst* this);
typedef bool (*vm_itemst_checkTemperatureDamage)(itemst* this);
typedef bool (*vm_itemst_checkHeatColdDamage)(itemst* this);
typedef bool (*vm_itemst_checkMeltBoil)(itemst* this);
typedef int32_t (*vm_itemst_getMeleeSkill)(itemst* this);
typedef int32_t (*vm_itemst_getRangedSkill)(itemst* this);
typedef void (*vm_itemst_setQuality)(itemst* this,int16_t quality);
typedef int16_t (*vm_itemst_getQuality)(itemst* this);
typedef int16_t (*vm_itemst_getOverallQuality)(itemst* this);
typedef int16_t (*vm_itemst_getDamage)(itemst* this);
typedef bool (*vm_itemst_isImprovable)(itemst* this,void*,int32_t material,int32_t matgloss);
typedef bool (*vm_itemst_isDyeable)(itemst* this);
typedef bool (*vm_itemst_isNotDyed)(itemst* this);
typedef bool (*vm_itemst_isDyed)(itemst* this);
typedef bool (*vm_itemst_canSewImage)(itemst* this);
typedef bool (*vm_itemst_canAddSewnImage)(itemst* this);
typedef bool (*vm_itemst_isProcessableVialAtStill)(itemst* this);
typedef bool (*vm_itemst_isSimilarToItem)(itemst* this,item_type item_type,int16_t item_subtype,material_type material,int16_t matgloss);
typedef int32_t (*vm_itemst_getBlockChance)(itemst* this);
typedef int32_t (*vm_itemst_getParryChance)(itemst* this);
typedef int16_t (*vm_itemst_getMakerRace)(itemst* this);
typedef void (*vm_itemst_setMakerRace)(itemst* this,int16_t);
typedef int8_t (*vm_itemst_getEffectiveArmorLevel)(itemst* this);
typedef bool (*vm_itemst_isConstructed)(itemst* this);
typedef bool (*vm_itemst_canBeDyed)(itemst* this);
typedef bool (*vm_itemst_isDyeableCloth)(itemst* this);
typedef int32_t (*vm_itemst_getCritBoost)(itemst* this);
typedef void (*vm_itemst_coverWithContaminant)(itemst* this,material_type material);
typedef bool (*vm_itemst_hasImprovements)(itemst* this);
typedef bool (*vm_itemst_isImproved)(itemst* this);
typedef void* (*vm_itemst_getMagic)(itemst* this);
typedef void (*vm_itemst_getItemDescription)(itemst* this,void* str,int8_t mode);
typedef void (*vm_itemst_getItemDescriptionPrefix)(itemst* this,void* str,int8_t mode);
typedef int32_t (*vm_itemst_getImprovementsValue)(itemst* this,void* caravan);
typedef bool (*vm_itemst_isExtractBearingFish)(itemst* this);
typedef bool (*vm_itemst_isExtractBearingVermin)(itemst* this);
typedef int32_t (*vm_itemst_getBaseWeight)(itemst* this);
typedef int32_t (*vm_itemst_getWeightShiftBits)(itemst* this);
typedef bool (*vm_itemst_isCollected)(itemst* this);
typedef int32_t (*vm_itemst_getVolume)(itemst* this);
typedef bool (*vm_itemst_isEdibleVermin)(itemst* this);
typedef int8_t (*vm_itemst_getTile)(itemst* this);
typedef bool (*vm_itemst_isRangedWeapon)(itemst* this);
typedef bool (*vm_itemst_isClothing)(itemst* this);
typedef bool (*vm_itemst_isWet)(itemst* this);
typedef int32_t (*vm_itemst_getCurrencyValue)(itemst* this,void* entity);
typedef bool (*vm_itemst_isAssignedToAnyStockpile)(itemst* this);
typedef bool (*vm_itemst_isAssignedToThisStockpile)(itemst* this,int32_t building);
typedef void (*vm_itemst_removeFromStockpile)(itemst* this);
typedef void (*vm_itemst_clearStockpileAssignment)(itemst* this);
typedef void* (*vm_itemst_getStockpile)(itemst* this);
typedef void (*vm_itemst_addDye)(itemst* this,int16_t material,int16_t matgloss,void* unit,void* job);
typedef void (*vm_itemst_addImage)(itemst* this,int32_t art_chunk_id,int32_t art_subid,int16_t material,int16_t matgloss,int16_t dye_material,int16_t dye_matgloss,void* src_item,int32_t quality,int16_t skill_level,int32_t maker_hfid);
typedef void (*vm_itemst_addImprovementsFromItem)(itemst* this,void* item);
typedef int32_t (*vm_itemst_getThreadDyeValue)(itemst* this,void* caravan);
typedef void (*vm_itemst_getColorAndShape)(itemst* this,void* colors,void* shapes);
typedef bool (*vm_itemst_isCritter2)(itemst* this);
typedef bool (*vm_itemst_isArmorOrClothing)(itemst* this);
typedef void (*vm_itemst_vmeth_648)(itemst* this);
struct vtable_itemst {
    vm_itemst_getType getType;
    vm_itemst_getSubtype getSubtype;
    vm_itemst_getMaterial getMaterial;
    vm_itemst_getMatgloss getMatgloss;
    vm_itemst_setSubtype setSubtype;
    vm_itemst_setMaterial setMaterial;
    vm_itemst_setMatgloss setMatgloss;
    vm_itemst_getActualMaterial getActualMaterial;
    vm_itemst_getActualMatgloss getActualMatgloss;
    vm_itemst_getRace getRace;
    vm_itemst_clearLastTempUpdateTS clearLastTempUpdateTS;
    vm_itemst_getSpecHeat getSpecHeat;
    vm_itemst_getIgnitePoint getIgnitePoint;
    vm_itemst_getHeatdamPoint getHeatdamPoint;
    vm_itemst_getColddamPoint getColddamPoint;
    vm_itemst_getBoilingPoint getBoilingPoint;
    vm_itemst_getMeltingPoint getMeltingPoint;
    vm_itemst_getFixedTemp getFixedTemp;
    vm_itemst_getTemperature getTemperature;
    vm_itemst_adjustTemperature adjustTemperature;
    vm_itemst_extinguish extinguish;
    vm_itemst_getGloveHandedness getGloveHandedness;
    vm_itemst_setGloveHandedness setGloveHandedness;
    vm_itemst_pickRandomSubtype pickRandomSubtype;
    vm_itemst_getWeaponSize getWeaponSize;
    vm_itemst_getWear getWear;
    vm_itemst_setWear setWear;
    vm_itemst_getMaker getMaker;
    vm_itemst_setMaker setMaker;
    vm_itemst_getCorpseRace getCorpseRace;
    vm_itemst_getCorpseInfo getCorpseInfo;
    vm_itemst_getGloveFlags getGloveFlags;
    vm_itemst_setSeedsPlantSkill setSeedsPlantSkill;
    vm_itemst_ageItem ageItem;
    vm_itemst_getCritterAirdrownTimer getCritterAirdrownTimer;
    vm_itemst_setCritterAirdrownTimer setCritterAirdrownTimer;
    vm_itemst_incrementCritterAirdrownTimer incrementCritterAirdrownTimer;
    vm_itemst_getRotTimer getRotTimer;
    vm_itemst_setRotTimer setRotTimer;
    vm_itemst_incrementRotTimer incrementRotTimer;
    vm_itemst_getAmmoType getAmmoType;
    vm_itemst_getDamageType getDamageType;
    vm_itemst_isLiquipowder isLiquipowder;
    vm_itemst_isLiquid isLiquid;
    vm_itemst_isCritter1 isCritter1;
    vm_itemst_getStickChance getStickChance;
    vm_itemst_addImprovementFromJob addImprovementFromJob;
    vm_itemst_isWeapon isWeapon;
    vm_itemst_isArmorNotClothing isArmorNotClothing;
    vm_itemst_canStoreInWeaponRack canStoreInWeaponRack;
    vm_itemst_canStoreInArmorStand canStoreInArmorStand;
    vm_itemst_isMillable isMillable;
    vm_itemst_isProcessableThread isProcessableThread;
    vm_itemst_isProcessableVial isProcessableVial;
    vm_itemst_isProcessableBag isProcessableBag;
    vm_itemst_isProcessableBarrel isProcessableBarrel;
    vm_itemst_isEdible isEdible;
    vm_itemst_isEdibleRaw isEdibleRaw;
    vm_itemst_isEdibleCarnivore isEdibleCarnivore;
    vm_itemst_isEdibleBonecarn isEdibleBonecarn;
    vm_itemst_moveToGround moveToGround;
    vm_itemst_isFat isFat;
    vm_itemst_isAnimal isAnimal;
    vm_itemst_assignQuality assignQuality;
    vm_itemst_notifyLostMasterwork notifyLostMasterwork;
    vm_itemst_addMagic addMagic;
    vm_itemst_magic_unk1 magic_unk1;
    vm_itemst_magic_unk2 magic_unk2;
    vm_itemst_magic_unk3 magic_unk3;
    vm_itemst_magic_unk4 magic_unk4;
    vm_itemst_setDisplayColor setDisplayColor;
    vm_itemst_isDamagedByHeat isDamagedByHeat;
    vm_itemst_needTwoHandedWield needTwoHandedWield;
    vm_itemst_splitStack splitStack;
    vm_itemst_isTameableVermin isTameableVermin;
    vm_itemst_isDistillable isDistillable;
    vm_itemst_isDye isDye;
    vm_itemst_isMilkable isMilkable;
    vm_itemst_isSandBearing isSandBearing;
    vm_itemst_isLyeBearing isLyeBearing;
    vm_itemst_isAnimalProduct isAnimalProduct;
    vm_itemst_getStorageInfo getStorageInfo;
    vm_itemst_addWear addWear;
    vm_itemst_addContaminant addContaminant;
    vm_itemst_removeContaminantByIdx removeContaminantByIdx;
    vm_itemst_removeContaminantByType removeContaminantByType;
    vm_itemst_getClothingCategory getClothingCategory;
    vm_itemst_write_file write_file;
    vm_itemst_read_file read_file;
    vm_itemst_isOnGround isOnGround;
    vm_itemst_isSplittable isSplittable;
    vm_itemst_addRandomDye addRandomDye;
    vm_itemst_addImprovementFromClothOrDye addImprovementFromClothOrDye;
    vm_itemst_propagateUnitRefs propagateUnitRefs;
    vm_itemst_isBag isBag;
    vm_itemst_getStackSize getStackSize;
    vm_itemst_addStackSize addStackSize;
    vm_itemst_setStackSize setStackSize;
    vm_itemst_isAmmoClass isAmmoClass;
    vm_itemst_setTemperatureFromMap setTemperatureFromMap;
    vm_itemst_setTemperature setTemperature;
    vm_itemst_updateTemperatureFromMap updateTemperatureFromMap;
    vm_itemst_updateTemperature updateTemperature;
    vm_itemst_updateFromWeather updateFromWeather;
    vm_itemst_updateContaminants updateContaminants;
    vm_itemst_checkTemperatureDamage checkTemperatureDamage;
    vm_itemst_checkHeatColdDamage checkHeatColdDamage;
    vm_itemst_checkMeltBoil checkMeltBoil;
    vm_itemst_getMeleeSkill getMeleeSkill;
    vm_itemst_getRangedSkill getRangedSkill;
    vm_itemst_setQuality setQuality;
    vm_itemst_getQuality getQuality;
    vm_itemst_getOverallQuality getOverallQuality;
    vm_itemst_getDamage getDamage;
    vm_itemst_isImprovable isImprovable;
    vm_itemst_isDyeable isDyeable;
    vm_itemst_isNotDyed isNotDyed;
    vm_itemst_isDyed isDyed;
    vm_itemst_canSewImage canSewImage;
    vm_itemst_canAddSewnImage canAddSewnImage;
    vm_itemst_isProcessableVialAtStill isProcessableVialAtStill;
    vm_itemst_isSimilarToItem isSimilarToItem;
    vm_itemst_getBlockChance getBlockChance;
    vm_itemst_getParryChance getParryChance;
    vm_itemst_getMakerRace getMakerRace;
    vm_itemst_setMakerRace setMakerRace;
    vm_itemst_getEffectiveArmorLevel getEffectiveArmorLevel;
    vm_itemst_isConstructed isConstructed;
    vm_itemst_canBeDyed canBeDyed;
    vm_itemst_isDyeableCloth isDyeableCloth;
    vm_itemst_getCritBoost getCritBoost;
    vm_itemst_coverWithContaminant coverWithContaminant;
    vm_itemst_hasImprovements hasImprovements;
    vm_itemst_isImproved isImproved;
    vm_itemst_getMagic getMagic;
    vm_itemst_getItemDescription getItemDescription;
    vm_itemst_getItemDescriptionPrefix getItemDescriptionPrefix;
    vm_itemst_getImprovementsValue getImprovementsValue;
    vm_itemst_isExtractBearingFish isExtractBearingFish;
    vm_itemst_isExtractBearingVermin isExtractBearingVermin;
    vm_itemst_getBaseWeight getBaseWeight;
    vm_itemst_getWeightShiftBits getWeightShiftBits;
    vm_itemst_isCollected isCollected;
    vm_itemst_getVolume getVolume;
    vm_itemst_isEdibleVermin isEdibleVermin;
    vm_itemst_getTile getTile;
    vm_itemst_isRangedWeapon isRangedWeapon;
    vm_itemst_isClothing isClothing;
    vm_itemst_isWet isWet;
    vm_itemst_getCurrencyValue getCurrencyValue;
    vm_itemst_isAssignedToAnyStockpile isAssignedToAnyStockpile;
    vm_itemst_isAssignedToThisStockpile isAssignedToThisStockpile;
    vm_itemst_removeFromStockpile removeFromStockpile;
    vm_itemst_clearStockpileAssignment clearStockpileAssignment;
    vm_itemst_getStockpile getStockpile;
    vm_itemst_addDye addDye;
    vm_itemst_addImage addImage;
    vm_itemst_addImprovementsFromItem addImprovementsFromItem;
    vm_itemst_getThreadDyeValue getThreadDyeValue;
    vm_itemst_getColorAndShape getColorAndShape;
    vm_itemst_isCritter2 isCritter2;
    vm_itemst_isArmorOrClothing isArmorOrClothing;
    vm_itemst_vmeth_648 vmeth_648;
};
struct itemst {
    struct vtable_itemst *vtable;
    struct coord32 pos;
    struct item_flags item_flags;
    uint32_t age;
    int32_t id;
    struct stl_vector_ptr_specific_ref specific_refs;
    struct stl_vector_ptr_general_refst general_refs;
};

struct item_actualst;
typedef void (*vm_item_actualst_removeContaminant)(item_actualst* this,int32_t type,int32_t material,int32_t amount);
struct item_magicness {
    int16_t type;
    int16_t value;
    int16_t item_magicness_anon_1;
    int32_t item_magicness_flags;
};

struct stl_vector_ptr_item_magicness {
struct item_magicness **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_contaminant {
struct contaminant **ptr;
void *endptr;
void *endalloc;
};
struct vtable_item_actualst {
    struct vtable_itemst super;
    vm_item_actualst_removeContaminant removeContaminant;
};
struct item_actualst {
    struct vtable_item_actualst *vtable;
        struct coord32 pos;
        struct item_flags item_flags;
        uint32_t age;
        int32_t id;
        struct stl_vector_ptr_specific_ref specific_refs;
        struct stl_vector_ptr_general_refst general_refs;
    int32_t stack_size;
    struct stl_vector_ptr_item_magicness *magic;
    struct stl_vector_ptr_contaminant *contaminants;
    struct temperaturest temperature;
    int16_t wear;
    int32_t wear_timer;
    int32_t temp_updated_frame;
};

struct item_craftedst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
    int16_t maker_race;
    int16_t quality;
    int16_t skill_level;
    int32_t maker;
};

struct itemimprovementst;
typedef void* (*vm_itemimprovementst_getImage)(itemimprovementst* this);
typedef void (*vm_itemimprovementst_getColorAndShape)(itemimprovementst* this,void* colors,void* shapes);
typedef void* (*vm_itemimprovementst_clone)(itemimprovementst* this);
typedef void (*vm_itemimprovementst_write_file)(itemimprovementst* this,void*);
typedef void (*vm_itemimprovementst_read_file)(itemimprovementst* this,void*,int32_t loadversion);
typedef improvement_type (*vm_itemimprovementst_getType)(itemimprovementst* this);
typedef bool (*vm_itemimprovementst_isDecoration)(itemimprovementst* this);
typedef void (*vm_itemimprovementst_vmeth_28)(itemimprovementst* this);
typedef int32_t (*vm_itemimprovementst_getDyeValue)(itemimprovementst* this,void* caravan);
struct vtable_itemimprovementst {
    vm_itemimprovementst_getImage getImage;
    vm_itemimprovementst_getColorAndShape getColorAndShape;
    vm_itemimprovementst_clone clone;
    vm_itemimprovementst_write_file write_file;
    vm_itemimprovementst_read_file read_file;
    vm_itemimprovementst_getType getType;
    vm_itemimprovementst_isDecoration isDecoration;
    vm_itemimprovementst_vmeth_28 vmeth_28;
    vm_itemimprovementst_getDyeValue getDyeValue;
};
struct itemimprovementst {
    struct vtable_itemimprovementst *vtable;
    int16_t material;
    int16_t matgloss;
    int32_t maker;
    int16_t quality;
    int16_t skill_rating;
    int32_t age;
};

struct stl_vector_ptr_itemimprovementst {
struct itemimprovementst **ptr;
void *endptr;
void *endalloc;
};
struct item_constructedst {
            struct vtable_item_actualst *vtable;
                struct coord32 pos;
                struct item_flags itemst_flags;
                uint32_t age;
                int32_t id;
                struct stl_vector_ptr_specific_ref specific_refs;
                struct stl_vector_ptr_general_refst general_refs;
            int32_t stack_size;
            struct stl_vector_ptr_item_magicness *magic;
            struct stl_vector_ptr_contaminant *contaminants;
            struct temperaturest temperature;
            int16_t wear;
            int32_t wear_timer;
            int32_t temp_updated_frame;
        int16_t material;
        int16_t matgloss;
        int16_t maker_race;
        int16_t quality;
        int16_t skill_level;
        int32_t maker;
    struct stl_vector_ptr_itemimprovementst improvements;
};

struct itemdef_ammost;
struct item_ammost {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_ammost *subtype;
};

struct item_amuletst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_animaltrapst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_anvilst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct itemdef_armorst;
struct item_armorst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_armorst *subtype;
};

struct item_armorstandst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_backpackst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_ballistaarrowheadst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct item_ballistapartsst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_stockpile_ref {
    int32_t id;
    int16_t x;
    int16_t y;
};

struct item_barrelst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct item_stockpile_ref stockpile;
};

struct item_barst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t subtype;
    int16_t material;
    int16_t matgloss;
};

struct item_bedst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_binst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct item_stockpile_ref stockpile;
};

struct item_blocksst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct item_bonesst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
};

struct item_boxst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_braceletst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_bucketst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_cabinetst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_cagest {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_catapultpartsst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_chainst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_chairst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_cheesest {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
    int32_t rot_timer;
};

struct item_clothst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_coffinst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_coinst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    int16_t coin_batch;
};

struct item_corpsepiecest {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t part_id;
    int16_t race;
    int16_t racegloss;
    int8_t sex;
    int32_t hist_figure_id;
    int32_t unit_id;
    int8_t is_generic;
    int32_t rot_timer;
};

struct item_corpsest {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
    int32_t hist_figure_id;
    int32_t unit_id;
    int16_t racegloss;
    int8_t sex;
    int32_t rot_timer;
};

struct item_critterst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
    int32_t milk_timer;
    int32_t airdrown_timer;
};

struct item_crownst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_doorst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_liquipowderst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
};

struct item_liquidst {
            struct vtable_item_actualst *vtable;
                struct coord32 pos;
                struct item_flags itemst_flags;
                uint32_t age;
                int32_t id;
                struct stl_vector_ptr_specific_ref specific_refs;
                struct stl_vector_ptr_general_refst general_refs;
            int32_t stack_size;
            struct stl_vector_ptr_item_magicness *magic;
            struct stl_vector_ptr_contaminant *contaminants;
            struct temperaturest temperature;
            int16_t wear;
            int32_t wear_timer;
            int32_t temp_updated_frame;
};

struct item_drinkst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct item_earringst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_extractst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct item_figurinest {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_fish_rawst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
    int32_t rot_timer;
};

struct item_fishst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
    int32_t rot_timer;
};

struct item_flaskst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_floodgatest {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct itemdef_foodst;
struct T_ingredients_5145 {
    int16_t prep_type;
    int16_t item_type;
    int16_t item_subtype;
    int16_t material;
    int16_t matgloss;
    int32_t maker;
    int16_t quality;
    int16_t skill_level;
} ;
struct stl_vector_ptr_T_ingredients_5145 {
struct T_ingredients_5145 **ptr;
void *endptr;
void *endalloc;
};
struct item_foodst {
            struct vtable_item_actualst *vtable;
                struct coord32 pos;
                struct item_flags itemst_flags;
                uint32_t age;
                int32_t id;
                struct stl_vector_ptr_specific_ref specific_refs;
                struct stl_vector_ptr_general_refst general_refs;
            int32_t stack_size;
            struct stl_vector_ptr_item_magicness *magic;
            struct stl_vector_ptr_contaminant *contaminants;
            struct temperaturest temperature;
            int16_t wear;
            int32_t wear_timer;
            int32_t temp_updated_frame;
        int16_t material;
        int16_t matgloss;
        int16_t maker_race;
        int16_t quality;
        int16_t skill_level;
        int32_t maker;
    struct itemdef_foodst *subtype;
    int32_t entity;
    int16_t recipe_id;
    struct stl_vector_ptr_T_ingredients_5145 ingredients;
    int32_t rot_timer;
};

struct item_gemst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_globst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
    int32_t rot_timer;
};

struct itemdef_glovesst;
struct item_glovesst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_glovesst *subtype;
    struct df_flagarray item_glovesst_flags;
};

struct item_gobletst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct itemdef_helmst;
struct item_helmst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_helmst *subtype;
};

struct itemdef_instrumentst;
struct item_instrumentst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_instrumentst *subtype;
};

struct item_leavesst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t plant;
    int32_t rot_timer;
};

struct item_liquid_miscst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

enum item_magicness_type {
    item_magicness_type_Sparkle,
    item_magicness_type_AirWarped,
    item_magicness_type_Whistle,
    item_magicness_type_OddlySquare,
    item_magicness_type_SmallBumps,
    item_magicness_type_EarthSmell,
    item_magicness_type_Lightning,
    item_magicness_type_GrayHairs,
    item_magicness_type_RustlingLeaves
};

struct item_meatst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
    int32_t rot_timer;
};

struct item_orest {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct itemdef_pantsst;
struct item_pantsst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_pantsst *subtype;
};

struct item_petst {
            struct vtable_item_actualst *vtable;
                struct coord32 pos;
                struct item_flags itemst_flags;
                uint32_t age;
                int32_t id;
                struct stl_vector_ptr_specific_ref specific_refs;
                struct stl_vector_ptr_general_refst general_refs;
            int32_t stack_size;
            struct stl_vector_ptr_item_magicness *magic;
            struct stl_vector_ptr_contaminant *contaminants;
            struct temperaturest temperature;
            int16_t wear;
            int32_t wear_timer;
            int32_t temp_updated_frame;
        int16_t race;
        int32_t milk_timer;
        int32_t airdrown_timer;
};

struct item_plantst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t plant;
    int32_t rot_timer;
};

struct item_potionst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
};

struct item_powderst {
            struct vtable_item_actualst *vtable;
                struct coord32 pos;
                struct item_flags itemst_flags;
                uint32_t age;
                int32_t id;
                struct stl_vector_ptr_specific_ref specific_refs;
                struct stl_vector_ptr_general_refst general_refs;
            int32_t stack_size;
            struct stl_vector_ptr_item_magicness *magic;
            struct stl_vector_ptr_contaminant *contaminants;
            struct temperaturest temperature;
            int16_t wear;
            int32_t wear_timer;
            int32_t temp_updated_frame;
};

struct item_powder_organicst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

enum item_quality {
    item_quality_Ordinary,
    item_quality_WellCrafted,
    item_quality_FinelyCrafted,
    item_quality_Superior,
    item_quality_Exceptional,
    item_quality_Masterful,
    item_quality_Artifact
};

struct item_quiverst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_remainsst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
    int32_t rot_timer;
};

struct item_ringst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_rockst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct item_roughst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct item_sandst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
};

struct item_scepterst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_seedsst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t plant;
    int32_t grow_counter;
    int16_t planting_skill;
};

struct item_shellst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
};

struct itemdef_shieldst;
struct item_shieldst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_shieldst *subtype;
};

struct itemdef_shoesst;
struct item_shoesst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_shoesst *subtype;
};

struct itemdef_siegeammost;
struct item_siegeammost {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_siegeammost *subtype;
};

struct item_skin_rawst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
    int32_t rot_timer;
};

struct item_skin_tannedst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
    int32_t item_skin_tannedst_anon_1;
};

struct item_skullst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t race;
};

struct item_smallgemst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct item_statuest {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_stonest {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
};

struct item_tablest {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_threadst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t material;
    int16_t matgloss;
    int16_t dye_material;
    int16_t dye_matgloss;
    int32_t dye_maker;
    int16_t dye_quality;
    int16_t dye_skill;
    int32_t item_threadst_anon_1;
};

struct item_totemst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct itemdef_toyst;
struct item_toyst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_toyst *subtype;
};

struct itemdef_trapcompst;
struct item_trapcompst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_trapcompst *subtype;
};

struct item_trappartsst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_verminst {
            struct vtable_item_actualst *vtable;
                struct coord32 pos;
                struct item_flags itemst_flags;
                uint32_t age;
                int32_t id;
                struct stl_vector_ptr_specific_ref specific_refs;
                struct stl_vector_ptr_general_refst general_refs;
            int32_t stack_size;
            struct stl_vector_ptr_item_magicness *magic;
            struct stl_vector_ptr_contaminant *contaminants;
            struct temperaturest temperature;
            int16_t wear;
            int32_t wear_timer;
            int32_t temp_updated_frame;
        int16_t race;
        int32_t milk_timer;
        int32_t airdrown_timer;
};

struct item_weaponrackst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct itemdef_weaponst;
struct item_weaponst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
    struct itemdef_weaponst *subtype;
};

struct item_windowst {
                struct vtable_item_actualst *vtable;
                    struct coord32 pos;
                    struct item_flags itemst_flags;
                    uint32_t age;
                    int32_t id;
                    struct stl_vector_ptr_specific_ref specific_refs;
                    struct stl_vector_ptr_general_refst general_refs;
                int32_t stack_size;
                struct stl_vector_ptr_item_magicness *magic;
                struct stl_vector_ptr_contaminant *contaminants;
                struct temperaturest temperature;
                int16_t wear;
                int32_t wear_timer;
                int32_t temp_updated_frame;
            int16_t material;
            int16_t matgloss;
            int16_t maker_race;
            int16_t quality;
            int16_t skill_level;
            int32_t maker;
        struct stl_vector_ptr_itemimprovementst improvements;
};

struct item_woodst {
        struct vtable_item_actualst *vtable;
            struct coord32 pos;
            struct item_flags itemst_flags;
            uint32_t age;
            int32_t id;
            struct stl_vector_ptr_specific_ref specific_refs;
            struct stl_vector_ptr_general_refst general_refs;
        int32_t stack_size;
        struct stl_vector_ptr_item_magicness *magic;
        struct stl_vector_ptr_contaminant *contaminants;
        struct temperaturest temperature;
        int16_t wear;
        int32_t wear_timer;
        int32_t temp_updated_frame;
    int16_t matgloss;
};

struct itemdefst;
typedef void (*vm_itemdefst_parseRaws)(itemdefst* this,void* raw,void* token_name,int32_t token_len);
typedef void (*vm_itemdefst_finalize)(itemdefst* this);
typedef void (*vm_itemdefst_vmeth_8)(itemdefst* this);
struct vtable_itemdefst {
    vm_itemdefst_parseRaws parseRaws;
    vm_itemdefst_finalize finalize;
    vm_itemdefst_vmeth_8 vmeth_8;
};
struct itemdefst {
    struct vtable_itemdefst *vtable;
    struct stl_string id;
    int16_t subtype;
};

struct itemdef_ammost {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    int32_t damage;
    int32_t damage_type;
    struct stl_string ammo_class;
    int16_t stick_chance;
};

struct itemdef_armorst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    struct stl_string name_preplural;
    struct stl_string material_placeholder;
    int32_t weight;
    int32_t value;
    int8_t armorlevel;
    int16_t ubstep;
    int16_t lbstep;
    int32_t mainblock;
    int32_t secondblock;
    int32_t material_size;
    struct armor_properties props;
    struct df_flagarray itemdef_armorst_flags;
};

struct itemdef_foodst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    int16_t level;
};

struct itemdef_glovesst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    int32_t weight;
    int32_t value;
    int32_t blockpower;
    int8_t armorlevel;
    int16_t upstep;
    struct df_flagarray itemdef_glovesst_flags;
    int32_t material_size;
    struct armor_properties props;
};

struct itemdef_helmst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    int32_t weight;
    int32_t value;
    int32_t blockpower;
    int8_t armorlevel;
    struct df_flagarray itemdef_helmst_flags;
    int32_t material_size;
    struct armor_properties props;
};

struct itemdef_instrumentst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    struct df_flagarray itemdef_instrumentst_flags;
};

struct itemdef_pantsst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    struct stl_string name_preplural;
    struct stl_string material_placeholder;
    int32_t weight;
    int32_t value;
    int32_t blockpower;
    int8_t armorlevel;
    struct df_flagarray itemdef_pantsst_flags;
    int32_t material_size;
    int16_t lbstep;
    struct armor_properties props;
};

struct itemdef_shieldst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    int32_t weight;
    int32_t value;
    int32_t blockchance;
    int32_t blockpower;
    int8_t armorlevel;
    int16_t upstep;
    int32_t material_size;
};

struct itemdef_shoesst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    int32_t weight;
    int32_t value;
    int32_t blockpower;
    int8_t armorlevel;
    int16_t upstep;
    struct df_flagarray itemdef_shoesst_flags;
    int32_t material_size;
    struct armor_properties props;
};

struct itemdef_siegeammost {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    struct stl_string ammo_class;
};

struct itemdef_toyst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    struct df_flagarray itemdef_toyst_flags;
};

struct itemdef_trapcompst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    struct stl_string adjective;
    int32_t damage;
    int32_t damage_type;
    int32_t weight;
    int32_t hits;
    int32_t crit_boost;
    int32_t material_size;
    int16_t stick_chance;
};

struct itemdef_weaponst {
        struct vtable_itemdefst *vtable;
        struct stl_string id;
        int16_t subtype;
    struct stl_string name;
    struct stl_string name_plural;
    struct stl_string adjective;
    int32_t damage;
    int32_t damage_type;
    int32_t weight;
    int32_t skill_melee;
    int32_t skill_ranged;
    struct stl_string ranged_ammo;
    int32_t crit_boost;
    int16_t two_handed;
    int16_t minimum_size;
    int32_t material_size;
    struct df_flagarray itemdef_weaponst_flags;
    int16_t stick_chance;
};

struct itemimprovementst;
typedef void* (*vm_itemimprovementst_getImage)(itemimprovementst* this);
typedef void (*vm_itemimprovementst_getColorAndShape)(itemimprovementst* this,void* colors,void* shapes);
typedef void* (*vm_itemimprovementst_clone)(itemimprovementst* this);
typedef void (*vm_itemimprovementst_write_file)(itemimprovementst* this,void*);
typedef void (*vm_itemimprovementst_read_file)(itemimprovementst* this,void*,int32_t loadversion);
typedef improvement_type (*vm_itemimprovementst_getType)(itemimprovementst* this);
typedef bool (*vm_itemimprovementst_isDecoration)(itemimprovementst* this);
typedef void (*vm_itemimprovementst_vmeth_28)(itemimprovementst* this);
typedef int32_t (*vm_itemimprovementst_getDyeValue)(itemimprovementst* this,void* caravan);
struct vtable_itemimprovementst {
    vm_itemimprovementst_getImage getImage;
    vm_itemimprovementst_getColorAndShape getColorAndShape;
    vm_itemimprovementst_clone clone;
    vm_itemimprovementst_write_file write_file;
    vm_itemimprovementst_read_file read_file;
    vm_itemimprovementst_getType getType;
    vm_itemimprovementst_isDecoration isDecoration;
    vm_itemimprovementst_vmeth_28 vmeth_28;
    vm_itemimprovementst_getDyeValue getDyeValue;
};
struct itemimprovementst {
    struct vtable_itemimprovementst *vtable;
    int16_t material;
    int16_t matgloss;
    int32_t maker;
    int16_t quality;
    int16_t skill_rating;
    int32_t age;
};

struct itemimprovement_art_imagest {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
    struct art_image_ref image;
};

struct itemimprovement_bandsst {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
};

struct itemimprovement_clothst {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
};

struct itemimprovement_coveredst {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
};

struct itemimprovement_itemspecificst {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
    int32_t type;
};

struct itemimprovement_rings_hangingst {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
};

struct itemimprovement_sewn_imagest {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
    struct art_image_ref image;
    struct T_cloth_4416 {
        int32_t unit_id;
        int16_t quality;
        int16_t anon_1;
    } cloth;
    struct dye_info dye;
};

struct itemimprovement_spikesst {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
};

struct itemimprovement_threadst {
        struct vtable_itemimprovementst *vtable;
        int16_t material;
        int16_t matgloss;
        int32_t maker;
        int16_t quality;
        int16_t skill_rating;
        int32_t age;
    struct dye_info dye;
};

enum items_other_id {
    items_other_id_ANY = -1,
    items_other_id_IN_PLAY,
    items_other_id_ANY_ARTIFACT,
    items_other_id_WEAPON,
    items_other_id_ANY_WEAPON,
    items_other_id_ANY_TRUE_ARMOR,
    items_other_id_ANY_ARMOR_HELM,
    items_other_id_ANY_ARMOR_SHOES,
    items_other_id_SHIELD,
    items_other_id_ANY_ARMOR_GLOVES,
    items_other_id_ANY_ARMOR_PANTS,
    items_other_id_QUIVER,
    items_other_id_BACKPACK,
    items_other_id_AMMO,
    items_other_id_WOOD,
    items_other_id_STONE,
    items_other_id_ROCK,
    items_other_id_ANY_REFUSE,
    items_other_id_ANY_GOOD_FOOD,
    items_other_id_ANY_AUTO_CLEAN,
    items_other_id_ANY_GENERIC19,
    items_other_id_ANY_GENERIC20,
    items_other_id_ANY_BUTCHERABLE,
    items_other_id_ANY_FURNITURE,
    items_other_id_ANY_ANIMAL,
    items_other_id_ANY_EDIBLE_RAW,
    items_other_id_ANY_EDIBLE_CARNIVORE,
    items_other_id_ANY_EDIBLE_BONECARN,
    items_other_id_ANY_EDIBLE_VERMIN,
    items_other_id_ANY_FOOD_CONTAINER,
    items_other_id_ANY_CAN_ROT,
    items_other_id_ANY_MURDERED,
    items_other_id_ANY_DEAD_DWARF,
    items_other_id_ANY_GENERIC32,
    items_other_id_ANY_GENERIC33,
    items_other_id_ANY_GENERIC34,
    items_other_id_ANY_GENERIC35,
    items_other_id_DOOR,
    items_other_id_FLOODGATE,
    items_other_id_CAGE,
    items_other_id_FLASK,
    items_other_id_WINDOW,
    items_other_id_GOBLET,
    items_other_id_INSTRUMENT,
    items_other_id_TOY,
    items_other_id_BUCKET,
    items_other_id_BARREL,
    items_other_id_CHAIN,
    items_other_id_ANIMALTRAP,
    items_other_id_BED,
    items_other_id_CHAIR,
    items_other_id_COFFIN,
    items_other_id_TABLE,
    items_other_id_STATUE,
    items_other_id_BOX,
    items_other_id_BIN,
    items_other_id_SAND,
    items_other_id_ARMORSTAND,
    items_other_id_WEAPONRACK,
    items_other_id_CABINET,
    items_other_id_ANVIL,
    items_other_id_CATAPULTPARTS,
    items_other_id_BALLISTAPARTS,
    items_other_id_SIEGEAMMO,
    items_other_id_TRAPPARTS,
    items_other_id_ANY_WEBS,
    items_other_id_ANY_ENCASED,
    items_other_id_ANY_ITEM_FLAG_400,
    items_other_id_DRINK,
    items_other_id_ANY_DRINK,
    items_other_id_LIQUID_MISC,
    items_other_id_EXTRACT,
    items_other_id_POTION,
    items_other_id_POWDER_ORGANIC,
    items_other_id_ANY_COOKABLE,
    items_other_id_ANY_GENERIC74,
    items_other_id_VERMIN,
    items_other_id_PET,
    items_other_id_ANY_CRITTER,
    items_other_id_COIN,
    items_other_id_GLOB,
    items_other_id_ANY_UNKNOWN_80,
    items_other_id_ANY_MELT,
    items_other_id_BAD
};

enum job_item_flags1_enum {
    job_item_flags1_improvable=0x01,
    job_item_flags1_butcherable=0x02,
    job_item_flags1_millable=0x04,
    job_item_flags1_buryable=0x08,
    job_item_flags1_unrotten=0x10,
    job_item_flags1_undisturbed=0x20,
    job_item_flags1_collected=0x40,
    job_item_flags1_sharpenable=0x80,
    job_item_flags1_murdered=0x100,
    job_item_flags1_distillable=0x200,
    job_item_flags1_empty=0x400,
    job_item_flags1_processable=0x800,
    job_item_flags1_bag=0x1000,
    job_item_flags1_cookable=0x2000,
    job_item_flags1_extract_bearing_plant=0x4000,
    job_item_flags1_extract_bearing_fish=0x8000,
    job_item_flags1_extract_bearing_vermin=0x10000,
    job_item_flags1_processable_to_vial=0x20000,
    job_item_flags1_processable_to_bag=0x40000,
    job_item_flags1_processable_to_barrel=0x80000,
    job_item_flags1_alchemical=0x100000,
    job_item_flags1_tameable_vermin=0x200000,
    job_item_flags1_nearby=0x400000,
    job_item_flags1_sand_bearing=0x800000,
    job_item_flags1_glass=0x1000000,
    job_item_flags1_milk=0x2000000,
    job_item_flags1_milkable=0x4000000,
    job_item_flags1_finished_goods=0x8000000,
    job_item_flags1_ammo=0x10000000,
    job_item_flags1_furniture=0x20000000,
    job_item_flags1_not_bin=0x40000000,
    job_item_flags1_lye_bearing=0x80000000
};

struct job_item_flags1 {
    uint32_t bitfield;
};

enum job_item_flags2_enum {
    job_item_flags2_dye=0x01,
    job_item_flags2_dyeable=0x02,
    job_item_flags2_dyed=0x04,
    job_item_flags2_sewn_imageless=0x08
};

struct job_item_flags2 {
    uint32_t bitfield;
};

struct job_item_filter {
    int16_t item_type;
    int16_t item_subtype;
    int16_t material;
    int16_t matgloss;
    struct job_item_flags1 job_item_filter_flags1;
    struct stl_vector_ptr_itemst *item_vector;
    int8_t use_matgloss_1;
    int8_t use_matgloss_2;
    struct job_item_flags2 job_item_filter_flags2;
    int8_t job_item_filter_use_flags2;
    struct job *job;
    struct buildingst *building;
};

struct job_list_link {
    struct job *item;
    struct job_list_link *prev;
    struct job_list_link *next;
};

enum job_skill {
    job_skill_NONE = -1,
    job_skill_MINING,
    job_skill_WOODCUTTING,
    job_skill_CARPENTRY,
    job_skill_DETAILSTONE,
    job_skill_MASONRY,
    job_skill_ANIMALTRAIN,
    job_skill_ANIMALCARE,
    job_skill_DISSECT_FISH,
    job_skill_DISSECT_VERMIN,
    job_skill_PROCESSFISH,
    job_skill_BUTCHER,
    job_skill_TRAPPING,
    job_skill_TANNER,
    job_skill_WEAVING,
    job_skill_BREWING,
    job_skill_ALCHEMY,
    job_skill_CLOTHESMAKING,
    job_skill_MILLING,
    job_skill_PROCESSPLANTS,
    job_skill_CHEESEMAKING,
    job_skill_MILK,
    job_skill_COOK,
    job_skill_PLANT,
    job_skill_HERBALISM,
    job_skill_FISH,
    job_skill_SMELT,
    job_skill_EXTRACT_ADAMANTINE,
    job_skill_FORGE_WEAPON,
    job_skill_FORGE_ARMOR,
    job_skill_FORGE_FURNITURE,
    job_skill_CUTGEM,
    job_skill_ENCRUSTGEM,
    job_skill_WOODCRAFT,
    job_skill_STONECRAFT,
    job_skill_METALCRAFT,
    job_skill_GLASSMAKER,
    job_skill_ADAMANTINE_WORK,
    job_skill_ADAMANTINE_SMELT,
    job_skill_ADAMANTINE_WEAVE,
    job_skill_LEATHERWORK,
    job_skill_BONECARVE,
    job_skill_UNARMED,
    job_skill_AXE,
    job_skill_SWORD,
    job_skill_DAGGER,
    job_skill_MACE,
    job_skill_HAMMER,
    job_skill_SPEAR,
    job_skill_CROSSBOW,
    job_skill_SHIELD,
    job_skill_ARMOR,
    job_skill_SIEGECRAFT,
    job_skill_SIEGEOPERATE,
    job_skill_BOWYER,
    job_skill_PIKE,
    job_skill_WHIP,
    job_skill_BOW,
    job_skill_BLOWGUN,
    job_skill_THROW,
    job_skill_MECHANICS,
    job_skill_MAGIC_NATURE,
    job_skill_SNEAK,
    job_skill_DESIGNBUILDING,
    job_skill_WOOD_BURNING,
    job_skill_LYE_MAKING,
    job_skill_SOAP_MAKING,
    job_skill_POTASH_MAKING,
    job_skill_DYER
};

enum job_skill_class {
    job_skill_class_Normal,
    job_skill_class_Medical,
    job_skill_class_Personal,
    job_skill_class_MilitaryWeapon,
    job_skill_class_MilitaryAttack,
    job_skill_class_MilitaryDefense,
    job_skill_class_MilitaryMisc
};

enum job_type_class {
    job_type_class_Misc,
    job_type_class_Digging,
    job_type_class_Building,
    job_type_class_Hauling,
    job_type_class_LifeSupport,
    job_type_class_TidyUp,
    job_type_class_Leisure,
    job_type_class_Gathering,
    job_type_class_Manufacture,
    job_type_class_Improvement,
    job_type_class_Crime,
    job_type_class_LawEnforcement,
    job_type_class_StrangeMood,
    job_type_class_UnitHandling,
    job_type_class_SiegeWeapon
};

enum language_name_category {
    language_name_category_Unit,
    language_name_category_Artifact,
    language_name_category_ArtifactEvil,
    language_name_category_Swamp,
    language_name_category_Desert,
    language_name_category_Forest,
    language_name_category_Mountains,
    language_name_category_Lake,
    language_name_category_Ocean,
    language_name_category_Glacier,
    language_name_category_Tundra,
    language_name_category_Grassland,
    language_name_category_Hills,
    language_name_category_Region,
    language_name_category_Cave,
    language_name_category_SwampEvil,
    language_name_category_DesertEvil,
    language_name_category_ForestEvil,
    language_name_category_MountainsEvil,
    language_name_category_LakeEvil,
    language_name_category_OceanEvil,
    language_name_category_GlacierEvil,
    language_name_category_TundraEvil,
    language_name_category_GrasslandEvil,
    language_name_category_HillsEvil,
    language_name_category_SwampGood,
    language_name_category_DesertGood,
    language_name_category_ForestGood,
    language_name_category_MountainsGood,
    language_name_category_LakeGood,
    language_name_category_OceanGood,
    language_name_category_GlacierGood,
    language_name_category_TundraGood,
    language_name_category_GrasslandGood,
    language_name_category_HillsGood,
    language_name_category_ArtImage,
    language_name_category_DemonEvil,
    language_name_category_DemonGood
};

struct language_symbol {
    struct stl_string name;
    struct stl_vector_strptr words_str;
    struct stl_vector_int32_t words;
};

struct language_translation {
    struct stl_string name;
    struct stl_vector_strptr words_pre;
    struct stl_vector_strptr trans_pre;
    struct stl_vector_strptr words;
};

struct language_word {
    struct stl_string word;
    struct stl_string forms[9];
    uint8_t adj_dist;
    char language_word_anon_1[7];
    struct df_flagarray language_word_flags;
};

enum language_word_flags {
    language_word_flags_FRONT_COMPOUND_NOUN_SING,
    language_word_flags_FRONT_COMPOUND_NOUN_PLUR,
    language_word_flags_FRONT_COMPOUND_ADJ,
    language_word_flags_FRONT_COMPOUND_PREFIX,
    language_word_flags_REAR_COMPOUND_NOUN_SING,
    language_word_flags_REAR_COMPOUND_NOUN_PLUR,
    language_word_flags_REAR_COMPOUND_ADJ,
    language_word_flags_THE_NOUN_SING,
    language_word_flags_THE_NOUN_PLUR,
    language_word_flags_THE_COMPOUND_NOUN_SING,
    language_word_flags_THE_COMPOUND_NOUN_PLUR,
    language_word_flags_THE_COMPOUND_ADJ,
    language_word_flags_THE_COMPOUND_PREFIX,
    language_word_flags_OF_NOUN_SING,
    language_word_flags_OF_NOUN_PLUR,
    language_word_flags_STANDARD_VERB
};

struct layer_objectst;
typedef int32_t (*vm_layer_objectst_getFirstVisible)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getLastVisible)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getX1)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getY1)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getX2)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getY2)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_isList)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getListCursor)(layer_objectst* this);
typedef void (*vm_layer_objectst_setListCursor)(layer_objectst* this,int32_t);
typedef void (*vm_layer_objectst_feed)(layer_objectst* this);
typedef bool (*vm_layer_objectst_isSetMouseLRCur)(layer_objectst* this);
typedef bool (*vm_layer_objectst_isSetMouseLCur)(layer_objectst* this);
typedef bool (*vm_layer_objectst_isSetMouseRCur)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getMouseLCur)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getMouseRCur)(layer_objectst* this);
typedef int32_t (*vm_layer_objectst_getListLength)(layer_objectst* this);
typedef void (*vm_layer_objectst_setListLength)(layer_objectst* this,int32_t);
struct vtable_layer_objectst {
    vm_layer_objectst_getFirstVisible getFirstVisible;
    vm_layer_objectst_getLastVisible getLastVisible;
    vm_layer_objectst_getX1 getX1;
    vm_layer_objectst_getY1 getY1;
    vm_layer_objectst_getX2 getX2;
    vm_layer_objectst_getY2 getY2;
    vm_layer_objectst_isList isList;
    vm_layer_objectst_getListCursor getListCursor;
    vm_layer_objectst_setListCursor setListCursor;
    vm_layer_objectst_feed feed;
    vm_layer_objectst_isSetMouseLRCur isSetMouseLRCur;
    vm_layer_objectst_isSetMouseLCur isSetMouseLCur;
    vm_layer_objectst_isSetMouseRCur isSetMouseRCur;
    vm_layer_objectst_getMouseLCur getMouseLCur;
    vm_layer_objectst_getMouseRCur getMouseRCur;
    vm_layer_objectst_getListLength getListLength;
    vm_layer_objectst_setListLength setListLength;
};
struct layer_objectst {
    struct vtable_layer_objectst *vtable;
    int8_t enabled;
    int8_t active;
};

struct layer_object_buttonst {
        struct vtable_layer_objectst *vtable;
        int8_t enabled;
        int8_t active;
    int32_t x1;
    int32_t y1;
    int32_t x2;
    int32_t y2;
    int32_t mouse_l_cur;
    int32_t mouse_r_cur;
};

struct layer_object_listst {
        struct vtable_layer_objectst *vtable;
        int8_t enabled;
        int8_t active;
    int32_t cursor;
    int32_t num_entries;
    int32_t x1;
    int32_t y1;
    int32_t page_size;
    int32_t x2;
    int32_t y2;
    int32_t mouse_l_cur;
    int32_t mouse_r_cur;
    int8_t rclick_scrolls;
    int32_t key_lclick;
    int32_t key_rclick;
};

enum T_flags_15205_enum {
    T_flags_15205_discovered=0x01,
    T_flags_15205_extinct=0x02
};

struct local_population {
    int8_t type;
    union {
        int16_t race;
        int16_t plant;
        int16_t tree;
    };
    int32_t count_min;
    int32_t count_max;
    struct T_flags_15205 {
        uint8_t bitfield;
    } local_population_flags;
};

struct manager_order {
    int16_t job_type;
    int16_t item_subtype;
    struct stl_string ammo_class;
    int16_t material;
    int16_t amount_left;
    int16_t amount_total;
};

struct manager_order_template {
    int16_t job_type;
    struct stl_string ammo_class;
    int16_t item_subtype;
    int16_t material;
    int8_t visible;
    struct item_category item_category;
};

struct mandate {
    struct unit *unit;
    int16_t mode;
    int16_t item_type;
    int16_t item_subtype;
    int16_t material;
    int16_t matgloss;
    int16_t amount_total;
    int16_t amount_remaining;
    int32_t timeout_counter;
    int32_t timeout_limit;
    struct T_punishments_6393 {
        int16_t hammerstrikes;
        int16_t prison;
        int32_t beating;
    } punishments;
    uint8_t mandate_anon_1;
    int32_t mandate_flags;
};

struct stl_vector_ptr_flow_info {
struct flow_info **ptr;
void *endptr;
void *endalloc;
};
enum tile_color_enum {
    tile_color_color=0x0F,
    tile_color_mud=0x10,
    tile_color_rain=0x20,
    tile_color_snow=0x40,
    tile_color_dry=0x80
};

struct tile_color {
    uint8_t bitfield;
};

enum tile_designation_enum {
    tile_designation_pile=0x01,
    tile_designation__unk_1=0x02,
    tile_designation__unk_2=0x04,
    tile_designation__unk_3=0x08,
    tile_designation__unk_4=0x10,
    tile_designation__unk_5=0x20,
    tile_designation_smooth=0x40,
    tile_designation_dig=0x80,
    tile_designation_fortification=0x100,
    tile_designation_hidden=0x200,
    tile_designation_water_flood=0x400,
    tile_designation_magma_flood=0x800,
    tile_designation_geolayer_index=0xF000,
    tile_designation_light=0x10000,
    tile_designation_subterranean=0x20000,
    tile_designation_outside=0x40000
};

struct tile_designation {
    uint32_t bitfield;
};

enum tile_occupancy_enum {
    tile_occupancy_unit=0x01,
    tile_occupancy_unit_grounded=0x02,
    tile_occupancy_item=0x04,
    tile_occupancy_building=0x18,
    tile_occupancy_moss=0x20,
    tile_occupancy_water=0x40,
    tile_occupancy_vomit=0x80,
    tile_occupancy_arrow_color=0xF00,
    tile_occupancy_blood_g=0x3000,
    tile_occupancy_blood_b=0xC000,
    tile_occupancy_pus=0x30000,
    tile_occupancy_blood_m=0xC0000,
    tile_occupancy_blood_c=0x300000,
    tile_occupancy_ichor=0xC00000,
    tile_occupancy_goo=0x3000000,
    tile_occupancy_slime=0xC000000,
    tile_occupancy_blood=0x30000000,
    tile_occupancy_arrow_variant=0x40000000,
    tile_occupancy_lava=0x80000000
};

struct tile_occupancy {
    int32_t bitfield;
};

struct map_block {
    struct df_flagarray map_block_flags;
    struct stl_vector_int32_t items;
    struct stl_vector_ptr_flow_info flows;
    struct flow_reuse_pool flow_pool;
    struct tile_color color[16][16];
    struct tile_designation designation[16][16];
    uint8_t chr[16][16];
    struct tile_occupancy occupancy[16][16];
    uint8_t fog_of_war[16][16];
    uint32_t path_cost[16][16];
    uint16_t walkable[16][16];
    uint16_t elevation[16][16];
    uint16_t temperature_1[16][16];
    uint16_t temperature_2[16][16];
    uint16_t map_block_anon_1[16][16];
    struct coord map_pos;
};

enum matgloss_gem_flags_enum {
    matgloss_gem_flags_ORNAMENTAL=0x01,
    matgloss_gem_flags_SEMI=0x02,
    matgloss_gem_flags_PRECIOUS=0x04,
    matgloss_gem_flags_RARE=0x08,
    matgloss_gem_flags_GLASS=0x10
};

struct matgloss_gem_flags {
    uint32_t bitfield;
};

struct matgloss_gem {
    struct stl_string id;
    struct matgloss_gem_flags matgloss_gem_flags;
    struct stl_string name[2];
    int16_t color;
    int32_t value;
    uint16_t spec_heat;
    uint16_t heatdam_point;
    uint16_t colddam_point;
    uint16_t ignite_point;
    uint16_t melting_point;
    uint16_t boiling_point;
    uint16_t fixed_temp;
};

enum matgloss_plant_flags_enum {
    matgloss_plant_flags_SWAMP=0x01,
    matgloss_plant_flags_RIVER=0x02,
    matgloss_plant_flags_CAVE=0x04,
    matgloss_plant_flags_FOREST=0x08,
    matgloss_plant_flags_SPRING=0x10,
    matgloss_plant_flags_SUMMER=0x20,
    matgloss_plant_flags_AUTUMN=0x40,
    matgloss_plant_flags_WINTER=0x80,
    matgloss_plant_flags__unk_8=0x100,
    matgloss_plant_flags_SEED=0x200,
    matgloss_plant_flags_EDIBLE_RAW=0x400,
    matgloss_plant_flags_EDIBLE_VERMIN=0x800,
    matgloss_plant_flags_LEAVES=0x1000,
    matgloss_plant_flags_EXTRACT_VIAL=0x2000,
    matgloss_plant_flags_EXTRACT_BAG=0x4000,
    matgloss_plant_flags_EXTRACT_BARREL=0x8000,
    matgloss_plant_flags_THREAD=0x10000,
    matgloss_plant_flags_MILL=0x20000,
    matgloss_plant_flags_EXTRACT_STILL_VIAL=0x40000,
    matgloss_plant_flags_DRINK=0x80000,
    matgloss_plant_flags_EXTRACT_COOKABLE=0x100000,
    matgloss_plant_flags_EDIBLE_WHENCOOKED=0x200000,
    matgloss_plant_flags_COOKABLE_WHEN_MILLED=0x400000,
    matgloss_plant_flags_MILL_DYE=0x800000
};

struct matgloss_plant_flags {
    uint32_t bitfield;
};

struct matgloss_plant {
    struct stl_string id;
    struct matgloss_plant_flags matgloss_plant_flags;
    struct stl_string name;
    struct stl_string name_plural;
    struct stl_string drink_name;
    struct stl_string seedname;
    struct stl_string mill_name;
    struct stl_string extract_name;
    struct T_temperatures_7910 {
        uint16_t spec_heat;
        uint16_t heatdam_point;
        uint16_t colddam_point;
        uint16_t ignite_point;
        uint16_t melting_point;
        uint16_t boiling_point;
        uint16_t fixed_temp;
    } temperatures[5];
    struct stl_string mill_dye;
    int16_t mill_dye_color;
    uint8_t tile;
    uint8_t leaves;
    int32_t growdur;
    int32_t value;
    int32_t drinkvalue;
    int32_t extractvalue;
    int32_t mill_value;
    int16_t color[3];
    int16_t seed_color[3];
    int16_t drink_color[3];
    int16_t extract_color[3];
    int16_t mill_color[3];
    int16_t genpower;
    int16_t frequency;
    int16_t clustersize;
    struct stl_vector_strptr prefstring;
};

enum matgloss_stone_flags_enum {
    matgloss_stone_flags_LIGHT=0x01,
    matgloss_stone_flags_DARK=0x02,
    matgloss_stone_flags_LAVA=0x04,
    matgloss_stone_flags_SHARP=0x08,
    matgloss_stone_flags_RIVER=0x10,
    matgloss_stone_flags_FLUX=0x20
};

struct matgloss_stone_flags {
    uint32_t bitfield;
};

struct matgloss_stone {
    struct stl_string id;
    struct matgloss_stone_flags matgloss_stone_flags;
    struct stl_string name;
    uint8_t tile;
    int16_t color[3];
    uint16_t spec_heat;
    uint16_t heatdam_point;
    uint16_t colddam_point;
    uint16_t ignite_point;
    uint16_t melting_point;
    uint16_t boiling_point;
    uint16_t fixed_temp;
};

struct matgloss_wood {
    struct stl_string id;
    struct df_flagarray matgloss_wood_flags;
    uint8_t tile;
    struct stl_string name;
    struct stl_string adj;
    struct stl_vector_strptr prefstring;
    uint16_t spec_heat;
    uint16_t heatdam_point;
    uint16_t colddam_point;
    uint16_t ignite_point;
    uint16_t melting_point;
    uint16_t boiling_point;
    uint16_t fixed_temp;
};

enum matgloss_wood_flags {
    matgloss_wood_flags_AUTUMNCOLOR,
    matgloss_wood_flags_WET,
    matgloss_wood_flags_DRY,
    matgloss_wood_flags_BIOME_MOUNTAIN,
    matgloss_wood_flags_BIOME_GLACIER,
    matgloss_wood_flags_BIOME_TUNDRA,
    matgloss_wood_flags_BIOME_SWAMP_TEMPERATE_FRESHWATER,
    matgloss_wood_flags_BIOME_SWAMP_TEMPERATE_SALTWATER,
    matgloss_wood_flags_BIOME_MARSH_TEMPERATE_FRESHWATER,
    matgloss_wood_flags_BIOME_MARSH_TEMPERATE_SALTWATER,
    matgloss_wood_flags_BIOME_SWAMP_TROPICAL_FRESHWATER,
    matgloss_wood_flags_BIOME_SWAMP_TROPICAL_SALTWATER,
    matgloss_wood_flags_BIOME_SWAMP_MANGROVE,
    matgloss_wood_flags_BIOME_MARSH_TROPICAL_FRESHWATER,
    matgloss_wood_flags_BIOME_MARSH_TROPICAL_SALTWATER,
    matgloss_wood_flags_BIOME_FOREST_TAIGA,
    matgloss_wood_flags_BIOME_FOREST_TEMPERATE_CONIFER,
    matgloss_wood_flags_BIOME_FOREST_TEMPERATE_BROADLEAF,
    matgloss_wood_flags_BIOME_FOREST_TROPICAL_CONIFER,
    matgloss_wood_flags_BIOME_FOREST_TROPICAL_DRY_BROADLEAF,
    matgloss_wood_flags_BIOME_FOREST_TROPICAL_MOIST_BROADLEAF,
    matgloss_wood_flags_BIOME_GRASSLAND_TEMPERATE,
    matgloss_wood_flags_BIOME_SAVANNA_TEMPERATE,
    matgloss_wood_flags_BIOME_SHRUBLAND_TEMPERATE,
    matgloss_wood_flags_BIOME_GRASSLAND_TROPICAL,
    matgloss_wood_flags_BIOME_SAVANNA_TROPICAL,
    matgloss_wood_flags_BIOME_SHRUBLAND_TROPICAL,
    matgloss_wood_flags_BIOME_DESERT_BADLAND,
    matgloss_wood_flags_BIOME_DESERT_ROCK,
    matgloss_wood_flags_BIOME_DESERT_SAND,
    matgloss_wood_flags_BIOME_OCEAN,
    matgloss_wood_flags_BIOME_INLAND_FRESHWATER,
    matgloss_wood_flags_BIOME_INLAND_BRACKISHWATER,
    matgloss_wood_flags_BIOME_INLAND_SALTWATER,
    matgloss_wood_flags_BIOME_SUBTERRANEAN_RIVER,
    matgloss_wood_flags_BIOME_SUBTERRANEAN_CHASM,
    matgloss_wood_flags_BIOME_SUBTERRANEAN_LAVA
};

struct meeting_diplomat_info;
struct meeting_context {
    struct meeting_diplomat_info *meeting;
    struct dipscript_popup *popup;
    int32_t meeting_context_anon_1;
    int32_t meeting_context_anon_2;
};

struct stl_vector_ptr_active_script_varst {
struct active_script_varst **ptr;
void *endptr;
void *endalloc;
};
enum T_flags_8171_enum {
    T_flags_8171_dynamic_load=0x01,
    T_flags_8171_failure=0x02,
    T_flags_8171_success=0x04
};

struct meeting_diplomat_info {
    int32_t civ_id;
    int16_t meeting_diplomat_info_anon_1;
    int16_t is_first_contact;
    int32_t diplomat_id;
    int32_t associate_id;
    struct stl_vector_int16_t topic_list;
    struct stl_vector_int32_t topic_parms;
    struct entity_sell_requests *sell_requests;
    struct entity_buy_requests *buy_requests;
    struct dipscript_info *dipscript;
    int32_t cur_step;
    struct stl_vector_ptr_active_script_varst active_script_vars;
    struct stl_string meeting_diplomat_info_anon_2;
    struct stl_string meeting_diplomat_info_anon_3;
    struct T_flags_8171 {
        int32_t bitfield;
    } meeting_diplomat_info_flags;
    struct stl_vector_ptr_meeting_event events;
    struct stl_vector_int32_t agreement_entity;
    struct stl_vector_int16_t agreement_topic;
    struct stl_vector_int32_t agreement_year;
    struct stl_vector_int32_t agreement_season;
    struct stl_vector_int32_t agreement_season_tick;
    struct stl_vector_int16_t agreement_outcome;
    struct stl_vector_int32_t contact_entity;
    struct stl_vector_int32_t contact_year;
    struct stl_vector_int32_t contact_season;
    struct stl_vector_int32_t contact_season_tick;
};

enum meeting_event_type {
    meeting_event_type_AcceptAgreement,
    meeting_event_type_RejectAgreement,
    meeting_event_type_AcceptPeace,
    meeting_event_type_RejectPeace,
    meeting_event_type_ExportAgreement,
    meeting_event_type_ImportAgreement,
    meeting_event_type_LiaisonRequest
};

enum meeting_topic {
    meeting_topic_DiscussCurrent,
    meeting_topic_RequestPeace,
    meeting_topic_TreeQuota,
    meeting_topic_ExportAgreement,
    meeting_topic_ImportAgreement,
    meeting_topic_MakeLiaisonRequest,
    meeting_topic_PleasantPlace
};

struct meeting_variable {
    int32_t value;
    struct specific_ref ref;
    struct active_script_varst *active_var;
};

struct mineral_cluster {
    int16_t x1;
    int16_t x2;
    int16_t y1;
    int16_t y2;
    int16_t z;
    int16_t color;
    int16_t material;
    int16_t matgloss;
};

enum misc_trait_type {
    misc_trait_type_RequestWaterCooldown,
    misc_trait_type_RequestFoodCooldown,
    misc_trait_type_RequestRescueCooldown,
    misc_trait_type_GetDrinkCooldown,
    misc_trait_type_GetFoodCooldown,
    misc_trait_type_Migrant,
    misc_trait_type_RoomComplaint,
    misc_trait_type_ResidentCreature,
    misc_trait_type_RentBedroomCooldown,
    misc_trait_type_ClaimTrinketCooldown,
    misc_trait_type_ClaimClothingCooldown,
    misc_trait_type_WantsDrink,
    misc_trait_type_LikesOutdoors,
    misc_trait_type_Hardened,
    misc_trait_type_TimeSinceBreak,
    misc_trait_type_OnBreak,
    misc_trait_type_PrepareToDie,
    misc_trait_type_CaveAdapt
};

enum mood_type {
    mood_type_None = -1,
    mood_type_Fey,
    mood_type_Secretive,
    mood_type_Possessed,
    mood_type_Macabre,
    mood_type_Fell,
    mood_type_Melancholy,
    mood_type_Raving,
    mood_type_Berserk,
    mood_type_Baby
};

enum nemesis_flags {
    nemesis_flags_Adventurer = 2,
    nemesis_flags_ImportantCivMember
};

enum pants_flags {
    pants_flags_CHAIN_METAL,
    pants_flags_METAL_ARMOR_LEVELS
};

enum part_of_speech {
    part_of_speech_Noun,
    part_of_speech_NounPlural,
    part_of_speech_Adjective,
    part_of_speech_Prefix,
    part_of_speech_Verb,
    part_of_speech_Verb3rdPerson,
    part_of_speech_VerbPast,
    part_of_speech_VerbPassive,
    part_of_speech_VerbGerund
};

struct party_info {
    struct stl_vector_ptr_unit units;
    struct buildingst *location;
    int32_t timer;
    int32_t id;
};

struct pet_info {
    int32_t id;
    int32_t pet_item_id;
    int32_t pet_unit_id;
    struct language_name name;
    int32_t unk3;
    int32_t pet_info_owner_id;
};

struct vegst;
typedef void (*vm_vegst_addContaminant)(vegst* this,int32_t type,material_type material,int32_t size);
typedef void (*vm_vegst_removeContaminantByIdx)(vegst* this,int32_t index,int32_t amount);
typedef void (*vm_vegst_removeContaminantByType)(vegst* this,int32_t type,material_type material,int32_t amount);
enum T_damage_flags_8329_enum {
    T_damage_flags_8329_is_burning=0x01
};

struct vtable_vegst {
    vm_vegst_addContaminant addContaminant;
    vm_vegst_removeContaminantByIdx removeContaminantByIdx;
    vm_vegst_removeContaminantByType removeContaminantByType;
};
struct vegst {
    struct vtable_vegst *vtable;
    struct language_name name;
    int32_t plant_flags;
    union {
        int16_t plant_id;
        int16_t wood_id;
    };
    struct coord pos;
    int32_t grow_counter;
    struct temperaturest temperature;
    struct T_damage_flags_8329 {
        int32_t bitfield;
    } plant_damage_flags;
    int32_t hitpoints;
    struct stl_vector_ptr_contaminant contaminants;
    int32_t temp_updated_frame;
};

enum plant_flags {
    plant_flags_tree_outdoor_wet,
    plant_flags_tree_outdoor_dry,
    plant_flags_tree_indoor_dry,
    plant_flags_tree_indoor_wet,
    plant_flags_shrub_forest,
    plant_flags_shrub_swamp,
    plant_flags_shrub_river,
    plant_flags_shrub_cave
};

enum profession {
    profession_NONE = -1,
    profession_MINER,
    profession_CARPENTER,
    profession_MASON,
    profession_TRAPPER,
    profession_METALSMITH,
    profession_JEWELER,
    profession_CRAFTSMAN,
    profession_KING,
    profession_KING_CONSORT,
    profession_FISHERMAN,
    profession_FARMER,
    profession_MECHANIC,
    profession_MANAGER,
    profession_MAYOR,
    profession_GOVERNOR,
    profession_BROKER,
    profession_MINISTER_TRADE,
    profession_GUILDMASTER,
    profession_BOOKKEEPER,
    profession_TREASURER,
    profession_HOARDMASTER,
    profession_TAXCOLLECTOR,
    profession_EXECUTIONER,
    profession_SHERIFF,
    profession_BARON,
    profession_COUNT,
    profession_DUKE,
    profession_BARON_CONSORT,
    profession_COUNT_CONSORT,
    profession_DUKE_CONSORT,
    profession_GUILD_MINER,
    profession_GUILD_CARPENTER,
    profession_GUILD_MASON,
    profession_GUILD_METALSMITH,
    profession_GUILD_JEWELER,
    profession_GUILD_CRAFTSMAN,
    profession_HOUSE_DEATH,
    profession_HOUSE_ANIMAL,
    profession_HOUSE_FARMER,
    profession_PHILOSOPHER,
    profession_ADVISOR,
    profession_CULT_AXE,
    profession_CULT_MACE,
    profession_CULT_SWORD,
    profession_CULT_HAMMER,
    profession_CULT_CROSSBOW,
    profession_CULT_SPEAR,
    profession_ALCHEMIST,
    profession_DUNGEONMASTER,
    profession_MERCHANT,
    profession_DIPLOMAT,
    profession_GUILDREP,
    profession_MERCHANTBARON,
    profession_MERCHANTPRINCE,
    profession_OUTPOSTLIAISON,
    profession_DRUID,
    profession_CHAMPION,
    profession_HAMMERMAN,
    profession_MASTER_HAMMERMAN,
    profession_SPEARMAN,
    profession_MASTER_SPEARMAN,
    profession_CROSSBOWMAN,
    profession_MASTER_CROSSBOWMAN,
    profession_WRESTLER,
    profession_MASTER_WRESTLER,
    profession_AXEMAN,
    profession_MASTER_AXEMAN,
    profession_SWORDSMAN,
    profession_MASTER_SWORDSMAN,
    profession_MACEMAN,
    profession_MASTER_MACEMAN,
    profession_PIKEMAN,
    profession_MASTER_PIKEMAN,
    profession_BOWMAN,
    profession_MASTER_BOWMAN,
    profession_BLOWGUNMAN,
    profession_MASTER_BLOWGUNMAN,
    profession_RECRUIT,
    profession_TRAINED_HUNTER,
    profession_TRAINED_WAR,
    profession_MASTER_THIEF,
    profession_THIEF,
    profession_STANDARD,
    profession_CHILD,
    profession_BABY,
    profession_DRUNK,
    profession_LASHER,
    profession_MASTER_LASHER
};

struct projst;
enum projectile_type {
    projectile_type_Item,
    projectile_type_Unit,
    projectile_type_Magic
};

typedef projectile_type (*vm_projst_getType)(projst* this);
typedef bool (*vm_projst_checkImpact)(projst* this,bool noDamageFloor);
typedef bool (*vm_projst_checkMovement)(projst* this);
typedef void (*vm_projst_read_file)(projst* this,void*,int32_t loadversion);
typedef void (*vm_projst_write_file)(projst* this,void*);
typedef void (*vm_projst_drawSelf)(projst* this);
typedef void (*vm_projst_vmeth_24)(projst* this);
struct proj_list_link;
enum projectile_flags_enum {
    projectile_flags_no_destroy_on_impact=0x01,
    projectile_flags_has_hit_ground=0x02,
    projectile_flags_bouncing=0x04,
    projectile_flags_high_flying=0x08,
    projectile_flags_pierces=0x10,
    projectile_flags_to_be_deleted=0x20
};

struct projectile_flags {
    uint8_t bitfield;
};

struct vtable_projst {
    vm_projst_getType getType;
    vm_projst_checkImpact checkImpact;
    vm_projst_checkMovement checkMovement;
    vm_projst_read_file read_file;
    vm_projst_write_file write_file;
    vm_projst_drawSelf drawSelf;
    vm_projst_vmeth_24 vmeth_24;
};
struct projst {
    struct vtable_projst *vtable;
    struct proj_list_link *link;
    int32_t id;
    struct unit *firer;
    struct coord32 origin_pos;
    struct coord32 target_pos;
    struct coord32 cur_pos;
    int32_t distance_flown;
    int32_t fall_threshold;
    int32_t min_hit_distance;
    int32_t min_ground_distance;
    struct coord32 prev_pos;
    struct projectile_flags projectile_flags;
    int16_t fall_counter;
    int16_t fall_delay;
    int32_t skill_level;
    int32_t throw_strength;
};

struct proj_itemst {
        struct vtable_projst *vtable;
        struct proj_list_link *link;
        int32_t id;
        struct unit *firer;
        struct coord32 origin_pos;
        struct coord32 target_pos;
        struct coord32 cur_pos;
        int32_t distance_flown;
        int32_t fall_threshold;
        int32_t min_hit_distance;
        int32_t min_ground_distance;
        struct coord32 prev_pos;
        struct projectile_flags projst_flags;
        int16_t fall_counter;
        int16_t fall_delay;
        int32_t skill_level;
        int32_t throw_strength;
    struct itemst *item;
};

struct proj_list_link {
    struct projst *item;
    struct proj_list_link *prev;
    struct proj_list_link *next;
};

struct proj_magicst {
        struct vtable_projst *vtable;
        struct proj_list_link *link;
        int32_t id;
        struct unit *firer;
        struct coord32 origin_pos;
        struct coord32 target_pos;
        struct coord32 cur_pos;
        int32_t distance_flown;
        int32_t fall_threshold;
        int32_t min_hit_distance;
        int32_t min_ground_distance;
        struct coord32 prev_pos;
        struct projectile_flags projst_flags;
        int16_t fall_counter;
        int16_t fall_delay;
        int32_t skill_level;
        int32_t throw_strength;
    int16_t proj_magicst_anon_1;
    int16_t proj_magicst_anon_2;
};

struct proj_unitst {
        struct vtable_projst *vtable;
        struct proj_list_link *link;
        int32_t id;
        struct unit *firer;
        struct coord32 origin_pos;
        struct coord32 target_pos;
        struct coord32 cur_pos;
        int32_t distance_flown;
        int32_t fall_threshold;
        int32_t min_hit_distance;
        int32_t min_ground_distance;
        struct coord32 prev_pos;
        struct projectile_flags projst_flags;
        int16_t fall_counter;
        int16_t fall_delay;
        int32_t skill_level;
        int32_t throw_strength;
    struct unit *unit;
};

struct punishment_info {
    struct unit *criminal;
    struct unit *officer;
    int16_t beating;
    int16_t hammer_strikes;
    int32_t prison_counter;
    int16_t delay;
    struct buildingst *jail;
    struct stl_vector_ptr_unit victims;
};

struct quest_list_link {
    struct taskst *item;
    struct quest_list_link *prev;
    struct quest_list_link *next;
};

enum region_biome_type {
    region_biome_type_SWAMP,
    region_biome_type_DESERT,
    region_biome_type_FOREST,
    region_biome_type_MOUNTAINS,
    region_biome_type_OCEAN,
    region_biome_type_LAKE,
    region_biome_type_GLACIER,
    region_biome_type_TUNDRA,
    region_biome_type_GRASSLAND,
    region_biome_type_HILLS
};

enum T_type_15234 {
    T_type_15234_PlayerFortress,
    T_type_15234_DarkFortress,
    T_type_15234_Cave,
    T_type_15234_MountainHalls,
    T_type_15234_ForestRetreat,
    T_type_15234_Town,
    T_type_15234_LostFortress,
    T_type_15234_Ruin
};

struct stl_vector_ptr_abstract_building {
struct abstract_building **ptr;
void *endptr;
void *endalloc;
};
struct world_site {
    struct language_name name;
    int32_t civ_id;
    int32_t world_site_owner1;
    int32_t type;
    struct coord2d region_indoor;
    struct coord2d region_outdoor;
    int32_t id;
    struct stl_vector_int32_t nemesis;
    int32_t world_site_anon_1;
    void *world_site_anon_2;
    struct df_flagarray world_site_flags;
    struct stl_vector_ptr_abstract_building buildings;
    int32_t next_building_id;
};

struct stl_vector_ptr_world_site {
struct world_site **ptr;
void *endptr;
void *endalloc;
};
enum T_clouds_15343_enum {
    T_clouds_15343_front=0x03,
    T_clouds_15343_cumulus=0x0C,
    T_clouds_15343_cirrus=0x10,
    T_clouds_15343_stratus=0x60,
    T_clouds_15343_fog=0x180,
    T_clouds_15343_countdown=0x1E00
};

enum T_wind_15351_enum {
    T_wind_15351_north_1=0x01,
    T_wind_15351_south_1=0x02,
    T_wind_15351_east_1=0x04,
    T_wind_15351_west_1=0x08,
    T_wind_15351_north_2=0x10,
    T_wind_15351_south_2=0x20,
    T_wind_15351_east_2=0x40,
    T_wind_15351_west_2=0x80
};

struct region_map_entry {
    int32_t temp_distance;
    struct stl_vector_ptr_world_site sites;
    struct df_flagarray region_map_entry_flags;
    int16_t elevation;
    int16_t rainfall;
    int16_t vegetation;
    int16_t temperature;
    int16_t evilness;
    int16_t drainage;
    int16_t savagery;
    int16_t air_temp;
    int16_t air_x;
    int16_t air_y;
    struct T_clouds_15343 {
        uint16_t bitfield;
    } clouds;
    struct T_wind_15351 {
        uint16_t bitfield;
    } wind;
    int16_t snowfall;
    int16_t salinity;
    struct coord _unk_3e;
    struct coord _unk_44;
    struct coord _unk_4a;
    int32_t region_id;
};

enum region_map_entry_flags {
    region_map_entry_flags_has_river,
    region_map_entry_flags_tile_variant,
    region_map_entry_flags_has_site = 3,
    region_map_entry_flags_river_up = 5,
    region_map_entry_flags_river_down,
    region_map_entry_flags_river_right,
    region_map_entry_flags_river_left,
    region_map_entry_flags_discovered = 10,
    region_map_entry_flags_visible
};

struct region_population {
    int16_t type;
    union {
        int16_t race;
        int16_t plant;
        int16_t tree;
    };
};

enum region_property_type {
    region_property_type_elevation,
    region_property_type_rainfall,
    region_property_type_vegetation,
    region_property_type_temperature,
    region_property_type_evilness,
    region_property_type_drainage,
    region_property_type_savagery,
    region_property_type_air_temp,
    region_property_type_air_x,
    region_property_type_air_y,
    region_property_type_clouds,
    region_property_type_wind,
    region_property_type_snowfall,
    region_property_type_salinity
};

enum T_flags_8259_enum {
    T_flags_8259_eviction_underway=0x01,
    T_flags_8259_move_underway=0x02
};

struct room_rent_info {
    struct stl_vector_ptr_buildingst elements;
    int32_t rent_value;
    struct T_flags_8259 {
        int32_t bitfield;
    } room_rent_info_flags;
};

struct schedule_slot {
    int16_t type;
    int16_t start_time;
    int16_t end_time;
    int16_t schedule_slot_anon_1;
    int8_t processed;
};

struct stl_vector_ptr_schedule_slot {
struct schedule_slot **ptr;
void *endptr;
void *endalloc;
};
struct schedule_info {
    int32_t id;
    struct stl_vector_ptr_schedule_slot slots;
};

struct script_step_conditionalst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
    struct T_condition_8073 {
        struct stl_string var1_type;
        struct stl_string var1_name;
        struct stl_string comparison;
        struct stl_string var2_type;
        struct stl_string var2_name;
    } condition;
    int32_t conditional_next_step_idx;
};

struct script_step_constructtopiclistst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
};

struct script_step_eventst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
};

struct script_step_dipeventst {
            struct vtable_script_stepst *vtable;
            int32_t next_step_idx;
    struct stl_string parm1;
    struct stl_string parm2;
    struct stl_string parm3;
    struct stl_string parm4;
    struct stl_string parm5;
};

struct script_step_diphistoryst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
    char event[80];
};

struct script_step_discussst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
    char event[12];
};

struct script_step_invasionst {
            struct vtable_script_stepst *vtable;
            int32_t next_step_idx;
    struct stl_string parm;
};

struct script_step_setvarst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
    struct stl_string dest_type;
    struct stl_string dest_name;
    struct stl_string src_type;
    struct stl_string src_name;
};

struct script_step_simpleactionst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
    struct stl_string type;
    struct stl_string subtype;
};

struct script_step_textviewerst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
    struct stl_string filename;
    struct stl_string outvar_name;
};

struct script_step_topicdiscussionst {
        struct vtable_script_stepst *vtable;
        int32_t next_step_idx;
};

struct script_var_longst {
        struct vtable_script_varst *vtable;
        struct stl_string name;
};

struct script_var_unitst {
        struct vtable_script_varst *vtable;
        struct stl_string name;
};

enum shoes_flags {
    shoes_flags_METAL_ARMOR_LEVELS = 1
};

enum shop_type {
    shop_type_GeneralStore,
    shop_type_CraftsMarket,
    shop_type_ClothingShop,
    shop_type_ExoticClothingShop
};

enum siegeengine_type {
    siegeengine_type_Catapult,
    siegeengine_type_Ballista
};

enum site_flags {
    site_flags_Hidden,
    site_flags_Destroyed = 2
};

enum site_type {
    site_type_PLAYER_FORTRESS,
    site_type_DARK_FORTRESS,
    site_type_CAVE,
    site_type_CAVE_DETAILED,
    site_type_TREE_CITY,
    site_type_CITY,
    site_type_FORTRESS = 8
};

enum skill_rating {
    skill_rating_Dabbling,
    skill_rating_Novice,
    skill_rating_Adequate,
    skill_rating_Competent,
    skill_rating_Skilled,
    skill_rating_Proficient,
    skill_rating_Talented,
    skill_rating_Adept,
    skill_rating_Expert,
    skill_rating_Professional,
    skill_rating_Accomplished,
    skill_rating_Great,
    skill_rating_Master,
    skill_rating_HighMaster,
    skill_rating_GrandMaster,
    skill_rating_Legendary,
    skill_rating_Legendary1,
    skill_rating_Legendary2,
    skill_rating_Legendary3,
    skill_rating_Legendary4,
    skill_rating_Legendary5
};

enum specific_ref_type {
    specific_ref_type_BUILDING_GENERAL,
    specific_ref_type_UNIT_INVENTORY,
    specific_ref_type_JOB,
    specific_ref_type_BUILDING_PARTY,
    specific_ref_type_UNIT_TRAINEE,
    specific_ref_type_UNIT_ITEMOWNER,
    specific_ref_type_UNIT_TRADEBRINGER,
    specific_ref_type_UNIT_CAGEE,
    specific_ref_type_UNIT_BEATEE,
    specific_ref_type_UNIT_FOODRECEIVER,
    specific_ref_type_UNIT_KIDNAPEE,
    specific_ref_type_UNIT_PATIENT,
    specific_ref_type_UNIT_INFANT,
    specific_ref_type_ENTITY_ITEMOWNER,
    specific_ref_type_ENTITY_STOLEN,
    specific_ref_type_ENTITY_OFFERED,
    specific_ref_type_ACTIVITY,
    specific_ref_type_ITEM_GENERAL,
    specific_ref_type_CONTAINS_ITEM,
    specific_ref_type_CONTAINED_IN_ITEM,
    specific_ref_type_CONTAINS_UNIT,
    specific_ref_type_EFFECT,
    specific_ref_type_DRINK_AREA,
    specific_ref_type_BUILDING_TRIGGER,
    specific_ref_type_BUILDING_TRIGGERTARGET,
    specific_ref_type_BUILDING_CHAIN,
    specific_ref_type_BUILDING_CAGED,
    specific_ref_type_BUILDING_CIVZONE_ASSIGNED,
    specific_ref_type_BUILDING_CHANNELED,
    specific_ref_type_PETINFO_PET,
    specific_ref_type_PETINFO_OWNER,
    specific_ref_type_VERMIN_EVENT,
    specific_ref_type_VERMIN_ESCAPED_PET,
    specific_ref_type_ENTITY,
    specific_ref_type_PLOT_INFO,
    specific_ref_type_VIEWSCREEN,
    specific_ref_type_IS_NEMESIS,
    specific_ref_type_UNIT_ITEM_WRESTLE,
    specific_ref_type_IS_ARTIFACT,
    specific_ref_type_NULL_REF,
    specific_ref_type_DEFAULT,
    specific_ref_type_UNIT_SLAUGHTEREE,
    specific_ref_type_HIST_FIG,
    specific_ref_type_SITE,
    specific_ref_type_ARTIFACT,
    specific_ref_type_ITEM_IMPROVEMENT,
    specific_ref_type_COIN_FRONT,
    specific_ref_type_COIN_BACK,
    specific_ref_type_DETAIL_EVENT,
    specific_ref_type_SUBREGION,
    specific_ref_type_ART_IMAGE,
    specific_ref_type_CREATURE_DEF,
    specific_ref_type_PROJECTILE,
    specific_ref_type_GENERAL_REF
};

enum stockpile_category {
    stockpile_category_Remove,
    stockpile_category_Animal,
    stockpile_category_Food,
    stockpile_category_Furniture,
    stockpile_category_Graveyard,
    stockpile_category_Refuse,
    stockpile_category_Stone,
    stockpile_category_Ore,
    stockpile_category_Mining,
    stockpile_category_Ammo,
    stockpile_category_Coins,
    stockpile_category_BarBlock,
    stockpile_category_Gem,
    stockpile_category_FinishedGoods,
    stockpile_category_Leather,
    stockpile_category_Cloth,
    stockpile_category_Wood,
    stockpile_category_Weapons,
    stockpile_category_Armor,
    stockpile_category_Custom
};

enum stockpile_list {
    stockpile_list_Animals,
    stockpile_list_Food,
    stockpile_list_FoodMeatFish,
    stockpile_list_FoodUnpreparedFish,
    stockpile_list_FoodPlants,
    stockpile_list_FoodDrinkPlant,
    stockpile_list_FoodDrinkAnimal,
    stockpile_list_FoodCheesePlant,
    stockpile_list_FoodCheeseAnimal,
    stockpile_list_FoodSeeds,
    stockpile_list_FoodLeaves,
    stockpile_list_FoodMilledPlant,
    stockpile_list_FoodBoneMeal,
    stockpile_list_FoodFat,
    stockpile_list_FoodExtractPlant,
    stockpile_list_FoodExtractAnimal,
    stockpile_list_FoodMiscLiquid,
    stockpile_list_Furniture,
    stockpile_list_FurnitureType,
    stockpile_list_FurnitureMaterial,
    stockpile_list_Graveyard,
    stockpile_list_Refuse,
    stockpile_list_Stone,
    stockpile_list_Ore,
    stockpile_list_Ammo,
    stockpile_list_AmmoType,
    stockpile_list_AmmoMaterial,
    stockpile_list_Coins,
    stockpile_list_BarsBlocks,
    stockpile_list_BarsMaterial,
    stockpile_list_BlocksMaterial,
    stockpile_list_Gems,
    stockpile_list_RoughMaterial,
    stockpile_list_CutMaterial,
    stockpile_list_Goods,
    stockpile_list_GoodsType,
    stockpile_list_GoodsMaterial,
    stockpile_list_Leather,
    stockpile_list_Cloth,
    stockpile_list_ThreadSilk,
    stockpile_list_ThreadPlant,
    stockpile_list_ClothSilk,
    stockpile_list_ClothPlant,
    stockpile_list_Wood,
    stockpile_list_Weapons,
    stockpile_list_WeaponsType,
    stockpile_list_WeaponsTrapcomp,
    stockpile_list_WeaponsMaterial,
    stockpile_list_Armor,
    stockpile_list_ArmorBody,
    stockpile_list_ArmorHead,
    stockpile_list_ArmorFeet,
    stockpile_list_ArmorHands,
    stockpile_list_ArmorLegs,
    stockpile_list_ArmorShield,
    stockpile_list_ArmorMaterial
};

enum stratus_type {
    stratus_type_stratus_none,
    stratus_type_stratus_alto,
    stratus_type_stratus_proper,
    stratus_type_stratus_nimbus
};

struct task_kill_nemesisst {
        struct quest_list_link *link;
        int32_t id;
        int32_t giver_hf;
        int32_t giver_site;
        int32_t giver_entity;
        int32_t recipient_hf;
        int32_t taskst_anon_1;
        struct coord2d32 target_pos;
        struct coord2d32 giver_pos;
    int32_t task_kill_nemesisst_anon_1;
    int32_t target_site;
    int32_t target_hf;
    int8_t completed;
};

struct text_info_elementst;
typedef void (*vm_text_info_elementst_getString)(text_info_elementst* this,void* val);
typedef int32_t (*vm_text_info_elementst_getLong)(text_info_elementst* this);
typedef void (*vm_text_info_elementst_vmeth_8)(text_info_elementst* this);
struct vtable_text_info_elementst {
    vm_text_info_elementst_getString getString;
    vm_text_info_elementst_getLong getLong;
    vm_text_info_elementst_vmeth_8 vmeth_8;
};
struct text_info_elementst {
    struct vtable_text_info_elementst *vtable;
};

struct stl_vector_ptr_text_info_elementst {
struct text_info_elementst **ptr;
void *endptr;
void *endalloc;
};
struct text_info {
    struct stl_vector_ptr_text_info_elementst elements;
};

struct text_info_element_longst {
        struct vtable_text_info_elementst *vtable;
    int32_t val;
};

struct text_info_element_stringst {
        struct vtable_text_info_elementst *vtable;
    struct stl_string val;
};

struct tile_bitmask {
    uint16_t bits[16];
};

enum tile_building_occ {
    tile_building_occ_None,
    tile_building_occ_Planned,
    tile_building_occ_Passable,
    tile_building_occ_Impassable
};

enum tile_chr {
    tile_chr_Void,
    tile_chr_Gem = 15,
    tile_chr_Tree = 24,
    tile_chr_OpenSpace = 32,
    tile_chr_Shrub = 34,
    tile_chr_Chasm,
    tile_chr_RampTop,
    tile_chr_Floor1 = 39,
    tile_chr_FloorSmooth = 43,
    tile_chr_Floor2,
    tile_chr_Floor4 = 46,
    tile_chr_StairU = 60,
    tile_chr_StairD = 62,
    tile_chr_Fortification = 65,
    tile_chr_Campfire = 67,
    tile_chr_Fire = 70,
    tile_chr_Pillar = 79,
    tile_chr_Waterfall = 87,
    tile_chr_StairUD,
    tile_chr_Channel = 95,
    tile_chr_Floor3,
    tile_chr_Ashes3 = 126,
    tile_chr_Ore = 156,
    tile_chr_WallWorn1 = 176,
    tile_chr_WallWorn2,
    tile_chr_WallWorn3,
    tile_chr_WallSmoothLD2 = 183,
    tile_chr_WallSmoothL2D,
    tile_chr_WallSmoothLUD,
    tile_chr_WallSmoothUD,
    tile_chr_WallSmoothLD,
    tile_chr_WallSmoothLU,
    tile_chr_WallSmoothLU2,
    tile_chr_WallSmoothL2U,
    tile_chr_WallSmoothRU = 200,
    tile_chr_WallSmoothRD,
    tile_chr_WallSmoothLRU,
    tile_chr_WallSmoothLRD,
    tile_chr_WallSmoothRUD,
    tile_chr_WallSmoothLR,
    tile_chr_WallSmoothLRUD,
    tile_chr_WallSmoothRU2 = 211,
    tile_chr_WallSmoothR2U,
    tile_chr_WallSmoothR2D,
    tile_chr_WallSmoothRD2,
    tile_chr_Wall = 219,
    tile_chr_Sapling = 231,
    tile_chr_Ramp = 240,
    tile_chr_Ashes1 = 242,
    tile_chr_Ashes2,
    tile_chr_River = 247
};

enum tiletype {
    tiletype_Void,
    tiletype_GemWallRed,
    tiletype_GemWallGreen,
    tiletype_GemWallBlue,
    tiletype_GemWallWhite,
    tiletype_CoalWall,
    tiletype_Tree,
    tiletype_TreeDead,
    tiletype_OpenSpace,
    tiletype_Shrub,
    tiletype_ShrubDead,
    tiletype_Chasm,
    tiletype_ChasmDead,
    tiletype_EeriePit,
    tiletype_StoneRampTop,
    tiletype_DarkStoneRampTop,
    tiletype_LightStoneRampTop,
    tiletype_WoodRampTop,
    tiletype_StoneFloor1,
    tiletype_StoneFloor2,
    tiletype_StoneFloor3,
    tiletype_StoneFloor4,
    tiletype_DarkStoneFloor1,
    tiletype_DarkStoneFloor2,
    tiletype_DarkStoneFloor3,
    tiletype_DarkStoneFloor4,
    tiletype_LightStoneFloor1,
    tiletype_LightStoneFloor2,
    tiletype_LightStoneFloor3,
    tiletype_LightStoneFloor4,
    tiletype_GrassDarkFloor1,
    tiletype_GrassDarkFloor2,
    tiletype_GrassDarkFloor3,
    tiletype_GrassDarkFloor4,
    tiletype_GrassLightFloor1,
    tiletype_GrassLightFloor2,
    tiletype_GrassLightFloor3,
    tiletype_GrassLightFloor4,
    tiletype_DirtFloor1,
    tiletype_DirtFloor2,
    tiletype_DirtFloor3,
    tiletype_DirtFloor4,
    tiletype_StoneFloorSmooth,
    tiletype_DarkStoneFloorSmooth,
    tiletype_LightStoneFloorSmooth,
    tiletype_WoodFloorSmooth,
    tiletype_StoneStairU,
    tiletype_StoneStairD,
    tiletype_StoneStairUD,
    tiletype_DarkStoneStairU,
    tiletype_DarkStoneStairD,
    tiletype_DarkStoneStairUD,
    tiletype_LightStoneStairU,
    tiletype_LightStoneStairD,
    tiletype_LightStoneStairUD,
    tiletype_WoodStairU,
    tiletype_WoodStairD,
    tiletype_WoodStairUD,
    tiletype_StoneFortification,
    tiletype_DarkStoneFortification,
    tiletype_LightStoneFortification,
    tiletype_Campfire,
    tiletype_Fire,
    tiletype_StonePillar,
    tiletype_DarkStonePillar,
    tiletype_LightStonePillar,
    tiletype_WoodPillar,
    tiletype_WaterfallDrain1,
    tiletype_WaterfallDrain2,
    tiletype_WaterfallDrain3,
    tiletype_StoneChannel,
    tiletype_DarkStoneChannel,
    tiletype_LightStoneChannel,
    tiletype_DirtChannel,
    tiletype_Ashes1,
    tiletype_Ashes2,
    tiletype_Ashes3,
    tiletype_TrampledDirt,
    tiletype_SphaleriteWall,
    tiletype_MalachiteWall,
    tiletype_HematiteWall,
    tiletype_CassiteriteWall,
    tiletype_GalenaWall,
    tiletype_AdamantineWall,
    tiletype_GoldWall,
    tiletype_PlatinumWall,
    tiletype_StoneWallWorn1,
    tiletype_StoneWallWorn2,
    tiletype_StoneWallWorn3,
    tiletype_DarkStoneWallWorn1,
    tiletype_DarkStoneWallWorn2,
    tiletype_DarkStoneWallWorn3,
    tiletype_LightStoneWallWorn1,
    tiletype_LightStoneWallWorn2,
    tiletype_LightStoneWallWorn3,
    tiletype_WoodWallWorn1,
    tiletype_WoodWallWorn2,
    tiletype_WoodWallWorn3,
    tiletype_StoneWallSmoothRD2,
    tiletype_StoneWallSmoothR2D,
    tiletype_StoneWallSmoothR2U,
    tiletype_StoneWallSmoothRU2,
    tiletype_StoneWallSmoothL2U,
    tiletype_StoneWallSmoothLU2,
    tiletype_StoneWallSmoothL2D,
    tiletype_StoneWallSmoothLD2,
    tiletype_StoneWallSmoothLRUD,
    tiletype_StoneWallSmoothRUD,
    tiletype_StoneWallSmoothLRD,
    tiletype_StoneWallSmoothLRU,
    tiletype_StoneWallSmoothLUD,
    tiletype_StoneWallSmoothRD,
    tiletype_StoneWallSmoothRU,
    tiletype_StoneWallSmoothLU,
    tiletype_StoneWallSmoothLD,
    tiletype_StoneWallSmoothUD,
    tiletype_StoneWallSmoothLR,
    tiletype_DarkStoneWallSmoothRD2,
    tiletype_DarkStoneWallSmoothR2D,
    tiletype_DarkStoneWallSmoothR2U,
    tiletype_DarkStoneWallSmoothRU2,
    tiletype_DarkStoneWallSmoothL2U,
    tiletype_DarkStoneWallSmoothLU2,
    tiletype_DarkStoneWallSmoothL2D,
    tiletype_DarkStoneWallSmoothLD2,
    tiletype_DarkStoneWallSmoothLRUD,
    tiletype_DarkStoneWallSmoothRUD,
    tiletype_DarkStoneWallSmoothLRD,
    tiletype_DarkStoneWallSmoothLRU,
    tiletype_DarkStoneWallSmoothLUD,
    tiletype_DarkStoneWallSmoothRD,
    tiletype_DarkStoneWallSmoothRU,
    tiletype_DarkStoneWallSmoothLU,
    tiletype_DarkStoneWallSmoothLD,
    tiletype_DarkStoneWallSmoothUD,
    tiletype_DarkStoneWallSmoothLR,
    tiletype_LightStoneWallSmoothRD2,
    tiletype_LightStoneWallSmoothR2D,
    tiletype_LightStoneWallSmoothR2U,
    tiletype_LightStoneWallSmoothRU2,
    tiletype_LightStoneWallSmoothL2U,
    tiletype_LightStoneWallSmoothLU2,
    tiletype_LightStoneWallSmoothL2D,
    tiletype_LightStoneWallSmoothLD2,
    tiletype_LightStoneWallSmoothLRUD,
    tiletype_LightStoneWallSmoothRUD,
    tiletype_LightStoneWallSmoothLRD,
    tiletype_LightStoneWallSmoothLRU,
    tiletype_LightStoneWallSmoothLUD,
    tiletype_LightStoneWallSmoothRD,
    tiletype_LightStoneWallSmoothRU,
    tiletype_LightStoneWallSmoothLU,
    tiletype_LightStoneWallSmoothLD,
    tiletype_LightStoneWallSmoothUD,
    tiletype_LightStoneWallSmoothLR,
    tiletype_WoodWallSmoothRD2,
    tiletype_WoodWallSmoothR2D,
    tiletype_WoodWallSmoothR2U,
    tiletype_WoodWallSmoothRU2,
    tiletype_WoodWallSmoothL2U,
    tiletype_WoodWallSmoothLU2,
    tiletype_WoodWallSmoothL2D,
    tiletype_WoodWallSmoothLD2,
    tiletype_WoodWallSmoothLRUD,
    tiletype_WoodWallSmoothRUD,
    tiletype_WoodWallSmoothLRD,
    tiletype_WoodWallSmoothLRU,
    tiletype_WoodWallSmoothLUD,
    tiletype_WoodWallSmoothRD,
    tiletype_WoodWallSmoothRU,
    tiletype_WoodWallSmoothLU,
    tiletype_WoodWallSmoothLD,
    tiletype_WoodWallSmoothUD,
    tiletype_WoodWallSmoothLR,
    tiletype_StoneWall,
    tiletype_DarkStoneWall,
    tiletype_LightStoneWall,
    tiletype_WoodWall,
    tiletype_Sapling,
    tiletype_SaplingDead,
    tiletype_StoneRamp,
    tiletype_DarkStoneRamp,
    tiletype_LightStoneRamp,
    tiletype_WoodRamp,
    tiletype_MurkyPool,
    tiletype_MurkyPool2,
    tiletype_MagmaFlow,
    tiletype_MagmaFlowBright,
    tiletype_River,
    tiletype_Waterfall,
    tiletype_WaterfallDrain0,
    tiletype_Mud,
    tiletype_Sand
};

enum tiletype_material {
    tiletype_material_NONE = -1,
    tiletype_material_AIR,
    tiletype_material_DIRT,
    tiletype_material_MUD,
    tiletype_material_SAND,
    tiletype_material_STONE,
    tiletype_material_STONE_LIGHT,
    tiletype_material_STONE_DARK,
    tiletype_material_WOOD,
    tiletype_material_ORE,
    tiletype_material_GEM,
    tiletype_material_GRASS_LIGHT,
    tiletype_material_GRASS_DARK,
    tiletype_material_PLANT,
    tiletype_material_HFS,
    tiletype_material_CAMPFIRE,
    tiletype_material_FIRE,
    tiletype_material_ASHES,
    tiletype_material_MAGMA,
    tiletype_material_POOL,
    tiletype_material_RIVER
};

enum tiletype_shape {
    tiletype_shape_NONE = -1,
    tiletype_shape_EMPTY,
    tiletype_shape_FLOOR,
    tiletype_shape_WALL,
    tiletype_shape_FORTIFICATION,
    tiletype_shape_STAIR_UP,
    tiletype_shape_STAIR_DOWN,
    tiletype_shape_STAIR_UPDOWN,
    tiletype_shape_RAMP,
    tiletype_shape_RAMP_TOP,
    tiletype_shape_TREE,
    tiletype_shape_SAPLING,
    tiletype_shape_SHRUB,
    tiletype_shape_ENDLESS_PIT,
    tiletype_shape_LIQUID,
    tiletype_shape_CHANNEL
};

enum tiletype_shape_basic {
    tiletype_shape_basic_None = -1,
    tiletype_shape_basic_Open,
    tiletype_shape_basic_Floor,
    tiletype_shape_basic_Ramp,
    tiletype_shape_basic_Wall,
    tiletype_shape_basic_Stair
};

enum tiletype_special {
    tiletype_special_NONE = -1,
    tiletype_special_NORMAL,
    tiletype_special_WATERFALL,
    tiletype_special_DRAIN_0,
    tiletype_special_DRAIN_1,
    tiletype_special_DRAIN_2,
    tiletype_special_DRAIN_3,
    tiletype_special_SMOOTH,
    tiletype_special_TRAMPLED,
    tiletype_special_DEAD,
    tiletype_special_WORN_1,
    tiletype_special_WORN_2,
    tiletype_special_WORN_3,
    tiletype_special_BRIGHT,
    tiletype_special_IRON,
    tiletype_special_COPPER,
    tiletype_special_TIN,
    tiletype_special_ZINC,
    tiletype_special_SILVER,
    tiletype_special_GOLD,
    tiletype_special_PLATINUM,
    tiletype_special_ADAMANTINE,
    tiletype_special_COAL,
    tiletype_special_RED,
    tiletype_special_GREEN,
    tiletype_special_BLUE,
    tiletype_special_WHITE
};

enum tiletype_variant {
    tiletype_variant_NONE = -1,
    tiletype_variant_VAR_1,
    tiletype_variant_VAR_2,
    tiletype_variant_VAR_3,
    tiletype_variant_VAR_4
};

struct timed_event {
    int16_t type;
    int8_t season;
    int16_t season_ticks;
    struct historical_entity *entity;
};

enum timed_event_type {
    timed_event_type_Caravan,
    timed_event_type_Migrants,
    timed_event_type_Diplomat,
    timed_event_type_CivAttack,
    timed_event_type_RiverAttack,
    timed_event_type_ChasmAttack,
    timed_event_type_MagmaAttack,
    timed_event_type_TooDeep,
    timed_event_type_Megabeast,
    timed_event_type_CuriousBeasts
};

enum toy_flags {
    toy_flags_HARD_MAT
};

enum trap_type {
    trap_type_Lever,
    trap_type_PressurePlate,
    trap_type_CageTrap,
    trap_type_StoneFallTrap,
    trap_type_WeaponTrap
};

struct stl_vector_ptr_caravan_state {
struct caravan_state **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_activity_info {
struct activity_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_meeting_diplomat_info {
struct meeting_diplomat_info **ptr;
void *endptr;
void *endalloc;
};
enum T_flags_12717_enum {
    T_flags_12717_active=0x01,
    T_flags_12717_siege=0x02,
    T_flags_12717_history=0x04
};

struct stl_vector_ptr_crime_info {
struct crime_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_punishment_info {
struct punishment_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_pet_info {
struct pet_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_party_info {
struct party_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_room_rent_info {
struct room_rent_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_dipscript_info {
struct dipscript_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_dipscript_popup {
struct dipscript_popup **ptr;
void *endptr;
void *endalloc;
};
enum T_flags_12748_enum {
    T_flags_12748_first_year=0x01,
    T_flags_12748_recalc_entrypoints=0x02,
    T_flags_12748_clear_aid_timeouts=0x04
};

struct ui {
    int32_t gameover_type;
    int32_t gameover_sieger;
    struct T_tax_collection_12642 {
        int16_t state;
        int32_t check_timer;
        struct stl_vector_ptr_buildingst rooms;
        int32_t reach_room_timer;
        int32_t tc_protect_timer;
        int32_t guard1_reach_tc_timer;
        int32_t guard2_reach_tc_timer;
        int16_t collected;
        int16_t quota;
        int32_t tc_x;
        int32_t tc_y;
        int32_t tc_z;
        int32_t guard1_x;
        int32_t guard2_x;
        int32_t guard1_y;
        int32_t guard2_y;
        int32_t guard1_z;
        int32_t guard2_z;
        struct unit *collector;
        struct unit *guard1;
        struct unit *guard2;
        int8_t guard_lack_complained;
    } tax_collection;
    struct stl_vector_ptr_caravan_state caravans;
    int8_t firstCaravan;
    struct coord32_path dwarfArrivalTiles;
    struct coord32_path roadInfo;
    int16_t progress_population;
    int16_t progress_trade;
    int16_t progress_production;
    int8_t king_arrived;
    int8_t king_hasty;
    int8_t anvil_arrived;
    int8_t economy_active;
    int8_t ignore_labor_shortage;
    int8_t justice_active;
    int16_t manager_timer;
    struct T_incoming_king_12684 {
        int32_t desired_architecture;
        int32_t desired_roads;
        int32_t desired_offerings;
    } incoming_king;
    int16_t nobles_enabled[88];
    int16_t nobles_arrived[88];
    int16_t units_killed[88];
    int32_t guild_wages[16];
    int16_t guild_happiness[16];
    int16_t labor_slowdown_timer[16];
    int32_t currency_value[64];
    int32_t trees_removed;
    int32_t adamantine_seasons;
    int32_t adamantine_mined;
    int32_t fortress_age;
    struct entity_activity_statistics tasks;
    struct stl_vector_int32_t meeting_requests;
    struct stl_vector_ptr_activity_info activities;
    struct stl_vector_ptr_meeting_diplomat_info dip_meeting_info;
    struct stl_vector_int32_t royal_guards;
    struct stl_vector_int32_t fortress_guards;
    struct stl_vector_int32_t aid_requesters;
    int8_t game_over;
    struct T_siege_12711 {
        int32_t attacker;
        int32_t active_size1;
        int32_t active_size2;
        int32_t size;
        int32_t timeout;
        struct T_flags_12717 {
            uint16_t bitfield;
        } flags;
    } siege;
    struct stl_vector_ptr_crime_info crimes;
    struct stl_vector_ptr_punishment_info punishments;
    struct stl_vector_ptr_pet_info pet_info;
    struct stl_vector_ptr_party_info parties;
    struct stl_vector_ptr_room_rent_info room_rent;
    struct stl_vector_ptr_dipscript_info dipscripts;
    struct stl_vector_ptr_dipscript_popup dipscript_popups;
    struct T_kitchen_12732 {
        struct stl_vector_int16_t item_types;
        struct stl_vector_int32_t item_subtypes;
        struct stl_vector_int16_t materials;
        struct stl_vector_int32_t matglosses;
        struct stl_vector_int8_t exc_types;
    } kitchen;
    struct T_flags_12748 {
        uint32_t bitfield;
    } ui_flags;
    int16_t unit_action_divisor;
    int16_t max_dig_depth;
    int16_t min_dig_depth;
    int16_t mood_cooldown;
    struct T_main_12757 {
        int16_t mode;
        int16_t unk1;
    } main;
    int8_t baron_needed;
    int8_t count_needed;
    int8_t duke_needed;
    int32_t civ_id;
    int32_t group_id;
    int16_t race_id;
    struct stl_vector_int16_t farm_crops;
    struct stl_vector_int8_t farm_seasons;
    int16_t feature_attack_counts[3];
    int8_t feature_initial_flood[3];
    struct T_economy_prices_12775 {
        struct T_price_adjustment_12776 {
            struct stl_vector_int32_t general_items;
            struct stl_vector_int32_t weapons;
            struct stl_vector_int32_t armor;
            struct stl_vector_int32_t handwear;
            struct stl_vector_int32_t footwear;
            struct stl_vector_int32_t headgear;
            struct stl_vector_int32_t legwear;
            struct stl_vector_int32_t prepared_food;
            struct stl_vector_int32_t potions;
            struct stl_vector_int32_t materials;
            struct stl_vector_int32_t wood;
            struct stl_vector_int32_t cloth;
            struct stl_vector_int32_t bone;
            struct stl_vector_int32_t ivory;
            struct stl_vector_int32_t horn;
            struct stl_vector_int32_t pearl;
            struct stl_vector_int32_t shell;
            struct stl_vector_int32_t leather;
            struct stl_vector_int32_t silk;
            struct stl_vector_int32_t gems;
            struct stl_vector_int32_t stone;
            struct stl_vector_int32_t meat_fish;
            struct stl_vector_int32_t plants;
            struct stl_vector_int32_t drinks;
            struct stl_vector_int32_t extract_animal;
            struct stl_vector_int32_t extract_plant;
            struct stl_vector_int32_t mill_animal;
            struct stl_vector_int32_t mill_plant;
            struct stl_vector_int32_t cheese_animal;
            struct stl_vector_int32_t cheese_plant;
            struct stl_vector_int32_t pets;
        } price_adjustment;
        struct T_price_setter_12809 {
            struct stl_vector_ptr_unit general_items;
            struct stl_vector_ptr_unit weapons;
            struct stl_vector_ptr_unit armor;
            struct stl_vector_ptr_unit handwear;
            struct stl_vector_ptr_unit footwear;
            struct stl_vector_ptr_unit headgear;
            struct stl_vector_ptr_unit legwear;
            struct stl_vector_ptr_unit prepared_food;
            struct stl_vector_ptr_unit potions;
            struct stl_vector_ptr_unit materials;
            struct stl_vector_ptr_unit wood;
            struct stl_vector_ptr_unit cloth;
            struct stl_vector_ptr_unit bone;
            struct stl_vector_ptr_unit ivory;
            struct stl_vector_ptr_unit horn;
            struct stl_vector_ptr_unit pearl;
            struct stl_vector_ptr_unit shell;
            struct stl_vector_ptr_unit leather;
            struct stl_vector_ptr_unit silk;
            struct stl_vector_ptr_unit gems;
            struct stl_vector_ptr_unit stone;
            struct stl_vector_ptr_unit meat_fish;
            struct stl_vector_ptr_unit plants;
            struct stl_vector_ptr_unit drinks;
            struct stl_vector_ptr_unit extract_animal;
            struct stl_vector_ptr_unit extract_plant;
            struct stl_vector_ptr_unit mill_animal;
            struct stl_vector_ptr_unit mill_plant;
            struct stl_vector_ptr_unit cheese_animal;
            struct stl_vector_ptr_unit cheese_plant;
            struct stl_vector_ptr_unit pets;
        } price_setter;
    } economy_prices;
    struct T_stockpile_12844 {
        int32_t reserved_bins;
        int32_t reserved_barrels;
        struct stockpile_settings custom_settings;
    } stockpile;
};

struct stl_vector_ptr_conversation {
struct conversation **ptr;
void *endptr;
void *endalloc;
};
struct ui_advmode {
    int16_t menu;
    int16_t ui_advmode_anon_1;
    int16_t ui_advmode_anon_2;
    int16_t ui_advmode_anon_3;
    int8_t travel_clouds;
    int8_t ui_advmode_anon_4;
    int8_t ui_advmode_anon_5;
    int32_t tick_counter;
    int32_t frame_counter;
    int16_t ui_advmode_anon_6;
    int8_t sleeping;
    int8_t sleep_interrupted;
    int8_t ui_advmode_anon_7;
    struct stl_vector_ptr_unit talk_targets;
    struct stl_vector_ptr_conversation conversations;
    int32_t talk_target_cursor;
    struct stl_vector_int32_t searched_x;
    struct stl_vector_int32_t searched_y;
    struct stl_vector_int32_t searched_z;
    struct stl_vector_int32_t searched_timeout;
    int8_t can_retire;
    int32_t ui_advmode_anon_8;
    int32_t ui_advmode_anon_9;
    int32_t skill_level;
    int8_t recalc_skill_level;
};

enum ui_advmode_menu {
    ui_advmode_menu_Default,
    ui_advmode_menu_Look,
    ui_advmode_menu_Talk,
    ui_advmode_menu_Inventory,
    ui_advmode_menu_Drop,
    ui_advmode_menu_ThrowItem,
    ui_advmode_menu_Wear,
    ui_advmode_menu_Remove,
    ui_advmode_menu_Interact,
    ui_advmode_menu_PutItem,
    ui_advmode_menu_PutInto,
    ui_advmode_menu_Eat,
    ui_advmode_menu_ThrowAim,
    ui_advmode_menu_Fire,
    ui_advmode_menu_Get,
    ui_advmode_menu_CombatPrefs,
    ui_advmode_menu_InteractHow,
    ui_advmode_menu_Announcements,
    ui_advmode_menu_Attack,
    ui_advmode_menu_UseBuilding,
    ui_advmode_menu_Travel,
    ui_advmode_menu_Wrestle,
    ui_advmode_menu_AttackConfirm,
    ui_advmode_menu_WrestleConfirm,
    ui_advmode_menu_SleepConfirm
};

struct ui_build_selector {
    struct T_criteria_12397 {
        struct stl_vector_int16_t item_types;
        struct stl_vector_int16_t materials;
        struct stl_vector_int32_t quantities;
        struct stl_vector_ptr item_vecs;
    } criteria;
    struct T_improved_12410 {
        struct stl_vector_ptr_itemst items;
        struct stl_vector_int16_t category;
    } improved;
    struct T_unimproved_12415 {
        struct stl_vector_ptr_itemst items;
        struct stl_vector_int16_t category;
    } unimproved;
    struct T_visible_12420 {
        struct stl_vector_ptr_itemst items;
        struct stl_vector_int8_t selected;
        struct stl_vector_int16_t quantity;
    } visible;
    struct stl_vector_ptr_itemst selected_items;
    int16_t categories_required;
    int16_t categories_total;
    int32_t cursor_position;
    int16_t cur_category;
    int16_t ui_build_selector_anon_1;
    int16_t min_items_needed;
};

enum T_type_12576 {
    T_type_12576_Item,
    T_type_12576_Floor,
    T_type_12576_Unit,
    T_type_12576_Building,
    T_type_12576_Vermin,
    T_type_12576_Flow,
    T_type_12576_Campfire,
    T_type_12576_Blood,
    T_type_12576_Vomit,
    T_type_12576_Slime,
    T_type_12576_Pus,
    T_type_12576_Ichor,
    T_type_12576_Goo,
    T_type_12576_ItemInBuilding,
    T_type_12576_Fire
};

struct T_items_12575 {
    int16_t type;
    union {
        struct itemst *item;
        struct unit *unit;
        struct buildingst *building;
        struct vermin *vermin;
        struct flow_info *flow;
        int8_t amount;
    };
} ;
struct stl_vector_ptr_T_items_12575 {
struct T_items_12575 **ptr;
void *endptr;
void *endalloc;
};
struct ui_look_list {
    struct stl_vector_ptr_T_items_12575 items;
};

struct stl_vector_ptr_interface_button_buildingst {
struct interface_button_buildingst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_interface_button_constructionst {
struct interface_button_constructionst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_interface_button_buttonst {
struct interface_button_buttonst **ptr;
void *endptr;
void *endalloc;
};
struct ui_sidebar_menus {
    struct T_workshop_job_12513 {
        struct stl_vector_ptr_interface_button_buildingst choices_all;
        struct stl_vector_ptr_interface_button_buildingst choices_visible;
        int32_t cursor;
        int32_t category_id;
        int32_t material;
    } workshop_job;
    struct T_building_12527 {
        struct stl_vector_ptr_interface_button_constructionst choices_all;
        struct stl_vector_ptr_interface_button_constructionst choices_visible;
        int32_t category_id;
        int32_t cursor;
    } building;
    struct T_designation_12539 {
        struct stl_vector_ptr_interface_button_buttonst choices;
        int32_t anon_1;
        int32_t anon_2;
    } designation;
    struct T_unit_12547 {
        struct stl_vector_int32_t list;
        int8_t anon_1;
        int8_t anon_2;
    } unit;
    struct T_minimap_12556 {
        int32_t tiles[23][23];
        int8_t need_update;
        int8_t anon_1;
    } minimap;
    struct T_command_line_12564 {
        struct stl_string original;
        struct stl_vector_strptr arg_vect;
        int32_t gen_id;
    } command_line;
    int32_t num_speech_tokens;
};

enum ui_sidebar_mode {
    ui_sidebar_mode_Default,
    ui_sidebar_mode_Squads,
    ui_sidebar_mode_DesignateMine,
    ui_sidebar_mode_DesignateGatherPlants,
    ui_sidebar_mode_DesignateRemoveDesignation,
    ui_sidebar_mode_DesignateDetailStone,
    ui_sidebar_mode_DesignateCarveFortification,
    ui_sidebar_mode_Stockpiles,
    ui_sidebar_mode_Build,
    ui_sidebar_mode_QueryBuilding,
    ui_sidebar_mode_Orders,
    ui_sidebar_mode_OrdersRefuse,
    ui_sidebar_mode_OrdersWorkshop,
    ui_sidebar_mode_BuildingItems,
    ui_sidebar_mode_ViewUnits,
    ui_sidebar_mode_LookAround,
    ui_sidebar_mode_DesignateReclaim,
    ui_sidebar_mode_DesignateChopTrees,
    ui_sidebar_mode_DesignateToggleEngravings
};

enum T_value_12608 {
    T_value_12608_General,
    T_value_12608_Inventory,
    T_value_12608_Preferences,
    T_value_12608_Wounds,
    T_value_12608_PrefLabor,
    T_value_12608_PrefPet,
    T_value_12608_PrefSoldier
};

struct ui_unit_view_mode {
    int32_t value;
};

struct unit_chunk {
    int32_t id;
    struct T_units_14291 {
        struct stl_vector_ptr_itemst items;
        struct unit *unit;
    } units[100];
};

enum unit_labor {
    unit_labor_NONE = -1,
    unit_labor_MINE,
    unit_labor_HAUL_STONE,
    unit_labor_HAUL_WOOD,
    unit_labor_HAUL_BODY,
    unit_labor_HAUL_FOOD,
    unit_labor_HAUL_REFUSE,
    unit_labor_HAUL_ITEM,
    unit_labor_HAUL_FURNITURE,
    unit_labor_HAUL_ANIMAL,
    unit_labor_CLEAN,
    unit_labor_CUTWOOD,
    unit_labor_CARPENTER,
    unit_labor_DETAIL,
    unit_labor_MASON,
    unit_labor_ARCHITECT,
    unit_labor_ANIMALTRAIN,
    unit_labor_ANIMALCARE,
    unit_labor_HEALTHCARE,
    unit_labor_BUTCHER,
    unit_labor_TRAPPER,
    unit_labor_LEATHER,
    unit_labor_TANNER,
    unit_labor_BREWER,
    unit_labor_ALCHEMIST,
    unit_labor_WEAVER,
    unit_labor_CLOTHESMAKER,
    unit_labor_MILLER,
    unit_labor_FARMING_WORKSHOP,
    unit_labor_COOK,
    unit_labor_PLANT,
    unit_labor_HERBALIST,
    unit_labor_FISH,
    unit_labor_CLEAN_FISH,
    unit_labor_HUNT,
    unit_labor_SMELT,
    unit_labor_EXTRACT_ADAMANTINE,
    unit_labor_WORK_ADAMANTINE,
    unit_labor_FORGE,
    unit_labor_GEM,
    unit_labor_CRAFT,
    unit_labor_GLASSMAKER,
    unit_labor_AXE,
    unit_labor_SWORD,
    unit_labor_MACE,
    unit_labor_HAMMER,
    unit_labor_SPEAR,
    unit_labor_DAGGER,
    unit_labor_CROSSBOW,
    unit_labor_BOW,
    unit_labor_BLOWGUN,
    unit_labor_PIKE,
    unit_labor_WHIP,
    unit_labor_SHIELD,
    unit_labor_ARMOR,
    unit_labor_SIEGECRAFT,
    unit_labor_SIEGEOPERATE,
    unit_labor_BOWYER,
    unit_labor_MECHANIC,
    unit_labor_WEAPON_NUMBER,
    unit_labor_ASHERY,
    unit_labor_DYER,
    unit_labor_BURN_WOOD
};

struct unit_profile {
    struct language_name name;
    int16_t race;
    int8_t sex;
    int16_t skills[68];
    int32_t entity;
    int16_t nemesis_idx;
    int32_t military_profession;
    int32_t civilian_profession;
};

enum unit_relationship_type {
    unit_relationship_type_Pet,
    unit_relationship_type_Spouse,
    unit_relationship_type_Mother,
    unit_relationship_type_Father,
    unit_relationship_type_LastAttacker,
    unit_relationship_type_GroupLeader,
    unit_relationship_type_Dragee,
    unit_relationship_type_Dragger,
    unit_relationship_type_RiderMount,
    unit_relationship_type_unk9,
    unit_relationship_type_Sibling,
    unit_relationship_type_Child,
    unit_relationship_type_Friend
};

enum unit_thought_type {
    unit_thought_type_Miscarriage,
    unit_thought_type_Evicted,
    unit_thought_type_Tired,
    unit_thought_type_Exhausted,
    unit_thought_type_Hunger,
    unit_thought_type_Thirst,
    unit_thought_type_Starving,
    unit_thought_type_Dehydrated,
    unit_thought_type_ScarceRoyalGuards,
    unit_thought_type_ScarceFortressGuards,
    unit_thought_type_ScarceCageChain,
    unit_thought_type_Attacked,
    unit_thought_type_AttackedByDead,
    unit_thought_type_TaxRoomUnreachable,
    unit_thought_type_TaxRoomMisinformed,
    unit_thought_type_TaxCollectionRough,
    unit_thought_type_Taxed,
    unit_thought_type_TaxedLostProperty,
    unit_thought_type_DisappointedNoble,
    unit_thought_type_LackChairs,
    unit_thought_type_CrowdedTables,
    unit_thought_type_LackTables,
    unit_thought_type_EatVermin,
    unit_thought_type_EatLikedCreature,
    unit_thought_type_EatPet,
    unit_thought_type_LackWell,
    unit_thought_type_NastyWater,
    unit_thought_type_DrinkSlime,
    unit_thought_type_DrinkVomit,
    unit_thought_type_DrinkBlood,
    unit_thought_type_SleepNoise,
    unit_thought_type_SleepNoiseMajor,
    unit_thought_type_SleepNoiseWake,
    unit_thought_type_LackProtection,
    unit_thought_type_Drafted,
    unit_thought_type_Relieved,
    unit_thought_type_ExpelledRoyalGuard,
    unit_thought_type_ExpelledFortressGuard,
    unit_thought_type_ArtDefacement,
    unit_thought_type_AnnoyedFlies,
    unit_thought_type_AnnoyedVermin,
    unit_thought_type_AnnoyedCage,
    unit_thought_type_AnnoyedPond,
    unit_thought_type_WitnessDeath,
    unit_thought_type_LostPet,
    unit_thought_type_LostPet2,
    unit_thought_type_RageKill,
    unit_thought_type_SparringAccident,
    unit_thought_type_LostSpouse,
    unit_thought_type_LostFriend,
    unit_thought_type_LostSibling,
    unit_thought_type_LostChild,
    unit_thought_type_LostMother,
    unit_thought_type_LostFather,
    unit_thought_type_Decay,
    unit_thought_type_AteRotten,
    unit_thought_type_DrankSpoiled,
    unit_thought_type_LongPatrol,
    unit_thought_type_BloodyMist,
    unit_thought_type_Miasma,
    unit_thought_type_Smoke,
    unit_thought_type_Dust,
    unit_thought_type_Cavein,
    unit_thought_type_MeetingInDiningRoom,
    unit_thought_type_MeetingInBedroom,
    unit_thought_type_NoRooms,
    unit_thought_type_MajorInjuries,
    unit_thought_type_MinorInjuries,
    unit_thought_type_SleptMud,
    unit_thought_type_SleptGrass,
    unit_thought_type_SleptDirt,
    unit_thought_type_SleptRocks,
    unit_thought_type_SleptRoughFloor,
    unit_thought_type_SleptFloor,
    unit_thought_type_BedroomNone,
    unit_thought_type_BedroomBad5,
    unit_thought_type_BedroomBad4,
    unit_thought_type_BedroomBad3,
    unit_thought_type_BedroomBad2,
    unit_thought_type_BedroomBad1,
    unit_thought_type_OfficeBad5,
    unit_thought_type_OfficeBad4,
    unit_thought_type_OfficeBad3,
    unit_thought_type_OfficeBad2,
    unit_thought_type_OfficeBad1,
    unit_thought_type_DiningBad5,
    unit_thought_type_DiningBad4,
    unit_thought_type_DiningBad3,
    unit_thought_type_DiningBad2,
    unit_thought_type_DiningBad1,
    unit_thought_type_DiningNone,
    unit_thought_type_TombNone,
    unit_thought_type_TombBad5,
    unit_thought_type_TombBad4,
    unit_thought_type_TombBad3,
    unit_thought_type_TombBad2,
    unit_thought_type_TombBad1,
    unit_thought_type_DemandsAngry3,
    unit_thought_type_DemandsAngry2,
    unit_thought_type_DemandsAngry1,
    unit_thought_type_MoreChests,
    unit_thought_type_MoreCabinets,
    unit_thought_type_MoreArmorStands,
    unit_thought_type_MoreWeaponRacks,
    unit_thought_type_OldClothing,
    unit_thought_type_TatteredClothing,
    unit_thought_type_RottedClothing,
    unit_thought_type_Uncovered,
    unit_thought_type_NoShirt,
    unit_thought_type_NoShoes,
    unit_thought_type_NoCloak,
    unit_thought_type_Rain,
    unit_thought_type_SnowStorm,
    unit_thought_type_RoomPretension,
    unit_thought_type_NoHammer,
    unit_thought_type_MandateIgnored,
    unit_thought_type_MandateDeadlineMissed,
    unit_thought_type_RequestIgnored,
    unit_thought_type_NoPunishment,
    unit_thought_type_ImproperPunishment,
    unit_thought_type_DelayedPunishment,
    unit_thought_type_GotBeaten,
    unit_thought_type_GotHammered,
    unit_thought_type_Jailed,
    unit_thought_type_LackWork,
    unit_thought_type_Nightmare,
    unit_thought_type_AdmireBuilding,
    unit_thought_type_AdmireOwnBuilding,
    unit_thought_type_AdmireArrangedBuilding,
    unit_thought_type_AdmireOwnArrangedBuilding,
    unit_thought_type_ComfortedCage,
    unit_thought_type_ComfortedPond,
    unit_thought_type_RequestApproved,
    unit_thought_type_PunishmentReduced,
    unit_thought_type_PunishmentDelayed,
    unit_thought_type_GaveBeating,
    unit_thought_type_GaveHammering,
    unit_thought_type_JoinedRoyalGuard,
    unit_thought_type_JoinedFortressGuard,
    unit_thought_type_SatisfiedAtWork,
    unit_thought_type_PleasedNoble,
    unit_thought_type_MadeArtifact,
    unit_thought_type_AcquiredItem,
    unit_thought_type_AdoptedPet,
    unit_thought_type_JoyInSlaughter,
    unit_thought_type_GoodFood1,
    unit_thought_type_GoodFood2,
    unit_thought_type_GoodFood3,
    unit_thought_type_GoodFood4,
    unit_thought_type_GoodFood5,
    unit_thought_type_GoodDrink1,
    unit_thought_type_GoodDrink2,
    unit_thought_type_GoodDrink3,
    unit_thought_type_GoodDrink4,
    unit_thought_type_GoodDrink5,
    unit_thought_type_ComfortedPet,
    unit_thought_type_ComfortedCreature,
    unit_thought_type_MandateDeadlineMet,
    unit_thought_type_Talked,
    unit_thought_type_MadeFriend,
    unit_thought_type_TaxCollectionSmooth,
    unit_thought_type_Waterfall,
    unit_thought_type_OfficeGood5,
    unit_thought_type_OfficeGood4,
    unit_thought_type_OfficeGood3,
    unit_thought_type_OfficeGood2,
    unit_thought_type_OfficeGood1,
    unit_thought_type_DiningGood5,
    unit_thought_type_DiningGood4,
    unit_thought_type_DiningGood3,
    unit_thought_type_DiningGood2,
    unit_thought_type_DiningGood1,
    unit_thought_type_BedroomGood5,
    unit_thought_type_BedroomGood4,
    unit_thought_type_BedroomGood3,
    unit_thought_type_BedroomGood2,
    unit_thought_type_BedroomGood1,
    unit_thought_type_DemandsPleased3,
    unit_thought_type_DemandsPleased2,
    unit_thought_type_DemandsPleased1,
    unit_thought_type_TombGood5,
    unit_thought_type_TombGood4,
    unit_thought_type_TombGood3,
    unit_thought_type_TombGood2,
    unit_thought_type_TombGood1,
    unit_thought_type_FistFight,
    unit_thought_type_SmashedBuilding,
    unit_thought_type_ToppledStuff,
    unit_thought_type_ThrownStuff,
    unit_thought_type_Spar,
    unit_thought_type_Free,
    unit_thought_type_SunNausea,
    unit_thought_type_SunIrritated,
    unit_thought_type_Rest,
    unit_thought_type_ReceivedWater,
    unit_thought_type_ReceivedFood,
    unit_thought_type_Rescued
};

enum vermin_flags_enum {
    vermin_flags__unk_0=0x01,
    vermin_flags_is_colony=0x02
};

struct vermin_flags {
    uint32_t bitfield;
};

struct vermin {
    int32_t id;
    int16_t race;
    struct coord pos;
    int8_t visible;
    int16_t countdown;
    struct itemst *item;
    struct vermin_flags vermin_flags;
    int16_t amount;
};

struct viewscreen_adventure_logst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t show_map;
    int16_t player_x;
    int16_t player_y;
    int16_t x_min;
    int16_t y_min;
    int16_t x_max;
    int16_t y_max;
    int16_t cursor_x;
    int16_t cursor_y;
    int16_t menu_cursor;
    int8_t show_line;
    int32_t section_id;
    struct stl_vector_ptr sites;
    struct stl_vector_ptr tasks;
    struct stl_vector_ptr entities;
    struct stl_vector_ptr regions;
};

struct viewscreen_adventure_travelst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t viewscreen_adventure_travelst_anon_1;
    int32_t site_cursor;
    struct stl_vector_ptr_world_site sites;
};

struct viewscreen_announcelistst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cursor;
};

struct stl_vector_ptr_assign_trade_status {
struct assign_trade_status **ptr;
void *endptr;
void *endalloc;
};
struct viewscreen_assigntradest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cursor;
    struct stl_vector_ptr_assign_trade_status info;
    struct building_tradedepotst *depot;
};

struct viewscreen_barterst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct unit *shopkeeper;
    struct unit *adventurer;
    struct buildingst *building;
    struct stl_vector_ptr_itemst shopkeeper_items;
    struct stl_vector_ptr_itemst your_items;
    struct stl_vector_int8_t shopkeeper_selected;
    struct stl_vector_int8_t your_selected;
    struct stl_vector_ptr_itemst viewscreen_barterst_anon_1;
    int32_t viewscreen_barterst_anon_2;
    int32_t viewscreen_barterst_anon_3;
    int8_t viewscreen_barterst_anon_4;
    int16_t trade_reply;
    int8_t viewscreen_barterst_anon_5;
    int32_t max_ask;
    int32_t max_offer;
    int32_t cur_ask;
    int32_t cur_offer;
};

struct viewscreen_buildinglistst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cursor;
    int8_t alt_right_panel;
    struct stl_vector_ptr_buildingst buildings;
    struct stl_vector_ptr_buildingst buildings2;
    struct stl_vector_int32_t room_value;
    struct stl_vector_int32_t room_value2;
};

struct viewscreen_buildingst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct buildingst *building;
};

struct stl_vector_ptr_historical_entity {
struct historical_entity **ptr;
void *endptr;
void *endalloc;
};
struct viewscreen_civlistst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cursor;
    struct stl_vector_ptr_historical_entity civs;
};

struct viewscreen_commandchainst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct stl_vector_ptr_unit units;
    struct stl_vector_int32_t indent_level;
    int32_t cursor;
    int32_t column;
    int32_t promote_parent;
    int8_t weapons_mode;
    int16_t royalguards_needed;
    int16_t royalguards_present;
    int16_t fortguards_needed;
    int16_t fortguards_present;
};

struct viewscreen_conversationst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct conversation *conversation;
    int32_t viewscreen_conversationst_anon_1;
    int32_t viewscreen_conversationst_anon_2;
    int16_t viewscreen_conversationst_anon_3;
};

struct stl_vector_ptr_manager_order_template {
struct manager_order_template **ptr;
void *endptr;
void *endalloc;
};
struct viewscreen_createquotast {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    char str_filter[80];
    int32_t top_idx;
    int32_t sel_idx;
    struct stl_vector_ptr_manager_order_template orders;
    struct stl_vector_int32_t page_indices;
    int8_t want_quantity;
};

struct viewscreen_customize_unitst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct unit *unit;
    int8_t editing_name;
    int8_t editing_profession;
    struct stl_string original_str;
    int8_t has_name;
};

struct viewscreen_dungeon_announcest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t viewscreen_dungeon_announcest_anon_1;
    int32_t viewscreen_dungeon_announcest_anon_2;
    int8_t map_rotate;
    int8_t more;
};

struct viewscreen_dungeon_monsterstatusst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct unit *unit;
    int32_t inventory_cursor;
    int32_t body_part_cursor;
    struct stl_vector_int16_t body_part;
};

struct viewscreen_dungeon_wrestlest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct unit *unit1;
    struct unit *unit2;
    int8_t viewscreen_dungeon_wrestlest_anon_1;
    int32_t cursor;
    struct stl_vector_ptr_unit_item_wrestle wrestle_items;
    int32_t viewscreen_dungeon_wrestlest_anon_2;
    struct stl_vector_int8_t viewscreen_dungeon_wrestlest_anon_3;
    struct stl_vector_ptr viewscreen_dungeon_wrestlest_anon_4;
    struct T_options_14532 {
        struct unit *target;
        int8_t anon_1;
        int8_t anon_2;
        struct stl_vector_ptr_unit_inventory_item your_inv;
        struct stl_vector_int32_t your_bp;
        struct stl_vector_ptr_unit_inventory_item enemy_inv;
        struct stl_vector_int32_t enemy_bp;
        struct stl_vector_ptr_unit_item_wrestle your_wrestles;
        struct stl_vector_ptr_unit_item_wrestle enemy_wrestles;
        struct stl_vector_ptr_unit_inventory_item your_stuckin_inv;
        struct stl_vector_ptr_unit_inventory_item enemy_stuckin_inv;
        struct stl_vector_int16_t cmd_your_bp_idx;
        struct stl_vector_int16_t cmd_your_inv_idx;
        struct stl_vector_int16_t cmd_enemy_bp_idx;
        struct stl_vector_int16_t cmd_enemy_inv_idx;
        struct stl_vector_int16_t aux_target_wrestle_idx;
        struct stl_vector_int16_t aux_move_type;
        struct stl_vector_int16_t aux_target_bp;
    } options;
};

struct viewscreen_dungeonmodest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t x;
    int32_t y;
    int32_t z;
    int8_t viewscreen_dungeonmodest_anon_1;
    int8_t viewscreen_dungeonmodest_anon_2;
};

struct viewscreen_dwarfmodest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t jeweler_mat_count;
    struct stl_vector_int32_t jeweler_cutgem;
    struct stl_vector_int32_t jeweler_encrust;
    struct stl_vector_int32_t unit_labor_list;
};

struct viewscreen_entityst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct historical_entity *entity;
    struct stl_vector_ptr viewscreen_entityst_anon_1;
    int32_t viewscreen_entityst_anon_2;
    struct stl_vector_ptr_nemesis_record members;
    int32_t member_cursor;
    struct stl_vector_ptr_meeting_event agreements;
    struct stl_vector_int8_t agreement_status;
    int32_t agreement_cursor;
    int16_t page;
};

struct viewscreen_export_regionst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t cur_step;
    struct T_export_state_14590 {
        struct stl_vector_int32_t anon_1;
        struct stl_vector_int16_t anon_2;
        struct stl_vector_ptr_unit offload_units;
        struct unit_chunk *cur_unit_chunk;
        int32_t unit_chunk_id;
        int32_t offload_count;
    } export_state;
};

struct viewscreen_itemst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct itemst *item;
    struct stl_vector_ptr_general_refst entry_ref;
    struct stl_vector_int16_t indent_levels;
    int32_t cursor_pos;
};

struct viewscreen_jobmanagementst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t sel_idx;
};

struct viewscreen_jobst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct job *job;
};

struct viewscreen_justicest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int16_t jails_needed;
    int16_t jails_present;
    int16_t cursor;
    struct stl_vector_ptr_unit criminals;
    struct stl_vector_ptr_crime_info crimes;
    struct punishment_info *punishment;
};

struct viewscreen_keybindingsst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct stl_vector_int32_t keys;
    int32_t cursor;
    int8_t in_modify;
};

struct viewscreen_kitchenprefst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cursor;
    struct stl_vector_int16_t item_type;
    struct stl_vector_int16_t item_subtype;
    struct stl_vector_int16_t material;
    struct stl_vector_int16_t matgloss;
    struct stl_vector_int32_t quantity;
    struct stl_vector_int8_t viewscreen_kitchenprefst_cur_flags;
    struct stl_vector_int8_t viewscreen_kitchenprefst_valid_flags;
};

struct stl_vector_ptr_layer_objectst {
struct layer_objectst **ptr;
void *endptr;
void *endalloc;
};
struct viewscreen_layerst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct stl_vector_ptr_layer_objectst layer_objects;
};

struct viewscreen_layer_stockpilest {
            struct vtable_viewscreenst *vtable;
            struct viewscreenst *child;
            struct viewscreenst *parent;
            int8_t breakdown_level;
            int8_t option_key_pressed;
        struct stl_vector_ptr_layer_objectst layer_objects;
    struct stockpile_settings *settings;
    int32_t cur_group;
    int32_t cur_list;
    struct stl_vector_int32_t group_ids;
    struct stl_vector_uint32_t group_bits;
    struct stl_vector_int32_t list_ids;
    struct stl_vector_strptr item_names;
    struct stl_vector_ptr item_status;
};

struct viewscreen_layer_workshop_profilest {
            struct vtable_viewscreenst *vtable;
            struct viewscreenst *child;
            struct viewscreenst *parent;
            int8_t breakdown_level;
            int8_t option_key_pressed;
        struct stl_vector_ptr_layer_objectst layer_objects;
    struct workshop_profile *profile;
    struct stl_vector_ptr_unit workers;
};

struct viewscreen_legendsst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct stl_vector_int32_t histfigs;
    struct stl_vector_int32_t sites;
    struct stl_vector_int32_t artifacts;
    struct stl_vector_int32_t regions;
    struct stl_vector_int32_t entities;
    int16_t cur_section;
    int16_t outer_cursor;
    struct stl_vector_int16_t avail_sections;
    int32_t inner_cursor;
};

struct world_sav_summary {
    struct stl_string filename;
    int32_t save_slot_num;
    int32_t last_unit_id;
    int32_t last_item_id;
    int32_t last_entity_id;
    int32_t last_nemesis_id;
    int32_t last_artifact_id;
    int32_t last_job_id;
    int32_t last_schedule_id;
    int32_t last_projectile_id;
    int32_t last_building_id;
    int32_t last_hist_figure_id;
    int32_t last_hist_event_id;
    int32_t last_unit_chunk_id;
    int32_t last_art_image_chunk_id;
    int32_t last_task_id;
    int32_t game_mode;
    struct stl_string FortOrAdvName;
    struct stl_string WorldName;
    int32_t year;
};

struct stl_vector_ptr_world_sav_summary {
struct world_sav_summary **ptr;
void *endptr;
void *endalloc;
};
struct viewscreen_loadgamest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t do_load;
    int32_t cursor;
    struct stl_vector_ptr_world_sav_summary world_sav_files;
};

struct viewscreen_meetingst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct dipscript_popup *popup;
    struct activity_info *activity;
    struct unit *holder;
};

struct viewscreen_movieplayerst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t saving;
    int8_t loading;
    int8_t editing;
    int8_t text_mode;
    uint8_t editing_char;
    int32_t editing_copy_from;
    int16_t editing_screenf;
    int16_t editing_screenb;
    int16_t editing_screenbright;
    int32_t editing_selected_sound;
    int8_t editing_menu;
    struct stl_string savename;
    struct stl_string force_file;
    int8_t is_playing;
    int8_t is_forced_play;
    int8_t quit_if_no_play;
    int32_t maxmoviepos;
    int32_t end_frame_pos;
    int32_t selfile;
    struct stl_vector_ptr filelist;
};

struct viewscreen_new_regionst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t prompt_abort;
};

struct viewscreen_noblelistst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cursor;
    struct stl_vector_ptr_unit nobles;
    struct stl_vector_ptr room_status;
};

struct viewscreen_noblest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cur_offerings;
};

struct viewscreen_optionst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t quit_msg;
    int8_t retire_confirm;
    int8_t peasant_msg;
    int8_t quit_confirm;
    int8_t end_game;
    int32_t cursor;
};

struct viewscreen_overallstatusst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int16_t cursor;
    int16_t cursor_max;
};

struct viewscreen_petst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cursor;
    struct stl_vector_ptr animal;
    struct stl_vector_int8_t is_vermin;
    struct stl_vector_ptr_pet_info pet_info;
    struct stl_vector_int8_t is_tame;
    struct stl_vector_int8_t is_adopting;
};

struct viewscreen_pricest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int16_t cursor;
    int32_t category_scroll;
};

struct viewscreen_requestagreementst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct entity_buy_prices *requests;
    int32_t civ_id;
    int32_t cursor;
    char title[200];
    struct historical_entity *civ;
};

struct viewscreen_savegamest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t show_prompt;
    int8_t show_success;
    int8_t do_save;
    struct stl_string save_filename;
};

struct viewscreen_setupdwarfgamest;
struct viewscreen_selectitemst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t *item_type;
    int32_t *item_subtype;
    int32_t *material;
    int32_t *matgloss;
    struct stl_vector_ptr all_items;
    struct viewscreen_setupdwarfgamest *embark_screen;
    struct stl_vector_ptr matching_items;
    char title[80];
    char viewscreen_selectitemst_anon_1[200];
    char filter[80];
    int32_t cursor;
    int32_t viewscreen_selectitemst_anon_2;
};

struct viewscreen_setupadventurest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t entering_name;
    struct stl_string name_buffer;
    int32_t civ_cursor;
    int32_t skill_cursor;
    int32_t skill_points;
    int16_t screen_id;
    struct unit_profile player;
    struct stl_vector_int16_t races;
    struct stl_vector_int32_t entities;
    struct stl_vector_int16_t nemesis_idxs;
    struct stl_vector_int16_t avail_skills;
};

struct stl_vector_ptr_unit_profile {
struct unit_profile **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_embark_item {
struct embark_item **ptr;
void *endptr;
void *endalloc;
};
enum T_flags_15111_enum {
    T_flags_15111_add_item=0x01
};

struct viewscreen_setupdwarfgamest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    char title[200];
    struct stl_vector_ptr_unit_profile unit_profiles;
    struct stl_vector_int16_t embark_skills;
    struct stl_vector_int16_t reclaim_professions;
    int16_t mode;
    int16_t dwarf_cursor;
    int16_t dwarf_page_idx;
    int16_t item_cursor;
    int16_t skill_cursor;
    int16_t animal_cursor;
    int16_t dwarf_column;
    int16_t supply_column;
    int32_t display_row;
    int8_t show_play_now;
    struct stl_vector_ptr_embark_item avail_items;
    struct stl_vector_int16_t animal_professions;
    struct stl_vector_int32_t animal_races;
    struct stl_vector_int32_t animal_counts;
    struct stl_vector_ptr_unit dwarves;
    struct stl_vector_ptr_itemst items;
    int32_t num_wagons;
    struct coord2d region_indoor;
    int16_t reclaim_site;
    struct coord2d region_outdoor;
    int16_t points_remaining;
    int32_t add_item_type;
    int32_t add_item_subtype;
    int32_t add_material;
    int32_t add_matgloss;
    struct T_flags_15111 {
        uint32_t bitfield;
    } viewscreen_setupdwarfgamest_flags;
};

struct viewscreen_squadst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct unit *leader;
};

struct viewscreen_storesst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    char title[80];
    int16_t category_cursor;
    int16_t item_cursor;
    int16_t in_right_list;
    int16_t in_group_mode;
    struct stl_vector_int32_t category_total;
    struct stl_vector_int32_t category_busy;
    struct stl_vector_ptr_itemst items;
    struct T_group_14822 {
        struct stl_vector_int16_t item_type;
        struct stl_vector_int16_t item_subtype;
        struct stl_vector_int16_t material;
        struct stl_vector_int16_t matgloss;
        struct stl_vector_int32_t count;
    } group;
    int8_t can_zoom;
};

enum T_flags_15042_enum {
    T_flags_15042_hyperlink=0x01,
    T_flags_15042_no_newline=0x02
};

struct T_formatted_text_15039 {
    char **text;
    char **format;
    struct T_flags_15042 {
        uint16_t bitfield;
    } flags;
    int32_t pause_depth;
    int32_t return_val;
    int32_t indent;
} ;
struct stl_vector_ptr_T_formatted_text_15039 {
struct T_formatted_text_15039 **ptr;
void *endptr;
void *endalloc;
};
struct viewscreen_textviewerst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct stl_string title;
    struct stl_string title_colors;
    struct stl_vector_ptr src_text;
    struct stl_string outvar_type;
    struct stl_string outvar_name;
    struct meeting_context meeting_context;
    struct stl_string help_filename;
    struct stl_string page_filename;
    struct stl_vector_ptr_T_formatted_text_15039 formatted_text;
    struct stl_vector_ptr hyperlinks;
    int8_t logged_error;
    int32_t scroll_pos;
    int32_t cursor_line;
    int32_t pause_depth;
};

enum T_sel_subpage_14666 {
    T_sel_subpage_14666_None,
    T_sel_subpage_14666_StartRegion,
    T_sel_subpage_14666_StartType
};

struct world_dat_summary {
    struct stl_string world_dat_summary_anon_1;
    struct language_name name;
    struct stl_string world_dat_summary_anon_2;
    int8_t world_dat_summary_anon_3[15];
    int32_t save_slot_num;
    int32_t next_unit_id;
    int32_t next_item_id;
    int32_t next_entity_id;
    int32_t next_nemesis_id;
    int32_t next_artifact_id;
    int32_t next_building_id;
    int32_t next_hist_figure_id;
    int32_t next_hist_event_id;
    int32_t next_unit_chunk_id;
    int32_t next_art_image_chunk_id;
    int32_t next_task_id;
};

struct stl_vector_ptr_world_dat_summary {
struct world_dat_summary **ptr;
void *endptr;
void *endalloc;
};
struct viewscreen_titlest {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    char str_histories[200];
    char cur_option[200];
    int16_t sel_subpage;
    int16_t cursor;
    int16_t world_cursor;
    int8_t loading;
    struct stl_vector_int32_t menu_line_id;
    struct stl_vector_int32_t gametypes_id;
    struct stl_vector_strptr gametypes_str;
    struct stl_vector_ptr_world_dat_summary world_dat_files;
    struct stl_string str_slaves;
    struct stl_string str_chapter;
    struct stl_string str_copyright;
    struct stl_string str_version;
    struct stl_string str_programmed;
    struct stl_string str_designed;
    struct stl_string str_visit;
    struct stl_string str_site;
};

struct viewscreen_topicmeeting_takerequests_dwarfst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct dipscript_popup *popup;
    struct meeting_diplomat_info *meeting;
    int32_t cursor;
    struct stl_vector_int32_t item_type;
    struct stl_vector_int8_t priority;
    char title[200];
};

struct viewscreen_topicmeeting_takerequests_humanst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    char title[200];
    struct dipscript_popup *popup;
    struct meeting_diplomat_info *meeting;
    int32_t cursor_left;
    int32_t cursor_right;
};

struct viewscreen_topicmeetingst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct dipscript_popup *popup;
    struct meeting_diplomat_info *meeting;
};

struct viewscreen_tradeagreementst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct entity_sell_prices *requests;
    int32_t civ_id;
    int32_t cursor_left;
    int32_t cursor_right;
    char title[200];
    struct historical_entity *civ;
};

struct viewscreen_tradegoodsst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    char title[200];
    struct stl_string merchant_name;
    struct stl_string merchant_entity;
    struct building_tradedepotst *depot;
    struct caravan_state *caravan;
    struct historical_entity *entity;
    int8_t is_unloading;
    int8_t has_traders;
    struct stl_vector_ptr_itemst trader_items;
    struct stl_vector_ptr_itemst broker_items;
    struct stl_vector_int8_t trader_selected;
    struct stl_vector_int8_t broker_selected;
    int32_t trader_cursor;
    int32_t broker_cursor;
    int8_t in_right_pane;
    int16_t trade_reply;
    int8_t viewscreen_tradegoodsst_anon_1;
};

struct viewscreen_tradelistst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t cursor;
    struct buildingst *depot;
    struct stl_vector_ptr_caravan_state caravans;
};

struct viewscreen_treasurelistst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int32_t sel_idx;
};

enum T_mode_14751 {
    T_mode_14751_Jobs,
    T_mode_14751_Units
};

struct viewscreen_unitjobsst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int8_t mode;
    int8_t allow_zoom;
    int32_t cursor_pos;
    struct stl_vector_ptr_job jobs;
    struct stl_vector_ptr_unit units;
};

struct viewscreen_unitst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    struct unit *unit;
};

struct viewscreen_wagesst {
        struct vtable_viewscreenst *vtable;
        struct viewscreenst *child;
        struct viewscreenst *parent;
        int8_t breakdown_level;
        int8_t option_key_pressed;
    int16_t page;
};

struct waterfall {
    int16_t type;
    struct coord pos;
};

enum weapon_flags {
    weapon_flags_CAN_STONE
};

enum weather_type {
    weather_type_None,
    weather_type_Rain,
    weather_type_Snow
};

struct web_cluster {
    struct stl_vector_int16_t x;
    struct stl_vector_int16_t y;
    int16_t z;
    int16_t race;
    struct coord2d pos_min;
    struct coord2d pos_max;
    struct stl_vector_ptr_unit ambushers;
};

enum workshop_type {
    workshop_type_Alchemists,
    workshop_type_Carpenters,
    workshop_type_Farmers,
    workshop_type_Masons,
    workshop_type_Craftsdwarfs,
    workshop_type_Jewelers,
    workshop_type_MetalsmithsForge,
    workshop_type_MagmaForge,
    workshop_type_Bowyers,
    workshop_type_Mechanics,
    workshop_type_Siege,
    workshop_type_Butchers,
    workshop_type_Leatherworks,
    workshop_type_Tanners,
    workshop_type_Clothes,
    workshop_type_Fishery,
    workshop_type_Still,
    workshop_type_Loom,
    workshop_type_Mill,
    workshop_type_Kennels,
    workshop_type_Kitchen,
    workshop_type_Ashery,
    workshop_type_Dyers
};

struct stl_vector_ptr_mineral_cluster {
struct mineral_cluster **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_engraving {
struct engraving **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_vermin {
struct vermin **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_coord {
struct coord **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_drink_area {
struct drink_area **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_waterfall {
struct waterfall **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_cavein_region {
struct cavein_region **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_campfire {
struct campfire **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_web_cluster {
struct web_cluster **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_fire {
struct fire **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_effect_info {
struct effect_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_coin_batch {
struct coin_batch **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_local_population {
struct local_population **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_manager_order {
struct manager_order **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_mandate {
struct mandate **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_unit_chunk {
struct unit_chunk **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_art_image_chunk {
struct art_image_chunk **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_vegst {
struct vegst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_schedule_info {
struct schedule_info **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_map_block {
struct map_block **ptr;
void *endptr;
void *endalloc;
};
struct T_travel_15379 {
    struct coord2d pos;
    struct stl_vector_int32_t nemesis;
} ;
struct stl_vector_ptr_T_travel_15379 {
struct T_travel_15379 **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_history_eventst {
struct history_eventst **ptr;
void *endptr;
void *endalloc;
};
struct world_history {
    struct stl_vector_ptr_history_eventst events;
    struct stl_vector_ptr_historical_figure figures;
    struct stl_vector_int32_t art_image_ids;
    struct stl_vector_int16_t art_image_subids;
    int32_t art_image_total;
};

struct T_anon_1_15417 {
    int16_t anon_1;
    int16_t anon_2;
    int16_t anon_3;
    int16_t anon_4;
    int8_t anon_5;
    int32_t anon_6;
    int32_t anon_7;
} ;
struct stl_vector_ptr_T_anon_1_15417 {
struct T_anon_1_15417 **ptr;
void *endptr;
void *endalloc;
};
struct T_unused_194_15413 {
    struct stl_vector_ptr_T_anon_1_15417 anon_1[3];
    int32_t anon_2;
    int32_t anon_3;
    int32_t anon_4;
} ;
struct stl_vector_ptr_T_unused_194_15413 {
struct T_unused_194_15413 **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_region_population {
struct region_population **ptr;
void *endptr;
void *endalloc;
};
struct world_region {
    struct language_name name;
    int32_t id;
    int32_t biome_type;
    struct coord2d_path region_coords;
    int32_t _unk_88;
    int32_t _unk_8c;
    int32_t _unk_90;
    int32_t _unk_94;
    struct stl_vector_ptr_region_population populations;
    struct T_tree_tiles_15277 {
        int16_t tree1;
        int16_t tree2;
    } tree_tiles[34];
    int8_t allow_skeleton;
    int8_t allow_zombie;
    int8_t color_variant;
};

struct stl_vector_ptr_world_region {
struct world_region **ptr;
void *endptr;
void *endalloc;
};
struct world_data {
    struct language_name name;
    int8_t world_data_anon_1[15];
    int32_t save_folder_number;
    int32_t next_site_id;
    int32_t world_data_anon_2;
    int16_t world_width;
    int16_t world_height;
    struct stl_vector_ptr_T_travel_15379 travel;
    struct df_flagarray world_data_flags;
    struct world_history history;
    struct stl_vector_int32_t embark_indoor_x;
    struct stl_vector_int32_t embark_indoor_y;
    struct stl_vector_int32_t embark_outdoor_x;
    struct stl_vector_int32_t embark_outdoor_y;
    struct stl_vector_int32_t reclaim_site;
    struct stl_vector_int32_t reclaim_indoor_x;
    struct stl_vector_int32_t reclaim_indoor_y;
    struct stl_vector_int32_t reclaim_outdoor_x;
    struct stl_vector_int32_t reclaim_outdoor_y;
    int32_t world_data_anon_3;
    int32_t flip_latitude;
    int32_t flip_longitude;
    int16_t world_data_anon_4[3];
    int16_t world_data_anon_5[3];
    int32_t next_unit_chunk_id;
    int32_t next_unit_chunk_index;
    int32_t next_art_image_chunk_id;
    int32_t next_art_image_chunk_index;
    struct stl_vector_ptr_T_unused_194_15413 unused_194;
    struct stl_vector_ptr_world_site sites;
    struct stl_vector_ptr_world_region regions;
    struct region_map_entry **region_map;
    int16_t world_data_anon_6;
    int16_t world_data_anon_7;
};

struct stl_vector_ptr_matgloss_wood {
struct matgloss_wood **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_matgloss_stone {
struct matgloss_stone **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_matgloss_gem {
struct matgloss_gem **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_matgloss_plant {
struct matgloss_plant **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_body_template {
struct body_template **ptr;
void *endptr;
void *endalloc;
};
struct T_glosses_8445 {
    struct stl_string id;
    struct stl_string oldtext;
    struct stl_string newtext;
} ;
struct stl_vector_ptr_T_glosses_8445 {
struct T_glosses_8445 **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_creature_raw {
struct creature_raw **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdefst {
struct itemdefst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_weaponst {
struct itemdef_weaponst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_trapcompst {
struct itemdef_trapcompst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_toyst {
struct itemdef_toyst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_instrumentst {
struct itemdef_instrumentst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_armorst {
struct itemdef_armorst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_ammost {
struct itemdef_ammost **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_siegeammost {
struct itemdef_siegeammost **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_glovesst {
struct itemdef_glovesst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_shoesst {
struct itemdef_shoesst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_shieldst {
struct itemdef_shieldst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_helmst {
struct itemdef_helmst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_pantsst {
struct itemdef_pantsst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_itemdef_foodst {
struct itemdef_foodst **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_entity_raw {
struct entity_raw **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_language_word {
struct language_word **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_language_symbol {
struct language_symbol **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_language_translation {
struct language_translation **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_descriptor_color {
struct descriptor_color **ptr;
void *endptr;
void *endalloc;
};
struct stl_vector_ptr_descriptor_shape {
struct descriptor_shape **ptr;
void *endptr;
void *endalloc;
};
struct world_raws {
    struct T_matgloss_8424 {
        struct stl_vector_ptr_matgloss_wood wood;
        struct stl_vector_ptr_matgloss_stone stone;
        struct stl_vector_ptr_matgloss_gem gem;
        struct stl_vector_ptr_matgloss_plant plant;
    } matgloss;
    struct T_body_8439 {
        struct stl_vector_ptr_body_template templates;
        struct stl_vector_ptr_T_glosses_8445 glosses;
    } body;
    struct stl_vector_ptr_creature_raw creatures;
    struct T_itemdefs_8461 {
        struct stl_vector_ptr_itemdefst all;
        struct stl_vector_ptr_itemdef_weaponst weapons;
        struct stl_vector_ptr_itemdef_trapcompst trapcomps;
        struct stl_vector_ptr_itemdef_toyst toys;
        struct stl_vector_ptr_itemdef_instrumentst instruments;
        struct stl_vector_ptr_itemdef_armorst armor;
        struct stl_vector_ptr_itemdef_ammost ammo;
        struct stl_vector_ptr_itemdef_siegeammost siegeammo;
        struct stl_vector_ptr_itemdef_glovesst gloves;
        struct stl_vector_ptr_itemdef_shoesst shoes;
        struct stl_vector_ptr_itemdef_shieldst shields;
        struct stl_vector_ptr_itemdef_helmst helms;
        struct stl_vector_ptr_itemdef_pantsst pants;
        struct stl_vector_ptr_itemdef_foodst food;
    } itemdefs;
    struct stl_vector_ptr_entity_raw entities;
    struct T_language_8512 {
        struct stl_vector_ptr_language_word words;
        struct stl_vector_ptr_language_symbol symbols;
        struct stl_vector_ptr_language_translation translations;
        struct language_word_table _word_table[2][38];
    } language;
    struct T_descriptors_8527 {
        struct stl_vector_ptr_descriptor_color colors;
        struct stl_vector_ptr_descriptor_shape shapes;
    } descriptors;
};

struct world {
    struct stl_vector_ptr_mineral_cluster gem_clusters;
    struct stl_vector_ptr_mineral_cluster stone_clusters;
    struct stl_vector_ptr_engraving engravings;
    struct stl_vector_ptr_vermin vermin;
    struct stl_vector_ptr_coord contaminated_rivers;
    struct stl_vector_ptr_drink_area drink_areas;
    struct stl_vector_ptr_coord caveriver_tiles;
    struct stl_vector_ptr_coord chasm_tiles;
    struct stl_vector_ptr_coord magmaflow_tiles;
    struct stl_vector_ptr_waterfall waterfalls;
    struct stl_vector_ptr_cavein_region cavein_regions;
    struct stl_vector_ptr_campfire campfires;
    struct stl_vector_ptr_coord contaminated_floors;
    struct stl_vector_ptr_web_cluster web_clusters;
    struct stl_vector_ptr_fire fires;
    struct stl_vector_ptr_effect_info _effects;
    struct stl_vector_ptr_coin_batch coin_batches;
    struct stl_vector_ptr_local_population populations;
    struct stl_vector_ptr_manager_order manager_orders;
    struct stl_vector_ptr_mandate mandates;
    struct T_entities_15510 {
        struct stl_vector_ptr_historical_entity all;
        struct stl_vector_ptr_historical_entity bad;
    } entities;
    struct T_units_15515 {
        struct stl_vector_ptr_unit all;
        struct stl_vector_ptr_unit active;
        struct stl_vector_ptr_unit other[3];
        struct stl_vector_ptr_unit bad;
    } units;
    struct stl_vector_ptr_unit_chunk unit_chunks;
    struct stl_vector_ptr_art_image_chunk art_image_chunks;
    struct T_nemesis_15527 {
        struct stl_vector_ptr_nemesis_record all;
        struct stl_vector_ptr_nemesis_record bad;
    } nemesis;
    struct T_items_15532 {
        struct stl_vector_ptr_itemst all;
        struct stl_vector_ptr_itemst other[82];
        struct stl_vector_ptr_itemst bad;
        struct stl_vector_int32_t bad_tag;
    } items;
    struct T_artifacts_15541 {
        struct stl_vector_ptr_artifact_record all;
        struct stl_vector_ptr_artifact_record bad;
    } artifacts;
    struct df_linked_list job_list;
    struct df_linked_list proj_list;
    struct T_buildings_15549 {
        struct stl_vector_ptr_buildingst all;
        struct stl_vector_ptr_buildingst other[63];
        struct stl_vector_ptr_buildingst bad;
    } buildings;
    struct T_hauling_15559 {
        struct stl_vector_int8_t local_weapon[64];
        struct stl_vector_int8_t foreign_weapon[64];
        struct stl_vector_int8_t local_siegeammo[64];
        struct stl_vector_int8_t foreign_siegeammo[64];
        int8_t local_trapcomp[64];
        int8_t foreign_trapcomp[64];
        struct stl_vector_int8_t local_armor[64];
        struct stl_vector_int8_t local_helm[64];
        struct stl_vector_int8_t local_shoes[64];
        struct stl_vector_int8_t local_gloves[64];
        struct stl_vector_int8_t local_pants[64];
        struct stl_vector_int8_t local_shield[64];
        struct stl_vector_int8_t foreign_armor[64];
        struct stl_vector_int8_t foreign_helm[64];
        struct stl_vector_int8_t foreign_shoes[64];
        struct stl_vector_int8_t foreign_gloves[64];
        struct stl_vector_int8_t foreign_pants[64];
        struct stl_vector_int8_t foreign_shields[64];
        int32_t num_jobs[10];
        int32_t num_haulers[10];
        int8_t anon_1;
        int8_t prepared_meal;
        struct stl_vector_int8_t seed_mats;
        struct stl_vector_int8_t plant_mats;
        struct stl_vector_int8_t cheese_mats;
        struct stl_vector_int8_t meat_mats;
        struct stl_vector_int8_t leaves_mats;
        struct stl_vector_int8_t powder_mats;
        int8_t seeds;
        int8_t plants;
        int8_t cheese;
        int8_t fish;
        int8_t meat;
        int8_t leaves;
        int8_t powder;
        struct stl_vector_int8_t plant_extract;
        struct stl_vector_int8_t animal_extract;
        struct stl_vector_int8_t liquid_misc;
        struct stl_vector_int8_t fat;
        int8_t weapons;
        int8_t armor;
        int8_t ammo;
        int8_t coins;
        int8_t bar_blocks;
        int8_t gems;
        int8_t finished_goods;
        int8_t leather;
        int8_t cloth;
    } hauling;
    struct T_plants_15611 {
        struct stl_vector_ptr_vegst all;
        struct stl_vector_ptr_vegst shrub_forest;
        struct stl_vector_ptr_vegst shrub_swamp;
        struct stl_vector_ptr_vegst shrub_river;
        struct stl_vector_ptr_vegst shrub_cave;
        struct stl_vector_ptr_vegst unknown;
        struct stl_vector_ptr_vegst tree_outside_dry;
        struct stl_vector_ptr_vegst tree_outside_wet;
        struct stl_vector_ptr_vegst tree_inside_dry;
        struct stl_vector_ptr_vegst tree_inside_wet;
    } plants;
    struct df_linked_list quests;
    struct T_enemy_status_cache_15626 {
        int8_t slot_used[500];
        int8_t rel_map[500][500];
        int32_t next_slot;
    } enemy_status_cache;
    struct T_schedules_15634 {
        struct stl_vector_ptr_schedule_info all;
        struct stl_vector_ptr_schedule_info bad;
    } schedules;
    struct buildingst *selected_building;
    union {
        int16_t building_type;
        int16_t selected_stockpile_type;
    } build_type;
    union {
        int16_t furnace_type;
        int16_t workshop_type;
        int16_t siegeengine_type;
        int16_t trap_type;
    } build_subtype;
    int8_t update_selected_building;
    int16_t building_width;
    int16_t building_height;
    int8_t build_direction_1;
    int8_t build_direction_2;
    int8_t build_direction_3;
    int8_t build_direction_4;
    struct T_map_15659 {
        struct stl_vector_ptr_map_block map_blocks;
        struct map_block ****block_index;
        int32_t x_count_block;
        int32_t y_count_block;
        int32_t z_count_block;
        int32_t x_count;
        int32_t y_count;
        int32_t z_count;
        int16_t stone_types[16];
        int16_t distance_lookup[53][53];
    } map;
    int32_t world_anon_1[20000];
    int32_t world_anon_2[20000];
    int32_t world_anon_3[20000];
    int8_t mapElevationRotation[20000];
    int8_t showFakeElevationDividers;
    int32_t feature_type[3];
    int32_t feature_depth[3];
    int32_t world_anon_4;
    int8_t world_anon_5;
    int32_t world_anon_6;
    int32_t world_anon_7;
    struct world_data world_data;
    struct T_worldgen_15697 {
        int16_t state;
        int32_t num_rejects;
        int32_t lakes_total;
        int32_t anon_1;
        int16_t anon_2;
        int32_t lakes_cur;
        int32_t anon_3;
        struct stl_vector_ptr anon_4;
        struct stl_vector_ptr anon_5;
        struct stl_vector_ptr anon_6;
        int32_t finalized_sites;
        int32_t finalized_histfigs;
        int32_t finalized_site_units;
        struct stl_vector_ptr anon_7;
        int32_t anon_8;
        int32_t anon_9;
        int32_t anon_10;
        int32_t anon_11;
        int32_t anon_12;
        int32_t anon_13;
        struct stl_vector_ptr anon_14;
        struct stl_vector_ptr anon_15;
        int32_t rivers_total;
        int32_t rivers_cur;
    } worldgen;
    int16_t surface_z;
    int16_t riverCenterXs[480];
    int16_t caveriverCenterXs[480];
    int16_t chasmCenterXs[480];
    int16_t magmaCenterXs[480];
    int8_t chasmIsDead;
    int16_t chasm_magma_counter;
    int32_t chasm_anger;
    struct flow_reuse_pool orphaned_flow_pool;
    struct world_raws raws;
    int16_t lava_stone;
    int16_t river_stone;
    int16_t flux_stone;
    int16_t sharp_stone;
    int16_t glass_gem;
    struct T_fortress_15742 {
        struct stl_string anon_1;
        struct language_name name;
        int32_t anon_2;
        int32_t site;
        int8_t anon_3;
        int16_t anon_4;
        int32_t anon_5;
        int16_t anon_6;
        int16_t anon_7;
        struct coord2d pos;
    } fortress;
    int8_t reindex_pathfinding;
    int32_t frame_counter;
    struct stl_vector_ptr_flow_info orphaned_flows;
};

enum world_population_type {
    world_population_type_Animal_Wildlife,
    world_population_type_Animal_FishPond,
    world_population_type_Animal_FishRiver,
    world_population_type_Animal_FishCaveRiver,
    world_population_type_Plant_River,
    world_population_type_Plant_Swamp,
    world_population_type_Plant_Forest,
    world_population_type_Plant_Cave,
    world_population_type_Animal_VerminEater,
    world_population_type_Animal_VerminFlies,
    world_population_type_Animal_VerminSwamper,
    world_population_type_Animal_VerminCaveRiver,
    world_population_type_Animal_LargeCaveRiver,
    world_population_type_Animal_VerminChasm,
    world_population_type_Animal_LargeChasm,
    world_population_type_Animal_VerminLava,
    world_population_type_Animal_LargeLava,
    world_population_type_Animal_VerminSoil,
    world_population_type_Animal_VerminSoilColony,
    world_population_type_Animal_VerminGrounder,
    world_population_type_Animal_FishOcean,
    world_population_type_Tree_IndoorWet,
    world_population_type_Tree_IndoorDry,
    world_population_type_Tree_OutdoorWet,
    world_population_type_Tree_OutdoorDry
};

enum wrestle_move_type {
    wrestle_move_type_Lock,
    wrestle_move_type_Choke,
    wrestle_move_type_Takedown,
    wrestle_move_type_Throw,
    wrestle_move_type_Pinch,
    wrestle_move_type_Gouge,
    wrestle_move_type_Break = 10,
    wrestle_move_type_Release,
    wrestle_move_type_Shake,
    wrestle_move_type_Strangle
};

struct stl_vector_ptr_timed_event {
struct timed_event **ptr;
void *endptr;
void *endalloc;
};
struct T_cursor_2312 {
    int32_t x;
    int32_t y;
    int32_t z;
} cursor;

struct T_selection_rect_2322 {
    int32_t start_x;
    int32_t start_y;
    int32_t start_z;
    int32_t end_x;
    int32_t end_y;
    int32_t end_z;
} selection_rect;

int32_t gamemode;

int32_t gametype;

int8_t ui_area_map_width;

int8_t ui_menu_width;

struct stl_vector_int16_t created_item_type;

struct stl_vector_int16_t created_item_subtype;

struct stl_vector_int16_t created_item_material;

struct stl_vector_int16_t created_item_matgloss;

struct stl_vector_int32_t created_item_count;

struct stl_vector_ptr_flow_info flows;

struct enabler enabler;

struct graphic gps;

struct interfacest gview;

struct init init;

struct stl_vector_ptr_timed_event timed_events;

struct ui ui;

struct ui_advmode ui_advmode;

struct ui_build_selector ui_build_selector;

struct stl_vector_int8_t ui_building_assign_type;

struct stl_vector_int8_t ui_building_assign_is_marked;

struct stl_vector_ptr_unit ui_building_assign_units;

struct stl_vector_ptr_itemst ui_building_assign_items;

struct ui_look_list ui_look_list;

struct ui_sidebar_menus ui_sidebar_menus;

struct world world;

int32_t art_image_chunk_next_id;

int32_t artifact_next_id;

int32_t building_next_id;

int32_t entity_next_id;

int32_t hist_event_next_id;

int32_t hist_figure_next_id;

int32_t item_next_id;

int32_t job_next_id;

int32_t nemesis_next_id;

int32_t proj_next_id;

int32_t schedule_next_id;

int32_t task_next_id;

int32_t unit_chunk_next_id;

int32_t unit_next_id;

int32_t cur_year;

int32_t cur_year_tick;

int32_t cur_year_tick_advmode;

int8_t cur_season;

int16_t cur_season_tick;

int8_t current_weather;

int8_t pause_state;

int8_t process_dig;

int8_t process_jobs;

int8_t ui_building_in_assign;

int8_t ui_building_in_resize;

int32_t ui_building_item_cursor;

int32_t ui_look_cursor;

int32_t ui_selected_unit;

struct ui_unit_view_mode ui_unit_view_mode;

int8_t ui_workshop_in_add;

int32_t ui_workshop_job_cursor;

int32_t window_x;

int32_t window_y;

int32_t window_z;

int8_t debug_nopause;

int8_t debug_nomoods;

int8_t debug_combat;

int8_t debug_wildlife;

int8_t debug_nodrink;

int8_t debug_noeat;

int8_t debug_nosleep;

int8_t debug_showambush;

int8_t debug_fastmining;

int8_t debug_nothought;

int8_t debug_noberserk;

int8_t debug_turbospeed;

int8_t save_on_exit;

uint8_t standing_orders_gather_minerals;

uint8_t standing_orders_gather_wood;

uint8_t standing_orders_gather_food;

uint8_t standing_orders_gather_bodies;

uint8_t standing_orders_gather_animals;

uint8_t standing_orders_gather_furniture;

uint8_t standing_orders_farmer_harvest;

uint8_t standing_orders_job_cancel_announce;

uint8_t standing_orders_mix_food;

uint8_t standing_orders_gather_refuse;

uint8_t standing_orders_gather_refuse_outside;

uint8_t standing_orders_dump_corpses;

uint8_t standing_orders_dump_skulls;

uint8_t standing_orders_dump_skins;

uint8_t standing_orders_dump_bones;

uint8_t standing_orders_dump_shells;

uint8_t standing_orders_dump_other;

uint8_t standing_orders_auto_loom;

uint8_t standing_orders_auto_collect_webs;

uint8_t standing_orders_auto_slaughter;

uint8_t standing_orders_auto_butcher;

uint8_t standing_orders_auto_tan;

uint8_t standing_orders_use_dyed_cloth;

uint8_t standing_orders_stay_indoors;

