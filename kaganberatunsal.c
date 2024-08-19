#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];
    int i = 0, j = 0;

    printf("Lütfen bir cümle giriniz: ");
    fgets(input, MAX_LENGTH, stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }
    while (isspace(input[i])) {
        i++;
    }
    while (i < len) {
        if (!isspace(input[i]) || (j > 0 && !isspace(output[j - 1]))) {
            output[j++] = input[i];
        }
        i++;
    }
    if (j > 0 && isspace(output[j - 1])) {
        j--;
    }
    if (j == 0 || output[j - 1] != '.') {
        output[j++] = '.';
    }
    output[j] = '\0';

    printf("Düzenlenmiş cümle: %s\n", output);

    return 0;
}