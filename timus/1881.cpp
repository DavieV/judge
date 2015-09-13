#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
	int h, w, n;
	string tmp;
	vector <string> words;
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		words.push_back(tmp);
	}

	int symbol = 0, line = 0, page = 1;
	for(int i = 0; i < n - 1; i++){
		symbol += words[i].size();
		if(symbol + words[i+1].size() + 1 >= w){
			symbol = 0;
			line++;
		}
		if(line > h){
			page++;
			line = 1;
		}
	}
	cout<<page<<endl;
}