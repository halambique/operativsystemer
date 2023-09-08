#include <stdio.h>

int main() {
    int n;
    int sum = 0;

    for (n = 0; n <= 100; n++) {
        sum += n * n;
    }

    printf("Summen er: %d\n", sum);
    return 0;
}
