#ifndef PASSWORD_GENERATOR_UTILITY
#define PASSWORD_GENERATOR_UTILITY

#define BASE64_TOKEN(x) "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define HEXADEC_TOKEN(x) "0123456789ABCDEFabcdef"

// Generates a 64 base password.
char* base64_pass(int length);
// Generates a hex password.
char* hex_pass(int length);

#endif