#include <iostream>

unsigned binary_reverse(unsigned, unsigned);
unsigned bit_len(unsigned);

int main() {
    unsigned int n;
    std::cin >> n;
    int len = bit_len(n);
    std::cout << binary_reverse(n, len) << std::endl;
    return 0;
}

unsigned bit_len(unsigned n) {
    unsigned len = 0;
    for (unsigned i = 0; i < 32; ++i) {
        if (n & (1 << i))
            len = i + 1;
    }
    return len;
}

unsigned int binary_reverse(unsigned n, unsigned len) {
    unsigned rev = 0;
    unsigned flip;
    for (unsigned i = 0; i < len; ++i) {
        if (n & (1 << i))
            flip = 1;
        else
            flip = 0;

        rev |= (flip << (len - i - 1));
    }
    return rev;
}
