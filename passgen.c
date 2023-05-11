#include "passgen.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

// Generates a 64 base password.
char* base64_pass(int length){
    char* outpass = malloc(length+2);
    if(outpass == NULL)return NULL; 
    
    srand(time(NULL));
    for(int i = 0; i < length; i++){
        outpass[i] = BASE64_TOKEN[rand()%64];
    }
    outpass[length+1]='\0';

    return outpass;
}

// Generates a hex password.
char* hex_pass(int length){
    char* outpass = malloc(length+2);
    if(outpass == NULL)return NULL; 
    
    srand(time(NULL));
    for(int i = 0; i < length; i++){
        outpass[i] = HEXADEC_TOKEN[rand()%22];
    }
    outpass[length+1]='\0';
    return outpass;
}