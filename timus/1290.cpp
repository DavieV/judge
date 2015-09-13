#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add1(int [], int n);

int main(void){
	int n, tmp;
	vector <int> nums;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());

	for(int i = nums.size() - 1; i >= 0; i--){
		cout << nums[i] << endl;
	}
}