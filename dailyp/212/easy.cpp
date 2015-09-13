#include <iostream>
#include <string>
#include <unordered_set>

char to_upper(char);

struct robber_struct {
    std::unordered_set<char> map;
    robber_struct() {
        map = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 
        'r', 's', 't', 'v', 'w', 'x', 'z'};
    }

    std::string operator ()(std::string s) {
        std::string n = "";
        for (auto c : s) {
            if (map.find(c) != map.end()) {
                std::cout << c << std::endl;
                n += c;
                n += 'o';
                n += c;
            } else {
                n += c;
            }
        }
        return n;
    }
};

int main() {
    std::string s;
    robber_struct r;
    std::cin >> s;
    std::cout << r(s) << std::endl;
    return 0;
}
