#include <stdio.h>

#define N 1000000000 // 1 milliard    - 10⁹
#define n 100000000  // 100 millioner - 10⁸

void count()
{
   int i;
   for (i = 0; i < N; i++)
     if (i % n == 0)
       printf(".\n");
}

int main ()
{
  count();
  printf("%d iterations completed!\n", N);
}
