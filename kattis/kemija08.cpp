#include <iostream>
#include <string>

std::string decode(std::string, bool[]);
bool is_coded(char, char, char, bool[]);
bool is_vowel(char);

int main() {
    bool vowels[26];
    for (int i = 0; i < 26; ++i)
        vowels[i] = is_vowel(i + 'a');

    std::string s;
    std::getline(std::cin, s);

    std::cout << decode(s, vowels) << std::endl;

    return 0;
}

std::string decode(std::string s, bool vowels[]) {
    std::string msg = "";
    int start = 0, end = 2;
    int len = s.length();

    while (end < len) {
        msg += s[start];
        if (is_coded(s[start], s[start + 1], s[end], vowels)) {
            start += 3;
            end += 3;
        } else {
            ++start;
            ++end;
        }
    }

    if (start <= len) {
        for (int i = start; i < len; ++i)
            msg += s[i];
    }

    return msg;
}

bool is_coded(char a, char b, char c, bool vowels[]) {
    if (a == c)
        return vowels[a - 'a'] && b == 'p' && vowels[c - 'a'];
    return false;
}

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
