#include <iostream>
#include <string>

using namespace std;

bool inString(char, string);

int main(void){
	string one, two, three, line;
	int cost = 0;
	one = "adgjmpsvy. ";
	two = "behknqtwz,";
	three = "cfilorux!";
	getline(cin, line);
	for(int i = 0; i < line.size(); i++){
		if(inString(line[i], one)) cost++;
		else if(inString(line[i], two)) cost += 2;
		else if(inString(line[i], three)) cost += 3;
	}
	cout<<cost<<endl;
}

bool inString(char c, string s){
	for(int i = 0; i < s.size(); i++){
		if(c == s[i]) return true;
	}
	return false;
}