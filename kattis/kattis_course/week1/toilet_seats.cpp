#include <iostream>
#include <string>

int up_policy(std::string);
int down_policy(std::string);
int pref_policy(std::string);

int main() {
    std::string s;

    std::cin >> s;

    std::cout << up_policy(s) << std::endl;
    std::cout << down_policy(s) << std::endl;
    std::cout << pref_policy(s) << std::endl;

    return 0;
}

int up_policy(std::string s) {
    char cur = s[0];
    int len = s.length();
    int count = 0;

    for (int i = 1; i < len; ++i) {
        if (cur != s[i]) ++count;
        if (s[i] != 'U') ++count;
        cur = 'U';
    }

    return count;
}

int down_policy(std::string s) {
    char cur = s[0];
    int len = s.length();
    int count = 0;

    for (int i = 1; i < len; ++i) {
        if (cur != s[i]) ++count;
        if (s[i] != 'D') ++count;
        cur = 'D';
    }

    return count;
}

int pref_policy(std::string s) {
    char cur = s[0];
    int len = s.length();
    int count = 0;

    for (int i = 1; i < len; ++i) {
        if (cur != s[i]) ++count;
        cur = s[i];
    }

    return count;
}
