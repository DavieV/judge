#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	int n, tmp;
	double total;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		total += tmp;
	}

	cout << fixed << setprecision(6) << total / n << endl;
}