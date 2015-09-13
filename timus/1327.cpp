#include <iostream>

using namespace std;

int main(void){
	int A, B, total = 0;
	cin >> A >> B;
	for(int i = A; i <= B; i++){
		if(i % 2 != 0) total++;
	}
	cout << total << endl;
}