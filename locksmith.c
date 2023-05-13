#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "passgen.h"
#include "util.h"

bool_t encodeBase64=FALSE;

bool_t countPossibilites=FALSE;

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

         if(!(i+1 < argc)){
            printf("Please specify a length.\n");
            printf("\t%s %s ####\n",argv[0],argv[1]);
            putchar('\t');
            for(int i = 0; i < strlen(argv[0])+strlen(argv[1])+1;i++)putchar(' ');
            printf(" ^~~~~~~~ Specify length here.\n");
            return 1;
         }
         passlen = str2uint(argv[i+1]);

         if(passlen == -1){
            printf("Can\'t not accept negative or null lengths.\n");
            return 1;
         }

         if(!(i+2 < argc))break; 
         i+=2;
      }

      if(!strcmp(argv[i],"--c-possibilites")){
         countPossibilites=TRUE;
      }
   }

   if(encodeBase64){
      char* out_base64 = base64_pass(passlen);
      printf("%s\n",out_base64);
      free(out_base64);
      
      if(countPossibilites){
         long p = pow2(passlen,strlen(BASE64_TOKEN));
         printf("There are %ld possibilites.\n",p);
      }

      return 0;
   }
   return 0;
}
