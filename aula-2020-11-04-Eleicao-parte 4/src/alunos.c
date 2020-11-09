#include"alunos.h"

#include<stdio.h>

#include"uteis.h"
#include"tipos.h"

void lerAluno(TAluno *a)
{
   lerString("Entre com o nome:", (*a).nome, _TAM_NOME_);
   lerString("Entre com o CPF:", (*a).cpf, _TAM_CPF_);
   lerString("Entre com o email:", (*a).email, _TAM_EMAIL_);
   /*ou
   lerString("Entre com o nome:", a->nome, _TAM_NOME_);
   lerString("Entre com o CPF:", a->cpf, _TAM_CPF_);
   lerString("Entre com o email:", a->email, _TAM_EMAIL_);
   */
}

void mostrarAluno(TAluno a)
{
   printf("Nome:%s\n", a.nome);
   printf("CPF:%s\n", a.cpf);
   printf("E-Mail:%s\n", a.email);
}

void inserirAluno(TAlunos *l, TAluno a)
{
   (*l).v[(*l).qtd] = a;
   (*l).qtd++;
} 

int obterIndiceAluno(TAlunos l, char cpf[])
{
   int i=0;
   logico achou = falso;
   while (!achou && i<l.qtd)
      if (strcmp(l.v[i].cpf,cpf)==0)
         achou = verdadeiro;
      else
         i++;
   return achou?i:-1;
}

void listarAlunos(TAlunos l)
{
   int i;
   printf("  #   %-30s %-50s %20s\n","nome", "e-mail", "CPF");
   for(i=0;i<108;i++)
      printf("-");
   printf("\n");
   for(i=0;i<l.qtd;i++)
      printf("%3i - %-30s %-50s %20s\n", i+1, l.v[i].nome, l.v[i].email, l.v[i].cpf);
   for(i=0;i<108;i++)
      printf("-");
   printf("\n");
}

void removerAluno(TAlunos *l, char cpf[])
{
   int pos = obterIndiceAluno(*l, cpf);
   if (pos>-1) 
   {
      (*l).v[pos] = (*l).v[ (*l).qtd-1 ];
      (*l).qtd--;
   }
}

void alterarAluno(TAlunos *l, char cpf[], TAluno a)
{
   int pos = obterIndiceAluno(*l, cpf);
   if (pos>-1) 
      (*l).v[pos] = a;
}