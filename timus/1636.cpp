#include <iostream>

using namespace std;

int main(void){
	int t1, t2, tmp;

	cin >> t1 >> t2;

	for(int i = 0; i < 10; i++){
		cin >> tmp;
		t2 -= 20 * tmp;
	}

	if(t1 <= t2) cout << "No chance.\n";
	else cout << "Dirty debug :(\n";
}