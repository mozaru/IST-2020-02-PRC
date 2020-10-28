#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

#define _MAX_CANDIDATOS_ 30
#define _MAX_ALUNOS_     500

#define _TAM_NOME_	 30
#define _TAM_EMAIL_	 50
#define _TAM_CHAPA_	 20
#define _TAM_CPF_	    20

typedef enum { falso, verdadeiro } logico;

typedef enum { 
    desconhecido, 
    preparacao, 
    emvotacao, 
    encerrada
} TEstado;

typedef struct
{
   char nome[_TAM_NOME_];
   char cpf[_TAM_CPF_];
   char email[_TAM_EMAIL_];
   logico votou;
} TAluno;

typedef struct
{
   int numero;
   char nome[_TAM_NOME_];
   char chapa[_TAM_CHAPA_];
   int votos;
} TCandidato;

typedef struct
{
  TAluno v[_MAX_ALUNOS_];
  int    qtd; 
} TAlunos;

typedef struct
{
  TCandidato v[_MAX_CANDIDATOS_];
  int    qtd; 
} TCandidatos;

typedef struct
{
  char nome[_TAM_NOME_];
  TEstado estado; //(1-preparacao, 2-emvotacao, 3-encerrada)
  TAlunos eleitores;
  TCandidatos candidatos;
} TEleicao;

//---------------------  funcoes auxiliares
void lerString(char msg[],char variavel[], int limite)
{
   int tam;
   printf("%s", msg);
   fgets(variavel,limite,stdin);
   tam = strlen(variavel);
   if (variavel[tam-1]=='\n')
      variavel[tam-1]='\0';
}  

void limparTela()
{
   system("cls");
   printf("===================================================================================================\n");
   printf("! ISSO É TÃÓ BÃÔ!                E L E I C O E S    2 0 2 0                     FAETERJ/Petropolis!\n");
   printf("===================================================================================================\n");
   printf("\n\n");
}

void pausar()
{
   printf("\n\n");
   system("pause");
}

//--------------------- implementacao Aluno -----------------

void lerAluno(TAluno *a)
{
   lerString("Entre com o nome:", (*a).nome, _TAM_NOME_);
   lerString("Entre com o CPF:", (*a).cpf, _TAM_CPF_);
   lerString("Entre com o email:", (*a).email, _TAM_EMAIL_);
   /*ou
   lerString("Entre com o nome:", a->nome, _TAM_NOME_);
   lerString("Entre com o CPF:", a->cpf, _TAM_CPF_);
   lerString("Entre com o email:", a->email, _TAM_EMAIL_);
   */
}


//--------------------- implementacao Candidato -------------

void lerCandidato(TCandidato *c)
{
   lerString("Entre com o nome:", (*c).nome, _TAM_NOME_);
   printf("Entre com o Numero:");
   scanf("%i",&(*c).numero);
   fflush(stdin);
   lerString("Entre com o Chapa:", (*c).chapa, _TAM_CHAPA_);
   (*c).votos = 0 ;
}

//--------------------- implementacao Alunos -------------
void inserirAluno(TAlunos *l, TAluno a)
{
   (*l).v[(*l).qtd] = a;
   (*l).qtd++;
} 

void listarAlunos(TAlunos l)
{
   int i;
   for(i=0;i<l.qtd;i++)
      printf("%s - %s - %s\n", l.v[i].nome, l.v[i].email, l.v[i].cpf);
   system("pause");
}

//--------------------- implementacao Candidatos -------------
void inserirCandidato(TCandidatos *l, TCandidato c)
{
   (*l).v[(*l).qtd] = c;
   (*l).qtd++;
} 

void listarCandidatos(TCandidatos l)
{
   int i;
   for(i=0;i<l.qtd;i++)
      printf("%i - %s - %s - %i\n", l.v[i].numero, l.v[i].nome, l.v[i].chapa, l.v[i].votos);
   system("pause");
}



//--------------------- implementacao eleicao -------------
void inicializarEleicao(TEleicao *e)
{
   (*e).eleitores.qtd = 0;
   (*e).candidatos.qtd = 0;
   (*e).estado = preparacao;
   /*ou
   e->eleitores.qtd = 0;
   e->candidatos.qtd = 0;
   e->estado = preparacao;
   */
}


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
            printf("0-sair\n");                    //0
            maxOpc = 5;
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

void realizarVoto(TEleicao *e)
{
}

void listarResultado(TEleicao e)
{
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
	      case 21:   //realizar voto
            limparTela();
            realizarVoto(&e);
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

