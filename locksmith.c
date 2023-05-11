#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "passgen.h"
#include "util.h"


int main(int argc, char** argv){
   if(argc == 1){
      printout_help();
      return 0;
   }

   for(int i = 1; i < argc; i++){
      bool_t badOption = TRUE;
      if(!strcmp(argv[i],"--base64")){
         
         printf("Please specify length: ");
         int nLength=0; 

         scanf("%u",&nLength);

         char* base64_p = base64_pass(nLength);

         if(base64_p == NULL)__fatal_assertion__("malloc() failed.");

        // printf("%s",base64_p);
         free(base64_p);
      }



      if(badOption){
         printf("Bad option \'%s\' \nType -h for help.\n",argv[i]);
         return 1;
      }
   }
   return 0;
}
