#include <iostream>

using namespace std;

int main(void){
	int N, K;

	cin >> N >> K;

	int copied = 1, hours = 0, left;

	while(copied < N){
		left = N - copied;
		if(copied < K){ //if the amount of computers with the program is less than the amount of cables
			copied += copied; //the amount of copies made goes up by the amount of computers with the program
			hours++;
		}

		else{
			if(left % K == 0){
				copied += left;
				hours += left / K;
			}
			else{
				copied += left;
				hours += left / K + 1;
			}
		}
	}

	cout << hours << endl;
}