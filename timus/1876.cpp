#include <iostream>

using namespace std;

int main(void){
	int a, b;
	cin >> a >> b;
	int max = (2 * a + 39) > (2 * b + 40) ? (2 * a + 39) : (2 * b + 40);
	cout << max << endl;
}