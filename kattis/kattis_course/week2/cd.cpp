#include <iostream>
#include <bitset>

#define MAX 1000000001

int main() {
    int n, m;

    std::bitset<MAX>* jack_cds;
    jack_cds = new std::bitset<MAX>();

    while (std::cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        int count = 0;

        for (int i = 0, tmp; i < n; ++i) {
            std::cin >> tmp;
            (*jack_cds)[tmp] = 1;
        }

        for (int i = 0, tmp; i < m; ++i) {
            std::cin >> tmp;
            if ((*jack_cds)[tmp])
                ++count;
        }

        std::cout << count << std::endl;
        jack_cds->reset();
    }

    return 0;
}
