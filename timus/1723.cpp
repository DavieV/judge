#include <iostream>
#include <string>

using namespace std;

int occurrences(string, string);

int main(void){
	string master, spell = "", tmp = "";
	int freq = 0, curr;

	cin >> master;

	for(int i = 0; i < master.length(); i++){
		for(int j = 1; j < master.length() - i + 1; j++){
			tmp = master.substr(i, j);
			curr = occurrences(master, tmp);
			//cout << tmp << ": " << curr << endl;
			if(freq < curr){
				freq = curr;
				spell = tmp;
			}
			else if(freq == curr && spell.size() < tmp.size()){
				freq = curr;
				spell = tmp;
			}
		}
	}
	cout << spell << endl;
}

int occurrences(string main, string sub){
	int occur = 0;
	for(int i = 0; i < main.size() - sub.size() + 1; i++){
		if(sub.compare(main.substr(i, sub.size())) == 0) occur++;
	}
	return occur;
}