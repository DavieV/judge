// Make a program that simply calculates the standard deviation of a set

#include <iostream>
#include <vector>
#include <cmath>

double population_stddev(std::vector<double>);
double sample_stddev(std::vector<double>);

int main() {
    std::vector<double> v;
    
    for (double tmp; std::cin >> tmp;)
        v.push_back(tmp);

    std::cout << "Population: " << population_stddev(v) << std::endl;
    std::cout << "Sample: " << sample_stddev(v) << std::endl;
    return 0;
}

double sample_stddev(std::vector<double> v) {
    double sum1 = 0;
    for (double i : v)
        sum1 += (i * i);  // sum the squares

    double sum2 = 0;
    for (double i : v)
        sum2 += i;
    sum2 *= sum2;  // square the sum;

    double variance = (sum1 - (sum2 / v.size())) / (v.size() - 1);

    return std::sqrt(variance);
}

double population_stddev(std::vector<double> v) {
    double sum1 = 0;
    for (double i : v)
        sum1 += (i * i);  // sum the squares

    double sum2 = 0;
    for (double i : v)
        sum2 += i;
    sum2 *= sum2;  // square the sum;

    double variance = (sum1 / v.size()) - (sum2 / (v.size() * v.size()));

    return std::sqrt(variance);
}
