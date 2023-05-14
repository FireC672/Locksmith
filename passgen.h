#ifndef PASSWORD_GENERATOR_UTILITY
#define PASSWORD_GENERATOR_UTILITY

#define BASE64_TOKEN "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define HEXADEC_TOKEN "0123456789ABCDEFabcdef"

// Generates a 64 base password.
char* base64_pass(int length);
// Generates a hex password.
char* hex_pass(int length);

double evaluate_password(int length, char* password);

// Ten of the most used passwords: 
/*
123456 6  <--+
password 8 <-+--=> 23
123456789 9 <+ 
12345678 8
12345 5
1234567 7
1234567890 10
qwerty 6
abc123 6
admin 5

TOTAL: 70 characters + 10 null terminators
TOTAL: 80 characters
*/

// Will generate the ten most used passwords.
char** outdb();

int isPasswordInDatabase(char* password, int length);

#endif