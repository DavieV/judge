#include <iostream>
#include <unordered_map>
#include <vector>

int mode(std::vector<int>);
//std::vector<int> largest_k(std::vector<int>, int);

int main(){
	std::vector<int> v = {1,1,1,3,2,7,8,9,9,8,10,11,8,99,8};
	std::cout << mode(v) << std::endl;
	return 0;
}

/*std::vector<int> largest_k(std::vector<int> v, int k){
	std::vector<int> maxs(k);
	for(int i = 0; i < k;)
}*/

int mode(std::vector<int> v){
	int cur_max = 0, occur = 0;
	std::unordered_map<int, int> freq;
	for(auto i : v){
		freq[i]++;
		if(freq[i] > occur){
			occur = freq[i];
			cur_max = i;
		}
	}
	return cur_max;
}