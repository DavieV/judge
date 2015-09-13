#include <iostream>

using namespace std;

int main(void){
	int m, n, area, turn = 0;
	cin>>m;
	cin>>n;
	area = m * n;
	if((area - 1) % 2 == 0) cout<<"[second]=:]\n";
	else cout<<"[:=[first]\n";
}