#include <iostream>
#include <algorithm>
#include <unordered_map>

unsigned cycle_length(unsigned, std::unordered_map<unsigned, unsigned>&);

int main() {
    std::unordered_map<unsigned, unsigned> lens;

    int n, m;

    while (std::cin >> n >> m) {
        int max = 0, cur;

        for (int i = std::min(n, m); i <= std::max(n, m); ++i) {
            cur = cycle_length(i, lens);
            if (cur > max)
                max = cur;
        }
        std::cout << n << " " << m << " " << max << std::endl;
    }

    return 0;
}

unsigned cycle_length(
    unsigned n,
    std::unordered_map<unsigned, unsigned>& lens
) {
    if (n == 1)
        return 1;

    if (lens.find(n) != lens.end())
        return lens[n];

    unsigned return_val;
    if (n & 1)
        return_val = 1 + cycle_length((3 * n) + 1, lens);
    else
        return_val = 1 + cycle_length(n / 2, lens);
    lens.insert({n, return_val});
    return return_val;
}

