#ifndef PROYECTO3_HASH_TABLE_STREET_INFO_H
#define PROYECTO3_HASH_TABLE_STREET_INFO_H

typedef enum StreetDir {
    NORTH_DIR,
    SOUTH_DIR,
    WEST_DIR,
    EAST_DIR,
    
} StreetDir;

typedef struct StreetInfo {
    float x;
    float y;
    StreetDir dir;
} StreetInfo;

typedef struct NodeStreetInfo {
    int key;
    StreetInfo *val;
    struct NodeStreetInfo *next;
} NodeStreetInfo;

typedef struct TableStreetInfo {
    int size;
    NodeStreetInfo **list;
} TableStreetInfo;

TableStreetInfo *create_table_street_info(int size);

StreetInfo *create_street_info(double, double, StreetDir);

int hash_code_street_info(TableStreetInfo *, int);

void insert_street_info(TableStreetInfo *, int, StreetInfo *);

StreetInfo *lookup_street_info(TableStreetInfo *t, int);

#endif //PROYECTO3_HASH_TABLE_STREET_INFO_H
