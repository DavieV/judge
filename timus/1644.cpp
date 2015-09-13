#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n, tmp, minsat = 10, maxhung = 2;
	string feel;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp >> feel;
		if(feel == "satisfied"){
			if(tmp < minsat) minsat = tmp;
		}
		else{
			if(tmp > maxhung) maxhung = tmp;
		}
	}
	if(minsat <= maxhung) cout << "Inconsistent\n";
	else cout << minsat << endl; 
}