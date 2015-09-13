#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    string line;

    if (getline(cin, line)) {
        double d;
        istringstream in(line);

        if (in >> d)
            cout << "d = " << d << "\n";
        else
            cout << "d not read ins.\n";
    }

    return 0;
}

