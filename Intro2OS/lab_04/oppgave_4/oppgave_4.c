#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


int main(){
	pid_t pid = fork();
	if (pid == 0){
		char *bashCommand[] = {"ping", "vg.no", "\0"};
		execvp(bashCommand[0], bashCommand);
	}

	else if (pid > 0){
		sleep(5);
		kill(pid, SIGINT);
	}

	return(0);
}
