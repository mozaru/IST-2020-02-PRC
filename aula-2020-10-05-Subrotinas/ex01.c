#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mensagem(char nome[])
{
   printf("oi, %s\n", nome);
}

int main(void)
{
    char nome[100];
    mensagem("Desconhecido");
    printf("entre com seu nome:");
    gets(nome);
    mensagem(nome);
    return 0;
}
