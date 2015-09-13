#include <iostream>

int main() {

    int tot;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            static int test = 0;
            ++test;
            tot = test;
        }
    }

    std::cout << tot << std::endl;

    return 0;
}
