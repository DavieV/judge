#include <iostream>
#include <cstring>

void percent_20(char *s);

int main() {
    char s[100] = "hello        there guys!";
    percent_20(s);
    std::cout << s << std::endl;
}

void percent_20(char *s) {
    while (*s) {
        if (*s == ' ') {
            memmove(s + 3, s + 1, strlen(s + 1));
            *s = '%';
            *(s + 1) = '2';
            *(s + 2) = '0';
        }
        ++s;
    }
}
