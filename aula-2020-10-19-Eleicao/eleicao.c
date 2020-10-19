#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define _MAX_CANDIDATOS_ 30
#define _MAX_ALUNOS_     500

#define _TAM_NOME_	 30
#define _TAM_EMAIL_	 50
#define _TAM_CHAPA_	 20
#define _TAM_CPF_	 20

typedef enum { falso, verdadeiro } logico;

typedef enum { 
    desconhecido=0, 
    preparacao=1, 
    emvotacao=2, 
    encerrada=3
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

//---------------------
void lerString(char msg[],char variavel[], int limite)
{
   int tam;
   printf("%s", msg);
   fgets(variavel,limite,stdin);
   tam = strlen(variavel);
   if (variavel[tam-1]=='\n')
      variavel[tam-1]='\0';
}  

//--------------------- implementacao Aluno -----------------

void lerAluno(TAluno *a)
{
   lerString("Entre com o nome:", (*a).nome, _TAM_NOME_);
   lerString("Entre com o CPF:", (*a).cpf, _TAM_CPF_);
   lerString("Entre com o email:", (*a).email, _TAM_EMAIL_);
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
}


int menu()
{
    int opc;
    printf("1-inserir aluno\n");
    printf("2-listar alunos\n");
    printf("3-inserir candidato\n");
    printf("4-listar candidatos\n");
    printf("5-sair\n");
    printf("entre com a sua opcao:");
    scanf("%i", &opc);
    fflush(stdin);
    return opc;
}

int main(void)
{
   TEleicao e;
   TAluno aluno;
   TCandidato candidato;
   logico acabou=falso;

   inicializarEleicao(&e);
   while (!acabou)
   {
      switch(menu())
      {
         case 1: 
            lerAluno(&aluno);
            inserirAluno(&e.eleitores, aluno);
            break;     
         case 2: 
            listarAlunos(e.eleitores);
            break;     
         case 3: 
            lerCandidato(&candidato);
            inserirCandidato(&e.candidatos, candidato);
            break;           
	 case 4: 
            listarCandidatos(e.candidatos);
            break;     
         case 5:
            acabou = verdadeiro;
            break;
      }
   }
   return 0;
}

