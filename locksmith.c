#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "passgen.h"
#include "util.h"

bool_t encodeBase64=FALSE;

int main(int argc, char** argv){
   if(argc == 1){
      printout_help();
      return 0;
   }

   for(int i = 1; i < argc; i++){
      //bool_t badOption = TRUE;
      if(!strcmp(argv[i],"--base64")){
         encodeBase64=TRUE;
         int arg1 = str2uint(argv[i+1]);
         printf("%i",arg1);
         if(!(i+2 < argc))break; 
         i+=2;
      }
   } 
   return 0;
}
