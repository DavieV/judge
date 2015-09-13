#include <iostream>
#include <vector>

using namespace std;

void largest(vector <int>);

int main(void){
	int len, tmp;
	vector <int> nums;
	cin>>len;
	for(int i = 0; i < len; i++){
		cin>>tmp;
		nums.push_back(tmp);
	}
	largest(nums);
}

void largest(vector <int> nums){
	int large = 0, pos = 1;
	for(int i = 1; i < nums.size() - 1; i++){
		if(nums[i - 1] + nums[i] + nums[i + 1] > large) {
			large = nums[i - 1] + nums[i] + nums[i + 1];
			pos = i;
		}
	}
	cout<<large<<" "<<pos + 1<<endl;
}