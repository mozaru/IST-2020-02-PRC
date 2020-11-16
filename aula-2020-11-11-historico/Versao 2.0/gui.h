#ifndef _GUI_H_
#define _GUI_H_

#include "disciplinas.h"

void inicializarInterface(int argc, char*argv[]);
void finalizarInterface();
void mostrarMensagem(char msg[]);
int lerCodigo();
int menu();
void mostrarDisciplina(Disciplina d);
int lerDisciplina(Disciplina *d);
void mostrarHistorico(Historico h);

#endif