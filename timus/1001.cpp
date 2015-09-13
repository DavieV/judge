#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void){
	double tmp;
	vector <double> nums;

	while(cin >> tmp){
		nums.push_back(tmp);
	}

	for(int i = nums.size() - 1; i >= 0; i--){
		cout << fixed << setprecision(4) << sqrt(nums[i]) << endl;
	}
}