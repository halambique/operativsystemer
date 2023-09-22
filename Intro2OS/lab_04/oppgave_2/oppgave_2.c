#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
   int status = 0;
   pid_t child = fork();
	
   if (child == 0)
   {
     printf("Jeg er barneprosessen med PID %d\n", getpid());
     sleep(1);
     return 42;
   }
   else if (child > 0)
   {
      printf("Jeg er forelderprosessen med PID %d\n", getpid());
      printf("Barneprosessen %d har terminert med returstatus lik %d\n",
             child, WEXITSTATUS(status));
   }
}
