#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct bin {
    unsigned brown;
    unsigned green;
    unsigned clear;
};

void min_moves(bin[]);

int main() {
    bin bins[3];
    string line;

    while(std::getline(cin, line)) {
        stringstream ss(line);
        for (unsigned i = 0; i != 3; ++i)
            ss >> bins[i].brown >> bins[i].green >> bins[i].clear;
        min_moves(bins);
    }

    return 0;
}

void min_moves(bin bins[]) {
    string form = "BCG";
    unsigned brown_moves = 0;
    unsigned green_moves = 0;
    unsigned clear_moves = 0;

    for (unsigned i = 0; i != 3; ++i) {
        brown_moves += bins[i].brown;
        green_moves += bins[i].green;
        clear_moves += bins[i].clear;
    }

    unsigned min = (~0 >> 1);
    string min_val;
    do {
        unsigned moves = 0;
        for (unsigned i = 0; i != form.length(); ++i) {
            if (form[i] == 'B')
                moves += brown_moves - bins[i].brown;
            else if (form[i] == 'G')
                moves += green_moves - bins[i].green;
            else
                moves += clear_moves - bins[i].clear;

        }
        if (moves < min) {
            min = moves;
            min_val = form;
        }
    } while (next_permutation(form.begin(), form.end()));

    cout << min_val << " " << min << endl;
}

