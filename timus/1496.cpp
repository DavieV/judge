#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isSpammer(string name, vector <string>);

int main(void){
	int n; 
	string tmp;
	vector <string> names;
	vector <string> submissions;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		submissions.push_back(tmp);
		if(find(names.begin(), names.end(), tmp) == names.end()) names.push_back(tmp);
	}

	for(int i = 0; i < names.size(); i++){
		if(isSpammer(names[i], submissions)) cout << names[i] << endl;
	}
}

bool isSpammer(string name, vector <string> submissions){
	int occurences = 0;
	for(int i = 0; i < submissions.size(); i++){
		if(name.compare(submissions[i]) == 0) occurences++;
	}
	if(occurences > 1) return true;
	else return false;
}