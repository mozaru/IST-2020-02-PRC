#include<stdio.h>

int soma(int a, int b)
{
   return a+b;
}

int main(void)
{
    int x,y;
    printf("entre com o valor de x:");
    scanf("%d",&x);    
    printf("entre com o valor de y:");
    scanf("%d",&y);
    
    printf("%d + %d = %d\n", x, y, soma(x,y));
    return 0;
}
