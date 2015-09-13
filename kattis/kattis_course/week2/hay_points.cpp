#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int m, n;
    
    std::cin >> m >> n;

    std::unordered_map<std::string, int> dict;

    for (int i = 0; i < m; ++i) {
        std::string word;
        int value;
        std::cin >> word >> value;
        dict.insert({word, value});
    }

    std::string word;
    int score = 0;

    while (std::cin >> word) {
        if (word == ".") {
            std::cout << score << std::endl;
            score = 0;
        } else {
            auto result = dict.find(word);
            if (result != dict.end())
                score += result->second;
        }
    }

    return 0;
}

