#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(char *s1) {
    int len = strlen(s1);  // Finner lengden av strengen s1
    char *s2 = malloc(len + 1);  // Allokerer minne for s2

    s2[len] = '\0';  // Setter null-terminatoren for den nye strengen s2

    for(int i = 0; i < len; i++) {
        // Når i=0, vil posisjonen være "len - 1", som er den siste posisjonen i s2.
        // Når i=1, vil posisjonen være "len - 2", som er nest siste posisjon i s2, osv.
        // "s1[i]" er char fra s1 på posisjon "i".
        // Jeg har fått hjelp fra medstudent til å skrive for-løkken, og fra chatGPT for å kommentere for egen forståelse.
        s2[len - i - 1] = s1[i];
    }


    // Bruker strcmp for å sjekke om s1 og s2 er like
    int result = strcmp(s1, s2) == 0;

    free(s2);  // Frigjør det allokerte minnet for s2
    return result;  // Returnerer resultatet (1 for palindrom, 0 for alt annet)
}

int main() {  // main-funksjon som er brukt til test/proof of concept
    char s1[] = "agnes i senga";
    int result = palindrome(s1);
    printf("%d\n", result);

    return 0;
}
