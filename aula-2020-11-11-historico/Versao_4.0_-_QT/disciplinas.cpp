#include"disciplinas.h"
#include<stdio.h>

float mediaDisciplina(Disciplina d)
{
   return (d.nota1+d.nota2)/2;
}

void inicializar(Historico *h)
{
   (*h).qtd=0;
}

void inserir(Historico *h, Disciplina d)
{
   (*h).vet[(*h).qtd] = d;
   (*h).qtd++;
}

int obterIndice(Historico h, int codigo)
{
   int achou,i;
   achou=0;
   i=0;
   while (!achou && i<h.qtd)
      if (h.vet[i].codigo == codigo)
         achou = 1;
      else
         i++;
   return achou?i:-1;
}

int existe(Historico h, int codigo)
{
   return obterIndice(h, codigo)!=-1;
}

Disciplina* obter(Historico *h, int codigo)
{
    int pos = obterIndice(*h, codigo);
    if (pos!=-1)
    {
        return &(h->vet[pos]);
    }
    else {
        return NULL;
    }
}

void remover(Historico *h, int codigo)
{
   int pos = obterIndice(*h, codigo);
   if (pos!=-1)
   {
       (*h).vet[pos] = (*h).vet[(*h).qtd-1];
       (*h).qtd--;
   }
}

void alterar(Historico *h, int codigo, Disciplina d)
{
   int pos = obterIndice(*h, codigo);
   if (pos!=-1)
       (*h).vet[pos] = d;
}

float CR(Historico h)
{
   float soma;
   int creditos,i;
   creditos=0;
   soma=0;
   for (i=0;i<h.qtd; i++)
   {
      Disciplina d = h.vet[i];
      creditos += d.creditos;
      soma += mediaDisciplina(d);
   }
   return creditos==0?0:soma/creditos;
}

