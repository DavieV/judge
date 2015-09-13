#include <iostream>

using namespace std;

int main(void){
	string tmp, msg = "";
	bool flag = true;
	while(getline(cin, tmp)) msg += tmp + '\n';
	int size = msg.size();
	for(int i = 0; i < size; i++){
		if(msg[i] >= 65 && msg[i] <= 90 && flag == true) flag = false;
		else if(msg[i] == '.' || msg[i] == '!' || msg[i] == '?') flag = true;
		else if(msg[i] >= 65 && msg[i] <= 90 && flag == false) msg[i] = tolower(msg[i]);
	}
	cout << msg;
}