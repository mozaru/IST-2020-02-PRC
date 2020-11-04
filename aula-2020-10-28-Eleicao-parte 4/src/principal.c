#include<locale.h>
#include<stdio.h>

#include"tipos.h"
#include"alunos.h"
#include"candidatos.h"
#include"eleicao.h"
#include"uteis.h"
#include"arqtxt.h"

#if defined(_WIN32) || defined(_WINDOWS)
#include <conio.h>
#else
#include <termios.h>

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}
#endif


int lerTecla()
{
   return getch();
}

int menuManeiroPakas(char Opcoes[][30], int qtd)
{
   int i,opc=0, opcAnt=-1;
   char tecla;
   do {
      if (opc!=opcAnt)
      {
         limparTela();
         for(i=0;i<qtd;i++)
            printf("%s %s\n", (opc==i)?"-->":"   ", Opcoes[i]);
      }
      tecla = lerTecla();
      opcAnt = opc;
      switch(tecla)
      {
         case 'H': opc--;
                  if (opc<0) opc = qtd-1;
                  break; 
         case 'P': opc++;
                  if (opc>=qtd) opc = 0;
                  break; 
      }
   }while ( tecla != 27 && tecla != 13 && tecla != 32); //27-esc, 13-enter e 32=espaco
   if (tecla==27 || opc == qtd-1)
      return 0;
   else
      return opc+1;   
}

typedef enum { Nenhum, Aluno, Candidato } TGerenciar;


int menu(TEstado estado, TGerenciar *estadoGerenciar)
{
   int opc,maxOpc;
   char itemsAluno[][30] = {"inserir aluno","remover aluno","alterar aluno","listar aluno","voltar"};
   char itemsCandidato[][30] = {"inserir candidato","remover candidato","alterar candidato","listar candidato","voltar"};
   char itemsPreparacao[][30] = {"gerenciar alunos","gerenciar candidato","iniciar votacao","sair"};
   char itemsVotacao[][30] = {"realizar voto","encerrar votacao","sair"};
   char itemsEncerrada[][30] = {"listar resultado","iniciar novo processo","sair"};
   char itemsPadrao[][30] = {"iniciar novo processo","sair"};

   switch(estado)
   {
      case preparacao:
         switch (*estadoGerenciar){
            case Nenhum: 
               switch(menuManeiroPakas(itemsPreparacao, 4))
               {
                  case 0: opc= 0;      
                        break;
                  case 1: *estadoGerenciar = Aluno;   
                        opc = -1;
                        break;
                  case 2: *estadoGerenciar = Candidato;
                        opc = -1;
                        break;
                  case 3: opc = 9;
                        break;
               }
               break;
            case Aluno: 
               opc = menuManeiroPakas(itemsAluno, 5);
               if (opc==0){
                  *estadoGerenciar = Nenhum;
                  opc = 1;
                  estado = 0;
               }
               break;
            case Candidato: 
               opc = menuManeiroPakas(itemsCandidato, 5);
               if (opc==0){
                  *estadoGerenciar = Nenhum;
                  opc = 2;
                  estado = 0;
               } else if (opc>0) 
                  opc = opc+4;
               break;
         }
         break;
         //printf("6-ler dados\n");               //16
         //printf("7-gravar dados\n");            //17
      case emvotacao:
         opc = menuManeiroPakas(itemsVotacao, 3);        break;
      case encerrada:
         opc = menuManeiroPakas(itemsEncerrada, 3);      break;
      default:
         opc = menuManeiroPakas(itemsPadrao, 2);         break;
   }

   fflush(stdin);
   if (opc>0)
      opc = estado*10+(opc);
   return opc;
}

int main(void)
{
   TEleicao e;
   TAluno aluno;
   TCandidato candidato;
   logico acabou=falso;
   TGerenciar estadoGerenciar = Nenhum;
   
   setlocale( LC_ALL, "" );

   inicializarEleicao(&e);
   lerAlunos("alunos.txt", &e.eleitores);
   lerCandidatos("candidatos.txt", &e.candidatos);

   while (!acabou)
   {
      switch(menu(e.estado, &estadoGerenciar))
      {
         case 1:
               gravarAlunos("alunos.txt", e.eleitores);
               break;
         case 2:
               gravarCandidatos("candidatos.txt", e.candidatos);
               break;
         case 11: 
            limparTela();
            lerAluno(&aluno);
            inserirAluno(&e.eleitores, aluno);
            printf("Inserido com sucesso!\n");
            pausar();
            break;     
         case 14: 
            limparTela();
            listarAlunos(e.eleitores);
            pausar();
            break;     
         case 15: 
            limparTela();
            lerCandidato(&candidato);
            inserirCandidato(&e.candidatos, candidato);
            printf("Inserido com sucesso!\n");
            pausar();
            break;           
	      case 18: 
            limparTela();
            listarCandidatos(e.candidatos);
            pausar();
            break;     
	      case 19: 
            limparTela();
            e.estado = emvotacao;
            printf("Zeresima\n");
            listarResultado(e);
            pausar();
            break;     
         /*case 16: 
            
            printf("Arquivos lidos com sucesso!");
            pausar();
            break;    
         case 17: 
            
            printf("Arquivos gravados com sucesso!");
            pausar();
            break;    
         */
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
         case 32:                //iniciar novo processo
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