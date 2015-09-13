#include <iostream>

using namespace std;

int main(void){
	int n, k, tmp;
	cin >> n >> k;

	int droids = n * k;
	int booms = 0;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp <= k){
			droids -= tmp;
		}
		else{
			droids -= k;
			booms += (tmp - k);
		}
	}

	cout << booms << " " << droids << endl;
}