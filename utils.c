#include "utils.h"

int string_cmp(const char* str1,const char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2)return 0;
    
    for(int i = 0; i < len1; i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}

size_t strlen(const char* str){
    size_t len = 0;
    while(str[len] != '\0'){
        len++;
    }

    return len;
}