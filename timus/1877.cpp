#include <iostream>
#include <string>

using namespace std;

int main(void){
	string str1, str2;
	int combo1, combo2;
	cin>>str1;
	cin>>str2;
	combo1 = stoi(str1);
	combo2 = stoi(str2);
	if(combo1 % 2 == 0 || combo2 % 2 != 0) cout<<"yes\n";
	else cout<<"no\n";
}