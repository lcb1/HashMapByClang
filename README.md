# HashMapByClang
> 测试代码
```
#include <stdio.h>
#include <stdlib.h>
#include "util/util.h"
#include "collection/map.h"
#include <errno.h>


map* new_map_int_int(){
    map* ret=new_map(int_hash,int_compare);
    return ret;
}

map* new_map_str_str(){
    map* ret=new_map(str_hash,str_compare);
    return ret;
}


void main(){
    char* key=new_str("Hello");
    char* val=new_str("World!");
    map* mp=new_map_str_str();
    put(mp,key,val);
    char* get_val=get_val_by_str(mp,key);
    printf("Hello: %s",get_val);
    free_map(mp);
}
```
> 输出: Hello: World
