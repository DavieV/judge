#include <iostream>
#include <string>
#include <unordered_set>

std::string clean_str(std::string, std::string);

int main() {
    std::string s1, s2;

    std::cin >> s1 >> s2;

    std::cout << clean_str(s1, s2) << std::endl;
    return 0;
}

std::string clean_str(std::string s1, std::string s2) {
    std::unordered_set<char> remove;

    for (auto c : s2)
        remove.insert(c);

    std::string clean;

    for (auto c : s1) {
        if (remove.find(c) == remove.end()) {
            clean += c;
        }
    }

    return clean;
}

