// Output the "sad cycle" of a number n, given a power p

#include <iostream>
#include <vector>
#include <unordered_set>

unsigned long my_pow(unsigned long, unsigned);
unsigned long sum_digit_powers(unsigned long, unsigned);
std::vector<unsigned long> find_cycle(unsigned long, unsigned);

int main() {
    unsigned long n;
    unsigned p;
    std::cin >> p >> n;
    auto v = find_cycle(n, p);

    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

unsigned long my_pow(unsigned long a, unsigned p) {
    unsigned long tmp = a;
    for (unsigned i = 0; i != p - 1; ++i)
        a *= tmp;
    return a;
}

unsigned long sum_digit_powers(unsigned long n, unsigned p) {
    unsigned long s = 0;
    while (n > 0) {
        s += my_pow(n % 10, p);
        n /= 10;
    }
    return s;
}

std::vector<unsigned long> find_cycle(unsigned long n, unsigned p) {
    std::unordered_set<unsigned long> map;
    std::vector<unsigned long> v;
    unsigned long tmp = n;

    // loop until we find a number that we have seen before
    while (map.find(tmp) == map.end()) {
        map.insert(tmp);
        tmp = sum_digit_powers(tmp, p);
    }

    // build up the list of numbers in the cycle
    unsigned long start = tmp;
    do {
        v.push_back(tmp);
        tmp = sum_digit_powers(tmp, p);
    } while (tmp != start);

    return v;
}
