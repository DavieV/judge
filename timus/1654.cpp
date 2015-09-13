#include <iostream>
#include <string>

using namespace std;

bool hasRepeats(string);

int main(void){
	string cipher;

	getline(cin, cipher);

	int size = cipher.size();
	while(hasRepeats(cipher)){
		for(int i = 0; i < size - 1; i++){
			if(cipher[i] == cipher[i + 1]) cipher.erase(i, 2);
		}
	}

	cout << cipher << endl;
}

bool hasRepeats(string line){
	if(line.size() == 0) return false;
	for(int i = 0; i < line.size() - 1; i++){
		if(line[i] == line[i + 1]) return true;
	}
	return false;
}