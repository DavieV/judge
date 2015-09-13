#include <iostream>
#include <vector>
#include <unordered_map>

// Used a functor as a way to save the setup of the map
struct dna_functor {
    std::unordered_map<char, char> map;

    // fill in all of the pairs
    dna_functor() {
        map.insert({'A', 'T'});
        map.insert({'T', 'A'});
        map.insert({'C', 'G'});
        map.insert({'G', 'C'});
    }

    void operator ()(std::vector<char> strand) {
        for (char c : strand)
            std::cout << map[c] << " ";
        std::cout << std::endl;
    }
};

int main() {
    std::vector<char> strand;
    dna_functor d;

    for (char tmp; std::cin >> tmp;)
        strand.push_back(tmp);

    d(strand);

    return 0;
}

