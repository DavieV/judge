#include <iostream>

using namespace std;

int main(void){
	int n = 0;
	char tmp;
	while(cin >> tmp) n = (n * 10 + tmp - '0') % 7;
	cout << n << endl;
}