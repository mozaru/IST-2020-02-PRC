Subrotina
   comandos criados pelo usuario (programador)
   ou 
   trechos de codigo rotulados e parametrizáveis.

ex:

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



sintaxe subtortina:

tipo nome(parametros)
{
    codigo
}


subrotinas podem ser procedimento ou funcoes

sintaxe procedimentos
perror("deu erro");

void nome(parametros)
{
   codigo
}

sintaxe funcao
ex: sqrt(9)
tipo nome(parametros)
{
   codigo
   return valor_do_tipo
   codigo 
}

sintaxe dos parametros
tipo nome, tipo nome, tipo nome .....


ex: float somar(float a,float b, float c)
    {
       return a+b+c;
    }

exercicio de exemplo:
    faca um programa que leia um valor e informe o valor do fatorial

#include<stdio.h>

int fat(int x)
{
   int i,resp;
   resp=1;
   for(i=x; i>0; i--)
     resp = resp * i;
   return resp;   
}

int main(void)
{
   printf("entre com um numero:");
   scanf("%d",&n);

   printf(" o fatorial de %d eh %d\n", n, fat(n));
   return 0;

} 

