#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void sigurs1_handler(int sig){
   printf("Slutt å mase, din frekke f**n.\n");
}

int main() {
   signal(SIGUSR1, sigurs1_handler);
   pid_t pid = fork();

   if (pid == 0){
      char input[100];

      while (1){
         printf("Skriv en tekststreng: ");
         scanf("%s", input);
         if (strcmp(input, "quit") == 0){
            exit(0);
         }

         kill(getppid(), SIGUSR1);
         usleep(200000);
      }
   }
   else {
      wait(NULL);

   }
   return 0;
}
