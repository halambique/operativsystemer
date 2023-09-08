#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array[1000];
    int i, max = 0, min = 10000;

    srand(time(NULL));

    for (i = 0; i < 1000; i++) {
        array[i] = rand() % 100001;
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min){
            min = array[i];
        }
    }

    printf("Det største tallet i arrayet er: %d\n", max);
    printf("Det minste tallet i arrayet er: %d\n", min);

    return 0;
}
