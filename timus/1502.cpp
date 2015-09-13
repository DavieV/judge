#include <iostream>

using namespace std;

int main(void){
	long long n, sum = 0;
	cin >> n;
	sum = (n * (n + 1)) / 2; //summation from 1 to n
	cout << (n + 2) * sum << endl;
}