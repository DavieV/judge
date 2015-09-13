#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main(void){
	int n;
	string tmp;
	vector <string> names;
	vector <string> teams;
	vector <int> nums;

	cin >> n;

	for(int i = 0; i < n; i++){
		readLine(cin, tmp);
		teams.push_back(tmp);
	}
}