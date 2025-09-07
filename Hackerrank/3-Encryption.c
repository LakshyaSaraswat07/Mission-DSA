#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // For malloc and free

void remove_spaces(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

char* encryption(char* s) {
    remove_spaces(s);
    int len = strlen(s);

    int rows = floor(sqrt(len));
    int cols = ceil(sqrt(len));

    // Adjust rows if the calculated grid is too small
    if (rows * cols < len) {
        rows++;
    }

    char* encrypted_s = (char*)malloc(sizeof(char) * (len + cols + 1));
    if (encrypted_s == NULL) {
        // Handle memory allocation error
        return NULL;
    }
    int k = 0; // Index for the encrypted_s

    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            int index = r * cols + c;
            if (index < len) {
                encrypted_s[k++] = s[index];
            }
        }
        
        if (c < cols - 1) {
            encrypted_s[k++] = ' ';
        }
    }
    encrypted_s[k] = '\0'; // Null-terminate the string

    return encrypted_s;
}

int main() {
    char s[1000]; // Assuming a maximum string length
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Remove trailing newline if present

    char* result = encryption(s);
    printf("%s\n", result);

    free(result); // Free allocated memory
    return 0;
}
