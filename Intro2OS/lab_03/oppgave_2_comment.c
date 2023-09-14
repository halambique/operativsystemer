#include <stdio.h>  // For standard I/O operations like printf and scanf
#include <stdlib.h> // For dynamic memory allocation functions like malloc and free

int main(){
    int n;      // Declare variable for the number of integers
    int *A;     // Declare pointer for dynamic array

    printf("Skriv inn antall heltall: "); // Prompt user for the number of integers
    scanf("%d", &n); // Read user input

    // Allocate memory for 'n' integers and assign the address to pointer 'A'
    A = malloc(n * sizeof(int));

    printf("Skriv inn %d heltall: \n", n); // Prompt user for 'n' integers

    // Loop to read 'n' integers from the user
    for (int i = 0 ; i < n; i++){
        scanf("%d", A + i);
    }

    // Print the 'n' integers in reverse order
    printf("De %d tallene i omvendt rekkefølge: ", n);
    for (int i = n-1; i >= 0; i--){
        printf("%d ", *(A+i));
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(A);

    return 0;  // Exit program
}
