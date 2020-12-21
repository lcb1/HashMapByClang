//
// Created by admin on 2020/12/20.
//

#ifndef DICTTREEPRO_UTIL_H
#define DICTTREEPRO_UTIL_H
#include <stdlib.h>
#include <string.h>
char* new_str(char* str);
int str_hash(void* str);
int int_hash(void* integer);
int int_compare(void* a,void* b);
int str_compare(void* a,void* b);
int* new_int(int a);





#endif //DICTTREEPRO_UTIL_H
