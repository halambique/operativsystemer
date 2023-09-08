#include <stdio.h>

long fib(int n) {
     if(n == 0) {
         return 0;
}
    if(n == 1) {
        return 1;
    }
        return fib(n-1)+fib(n-2);
}

int main() {
    int n;
    printf("Value of n: ");
    scanf("%d", &n);

    FILE *file;
    file = fopen("fibonacci.txt", "w");

    for (int i = 0; i <= n; i++) {
    long result = fib(i);
    fprintf(file, "%ld\n", result);
    }

    fclose(file);
    printf("Fibonacci sequence succsessfully written to file up to n = %d\n", n);

    return 0;
}


