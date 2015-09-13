#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	vector <string> stores;
	string tmp;

	cin >> n;
	getline(cin, tmp); //clear the buffer;
	int freq = 0;

	for(int i = 0; i < n; i++){
		getline(cin, tmp);
		if(find(stores.begin(), stores.end(), tmp) != stores.end()) freq++;
		else stores.push_back(tmp);
	}

	cout << freq << endl;
}