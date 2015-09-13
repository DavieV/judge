#include <iostream>

using namespace std;

int main(void){
	long long n, a, p = 0, sum;
	int flag=0;
	cin >> n;
	for(int i = 0; i < n / 2; i++){
		sum = 0;
		int terms = 0;
		sum = (i * (i + 1)) / 2;
		terms = i + 1;
		if((n - sum) % terms == 0 && sum < n){
			if(terms > p){
				p = terms;
				a = (n - sum) / terms;
			}
		} 
	}
	cout << a << " " << p << " " << sum << endl;
}