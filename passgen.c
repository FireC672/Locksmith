#include "passgen.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
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


double evaluate_password(int length, char* password){
    int specialCharacters=0, digits=0, lowercases=0, uppercases=0;

    for(int i = 0; i < length; i++){
        if(isdigit(password[i]))digits++;
        if(isalpha(password[i])){
            lowercases += isupper(password[i]);
            uppercases += islower(password[i]);
        }

        if(isascii(password[i]) && !isalpha(password[i]))
            specialCharacters++;
    }

    return ((double)(specialCharacters+digits+lowercases+uppercases))/(4+length);
}