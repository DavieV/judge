#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int n, ways = 0;
	cin >> n;
	long long prev1 = 2, prev2 = 2, curr;

	if(n == 1) cout << 2 << endl;
	else if(n == 2) cout << 2 << endl;

	else{
		for(int i = 2; i < n; i++){
			curr = prev1 + prev2;
			prev2 = prev1;
			prev1 = curr;
		}
		cout << curr << endl;
	}
}