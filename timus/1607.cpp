#include <iostream>

using namespace std;

int main(void){
	int a, b, c, d, count = 0;
	cin >> a >> b >> c >> d;
	if(c < a) cout << a << endl;
	else{
		while(true){
			if(count % 2 == 0){
				if(a + b > c){
					cout << c << endl;
					break;
				}
				else{
					a += b;
					count++;
				}
			}
			else{
				if(c - d < a){
					cout << a << endl;
					break;
				}
				else{
					c -= d;
					count++;
				}
			}
		}
	}
}