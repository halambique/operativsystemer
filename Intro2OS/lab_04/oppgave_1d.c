#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
   pid_t child1, child2; 

   child1 = fork();
   if (child1 == 0)
       sleep(1);
       
   child2 = fork();
   if (child2 == 0)
     sleep(1);

   printf("Jeg er prosess %d, min forelder er %d\n", getpid(), getppid());
}
