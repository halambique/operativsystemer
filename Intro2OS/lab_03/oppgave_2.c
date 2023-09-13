#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *A;

    printf("Skriv inn antall heltall: ");
    scanf("%d", &n);


    A = malloc(n * sizeof(int));

    printf("Skriv inn %d heltall: \n", n);

    for (int i = 0 ; i < n; i++){
        scanf("%d", A + i);
    }

    printf("De %d tallene i omvendt rekkefølge: ", n);
    for (int i = n-1; i >= 0; i--){
        printf("%d ", *(A+i));
    }
    printf("\n");
    free(A);
    return 0;
}
