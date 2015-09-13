#include <iostream>
#include <set>

int main() {
    std::set<unsigned int> s;

    for (unsigned int tmp; std::cin >> tmp;)
        s.insert(tmp);

    for (auto i : s)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

