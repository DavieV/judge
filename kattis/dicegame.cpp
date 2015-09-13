#include <iostream>

double avg_roll(int, int, int, int);

int main() {
    int a1, b1, a2, b2;

    std::cin >> a1 >> b1 >> a2 >> b2;
    double gunnar = avg_roll(a1, b1, a2, b2);

    std::cin >> a1 >> b1 >> a2 >> b2;
    double emma = avg_roll(a1, b1, a2, b2);

    if (gunnar > emma)
        std::cout << "Gunnar" << std::endl;
    else if (gunnar < emma)
        std::cout << "Emma" << std::endl;
    else
        std::cout << "Tie" << std::endl;

    return 0;
}

double avg_roll(int a1, int b1, int a2, int b2) {
    double s = 0;   // sum of the values of each roll
    int c = 0;      // total number of possible rolls
    for (int i = a1; i <= b1; ++i) {
        for (int j = a2; j <= b2; ++j) {
            s += (i + j);
            ++c;
        }
    }
    return s / c;
}
