#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_perfect_square(long long);

int main(void){
	long long n, tmp;
	vector <long long> nums;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>tmp;
		nums.push_back(tmp);
	}

	for(int i = 0; i < n; i++){
		if(is_perfect_square((8 * nums[i]) - 7)) cout<<1<<" ";
		else cout<<0<<" ";
	}
	cout<<endl;
}

bool is_perfect_square(long long n) {
    if (n < 0)
        return false;
    long long root(round(sqrt(n)));
    return n == root * root;
}