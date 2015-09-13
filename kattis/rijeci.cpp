#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int a = 1, b = 0;

    for (int i = 0; i < n; ++i) {
        int tmp_b = a;
        int tmp_a = b;

        a = tmp_a;
        b = b + tmp_b;   
    }

    std::cout << a << " " << b << std::endl;
}
