#include <iostream>

using namespace std;

int main(void){
	string cipher, alphabet = "abcdefghijklmnopqrstuvwxyz";
	cin >> cipher;
	int size = cipher.size();
	int nums[size];
	for(int i = 0; i < size; i++){
		nums[i] = cipher[i] - 'a';
	}

	for(int i = 1; i < size; i++){
		while(nums[i] < nums[i-1]){
			nums[i] += 26;
		}
	}

	for(int i = size - 1; i > 0; i--){
		nums[i] = nums[i] - nums[i-1];
	}

	if(nums[0] > 5) nums[0] -= 5;
	else nums[0] += 21;

	for(int i = 0; i < size; i++){
		cout << alphabet[nums[i]];
	}
	cout << endl;
}