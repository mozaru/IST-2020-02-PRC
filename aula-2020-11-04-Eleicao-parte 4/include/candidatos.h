#ifndef _CANDIDATOS_H_
#define _CANDIDATOS_H_

#define _MAX_CANDIDATOS_ 30

#define _TAM_NOME_	 30
#define _TAM_CHAPA_	 20

typedef struct
{
   int numero;
   char nome[_TAM_NOME_];
   char chapa[_TAM_CHAPA_];
   int votos;
} TCandidato;

typedef struct
{
  TCandidato v[_MAX_CANDIDATOS_];
  int    qtd; 
} TCandidatos;

int obterIndiceCandidato(TCandidatos l, int numero);
void listarCandidatos(TCandidatos l);
void inserirCandidato(TCandidatos *l, TCandidato c);
void mostrarCandidato(TCandidato c);
void lerCandidato(TCandidato *c);
void removerCandidato(TCandidatos *l, int numero);
void alterarCandidato(TCandidatos *l, int numero, TCandidato c);

#endif
