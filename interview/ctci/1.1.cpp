#include <iostream>
#include <map>

bool unique_chars(std::string n);

int main() {
    std::string n;
    std::cin >> n;
    std::cout << unique_chars(n) << std::endl;
    return 0;
}

bool unique_chars(std::string n) {
    std::map<char, int> occur;
    for (int i = 0; i < n.size(); ++i) {
        if (occur.find(n[i]) == occur.end()) {
            occur[n[i]] = 1;
        } else {
            return false;
        }
    }
    return true;
}
