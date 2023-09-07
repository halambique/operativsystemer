#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array[1000];
    int i, max;

    srand(time(NULL));

    for (i = 1; i < 1000; i++) {
        array[i] = rand() % 100001;
        if (array[i] > max) {
            max = array[i];
        }
    }

    printf("Det største tallet i arrayet er: %d", max);
    return 0;
}
