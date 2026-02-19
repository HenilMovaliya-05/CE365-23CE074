#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i = 0;
    int len;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    // Count leading 'a'
    while (str[i] == 'a') {
        i++;
    }

    // Check for exactly "bb" after a*
    if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == '\0') {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
