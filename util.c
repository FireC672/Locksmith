#include "util.h"
#include <stdio.h> 
#include <string.h>

void printout_help(){
    printf("Passgenerator or Locksmith is a powerful password generator,\n");
    printf("And password rater, Passgenerator has cryptomodules\n for generating better passwords.\n");

    printf("\n--- AVAILABLE CRYPTOMODULES ---\n");
    printf("\t Base-64 Crypto: \'--base64\' \n");
    printf("\t Hexadecimal Crypto: \'--hex\' \n");

    printf("\nPassgenerator or Locksmith has also misc functions like, counting\n combinations \'--count-combinations\'\n");


    printf("\n\nPassgenerator/Locksmith is a free, open-source project.\n");
    printf("Passgenerator/Locksmith is under the GNU General Public License.\n\
And comes with absolutely no warranty. It was made By FireC675.\n");
}

long pow2(int n, int b){
    int tot = 1;
    for(int i = 0; i < n; i++){
       tot *= b;
    }
    return tot;
}

int str2uint(char *s){
    int l = strlen(s);
    if(l == 0)return -1;
    int out = 0;
    int j = l-1;
    for(int i = 0; i < l; i++){
        out += (s[i]-'0')*pow2(j,10);
        j--;
    }
    return out;
}