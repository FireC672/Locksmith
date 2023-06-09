#include "passgen.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "util.h"

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


double evaluate_password(int length, char* password, int* outputs){
    double specialCharacters=0, digits=0, lowercases=0, uppercases=0;

    for(int i = 0; i < length; i++){
        if(isdigit(password[i]))digits++;
        if(isalpha(password[i])){
            lowercases += isupper(password[i]);
            uppercases += islower(password[i]);
        }

        if(isascii(password[i]) && !isdigit(password[i]) && !isalpha(password[i]))
            specialCharacters++;
    }

    outputs[0]=(int)specialCharacters; 
    outputs[1]=(int)lowercases;
    outputs[2]=(int)uppercases;
    outputs[3]=(int)digits;

    // printf("%i spch -- %i digs -- %i lowcs -- %i upcsc.\n",
    // specialCharacters,digits,lowercases,uppercases);

    return 1/((specialCharacters*1+lowercases+uppercases+digits)*length);
}

double evaluate2(int length, char* password){
    double score = 0; 

    for(int i = 0; i < length; i++){
        if(isascii(password[i]) && !isalnum(password[i]))score+=1.0;
        if(isdigit(password[i]) ||  isalpha(password[i]))score+=0.5;
    }

    return 2/score;
}

char** outdb(){
    char** db = malloc(80);
    db[0] = "123456";
    db[1] = "password";
    db[2] = "123456789";
    db[3] = "1234567890";
    db[4] = "abc123";
    db[5] = "admin";
    db[6] = "12345";
    db[7] = "123456";
    db[8] = "1234567";
    return db;
}

int isPasswordInDatabase(char* password, int length){
    // Not in database, but not safe either.
    if(length < 5)return 2;
    int code = 0;
    if(length > 5 && length < 10){
        char** outdatabase = outdb();
        // In database.
        if(INSTR_ARRAY(password,outdatabase,10)){
            code=1;
        }
        free(outdatabase);
    }

    return code;
}