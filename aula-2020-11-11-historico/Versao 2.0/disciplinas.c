#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"disciplinas.h"


void lerString(char str[], int max)
{
   int tam;
   fflush(stdin);
   fgets(str, max, stdin);
   tam = strlen(str);
   if (str[tam-1]=='\n')
      str[tam-1]='\0';
}

float mediaDisciplina(Disciplina d)
{
   return (d.nota1+d.nota2)/2;
}

void lerDisciplina(Disciplina *d)  
{
   printf("Codigo:");		scanf("%d",& (*d).codigo);
   printf("Nome:");		lerString((*d).nome, _NOME_MAX_LEN_);
   printf("Professor:");	lerString((*d).professor, _NOME_MAX_LEN_);
   printf("Creditos:");		scanf("%d",& (*d).creditos);
   printf("Semestre:");		scanf("%d",& (*d).semestre);
   printf("Ano:");		scanf("%d",& (*d).ano);
   printf("Nota1:");		scanf("%f",& (*d).nota1);
   printf("Nota2:");		scanf("%f",& (*d).nota2);
}

void mostrarDisciplina(Disciplina d)
{
   printf("Codigo:%d\n",d.codigo);
   printf("Nome:%s\n",d.nome);
   printf("Professor:%s\n",d.professor);
   printf("Creditos:%d\n",d.creditos);
   printf("Semestre:%d\n",d.semestre);
   printf("Ano:%d\n",d.ano);
   printf("Nota1:%5.2f\n",d.nota1);
   printf("Nota2:%5.2f\n",d.nota2);
   printf("Media:%5.2f\n",mediaDisciplina(d));
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

void listar(Historico h)
{
   int i;
   printf("%-30s %5s %4s %4s %5s\n",
	     "Nome", "cred.", "sem.", "ano","media");
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   for (i=0; i<h.qtd; i++)
   {
      Disciplina d = h.vet[i];
      printf("%-30s   %02i    %i  %04i %5.2f\n", 
	     d.nome, d.creditos, d.semestre, d.ano, mediaDisciplina(d));
   }
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
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

void mostrar(Historico h)
{
   listar(h);
   printf("Coeficiente de Rendimento (CR)=%.2f\n", CR(h));
}
