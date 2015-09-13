#include <iostream>
#include <string>
#include <vector>

unsigned ragged_score(std::vector<std::string>, unsigned);

int main() {
    std::vector<std::string> lines;
    std::string line;
    unsigned max = 0;

    while (std::getline(std::cin, line)) {
        lines.push_back(line);
        if (line.length() > max)
            max = line.length();
    }

    std::cout << ragged_score(lines, max) << std::endl;

    return 0;
}

unsigned ragged_score(std::vector<std::string> lines, unsigned max) {
    unsigned score = 0;
    for (unsigned i = 0; i < lines.size() - 1; ++i) {
        unsigned dif = max - lines[i].length();
        score += dif * dif;
    }
    return score;
}

