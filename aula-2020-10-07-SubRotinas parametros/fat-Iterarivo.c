#include<stdio.h>

int fat(int x)
{
   int i,resp;
   resp=1;
   for(i=x; i>0; i--)
     resp = resp * i;
   return resp;   
}

int main(void)
{
   int n;
   printf("entre com um numero:");
   scanf("%d",&n);

   printf(" o fatorial de %d eh %d\n", n, fat(n));
   return 0;

} 
