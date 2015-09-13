#include <iostream>
#include <vector>
#include <utility>

bool is_valid(std::vector< std::pair<int, int> >);

int main() {
    std::vector< std::pair<int, int> > pairs;
    char tmp;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cin >> tmp;
            if (tmp == '*')
                pairs.push_back({i, j});
        }
    }

    if (is_valid(pairs))
        std::cout << "valid" << std::endl;
    else
        std::cout << "invalid" << std::endl;

    return 0;
}

/*
Determine if a given board configuration is a valid solution to the eight
queens problem. The input is a vector of pairs that represent the position
of each queen.
*/
bool is_valid(std::vector< std::pair<int, int> > pairs) {
    int len = pairs.size();

    if (len != 8) return false;

    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            auto p1 = pairs[i];
            auto p2 = pairs[j];

            if (p1.first == p2.first) return false;
            if (p1.second == p2.second) return false;

            int diff1 = p1.first - p2.first;
            int diff2 = p1.second - p2.second;

            if (std::abs(diff1) == std::abs(diff2)) return false;
        }
    }
    return true;
}
