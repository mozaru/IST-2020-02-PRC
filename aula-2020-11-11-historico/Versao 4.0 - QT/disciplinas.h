#ifndef _DISCIPLINAS_H_
#define _DISCIPLINAS_H_

#define _NOME_MAX_LEN_    30
#define _DISCIPLINAS_MAX_ 100


typedef struct {
  int codigo;
  char nome[_NOME_MAX_LEN_];
  int creditos;
  int semestre;
  int ano;
  float nota1, nota2;
  char professor[_NOME_MAX_LEN_];
} Disciplina;

typedef struct {
  Disciplina vet[_DISCIPLINAS_MAX_];
  int qtd;
} Historico;

float mediaDisciplina(Disciplina d);
void inicializar(Historico *h);
void inserir(Historico *h, Disciplina d);
int existe(Historico h, int codigo);
void remover(Historico *h, int codigo);
Disciplina* obter(Historico *h, int codigo);
void alterar(Historico *h, int codigo, Disciplina d);
float CR(Historico h);

#endif
