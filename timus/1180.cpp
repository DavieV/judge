#include <iostream>

using namespace std;

int main(void){
	int stones = 0;
	char tmp;
	while(cin >> tmp) stones += tmp - '0';
	if(stones % 3 == 0) cout << 2 << endl;
	else cout << 1 << endl << stones % 3 << endl;
}