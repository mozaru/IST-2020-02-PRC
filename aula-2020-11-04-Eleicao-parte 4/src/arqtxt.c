
#include "arqtxt.h"
#include "alunos.h"
#include"candidatos.h"

#include<stdio.h>
#include<string.h>

char *lerAte(FILE *arq, char sep, char strDestino[], int max)
{
    int i=0;
    int letra;
    while ( (letra = fgetc(arq)) > 0 && letra!=sep && i<max-1)
    {
        strDestino[i] = letra;
        i++;
    }
    strDestino[i] = '\0'; //terminador da string
    return strDestino;
}


void lerAlunos(char nomeArq[], TAlunos *l)
{
    FILE *arq;
    arq = fopen(nomeArq, "rt"); //modo r-readonly e t textfile
    if (arq!=NULL) //verifica se conseguiu abrir o arquivo
    {
        (*l).qtd=0;
        TAluno a;
        char letra;
        while ( !feof(arq) )
        {
            lerAte(arq, ',',a.nome, _TAM_NOME_);
            lerAte(arq, ',',a.cpf, _TAM_CPF_);
            lerAte(arq, ',', a.email, _TAM_EMAIL_);
            fscanf(arq,"%c\n", &letra);
            a.votou = letra == 'S';
            inserirAluno(&*l, a);
        }
        fclose(arq);
    }
} 

void lerCandidatos(char nomeArq[], TCandidatos *l)
{
    FILE *arq;
    arq = fopen(nomeArq, "rt"); //modo r-readonly e t textfile
    if (arq!=NULL) //verifica se conseguiu abrir o arquivo
    {
        (*l).qtd=0;
        TCandidato c;
        while ( !feof(arq) )
        {
            fscanf(arq,"%d,", &c.numero);
            lerAte(arq, ',',c.nome, _TAM_NOME_);
            lerAte(arq, ',',c.chapa, _TAM_CHAPA_);
            fscanf(arq,"%d\n", &c.votos);
            inserirCandidato(&*l, c);
        }
        fclose(arq);
    }
}

void gravarAlunos(char nomeArq[], TAlunos l)
{
    FILE *arq;
    arq = fopen(nomeArq, "wt"); //modo w-writefile mas apaga se ja existir e t textfile
    if (arq!=NULL) //verifica se conseguiu criar o arquivo
    {
        int i;
        for(i=0;i<l.qtd;i++)
        {
            TAluno a = l.v[i];
            fprintf(arq, "%s,%s,%s,%c\n", a.nome, a.cpf, a.email, a.votou?'S':'N');
        }
        fclose(arq);
    }
}

void gravarCandidatos(char nomeArq[], TCandidatos l)
{
    FILE *arq;
    arq = fopen(nomeArq, "wt"); //modo w-writefile mas apaga se ja existir e t textfile
    if (arq!=NULL) //verifica se conseguiu criar o arquivo
    {
        int i;
        for(i=0;i<l.qtd;i++)
        {
            TCandidato c = l.v[i];
            fprintf(arq, "%i,%s,%s,%i\n", c.numero, c.nome, c.chapa, c.votos);
        }
        fclose(arq);
    }
}