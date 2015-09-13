#include <iostream>

using namespace std;

bool isHamming(int [7]);

int main(void){
	int nums [7], tmp;

	for(int i = 0; i < 7; i++){
		cin >> tmp;
		nums[i] = tmp;
	}

	for(int i = 0; i < 7; i++){
		if(isHamming(nums)) cout << nums[i] << " ";
		else if(nums[i] == 0){
			nums[i] = 1;
			if(isHamming(nums)) cout << nums[i] << " ";
			else{
				nums[i] = 0;
				cout << nums[i] << " ";
			}
		}
		else{
			nums[i] = 0;
			if(isHamming(nums)) cout << nums[i] << " ";
			else{
				nums[i] = 1;
				cout << nums[i] << " ";
			}
		}
	}
	cout << endl;
}

bool isHamming(int nums[7]){
	int sum1 = nums[0] + nums[1] + nums[3], sum2 = nums[0] + nums[2] + nums[3], sum3 = nums[1] + nums[2] + nums[3];
	if(sum1 % 2 == nums[6] && sum2 % 2 == nums[5] && sum3 % 2 == nums[4]) return true;
	else return false;
}