#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
	    
int main()
{
   pid_t child1, child2; 

   child1 = fork();
   child2 = fork();
   
   printf("Jeg er prosess %d, min forelder er %d\n", getpid(), getppid());
   sleep(1);
}
