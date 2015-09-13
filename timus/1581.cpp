#include <iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;
	int nums[n];
	for(int i = 0; i < n; i++){
		cin>>nums[i];
	}

	int prev = nums[0], count = 1;
	for(int i = 1; i < n; i++){
		if(prev == nums[i]) count++;
		else{
			cout<<count<<" "<<prev<<" ";
			count = 1;
		}
		prev = nums[i];
	}
	cout<<count<<" "<<prev<<" ";
	cout<<endl;
}