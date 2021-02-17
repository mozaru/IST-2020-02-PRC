#include <stdio.h>
#include <string.h>

#include "disciplinas.h"

void inicializarInterface(int argc, char*argv[])
{
   
}

void finalizarInterface()
{

}

void pausar()
{
    system("pause");
}

void limparTela()
{
   system("cls");
}

void mostrarMensagem(char msg[])
{
   if (msg!=NULL)
     printf("%s\n",msg);
   system("pause");
}

void lerString(char str[], int max)
{
   int tam;
   fflush(stdin);
   fgets(str, max, stdin);
   tam = strlen(str);
   if (str[tam-1]=='\n')
      str[tam-1]='\0';
}

int lerCodigo()
{
   int cod;
   limparTela();
   printf("Entre com o codigo da disciplina para alterar:");
   scanf("%i", &cod);
   return cod;
}

int menu()
{
  int opc;
  do {
    limparTela();
    printf("1-Inserir\n");
    printf("2-Remover\n");
    printf("3-Alterar\n");
    printf("4-Historico\n");
    printf("5-Sair\n");
    printf("\nEntre com a sua opcao:");
    scanf("%d", &opc); 
  } while (opc<1 || opc>5);
  fflush(stdin);
  limparTela();
  return opc;
}


int lerDisciplina(Disciplina *d)  
{
   limparTela();
   printf("Codigo:");		scanf("%d",& (*d).codigo);
   printf("Nome:");		    lerString((*d).nome, _NOME_MAX_LEN_);
   printf("Professor:");	lerString((*d).professor, _NOME_MAX_LEN_);
   printf("Creditos:");		scanf("%d",& (*d).creditos);
   printf("Semestre:");		scanf("%d",& (*d).semestre);
   printf("Ano:");		    scanf("%d",& (*d).ano);
   printf("Nota1:");		scanf("%f",& (*d).nota1);
   printf("Nota2:");		scanf("%f",& (*d).nota2);
   return 1;
}

void mostrarDisciplina(Disciplina d)
{
   limparTela();
   printf("Codigo:%d\n",d.codigo);
   printf("Nome:%s\n",d.nome);
   printf("Professor:%s\n",d.professor);
   printf("Creditos:%d\n",d.creditos);
   printf("Semestre:%d\n",d.semestre);
   printf("Ano:%d\n",d.ano);
   printf("Nota1:%5.2f\n",d.nota1);
   printf("Nota2:%5.2f\n",d.nota2);
   printf("Media:%5.2f\n",mediaDisciplina(d));
   pausar();
}

void listarHistorico(Historico h)
{
   limparTela();
   int i;
   printf("%-30s %5s %4s %4s %5s\n",
	     "Nome", "cred.", "sem.", "ano","media");
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
   for (i=0; i<h.qtd; i++)
   {
      Disciplina d = h.vet[i];
      printf("%-30s   %02i    %i  %04i %5.2f\n", 
	     d.nome, d.creditos, d.semestre, d.ano, mediaDisciplina(d));
   }
   for(i=0;i<62;i++)
     printf("-");
   printf("\n");
}

void mostrarHistorico(Historico h)
{
   listarHistorico(h);
   printf("Coeficiente de Rendimento (CR)=%.2f\n", CR(h));
   pausar();
}
