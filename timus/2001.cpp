#include <iostream>

using namespace std;

int main(void){
	int a1, a2, a3, b1, b2, b3, w1, w2;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	w1 = a1 - a3;
	w2 = b1 - b2;
	cout << w1 << " " << w2 << endl;
}