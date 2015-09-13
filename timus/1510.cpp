#include <iostream>

using namespace std;

int main(void){
	int n, val, count = 0, tmp;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(count == 0){
			val = tmp;
			count = 1;
		}
		else if(val == tmp) count++;
		else count--;
	}
	cout << val << endl;
}