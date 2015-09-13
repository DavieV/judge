#include <iostream>

using namespace std;

int main(void){
	int bills[6];
	int price, tmp, sum = 0;
	for(int i = 0; i < 6; i++){
		cin >> tmp;
		sum += tmp * pow(10, i+1);
		bills[i] = tmp;
	}
	cin >> price;

	int max = sum / price;

}