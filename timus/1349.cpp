#include <iostream>

using namespace std;

int isPerfectNth(int n);

int main(void){
	int n;
	cin >> n;
	if(n == 1) cout << "1 2 3\n";
	else if(n == 2) cout << "3 4 5\n";
	else cout << -1 << endl;
}
