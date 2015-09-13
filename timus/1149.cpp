#include <iostream>
#include <string>

using namespace std;

string AsubN(int, int);
string SsubN(int, int);
string rBrackets(int);
string lBrackets(int);

int main(void){
	int n;
	cin >> n;
	//cout << AsubN(n, 1) << endl;
	cout << SsubN(n, 1) << endl;
}

string AsubN(int n, int count){
	string cStr = to_string(count);
	if(count == n) return "sin(" + cStr + rBrackets(n);

	else{
		if(count % 2 == 0) return "sin(" + cStr + "+" + AsubN(n, count + 1);
		else return "sin(" + cStr + "-" + AsubN(n, count + 1);
	}
}

string SsubN(int n, int count){
	string cStr = to_string(count);
	if(count == n) return lBrackets(n - 1) + AsubN(1, 1) + "+" + cStr + ")";

	else{
		if(count == 1)	return SsubN(n, count + 1) + AsubN(n - (count - 1), 1) + "+" + cStr;
		else return SsubN(n, count + 1) + AsubN(n - (count - 1), 1) + "+" + cStr + ")";
	}
}

string rBrackets(int n){
	string tmp = "";
	for(int i = 0; i < n; i++){
		tmp = tmp + ")";
	}
	return tmp;
}

string lBrackets(int n){
	string tmp = "";
	for(int i = 0; i < n; i++){
		tmp = tmp + "(";
	}
	return tmp;
}