#include <iostream>
#include <cstring>

int main() {
    int n;
    std::cin >> n;

    int* buckets = new int[n];
    memset(buckets, 0, sizeof(int) * n);

    for (int x; std::cin >> x;)
        ++buckets[x-1];

    for (int i = 0; i < n; ++i) {
        
    }

    return 0;
}
