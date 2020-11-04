#include "eleicao.h"

#include<stdio.h>
#include<stdlib.h>

#include "uteis.h"
#include "alunos.h"
#include "candidatos.h"

void inicializarEleicao(TEleicao *e)
{
   (*e).eleitores.qtd = 0;
   (*e).candidatos.qtd = 0;
   (*e).estado = preparacao;
   /*ou
   e->eleitores.qtd = 0;
   e->candidatos.qtd = 0;
   e->estado = preparacao;
   */
}

void computarVoto(TEleicao *e, char cpf[], int numero)
{
   int posEleitor = obterIndiceAluno((*e).eleitores, cpf);
   int posCandidato = obterIndiceCandidato((*e).candidatos, numero);
   if (posEleitor>=0 && posEleitor<(*e).eleitores.qtd && !(*e).eleitores.v[posEleitor].votou)
   {
      (*e).eleitores.v[posEleitor].votou = verdadeiro;   
      if (posCandidato>=0 && posCandidato < (*e).candidatos.qtd)
         (*e).candidatos.v[posCandidato].votos++;
   }
}

logico realizarVoto(TEleicao *e)
{
   char cpf[_TAM_CPF_];
   int pos;
   lerString("CPF:", cpf,_TAM_CPF_);
   pos = obterIndiceAluno((*e).eleitores, cpf);
   if (pos < 0) {
      printf("Eleitor com o cpf:%s nao encontrado!\n",cpf);
      return falso;
   } else if ((*e).eleitores.v[pos].votou) {
      printf("Eleitor com o cpf:%s ja votou!\n",cpf);
      return falso;
   } else {
      TAluno a = (*e).eleitores.v[pos];
      TCandidato c;
      char letra;
      int numero;
      do {
         limparTela();  
         mostrarAluno(a);
         printf("\nEntre com o numero do candidato:");
         scanf("%i",&numero);
         do {
            limparTela();
            if (numero==0)
               printf("Voto em Branco!\n");
            else {
               pos = obterIndiceCandidato((*e).candidatos, numero);
               if (pos < 0)
                  printf("Voto nulo!\n");
               else {
                  c = (*e).candidatos.v[pos];
                  mostrarCandidato(c);
               }
            }
            printf("\n\nConfirma (S/N)?\n");
            scanf("%c",&letra);
         } while (letra!='S' && letra!='s' && letra!='N' && letra!='n');
      } while (letra!='S' && letra!='s');
      computarVoto(&(*e), cpf, numero);
      return verdadeiro;
   }
} 

int compVotos(const void *pa, const void *pb)
{
   TCandidato a = *(TCandidato*)pa;
   TCandidato b = *(TCandidato*)pb;
   if (a.votos>b.votos)       return -1;
   else if (a.votos<b.votos)  return  1;
   else                       return  0;
}

void listarResultado(TEleicao e)
{
   qsort(e.candidatos.v, e.candidatos.qtd, sizeof(TCandidato), compVotos);
   listarCandidatos(e.candidatos);
}



