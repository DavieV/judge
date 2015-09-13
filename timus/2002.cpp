#include <iostream>
#include <map>

using namespace std;

int main(void){
	int n;
	string action, name, password;
	map < string, pair<string, bool> > users;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> action;

		if(action == "register"){
			cin >> name >> password;
			if(users.empty() || users.find(name) == users.end()){
				users[name] = make_pair(password, false);
				cout << "success: new user added\n";
			}
			else cout << "fail: user already exists\n";
		}

		else if(action == "login"){
			cin >> name >> password;
			if(users.find(name) != users.end()){
				if(users[name].first == password){
					if(users[name].second == false){
						users[name].second = true;
						cout << "success: user logged in\n";
					}
					else cout << "fail: already logged in\n";
				}
				else cout << "fail: incorrect password\n";
			}
			else cout << "fail: no such user\n";
		}
		else{
			cin >> name;
			if(users.find(name) != users.end()){
				if(users[name].second == true){
					users[name].second = false;
					cout << "success: user logged out\n";
				}
				else cout << "fail: already logged out\n";
			}
			else cout << "fail: no such user\n";
		}
	}
}