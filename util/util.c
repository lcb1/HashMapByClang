//
// Created by admin on 2020/12/20.
//
#include "util.h"
#include <stdio.h>
char* new_str(char* str){
    int len=strlen(str)+1;
    char* ret=(char*)malloc(sizeof(char)*len);

    for(int i=0;i<len;i++){
        ret[i]=str[i];
    }
//    printf("new_str: %s\n\r",ret);
    return ret;
}
int str_hash(void* str){
    int hash_val=0;
    char* real=(char*)str;
    int len=strlen(real);
    for(int i=0;i<len;i++){
        hash_val+=hash_val*31+real[i];
    }
//    printf("%d\n\r",hash_val);
    return hash_val;
}
int int_hash(void* integer){
    return *((int*)integer);
}
int int_compare(void* a,void* b){
    int* real_a=(int*)a;
    int* real_b=(int*)b;
    return *real_a==*real_b;
}
int str_compare(void* a,void* b){
    char* real_a=(char*)a;
    char* real_b=(char*)b;
    int len_a=strlen(real_a);
    int len_b=strlen(real_b);
    if(len_a!=len_b) return 0;


    for(int i=0;i<len_a;i++){
        if(real_b[i]!=real_a[i]) return 0;
    }
    return 1;

}
int* new_int(int a){
    int* ret=(int*)malloc(sizeof(int));
    *ret=a;
    return ret;
}