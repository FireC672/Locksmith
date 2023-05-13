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
      //bool_t badOption = TRUE;
      if(!strcmp(argv[i],"--base64")){
         
         printf("Please specify length: ");
         int nLength=1; 

         fflush(stdin);

         scanf("%i",&nLength);

         char* generatedBase64 = base64_pass(nLength);

         for(int i = 0; i < nLength; i++)putchar(generatedBase64[i]);

         putchar('\n');
         free(generatedBase64);
       //  badOption=FALSE;
      }



      // if(badOption == TRUE){
      //    printf("Bad option \'%s\' \nType -h for help.\n",argv[i]);
      //    return 1;
      // }
   }
   return 0;
}
