#include <iostream>

void compare_bits(unsigned int, unsigned int);

int main() {
    unsigned int num1, num2;
    while (std::cin >> num1 >> num2)
        compare_bits(num1, num2);

    return 0;
}

void compare_bits(unsigned int x, unsigned int y) {
    int c = 0;
    int tmp_x = x;
    int tmp_y = y;

    for (int i = 0; i < 32; ++i) {
        // only compare the rightmost bit
        if (((tmp_x << 31) ^ (tmp_y << 31)) == 0)
            ++c;

        // Clear out the rightmost bit
        tmp_x = tmp_x >> 1;
        tmp_y = tmp_y >> 1;
    }

    std::cout <<
        "The numbers are " <<
        ((c / 32.0) * 100) <<
        "% compatible" <<
    std::endl;

    std::cout << "x should avoid " << ~x << std::endl;
    std::cout << "y should avoid " << ~y << std::endl;
}
