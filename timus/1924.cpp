#include <iostream>

using namespace std;

int main(void){
	int n, total = 0;
	cin>>n;
	for(int i = 1; i <= n; i++){
		total += i;
	}
	if(total % 2 == 0) cout<<"black\n";
	else cout<<"grimy\n";
}