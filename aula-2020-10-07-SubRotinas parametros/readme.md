# Subrotina Parametros

sintaxe
 tipo nome, tipo nome, tipo nome..

ex: 
~~~C
float soma(float a, float b, float c)
    {....}
~~~

passagem por valor x passagem por referencia

Passagem por valor
   o argumento recebe uma copia do parametro passado
   ex do codigo abaixo o argumento x na subrotina incremento
      recebe uma copia do valor de a, por isso
      quando incrementa o valor de x, o valor de a nao é alterado.

ex:
~~~C
#include <stdio.h>

void incremento(int x)
{
   x = x + 1;
}

int main(void)
{
    int a = 10;
    incremento(a);
    printf("a=%d\n",a);
    return 0;
}
~~~

obs: o padrao de C eh passagem por valor, a unica excessão
     são os vetores que são passados por referencia sempre.

os vetores sempre são passados por referencia, por isso
no codigo abaixo a subrotina ler altera os valores vet,
pos o argumento v é uma referencia ao parametro vet.
~~~C
#include <stdio.h>

void lerVet(int v[], int qtd)
{
   int i;
   for(i=0; i<qtd; i++)
   {
       printf("V[%i]=",i);
       scanf("%d", &v[i]);
   }
}

void mostrarVet(int v[], int qtd)
{
   int i;
   for(i=0; i<qtd; i++)
       printf("%i ",v[i]);
   printf("\n");
}

int main(void)
{
    int vet[10];
    lerVet(vet,10);
    mostrarVet(vet,10);
    return 0;
}
~~~

Passagem por referencia
   o argumento é uma referencia ao parametro passado
   ex do codigo abaixo o argumento x na subrotina incremento
      é uma referencia a variavel a, por isso
      quando incrementa o valor de x, o valor de a é alterado.

ex:
~~~C
#include <stdio.h>

void incremento(int *x)
{
   *x = *x + 1;
}

int main(void)
{
    int a = 10;
    incremento(&a);
    printf("a=%d\n",a);
    return 0;
}
~~~

demonstração de exercicio complexo 1:
faça uma agenda de contatos com menu e as seguintes operações
1. inserir
2. remover
3. alterar
4. listar todos
5. listar filtrando por parte do nome ou telefone
6. sair

na agenda cada contato tem nome e telefone somente.

1. pensar nas entidades que estão sendo manipuladas
   agenda e contado
2. para cada entidade definir o dominio (criar um tipo de dados para representa-lo)
   contado
       nome    : string[30]
       telefone: string[15]      (xx)12345-1234

   agenda
       v : vetor [100] de contato    
      qtd: inteiro 

3. para cada entidade definir as operações necessarias
   contato
       ler : void
        
   agenda
       inicializar: void
       inserir : void  
       remover : void
       alterar : void
       listar  : void
       filtrar : void
       obterIndice: inteiro

4. para cada entidade criar uma strutura e 
   para cada operação criar uma subrotina onde o primeiro
   parametro é a estrutura

5. fazer o programa principal

~~~C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX_STRING_ 30
#define _MAX_NOME_ 30
#define _MAX_TELEFONE_ 20

typedef struct
{
   char nome[_MAX_NOME_];
   char telefone[_MAX_TELEFONE_];
} TContato;

typedef struct
{
   TContato v[100];
   int qtd;
} TAgenda;

void limparTela()
{
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
}

void pause()
{
#ifdef _WIN32
    system("pause");
#else
    //system("read -n1 -r -p \"Press any key to continue...\" key");
    printf("Press any key to continue...\n");
    getchar();
#endif    
}

void lerString(char str[], int max)
{
   fgets(str, max, stdin);
   str[strlen(str) - 1] = '\0';
}

void lerContato(TContato *c)
{
   printf("Entre com o nome:");
   lerString((*c).nome, _MAX_NOME_);
   printf("Entre com o telefone:");
   lerString((*c).telefone, _MAX_TELEFONE_);
}

void inicializar(TAgenda *a)
{
   a->qtd = 0; //(*a).qtd=0;
}

