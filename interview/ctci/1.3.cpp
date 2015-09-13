#include <iostream>
#include <string>

bool is_permute(std::string a, std::string b);

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << is_permute(a, b) << std::endl;
    return 0;
}

bool is_permute(std::string a, std::string b) {
    if (a.size() != b.size())
        return false;
    int occur[256] = {0};  // occurences of ascii characters
    for (char i : a)
        ++occur[i];

    for (char i : b)
        --occur[i];

    for (int i : occur) {
        if (i != 0)
            return false;
    }
    return true;
}
