// Caesar cipher function

#include <iostream>
#include <string>

std::string encrypt(std::string, int);
std::string decrypt(std::string, int);

int main() {
    std::string test;

    std::cin >> test;

    std::cout <<
        encrypt(test, 3) << " " <<
        decrypt(encrypt(test, 3), 3) << 
    std::endl;

    return 0;
}

std::string encrypt(std::string msg, int shift) {
    std::string crypt;

    for (auto c : msg) {
        crypt += 'a' + ((shift + (c - 'a')) % 26); 
    }

    return crypt;
}

std::string decrypt(std::string msg, int shift) {
    std::string plain;

    for (auto c : msg) {
        if ((c - 'a') - shift < 0)
            plain += 'a' + (26 - (shift - (c - 'a')));
        plain += c - shift;
    }

    return plain;
}

