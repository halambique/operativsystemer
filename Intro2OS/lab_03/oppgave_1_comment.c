#include <stdio.h>  // For printf
#include <stdlib.h> // For malloc, free
#include <string.h> // For strlen, strcmp

// Function to check if the given string s1 is a palindrome
int palindrome(char *s1) {
    int len = strlen(s1);       // Get length of input string
    char *s2 = malloc(len + 1); // Allocate memory for reversed string

    s2[len] = '\0'; // Null-terminate the new string

    // Reverse the string and store in s2
    for(int i = 0; i < len; i++) {
        s2[len - i - 1] = s1[i];
    }

    // Compare original and reversed strings
    int result = strcmp(s1, s2) == 0;

    free(s2); // Free dynamically allocated memory
    return result; // Return the result of the comparison
}

int main() {
    char s1[] = "agnes i senga";  // String to check
    int result = palindrome(s1);  // Call the palindrome function
    printf("%d\n", result);       // Print the result

    return 0;
}
