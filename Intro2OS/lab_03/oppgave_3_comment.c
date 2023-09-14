#include <stdio.h>  // Standard I/O library
#include <stdlib.h> // Standard library for malloc, free

// Define a struct to represent a process
struct process {
    int number;      // Process ID or number
    char status;     // Process status (e.g., 'A' for active)
    float start_time;// Start time of the process
    float CPU_time;  // CPU time consumed by the process
};

// Function to create a copy of a given process
struct process *copy(struct process p) {
    // Allocate memory for the new process and cast to struct process pointer
    struct process *newProcess = (struct process *) malloc(sizeof(struct process));

    // Copy the data from the original process to the new process
    *newProcess = p;

    // Return the pointer to the new process
    return newProcess;
}

int main() {
    // Create a process P1 with specified values
    struct process P1 = {1337, 'A', 13.37, 18.14};
    struct process *P2; // Declare pointer to hold copy of P1

    // Copy the process P1 into P2
    P2 = copy(P1);

    // Free the dynamically allocated memory for P2
    free(P2);

    // Program successfully completed
    return 0;
}
