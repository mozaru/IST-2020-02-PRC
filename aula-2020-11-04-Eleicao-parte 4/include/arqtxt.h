#ifndef _ARQTXT_H_
#define _ARQTXT_H_

#include"alunos.h"
#include"candidatos.h"

void lerAlunos(char nomeArq[], TAlunos *l);
void lerCandidatos(char nomeArq[], TCandidatos *l);
void gravarAlunos(char nomeArq[], TAlunos l);
void gravarCandidatos(char nomeArq[], TCandidatos l);

#endif

