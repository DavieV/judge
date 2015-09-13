#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

std::pair<int, std::string> parse_value(std::string);
int get_loop(std::vector<int>, std::vector<int>);

int main() {
    int t;

    std::cin >> t;

    int n;
    std::string s;
    std::vector<int> red;
    std::vector<int> blue;

    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        for (int j = 0; j < n; ++j) {
            std::cin >> s;
            auto p = parse_value(s);
            if (p.second == "R")
                red.push_back(p.first);
            else
                blue.push_back(p.first);
        }

        std::sort(red.begin(), red.end(),
            [](int a, int b) { return a > b; });
        std::sort(blue.begin(), blue.end(),
            [](int a, int b) { return a > b; });

        std::cout <<
            "Case #" <<
            (i + 1) <<
            ": " <<
            get_loop(red, blue) <<
        std::endl;

        red.clear();
        blue.clear();
    }

    return 0;
}

std::pair<int, std::string> parse_value(std::string s) {
    int val = 0;
    std::string color;
    for (auto c : s) {
        if (c >= '0' && c <= '9')
            val = (val * 10) + (c - '0');
        else
            color = c;
    }
    return {val, color};
}

int get_loop(std::vector<int> red, std::vector<int> blue) {
    int min_size = (red.size() < blue.size()) ? red.size() : blue.size();
    int loop = 0;
    for (int i = 0; i < min_size; ++i) {
        loop += red[i] + blue[i] - 2;
    }
    return loop;
}
