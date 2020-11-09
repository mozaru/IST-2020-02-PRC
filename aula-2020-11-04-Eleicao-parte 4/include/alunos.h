#ifndef _ALUNOS_H_
#define _ALUNOS_H_

#include"tipos.h"

#define _MAX_ALUNOS_     500

#define _TAM_NOME_	 30
#define _TAM_EMAIL_	 50
#define _TAM_CPF_    20

typedef struct
{
   char nome[_TAM_NOME_];
   char cpf[_TAM_CPF_];
   char email[_TAM_EMAIL_];
   logico votou;
} TAluno;

typedef struct
{
  TAluno v[_MAX_ALUNOS_];
  int    qtd; 
} TAlunos;

void lerAluno(TAluno *a);
void mostrarAluno(TAluno a);
void listarAlunos(TAlunos l);
int obterIndiceAluno(TAlunos l, char cpf[]);
void inserirAluno(TAlunos *l, TAluno a);
void removerAluno(TAlunos *l, char cpf[]);
void alterarAluno(TAlunos *l, char cpf[], TAluno a);

#endif
