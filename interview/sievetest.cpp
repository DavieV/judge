#include <iostream>
#include <vector>
#include "PrimeSieve.hpp"

int main() {
    pe::PrimeSieve<int> sieve {100};  // PrimeSieve requires 'pe' namespace
    std::vector<int> primes = sieve.to_vector();

    for (int p : primes)
        std::cout << p << std::endl;

    return 0;
}
