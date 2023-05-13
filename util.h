#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <stdio.h>

#define __fatal_assertion__(msg) printf("\033[31m\033[1mfatal error: \033[0m%s",msg);\
                                 exit(1);
#define __runtime_assertion__(msg) printf("\033[31m\033[1mruntime error: \033[0m%s",msg);\
                                 exit(1);

void printout_help();

int pow2(int n, int b);

int str2uint(char *s);

typedef unsigned char bool_t; 
#define TRUE 1
#define FALSE 0

#endif