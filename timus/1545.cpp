#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
	int n;
	string tmp;
	vector <string> words;
	char first;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		words.push_back(tmp);
	}

	cin >> first;

	for(int i = 0; i < n; i++){
		if(first == words[i][0]) cout << words[i] << endl;
	}
}