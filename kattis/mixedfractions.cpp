#include <iostream>

int main() {
    int n, d;

    std::cin >> n >> d;

    while (n != 0 && d != 0) {
        int full = n / d;
        int numerator = n % d;

        std::cout
            << full << " "
            << numerator << " / "
            << d
        << std::endl;

        std::cin >> n >> d;
    }

    return 0;
}
