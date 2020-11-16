//https://www.urionlinejudge.com.br/judge/pt/problems/view/2542
#include <stdio.h>

#define _MAX_CARTAS_    100
#define _MAX_ATRIBUTOS_ 100
 
typedef struct{
   int qtdCartas, qtdAtributos;
   int selecionada;
   int VetCartas[_MAX_CARTAS_][_MAX_ATRIBUTOS_];
}Cartas;


void lerCartas(Cartas *c)
{
   int i,j;
   for (i=0;i< (*c).qtdCartas; i++)
      for(j=0; j< (*c).qtdAtributos; j++)
        scanf("%d", & (*c).VetCartas[i][j]);
}

int obterValorAtributo(Cartas c, int atributo)
{
   return c.VetCartas[c.selecionada-1][atributo-1];
}

int main() {
 
    int n,a;
    Cartas m,l;
    
    while( scanf("%d",&n)>0)
    {
        scanf("%d %d", &m.qtdCartas, &l.qtdCartas );
	m.qtdAtributos = l.qtdAtributos = n;
        lerCartas(&m);
        lerCartas(&l);
        scanf("%d %d", &m.selecionada, &l.selecionada);
        scanf("%d", &a);
        if (obterValorAtributo(m,a)> obterValorAtributo(l,a))
           printf("Marcos\n");
        else if (obterValorAtributo(m,a)< obterValorAtributo(l,a))
           printf("Leonardo\n");
        else
           printf("Empate\n");
    }
    
 
    return 0;
}