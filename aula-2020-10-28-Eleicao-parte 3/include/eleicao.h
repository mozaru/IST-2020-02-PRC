#ifndef _ELEICAO_H_
#define _ELEICAO_H_

#include "tipos.h"
#include "alunos.h"
#include "candidatos.h"

#define _TAM_NOME_	 30

typedef enum { 
    desconhecido, 
    preparacao, 
    emvotacao, 
    encerrada
} TEstado;

typedef struct
{
  char nome[_TAM_NOME_];
  TEstado estado; //(1-preparacao, 2-emvotacao, 3-encerrada)
  TAlunos eleitores;
  TCandidatos candidatos;
} TEleicao;

void inicializarEleicao(TEleicao *e);
logico realizarVoto(TEleicao *e);
void computarVoto(TEleicao *e, char cpf[], int numero);
void listarResultado(TEleicao e);

#endif
