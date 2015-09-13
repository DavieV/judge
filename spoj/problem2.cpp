/*
Write a program that reverses two numbers, and then returns the reverse of their sum

Sample input: 

3
24 1
4358 754
305 794

Sample output:

34      // 42 + 1 = 43 -> 34
1998
1
*/

#include <iostream>

int reverse(int);

int main() {
    int n;
    std::cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        std::cout << reverse(reverse(a) + reverse(b)) << std::endl;
    }
}

int reverse(int a) {
    int r = 0;
    while (a > 0) {
        r = (r * 10) + a % 10;
        a /= 10;
    }
    return r;
}
