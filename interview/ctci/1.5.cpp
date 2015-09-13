#include <iostream>
#include <cstring>

void compress(char *s);

int main() {
    char s[100] = "aabbccazzz";
    compress(s);
    std::cout << s << std::endl;
}

void compress(char *s) {
    char cur = s[0];
    int count = 1, len = strlen(s), cur_index = 0;
    for (int i = 1; i < len; ++i) {
        while (s[i] == cur) {
            ++count;
            ++i;
        }
        s[cur_index] = cur;
        cur = s[i];
        s[cur_index + 1] = count + '0';
        cur_index += 2;
        count = 1;
    }
    s[cur_index] = cur;
    s[cur_index + 1] = count + '0';
    s[cur_index + 2] = '\0';
}
