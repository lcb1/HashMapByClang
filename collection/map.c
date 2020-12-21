//
// Created by admin on 2020/12/20.
//
#include "map.h"
#include <stdlib.h>
#include <stdio.h>
int is_debug=0;


map_node* new_map_node(void* key,void* val){
    map_node* ret=(map_node*)malloc(sizeof(map_node));
    ret->key=key;
    ret->val=val;
    ret->next=NULL;
    return ret;
}
void free_map_node(map_node* this){
    map_node* p=this;
    while(p!=NULL){
        map_node* t=p->next;
        free(p->key);
        free(p->val);
        free(p);
        p=t;
    }
}
map_node** new_map_table(int len){
    map_node** ret=(map_node**)malloc(sizeof(map_node*)*len);
    for(int i=0;i<len;i++){
        ret[i]=NULL;
    }
    return ret;
}
void free_map_table(map* this){
    for(int i=0;i<this->cap;i++){
        free_map_node(this->table[i]);
    }
    free(this->table);
}
map* new_map(hash al_hash,compare cmp){
    map* ret=(map*)malloc(sizeof(map));
    ret->count=0;
    ret->cap=8;
    ret->table=new_map_table(ret->cap);
    ret->al_hash=al_hash;
    ret->al_comp=cmp;
    return ret;
}
void free_map(map* this){
    free_map_table(this);
    free(this);
}
int get_index(map* this,void* key){
    return this->al_hash(key)&(this->cap-1);
}
map_node* get_map_node(map* this,void* key){
    int index=get_index(this,key);
    map_node* head=this->table[index];
    map_node* p=head;
    while(p!=NULL){
        if(this->al_comp(p->key,key)) return p;
        p=p->next;
    }

    return p;
}
void put(map* this,void* key,void* val){
//    printf("cap:%d,count:%d\n\r",this->cap,this->count);
    if(this->cap*2<this->count*3){
        rehash(this);
    }

    int index=get_index(this,key);
    map_node* now=new_map_node(key,val);
    map_node* head=this->table[index];

    if(head==NULL){

        this->table[index]=now;
        this->count++;
        return;
    }
    map_node* p=head;
    while(p->next!=NULL){
        if(this->al_comp(p->val,val)){
            p->val=val;
            return;
        }
        p=p->next;
    }
    p->next=now;
    this->count++;
}
void rehash(map* this){
    int count=this->count;
    int cap=this->cap;
    map_node** table=this->table;
    this->count=0;
    this->cap=cap<<1;
    this->table=new_map_table(this->cap);
    for(int i=0;i<cap;i++){
        map_node* p=table[i];
        while(p!=NULL){
            put(this,p->key,p->val);
            p=p->next;
        }
    }
    free(table);
}
void* get_val(map* this,void* key){
    map_node* now=get_map_node(this,key);
    if(now==NULL) return NULL;
    return now->val;
}
char* get_val_by_str(map* this,void* key){
    return (char*)get_val(this,key);
}
int* get_val_by_int(map* this,void* key){
    return (int*)get_val(this,key);
}