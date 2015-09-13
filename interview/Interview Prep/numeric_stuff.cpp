#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
constexpr T max_val();
long reverse(long);
void fib(int);
int age_occurances(std::vector<int>, int start);
void non_zero(std::vector<int>&);


int main(){
	/*std::cout << max_val<short>() << std::endl;
	std::cout << max_val<long>() << std::endl;

	std::cout << reverse(981) << std::endl;*/

	std::vector<int> ages{8, 8, 8, 9, 9, 11, 15, 16, 16, 16};
	int offset = age_occurances(ages, 0);
	while(offset < ages.size())
		offset = age_occurances(ages, offset);

	//fib(90);

	std::vector<int> test{8, 8, 8, 9, 0, 9, 11, 15, 0, 16, 16, 16};
	non_zero(test);
	for(auto i : test)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}

void non_zero(std::vector<int>& v){
	std::partition(v.begin(), v.end(), [](int x){ return x != 0; });
}

int age_occurances(std::vector<int> ages, int start){
	int start_val = ages[start];
	int offset = start + 1;
	while(ages[offset] == start_val)
		offset++;
	std::cout << start_val << ":" << offset - start << std::endl;
	return offset;
}

void fib(int n){
	int n1 = 0, n2 = 1, cur = 0;
	while(cur < n){
		cur = n1 + n2;
		std::cout << cur << std::endl;
		n1 = n2;
		n2 = cur;
	}
}

long reverse(long n){
	long m = 0;
	while(n > 0){
		m = (10 * m) + (n % 10);
		n /= 10;
	}
	return m;
}

template short max_val<short>();
template int max_val<int>();
template long max_val<long>();
template long long max_val<long long>();

template <typename T>
constexpr T max_val(){
	constexpr unsigned long s = sizeof(T);
	constexpr T x = 0;
	constexpr T one = 1;
	constexpr T none = -1;
	constexpr T eight = 8;
	return ((x | (one << ((s * eight) - one))) + one) * none;
}

