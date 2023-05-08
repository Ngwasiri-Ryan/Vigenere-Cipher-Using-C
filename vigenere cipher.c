#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//encryption function
void encrypt(){
    unsigned int i, j;
    char plain[200];
    char key[80];
    printf("\nEnter the plain text: ");
   scanf("%s",plain);
    printf("\nEnter the key: ");
   scanf("%s",key);

    for(i=0,j=0 ; i < strlen(plain); i++,j++){
        if(j >= strlen(key)){
            j = 0;
        }
        printf("%c" ,65 +( ((toupper(plain[i])-65) +(toupper(key[j])-65)) % 26  ));
    }
    printf("\n");
}

//decryption function
void decrypt(){
     unsigned int i, j;
     char plain[200];
     char key[15];
     int value;
     printf("\nEnter the cipher text: ");
     scanf("%s",plain);
     printf("\nEnter the key: ");
     scanf("%s",key);


     for(i = 0,j = 0 ; i < strlen(plain) ; i++,j++){
        if(j >= strlen(key) ){
            j = 0;
        }
        value = (toupper(plain[i])-64) - (toupper(key[j])-64);
        if(value < 0){
            value = value + 26 ;
        }
        printf("%c" , 65 + (value % 26));
     }
}

int main()
{
   int option;
   while(1){
    printf("\n 1. Encipher!");
    printf("\n 2. Decipher!");
    printf("\n 3.Exit \n");
    printf("\nEnter your option: ");
    scanf("%d", &option);

    if(option == 3)
        exit(0);
    else if (option == 1)
      encrypt();
    else if (option == 2)
     decrypt();
    else
    printf("\nInvalid selection! Try again!! ");
   }
   return 0;
   }
