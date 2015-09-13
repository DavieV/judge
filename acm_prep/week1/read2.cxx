#include <iostream>
#include <string>

using namespace std;

istream& read_string(istream& is, string& s) {
    s.clear();
    char_traits<char>::int_type byte;

    while ((byte = is.get()) != char_traits<char>::eof())
        s.push_back(char_traits<char>::to_char_type(byte));
    return is;
}

int main() {
    int i;
    string s;

    if (cin >> i && read_string(cin, s)) {
        cout
            << "i = " << i
            << "s = \"" << s << "\""
            << "\n"
        ;
    }

}

