#include "uteis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerString(char msg[],char variavel[], int limite)
{
   int tam;
   printf("%s", msg);
   fgets(variavel,limite,stdin);
   tam = strlen(variavel);
   if (variavel[tam-1]=='\n')
      variavel[tam-1]='\0';
}  

void limparTela()
{
   system("cls");
   printf("===================================================================================================\n");
   printf("!                                E L E I C O E S    2 0 2 0                     FAETERJ/Petropolis!\n");
   printf("===================================================================================================\n");
   printf("\n\n");
}

void pausar()
{
   printf("\n\n");
   system("pause");
}