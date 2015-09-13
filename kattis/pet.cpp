#include <iostream>

int main() {
    int max_val = 0;
    int max_pos = 1;
    int sum, tmp;

    for (int i = 0; i < 5; ++i) {
        sum = 0;

        for (int j = 0; j < 4; ++j) {
            std::cin >> tmp;
            sum += tmp;
        }

        if (sum > max_val) {
            max_val = sum;
            max_pos = i + 1;
        }
    }

    std::cout << max_pos << " " << max_val << std::endl;

    return 0;
}

