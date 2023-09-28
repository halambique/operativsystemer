#include <pthread.h>
#include <stdio.h>
#define N_THREADS 5

int value = 0; // Global variabel som deles av alle tråder

void *count()
{
  int i;
  
  for (i = 0; i < 100000; i++)
     value++;

  printf("%d ", value);
}

int main ()
{
   int i;
   pthread_t thread[N_THREADS];
   
   for(i = 0; i < N_THREADS; i++)
      pthread_create(&thread[i], NULL, count, NULL);
   
   for(i = 0; i < N_THREADS; i++)
     pthread_join(thread[i], NULL);
   
   printf("\n");
}
