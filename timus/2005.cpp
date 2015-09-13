#include <iostream>

using namespace std;

int smallest(int, int, int, int);

int main(void){
	int nums[25];
	int tmp, sum1, sum2, sum3, sum4;
	for(int i = 0; i < 25; i++){
		cin >> tmp;
		nums[i] = tmp;
	}
	sum1 = nums[1] + nums[7] + nums[13] + nums[19];
	sum2 = nums[2] + nums[11] + nums[8] + nums[19];
	sum3 = nums[2] + nums[13] + nums[16] + nums[9];
	sum4 = nums[3] + nums[17] + nums[11] + nums[9];

	int min = smallest(sum1, sum2, sum3, sum4);

	cout << min << endl;
	if(min == sum1) cout << "1 2 3 4 5\n";
	else if(min == sum2) cout << "1 3 2 4 5\n";
	else if(min == sum3) cout << "1 3 4 2 5\n";
	else cout << "1 4 3 2 5\n";
}

int smallest(int a, int b, int c, int d){
	return (((a < b) ? a : b) < ((c < d) ? c : d)) ? ((a < b) ? a : b) : ((c < d) ? c : d);
}