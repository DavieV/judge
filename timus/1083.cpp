#include <iostream>

using namespace std;

int fact(int, int);

int main(void){
	int n;
	string marks;

	cin >> n >> marks;

	int k = marks.size();

	cout << fact(n, k) << endl;
}

int fact(int n, int k){
	if(n - k == 0 || n < k) return n;
	else{
		return n * fact(n - k, k);
	}
}