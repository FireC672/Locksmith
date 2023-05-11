#ifndef UTILITY_HPP
#define UTILITY_HPP

#define __fatal_assertion__(msg) printf("\033[31m\033[1mfatal error: \033[0m%s",msg);\
                                 exit(1);
#define __runtime_assertion__(msg) printf("\033[31m\033[1mruntime error: \033[0m%s",msg);\
                                 exit(1);

void printout_help();

typedef unsigned char bool_t; 
#define TRUE 1
#define FALSE 0

#endif