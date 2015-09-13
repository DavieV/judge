#include <iostream>

int sum_digits(int);

int main() {
    int n;
    std::cin >> n;

    while (n != 0) {
        int s = sum_digits(n);
        int p = 11;
        while (s != sum_digits(n * p))
            ++p;
        std::cout << p << std::endl;

        std::cin >> n;
    }

    return 0;
}

int sum_digits(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
