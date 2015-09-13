// Random password generator

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <functional>

std::string gen_password(int);
std::vector<std::string> gen_passwords(int, int);

int main() {
    std::cout << gen_password(10) << std::endl;

    auto passwords = gen_passwords(10, 10);

    for (auto p : passwords)
        std::cout << p << std::endl;

    return 0;
}

std::string gen_password(int len) {
    std::default_random_engine gen;
    // range of visible non-whitespace characters
    std::uniform_int_distribution<char> dist(33, 126);
    gen.seed(time(NULL));
    auto roll = std::bind(dist, gen);

    std::string pswd;

    for (int i = 0; i != len; ++i)
        pswd += roll();

    return pswd;
}

std::vector<std::string> gen_passwords(int len, int amt) {
    std::default_random_engine gen;
    // range of visible non-whitespace characters
    std::uniform_int_distribution<char> dist(33, 126);
    gen.seed(time(NULL));
    auto roll = std::bind(dist, gen);

    std::vector<std::string> passwords;

    for (int i = 0; i != amt; ++i) {
        std::string pswd;
        for (int j = 0; j != len; ++j) {
            pswd += roll();
        }
        passwords.push_back(pswd);
    }

    return passwords;
}

