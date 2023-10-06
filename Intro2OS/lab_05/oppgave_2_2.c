#include <stdio.h>
#include <pthread.h>

#define N 1000000000 // 1 milliard    - 1o⁹
#define n 100000000  // 100 millioner - 10⁸

void *count()
{
  int i, N2 = N/2;
    
  for (i = 0; i < N2; i++)
    if (i % n == 0)
       printf(".\n");
}

int main ()
{
  pthread_t thread_1, thread_2;
  int i;

  pthread_create(&thread_1, NULL, count, NULL);    
  pthread_create(&thread_2, NULL, count, NULL);    

  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);

  printf("%d iterations completed!\n", N);
}
