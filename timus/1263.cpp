#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	int n, m; //n = candidates, m = voters
	cin >> n >> m;
	double votes[n];
	for(int i = 0; i < n; i++){
		votes[i] = 0;
	}
	int tmp;
	for(int i = 0; i < m; i++){
		cin >> tmp;
		votes[tmp - 1]++;
	}

	for(int i = 0; i < n; i++){
		cout << fixed << setprecision(2) << (votes[i] / m) * 100 << "%\n";
	}
}