#include<locale.h>
#include<stdio.h>

#include"tipos.h"
#include"alunos.h"
#include"candidatos.h"
#include"eleicao.h"
#include"arqtxt.h"

int menu(TEstado estado)
{
   int opc,maxOpc;
   do {
      limparTela();
      switch(estado)
      {
         case preparacao:
            printf("1-inserir aluno\n");           //11
            printf("2-listar alunos\n");           //12
            printf("3-inserir candidato\n");       //13
            printf("4-listar candidatos\n");       //14
            printf("5-iniciar votacao\n");         //15
            printf("6-ler dados\n");               //16
            printf("7-gravar dados\n");            //17
            printf("0-sair\n");                    //0
            maxOpc = 7;
            break;
         case emvotacao:
            printf("1-realizar voto\n");           //21
            printf("2-encerrar votacao\n");        //22
            printf("0-sair\n");                    //0
            maxOpc = 2;
            break;
         case encerrada:
            printf("1-listar resultado\n");        //31
            printf("2-iniciar novo processo\n");   //32
            printf("0-sair\n");                    //0
            maxOpc = 2;
            break;
         default:
            printf("1-iniciar novo processo\n");  //1
            printf("0-sair\n");                   //0
            maxOpc = 1;
            break;
      }
      printf("entre com a sua opcao:");
      scanf("%i", &opc);
   }while (opc<0 || opc>maxOpc);
   fflush(stdin);
   if (opc>0)
      opc = estado*10+opc;
   return opc;
}

int main(void)
{
   TEleicao e;
   TAluno aluno;
   TCandidato candidato;
   logico acabou=falso;

   setlocale( LC_ALL, "" );

   inicializarEleicao(&e);
   while (!acabou)
   {
      switch(menu(e.estado))
      {
         case 11: 
            limparTela();
            lerAluno(&aluno);
            inserirAluno(&e.eleitores, aluno);
            printf("Inserido com sucesso!\n");
            pausar();
            break;     
         case 12: 
            limparTela();
            listarAlunos(e.eleitores);
            pausar();
            break;     
         case 13: 
            limparTela();
            lerCandidato(&candidato);
            inserirCandidato(&e.candidatos, candidato);
            printf("Inserido com sucesso!\n");
            pausar();
            break;           
	      case 14: 
            limparTela();
            listarCandidatos(e.candidatos);
            pausar();
            break;     
	      case 15: 
            limparTela();
            e.estado = emvotacao;
            printf("Zeresima\n");
            listarResultado(e);
            pausar();
            break;     
         case 16: 
            lerAlunos("alunos.txt", &e.eleitores);
            lerCandidatos("candidatos.txt", &e.candidatos);
            printf("Arquivos lidos com sucesso!");
            pausar();
            break;    
         case 17: 
            gravarAlunos("alunos.txt", e.eleitores);
            gravarCandidatos("candidatos.txt", e.candidatos);
            printf("Arquivos gravados com sucesso!");
            pausar();
            break;    
	      case 21:   //realizar voto
            limparTela();
            if (realizarVoto(&e))
            {
               limparTela();
               printf("Voto computado com sucesso!");
            }
            pausar();
            break;     
	      case 22:   //encerrar votacao
            limparTela();
            e.estado = encerrada;
            printf("Votação encerrada!\n");
            pausar();
            break;     
	      case 31:    //listar resultado
            limparTela();
            listarResultado(e);
            pausar();
            break;     
         case 1:  case 32:                //iniciar novo processo
            limparTela();
            inicializarEleicao(&e);
            printf("Eleicao iniciada com sucesso!\n");
            pausar();
            break;
         case 0:
            acabou = verdadeiro;
            break;
      }
   }
   return 0;
}