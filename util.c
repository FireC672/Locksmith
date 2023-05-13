#include "util.h"
#include <stdio.h> 
#include <string.h>

void printout_help(){
    printf("--base64: will generate a base-64 password.\n");
}

int pow2(int n, int b){
    int tot = 1;
    for(int i = 0; i < n; i++){
       tot *= b;
    }
    return tot;
}

int str2uint(char *s){
    int l = strlen(s);
    if(l == 0)return -1;
    int out = 0;
    int j = l-1;
    for(int i = 0; i < l; i++){
        out += (s[i]-'0')*pow2(j,10);
        j--;
    }
    return out;
}