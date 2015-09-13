#include <iostream>
#include <string>

using namespace std;

bool inString(char, string);

int main(void){
	string p_wind = "AD", p_aisle = "BC", b_wind = "AF", b_aisle = "BCDE", e_wind = "AK", e_aisle = "CDGH";
	string tmp;
	cin >> tmp;
	int row;
	char seat;
	if(tmp.size() == 3){
		row = 10 * (tmp[0] - '0') + tmp[1] - '0';
		seat = tmp[2];
	}

	else{
		row = tmp[0] - '0';
		seat = tmp[1];
	}

	if(row < 3){
		if(inString(seat, p_wind)) cout << "window\n";
		else if(inString(seat, p_aisle)) cout << "aisle\n";
		else cout << "neither\n";
	}

	else if(row < 21){
		if(inString(seat, b_wind)) cout << "window\n";
		else if(inString(seat, b_aisle)) cout << "aisle\n";
		else cout << "neither\n";
	}

	else{
		if(inString(seat, e_wind)) cout << "window\n";
		else if(inString(seat, e_aisle)) cout << "aisle\n";
		else cout << "neither\n";
	}
}

bool inString(char c, string s){
	for(int i = 0; i < s.size(); i++){
		if(c == s[i]) return true;
	}
	return false;
}