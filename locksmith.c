#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "passgen.h"
#include "util.h"

bool_t encodeBase64=FALSE;
bool_t encodeHexMod=FALSE;

bool_t countPossibilites=FALSE;

int passlen = 0;

int main(int argc, char** argv){

   if(argc == 1){
      printout_help();
      return 0;
   }

   for(int i = 1; i < argc; i++){
      if(!strcmp(argv[i],"--help")){
         // abort all other steps.
         printout_help();
         return 0;
      }

      if(!strcmp(argv[i],"--base64")){
         encodeBase64=TRUE;
         encodeHexMod=FALSE;
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

      if(!strcmp(argv[i],"--evaluate")){
         int nLength = strlen(argv[i+1]);
         char* inpass = malloc(nLength);
         for(int j = 0; j < nLength;j++)inpass[j]=argv[i+1][j];
         
         // if(out == 2){
         //    printf("Password is unsecure, a shorter password is likely more crackable.\n");
         //    if(!(i+2 < argc))break; 
         //    i+=2;
         //    free(inpass);
         //    continue;
         // }
         
         // if(out == 1){
         //    printf("Password is a very common one, this password is in the scope of hackers.\n");
         //    if(!(i+2 < argc))break; 
         //    i+=2;
         //    free(inpass);
         //    continue;
         // }

         int values[4] = {0,0,0,0};
         double evaluation = evaluate_password(nLength, inpass, values);

         printf("+----------------------------+------------------------+\n");
         printf("| Special Characters         |    %.4i                |\n",values[0]);
         printf("| Digits (0-9)               |    %.4i                |\n",values[3]);
         printf("| Lowercases Letters         |    %.4i                |\n",values[1]);
         printf("| Uppercases Letters         |    %.4i                |\n",values[2]);
         printf("+----------------------------+------------------------+\n");
         printf("| Length (≥ 10)              |    %.4i                |\n",nLength);
         printf("+----------------------------+------------------------+\n");

         printf("Final Evaluation: %.2f\n\n",evaluation);

         if(evaluation >= 1){
            printf("\r<<<...\n");
         }
         for(int i = 0; i < 63 && evaluation < 1; i++){
            int flooredIndex = (int)(evaluation*63);

            if(63-flooredIndex == i)putchar('+');
            else putchar(' ');
         }


         putchar('\n');

         printf("\033[42m<+----------------\033[43m-----------+-----------\033[41m--------------------+>\033[0m\n");
         printf("\033[32m\033[1mPowerful                  \033[33mMedium                              \033[31mWeak\033[0m\n");
         

         printf("Final rating: ");

         if(evaluation >= 1){
            printf("\033[1m\033[32mVery powerful.\n\033[0m");
         }
         if(evaluation < 1 && evaluation > 0.74){
            printf("\033[32mPowerful.\033[0m\n");
         }
         if(evaluation < 0.74 && evaluation > 0.37){
            printf("\033[1m\033[33mMedium Safety.\033[0m\n");
         }
         if(evaluation < 0.37 && evaluation > 0.2){
            printf("\033[31mWeak.\033[0m\n");
         }
         if(evaluation < 0.2){
            printf("\033[31m\033[1mDangerously Weak.\033[0m\n");
         }

         free(inpass); 

         if(!(i+2 < argc))break; 
         i+=2;
      }

      if(!strcmp(argv[i],"--hex")){
         encodeHexMod=TRUE;
         encodeBase64=FALSE;
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
     
      if(!strcmp(argv[i],"--count-combinations")){
         countPossibilites=TRUE;
      }
   }

   if(encodeBase64){
      char* out_base64 = base64_pass(passlen);
      printf("%s\n",out_base64);
      free(out_base64);
      
      if(countPossibilites){
         unsigned long p = pow2(passlen,(int)strlen(BASE64_TOKEN));
         printf("There are %ld possibilites.\n",p);
      }

      return 0;
   }

   if(encodeHexMod){
      char* out_base64 = hex_pass(passlen);
      printf("%s\n",out_base64);
      free(out_base64);
      
      if(countPossibilites){
         unsigned long p = pow2(passlen,(int)strlen(HEXADEC_TOKEN));
         printf("There are %lu possibilites.\n",p);
      }

      return 0;
   }
   return 0;
}
