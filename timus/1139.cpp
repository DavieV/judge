#include <iostream>

using namespace std;

int lcf(int, int);

int main(void){
	int n, m;
	cin >> n >> m;
	int k = lcf(m - 1, n - 1);

	cout << (m - 1) + (n - 1) - k << endl;
}

int lcf(int n, int m){
	int max = (n > m) ? n : m;
	int min = (n < m) ? n : m;
	if(max % min == 0) return min;
	else return lcf(max - min, min);
}