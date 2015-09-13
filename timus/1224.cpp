#include <iostream>

using namespace std;

int main(void){
	long long n, m;

	cin >> n >> m;

	long long min = (2 * n - 2 < 2 * m - 1) ? (2 * n - 2) : (2 * m - 1);

	cout << min << endl;
}