#include <stdio.h>

void incremento(int x)
{
   x = x +1;
}

int main(void)
{
    int a = 10;
    incremento(a);
    printf("a=%d\n",a);
    return 0;
}