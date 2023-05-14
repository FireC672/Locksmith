#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <stdio.h>
#include <string.h>

#define __fatal_assertion__(msg) printf("\033[31m\033[1mfatal error: \033[0m%s",msg);\
                                 exit(1);
#define __runtime_assertion__(msg) printf("\033[31m\033[1mruntime error: \033[0m%s",msg);\
                                 exit(1);

#define IN_ARRAY(val, arr, len) ({ \
    bool found = false; \
    for (int i = 0; i < len; i++) { \
        if (arr[i] == val) { \
            found = true; \
            break; \
        } \
    } \
    found; \
})

#define INSTR_ARRAY(val, arr, len) ({ \
    bool found = false; \
    for (int i = 0; i < len; i++) { \
        if (!strcmp(arr[i],val)) { \
            found = true; \
            break; \
        } \
    } \
    found; \
})

void printout_help();

long pow2(int n, int b);

int str2uint(char *s);

typedef unsigned char bool_t; 
#define TRUE 1
#define FALSE 0

#endif