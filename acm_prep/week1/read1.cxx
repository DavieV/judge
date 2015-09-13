#include <iostream>
#include <string>

int main() {
    int i;

    if (std::cin >> i) {
        std::string s;
        if (getline(std::cin, s)) {
            std::cout
                << "i = " << i
                << "s = \"" << s << "\""
                << "\n"
            ;
        }
    }

}

