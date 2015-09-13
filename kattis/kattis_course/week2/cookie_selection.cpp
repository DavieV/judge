#include <iostream>
#include <string>
#include <set>


void insert_cookie(
    std::multiset<int>&,
    std::multiset<int>&,
    int
);

int main() {
    std::string s;
    std::multiset<int> small;
    std::multiset<int> large;

    while (std::cin >> s) {
        if (s == "#") {

        } else {
            insert_cookie(small, large, std::stoi(s));
        }
    }

    return 0;
}
