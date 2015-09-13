#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	double n, t, s, tmp;

	cin >> n >> t >> s;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		cout << fixed << setprecision(6) << ((tmp - s + t) / 2) + s << endl; 
	}

}