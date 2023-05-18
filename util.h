#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <stdio.h>
#include <string.h>

#define __fatal_assertion__(msg) printf("\033[31m\033[1mfatal error: \033[0m%s",msg);\
                                 exit(1);
#define __runtime_assertion__(msg) printf("\033[31m\033[1mruntime error: \033[0m%s",msg);\
                                 exit(1);

#define IN_ARRAY(val, arr, len) ({ \
    int found = 0; \
    for (int i = 0; i < len; i++) { \
        if (arr[i] == val) { \
            found = 1; \
            break; \
        } \
    } \
    found; \
})

#define INSTR_ARRAY(val, arr, len) ({ \
    int found = 0; \
    for (int i = 0; i < len; i++) { \
        if (!strcmp(val,arr[i])) { \
            found = 1; \
            break; \
        } \
    } \
    found; \
})

// #define CHAR_INSTR(chr, str, len) {\
//    for(int i = 0; i < len; i++){\
//      if(str[i] == chr)1;\
//    }\
//    0; \
// }


int CHAR_INSTR(char c, char* str, int l);

void printout_help();

long pow2(int n, int b);

int str2uint(char *s);

typedef unsigned char bool_t; 
#define TRUE 1
#define FALSE 0

#endif