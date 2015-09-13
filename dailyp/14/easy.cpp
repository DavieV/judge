#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <class Iter>
void reverse_blocks(Iter, Iter, unsigned int);

int main() {
    std::vector<int> v;
    int k;

    std::cin >> k;
    
    for (int tmp; std::cin >> tmp;)
        v.push_back(tmp);

    reverse_blocks(std::begin(v), std::end(v), k);

    for (int i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

template <class Iter>
void reverse_blocks(Iter b, Iter e, unsigned int k) {
    while (b + k <= e) {
        std::reverse(b, b+k);
        b += k;
    }
}

