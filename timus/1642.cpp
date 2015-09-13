#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int n, x, tmp, right = 1001, left = -1001;
	cin >> n >> x;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp > 0){
			if(tmp < right) right = tmp;
		}
		if(tmp < 0){
			if(tmp > left) left = tmp;
		}
	}

	if(x > right || x < left){ 
		cout << "Impossible\n"; 
		return 0;
	}
	else if(x < right && x > 0) cout << x << " " << (2 * abs(left)) + x << endl;
	else if(x > left && x < 0) cout << (2 * abs(right)) + abs(x) << " " << abs(x) << endl;
}