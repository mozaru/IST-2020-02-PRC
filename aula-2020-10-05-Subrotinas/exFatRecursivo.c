
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

/*fat(n) = fat(n-1)*n
ex: fat(5) = fat(4)*5 -> 5* 4*3*2*1
    fat(4) = fat(3)*4 -> 4* 3*2*1
    fat(3) = fat(2)*3 -> 3* 2*1
    fat(2) = fat(1)*2 -> 2*1
    fat(1) = 1
*/
int fat(int x)
{
   if (x<0)
   {
      errno = EINVAL;
      perror("nao pode usar menores que 1");
      exit(errno);
   }
   else if (x==1) 
     return 1;
   else      
     return fat(x-1)*x;   
}

int main(void)
{
   int n;
   printf("entre com um numero:");
   scanf("%d",&n);

   printf(" o fatorial de %d eh %d\n", n, fat(n));
   return 0;
} 