#include <stdio.h>
#include <pthread.h>

int count = 0;

void *increase()
{
   int i;
   for(i = 0; i < 1e8; ++i)
      count++;
}

void *decrease()
{
   int i;
   for(i = 0; i < 1e8; ++i)
      count--;
}

int main()
{
   pthread_t thread1, thread2;

   pthread_create(&thread1, NULL, increase, NULL);
   pthread_create(&thread2, NULL, decrease, NULL);

   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);

   printf("count = %d\n", count);
}
