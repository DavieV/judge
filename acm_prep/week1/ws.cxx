#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string s;

    if (cin >> s)
        cout << "s = \"" << s << "\"\n";
    else
        cout << "ERROR\n";

    return 0;
}