int obterIndice(TAgenda a, char info[])
{
   int achou, i;
   achou = 0; //falso
   i = 0;
   while (!achou && i < a.qtd)
      if (strcmp(a.v[i].nome, info) == 0 || strcmp(a.v[i].telefone, info) == 0)
         achou = 1; //verdadeiro;
      else
         i++;

   return achou ? i : -1;
}

void inserir(TAgenda *a, TContato c)
{
   (*a).v[(*a).qtd] = c;
   (*a).qtd++;
}

int remover(TAgenda *a, char info[])
{
   int pos = obterIndice(*a, info);
   if (pos > -1)
   {
      (*a).v[pos] = (*a).v[(*a).qtd - 1];
      (*a).qtd--;
      return 1;
   }
   else
      return 0;
}

int alterar(TAgenda *a, char info[], TContato c)
{
   int pos = obterIndice(*a, info);
   if (pos > -1)
   {
      (*a).v[pos] = c;
      return 1;
   }
   else
      return 0;
}

void listar(TAgenda a)
{
   int i;
   printf("%3s %-40s%30s\n", " # ", "Nome", "Telefone");
   printf("%3s %-40s%30s\n", "---", "----------------------------------------", "------------------------------");
   for (i = 0; i < a.qtd; i++)
      printf("%3i %-40s%30s\n", i + 1, a.v[i].nome, a.v[i].telefone);
   printf("%3s %-40s%30s\n", "---", "----------------------------------------", "------------------------------");
}

void filtrar(TAgenda a, char info[])
{
   int i, j;
   printf("%3s %-40s%30s\n", " # ", "Nome", "Telefone");
   printf("%3s %-40s%30s\n", "---", "----------------------------------------", "------------------------------");
   for (i = 0, j = 0; i < a.qtd; i++)
      if (strstr(a.v[i].nome, info) != NULL || strstr(a.v[i].telefone, info) != NULL)
         printf("%3i %-40s%30s\n", ++j, a.v[i].nome, a.v[i].telefone);
   printf("%3s %-40s%30s\n", "---", "----------------------------------------", "------------------------------");
}

int menu()
{
   int opc;
   char aux[10];//gambiarra para o pulo de linha
   do
   {
      limparTela();
      printf("1. inserir\n");
      printf("2. remover\n");
      printf("3. alterar\n");
      printf("4. listar todos\n");
      printf("5. listar filtrando por parte do nome ou telefone\n");
      printf("6. sair\n");
      printf("\nEntre com a sua opcao:");
      scanf("%d", &opc);
   } while (opc < 1 || opc > 6);
   lerString(aux,10); //gambiarra uma vez que o fflush(stdin) nao funfou!
   limparTela();
   return opc;
}

int main(void)
{
   TAgenda agenda;
   TContato ficha;
   char aux[_MAX_STRING_];
   int acabou = 0;
   inicializar(&agenda);
   while (!acabou)
   {
      switch (menu())
      {
      case 1: //inserir
         lerContato(&ficha);
         inserir(&agenda, ficha);
         printf("Contato inserido com sucesso!\n");
         pause();
         break;
      case 2: //remover
         printf("Entre com o nome ou telefone do contato a ser removido:");
         lerString(aux, _MAX_STRING_);
         if (remover(&agenda, aux))
            printf("Contato removido com sucesso!\n");
         else
            printf("Contato nao encontrado!");
         pause();
         break;
      case 3: //alterar
         printf("Entre com o nome ou telefone do contato a ser alterado:");
         lerString(aux, _MAX_STRING_);
         lerContato(&ficha);
         if (alterar(&agenda, aux, ficha))
            printf("Contato alterado com sucesso!\n");
         else
            printf("Contato nao encontrado!\n");
         pause();
         break;
      case 4: //listar
         listar(agenda);
         pause();
         break;
      case 5: //filtrar
         printf("Entre com parte do nome ou telefone do contato a ser filtrado:");
         lerString(aux, _MAX_STRING_);
         filtrar(agenda, aux);
         pause();
         break;
      case 6: //sair
         acabou = 1;
         break;
      default: //nenhuma das alternativas
         printf("alternativa nao implementada!\n");
         pause();
         break;
      }
   }
   return 0;
}

~~~