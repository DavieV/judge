#include <iostream>

using namespace std;

bool isLucky(int);

int main(void){
	int n;
	cin >> n;
	if(isLucky(n + 1)) cout << "Yes\n";
	else if(isLucky(n - 1)) cout << "Yes\n";
	else cout << "No\n";
}

bool isLucky(int ticket){
	int first = 0, last = 0;
	for(int i = 0; i < 6; i++){
		if(i < 3){
			last += ticket % 10;
			ticket /= 10;
		}
		else{
			first += ticket % 10;
			ticket /= 10;
		}
	}
	if(first == last) return true;
	else return false;
}