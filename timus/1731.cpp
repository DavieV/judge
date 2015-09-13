#include <iostream>

using namespace std;

int main(void){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cout << i << " ";
	}
	cout << endl;
	for(int i = 1; i <= m; i++){
		//cout << i * 100 << " ";
		cout << i << "00 "; //save a bunch of calculations this way
	}
	cout << endl;
}