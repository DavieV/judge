#include <iostream>

using namespace std;

int pow(int, int, int);

int main(void){
	int n, m, y;
	bool flag = false;
	cin >> n >> m >> y;
	for(int i = 0; i < m; i++){
		int tmp = pow(i, n, m);
		if(tmp % m == y){
			flag = true;
			cout << i << " ";
		}
	}
	if(flag == false) cout << -1;
	cout << endl;
}

int pow(int x, int n, int m){
	int c = x, d = n, r = 1;
	while(d > 0){
		if(d % 2 == 1) r = (c * r ) % m;
		d /= 2;
		c = (c * c) % m;
	}
	return r;
}