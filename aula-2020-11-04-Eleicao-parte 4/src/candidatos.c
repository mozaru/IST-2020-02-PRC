#include "candidatos.h"

#include<stdio.h>
#include "tipos.h"
#include "uteis.h"


void lerCandidato(TCandidato *c)
{
   lerString("Entre com o nome:", (*c).nome, _TAM_NOME_);
   printf("Entre com o Numero:");
   scanf("%i",&(*c).numero);
   fflush(stdin);
   lerString("Entre com o Chapa:", (*c).chapa, _TAM_CHAPA_);
   (*c).votos = 0 ;
}

void mostrarCandidato(TCandidato c)
{
   printf("Nome:%s\n", c.nome);
   printf("Numero:%i\n", c.numero);
   printf("Chapa:%s\n", c.chapa);
}

void inserirCandidato(TCandidatos *l, TCandidato c)
{
   (*l).v[(*l).qtd] = c;
   (*l).qtd++;
} 

void listarCandidatos(TCandidatos l)
{
   int i;
   printf("  #   %4s %-30s %-20s %5s\n", "Num.", "Nome", "Chapa", "Votos");
   for(i=0;i<68;i++)
      printf("-");
   printf("\n");
   for(i=0;i<l.qtd;i++)
      printf("%3i - %4i %-30s %-20s %5i\n", i+1, l.v[i].numero, l.v[i].nome, l.v[i].chapa, l.v[i].votos);
   for(i=0;i<68;i++)
      printf("-");
   printf("\n");
}

int obterIndiceCandidato(TCandidatos l, int numero)
{
   int i=0;
   logico achou = falso;
   while (!achou && i<l.qtd)
      if (l.v[i].numero == numero)
         achou = verdadeiro;
      else
         i++;
   return achou?i:-1;
}

void removerCandidato(TCandidatos *l, int numero)
{
   int i;
   int pos  = obterIndiceCandidato(*l, numero);
   if (pos>=0)
   {
      for(i=pos;i<(*l).qtd-1; i++)
         (*l).v[i] = (*l).v[i+1];
      (*l).qtd--;
   }
}

void alterarCandidato(TCandidatos *l, int numero, TCandidato c)
{
   int i;
   int pos  = obterIndiceCandidato(*l, numero);
   if (pos>=0)
      (*l).v[pos] = c;
}

