#include <stdio.h>
#include <stdlib.h>

void reverse(char *s);

int main() {
    char *s = malloc(256 * sizeof(char));
    scanf("%s", s);
    reverse(s);
    printf("%s\n", s);
}

void reverse(char *s) {
    int i = 0;
    while (s[i] != '\0')
        ++i;
    int len = i-1;
    char tmp;
    for (int c = 0; c < len / 2; ++c) {
        tmp = s[c];
        s[c] = s[len-c];
        s[len-c] = tmp;
    }
}
