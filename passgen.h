#ifndef PASSWORD_GENERATOR_UTILITY
#define PASSWORD_GENERATOR_UTILITY

#define BASE64_TOKEN "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define HEXADEC_TOKEN "0123456789ABCDEFabcdef"

// Generates a 64 base password.
char* base64_pass(int length);
// Generates a hex password.
char* hex_pass(int length);

// This function is now obsolete.
double evaluate_password(int length, char* password, int* outputs);

// This is the now improved function.
double evaluate2(int length, char* password);

// Will generate the ten most used passwords.
char** outdb();

int isPasswordInDatabase(char* password, int length);

#endif