#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(char *s1) {
    int len = strlen(s1);
    char *s2 = malloc(len + 1);

    s2[len] = '\0';

    for(int i = 0; i < len; i++) {
        s2[len - i - 1] = s1[i];
    }

    int result = strcmp(s1, s2) == 0;

    free(s2);
    return result;
}

int main() {
    char s1[] = "ragnhild";
    int result = palindrome(s1);
    printf("%d\n", result);

    return 0;
}
