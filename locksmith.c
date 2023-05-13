#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "passgen.h"
#include "util.h"

bool_t encodeBase64=FALSE;

int passlen = 0;

int main(int argc, char** argv){
   if(argc == 1){
      printout_help();
      return 0;
   }

   for(int i = 1; i < argc; i++){
      //bool_t badOption = TRUE;
      if(!strcmp(argv[i],"--base64")){
         encodeBase64=TRUE;
         passlen = str2uint(argv[i+1]);

         if(passlen == -1){
            printf("Can\'t not accept negative or null lengths.\n");
            return 1;
         }

         if(!(i+2 < argc))break; 
         i+=2;
      }
   }

   if(encodeBase64){
      char* out_base64 = base64_pass(passlen);
      printf("%s",out_base64);
      free(out_base64);
      return 0;
   }
   return 0;
}
