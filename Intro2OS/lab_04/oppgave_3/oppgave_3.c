#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
   int status = 0;
   pid_t child = fork();
	
   if (child == 0)
   {
      printf("Barneprosessen med PID %d avslutter\n", getpid());
      return 0;
   }
   else
   {
      printf("Forelderprosessen med PID %d starter en evig løkke\n",
             getpid());
      while (1)
	 sleep(10);
   }
}
