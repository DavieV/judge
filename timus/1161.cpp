#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void){
	int n, tmp;
	vector <double> nums;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());

	int size = nums.size();
	double out = nums[size-1];
	for(int i = size - 2; i >= 0; i--){
		out = 2 * sqrt(out * nums[i]);
	}
	cout << fixed << setprecision(2) << out << endl;
}