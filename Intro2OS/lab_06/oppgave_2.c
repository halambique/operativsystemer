#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
      
pthread_mutex_t mutex1, mutex2;

void* print1()
{
   pthread_mutex_lock(&mutex1);
   usleep(100000);
   pthread_mutex_lock(&mutex2);

   printf("Her er funksjonen \"print_1\"!\n");

   pthread_mutex_unlock(&mutex2);
   pthread_mutex_unlock(&mutex1);
}

void* print2()
{
   pthread_mutex_lock(&mutex2);
   usleep(100000);
   pthread_mutex_lock(&mutex1);
   
   printf("Her er funksjonen \"print_2\"!\n");
   
   pthread_mutex_unlock(&mutex1);
   pthread_mutex_unlock(&mutex2);
}

int main()
{
   pthread_t t1, t2;

   pthread_mutex_init(&mutex1, NULL);
   pthread_mutex_init(&mutex2, NULL);
   
   pthread_create(&t1, NULL, print1, NULL);
   pthread_create(&t2, NULL, print2, NULL);

   while (1)
   {
     putchar('.');
     fflush(stdout);
     usleep(100000);
   }
}

