#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v;
    
    for (int tmp; std::cin >> tmp;)
        v.push_back(tmp);

    std::sort(v.begin(), v.end());

    std::cout << v[0] * v[2] << std::endl;

    return 0;
}