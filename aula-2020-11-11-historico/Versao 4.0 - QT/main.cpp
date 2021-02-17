#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gui.h"
#include "Disciplinas.h"


int main(int argc, char *argv[])
{
   Historico hist;
   Disciplina disc;
   int cod, fim;
   Disciplina *d;

   inicializarInterface(argc, argv);

   fim = 0;
   inicializar(&hist);
   while (!fim)
   {
      switch (menu())
      {
      case 1: //inserir
         disc.codigo = 0;
         disc.creditos = 0;
         disc.semestre = 0;
         disc.ano = 0;
         disc.nota1 = 0;
         disc.nota2 = 0;
         strcpy(disc.nome, "");
         strcpy(disc.professor, "");
         if (lerDisciplina(&disc))
         {
            inserir(&hist, disc);
            mostrarMensagem("Inserido com sucesso!");
         }
         break;
      case 2: //remover
         cod = lerCodigo();
         if (existe(hist, cod))
         {
            remover(&hist, cod);
            mostrarMensagem("Removido com sucesso!");
         }
         else
            mostrarMensagem("Codigo nao encontrado!");

         break;
      case 3: //alterar
         cod = lerCodigo();
         d = obter(&hist,cod);
         if (cod > 0 && d!=NULL)
         {
            if (lerDisciplina(d))
               alterar(&hist, cod, *d);
         }
         else
            mostrarMensagem("Codigo nao encontrado!");
         break;
      case 4: //historico
         mostrarHistorico(hist);
         break;
      case 5: //fim
         fim = 1;
         break;
      }
   }

   finalizarInterface();
   return 0;
}
