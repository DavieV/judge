#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int size, cover, start, end;

	cin >> size >> cover >> start >> end;

	if(end - start == 1) cout << 2 * cover << endl;
	else{
		cout << (size * abs(end - start - 1)) + (2 * abs(end - start) * cover) << endl;
	}
}