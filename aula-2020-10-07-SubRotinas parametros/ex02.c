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
    int vet[10],a[100];
    lerVet(vet,10);
    lerVet(a,5);
    mostrarVet(vet,10);
    mostrarVet(a,5);
    return 0;
}
