//
// Created by admin on 2020/12/20.
//

#ifndef DICTTREEPRO_MAP_H
#define DICTTREEPRO_MAP_H
extern int is_debug;
struct map;
typedef struct map map;

struct map_node;
typedef struct map_node map_node;

typedef int (*hash)(void*);
typedef int (*compare)(void*,void*);


struct map_node{
    void* key;
    void* val;
    map_node* next;
};
struct map{
    int count;
    int cap;
    map_node** table;
    hash al_hash;
    compare al_comp;
};
map_node* new_map_node(void* key,void* val);
void free_map_node(map_node*);
map_node** new_map_table(int len);
void free_map_table(map* this);
map* new_map(hash al_hash,compare cmp);
void free_map(map* this);
int get_index(map* this,void* key);
map_node* get_map_node(map* this,void* key);
void put(map* this,void* key,void* val);
void rehash(map* this);
void* get_val(map* this,void* key);
char* get_val_by_str(map* this,void* key);
int* get_val_by_int(map* this,void* key);



#endif //DICTTREEPRO_MAP_H
