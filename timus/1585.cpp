#include <iostream>
#include <string>

using namespace std;

int main(void){
	int n, p1 = 0, p2 = 0, p3 = 0;
	cin >> n;
	string tmp;
	
	for(int i = 0; i <= n; i++){
		getline(cin, tmp);
		if(tmp.compare("Emperor Penguin") == 0) p1++;
		else if(tmp.compare("Macaroni Penguin") == 0) p2++;
		else p3++;
	}

	int largest = (((p1 > p2) ? p1 : p2) > p3) ? ((p1 > p2) ? p1 : p2) : p3;
	if(p1 == largest) cout << "Emperor Penguin\n";
	else if(p2 == largest) cout << "Macaroni Penguin\n";
	else cout << "Little Penguin";
}