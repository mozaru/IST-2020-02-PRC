#include<stdio.h>
#include<stdlib.h>
#include <iup.h>

#include"Disciplinas.h"

void pausar(char msg[])
{
   if (msg!=NULL)
     printf("%s\n",msg);
   system("pause");
}

int main(int argc, char **argv)
{
   Historico 	hist;
   Disciplina 	disc;
   int        	cod,fim;
   
   IupOpen(&argc, &argv);

   fim = 0;
   inicializar(&hist);
   while(!fim)
   {
     switch(menu())
     {
        case 1: //inserir
    	      if (frmDisciplina(&disc))
	            inserir(&hist, disc);
           break;
        case 2: //remover
           printf("Entre com o codigo da disciplina para remover:");
           scanf("%i", &cod);
           if (existe(hist, cod)) 
           {
              remover(&hist, cod); 
              pausar("Removido com sucesso!"); 
           } else
              pausar("Codigo nao encontrado!");
           break;   
        case 3: //alterar
           printf("Entre com o codigo da disciplina para alterar:");
           scanf("%i", &cod);
           if (existe(hist, cod)) 
           {
              if (frmDisciplina(&disc))
                  alterar(&hist, cod, disc); 
           } else
              pausar("Codigo nao encontrado!");
           break;   
        case 4: //historico
           mostrar(hist);
           pausar(NULL);
           break;
        case 5://fim 
           fim=1;
           break;
     }
   }
   IupClose();    
   return 0;
}