#include <stdio.h>
#include <stdlib.h>

struct process{
   int number;
   char status;
   float start_time;
   float CPU_time;
};


struct process *copy(struct process p){
    struct process *newProcess = (struct process *) malloc(sizeof(struct process));

    *newProcess = p;

    return newProcess;
}

int main() {
    struct process P1 = {1337, 'A', 16.10, 3.33};
    struct process *P2;

    P2 = copy(P1);

    printf("%d\n", P2->number);
}
