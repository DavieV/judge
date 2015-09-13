#include <iostream>
#include <cstring>

#define MAX 1000000

int next_prime(int p, bool s[]);
void del_mult(int p, bool s[]);

int main() {
    int euler_sieve[MAX];   // sieve for Euler's totient function
    bool prime_sieve[MAX];  // sieve of prime numbers

    for (int i = 0; i < MAX; ++i) {
        prime_sieve[i] = true;
        euler_sieve[i] = i;
    }

    prime_sieve[0] = false;
    prime_sieve[1] = false;
    int prime = 2;

    // Complete the sieve of prime numbers
    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, prime_sieve);
        prime = next_prime(prime, prime_sieve);
    }

    // complete the sieve for Euler's totient function
    for (int i = 1; i < MAX; ++i) {
        if (prime_sieve[i]) {
            for (int j = i; j < MAX; j += i)
                euler_sieve[j] -= euler_sieve[j] / i;
        }
    }

    std::cout << euler_sieve[14] << std::endl;
    std::cout << euler_sieve[15] << std::endl;

    return 0;
}

int next_prime(int p, bool s[]) {
    while (!s[++p]);
    return p;
}

void del_mult(int p, bool s[]) {
    for (int i = p * p; i < MAX; i +=p)
        s[i] = false;
}
