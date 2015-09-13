#include <iostream>
#include <algorithm>
#include <cassert>
#include <random>
#include <vector>

template <typename T>
void merge(T, T, T, T, T c);
template <typename T, typename Pred>
T _partition(T, T, Pred);
template <typename T, typename Pred>
bool is_paritioned(T, T, Pred);
template <typename T>
T r_select(T first, T last, int);

std::vector<int> rand_vector(int);

int main(){
	// Merging 2 sorted sequences
	srand(time(NULL));
	auto a = rand_vector(1000);
	auto b = rand_vector(1000);
	std::vector<int> c(a.size() + b.size());
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	assert(std::is_sorted(c.begin(), c.end()));
	// end of merging

	//Paritioning a sequence
	auto d = rand_vector(1000);
	int at = rand();
	_partition(d.begin(), d.end(), [&](int x) { return x <= at; });
	assert(is_paritioned(d.begin(), d.begin(), [&](int x) { return x <= at; }));

	std::vector<int> f {3, 8, 2, 5, 1, 4, 7, 6};
	auto g = _partition(f.begin(), f.end(), [](int x){ return x <= 3; });
	assert(is_paritioned(f.begin(), f.end(), [](int x) { return x <= 3; }));
	// end of paritioning

	// order stats
	//auto x = r_select(f.begin(), f.end(), 1);
	//std::cout << *x << std::endl;

	return 0;
}

template <typename T>
T r_select(T first, T last, int i){
	int size = first - last;
	if(size == 1) return first;
	int offset = rand() % size;
	int pivot = *(first + offset); // random pivot value
	int j = _partition(first, last, pivot);
	if(j == i) return first + offset;
	if(j > i) return r_select(first, first + j, i);
	else return r_select(first + j, last, i - j);
}

// Generates a random vector of maximum size m (may be smaller)
std::vector<int> rand_vector(int m){
	int s = rand() % m;
	std::vector<int> v;
	for(int i = 0; i < s; i++)
		v.push_back(rand());
	return v;
}

// Given 2 sets of iterators to sorted data this function will store the merged result in C
template <typename T>
void merge(T first1, T last1, T first2, T last2, T result){
	while(first1 < last1 && first2 < last2){ // Go until we reach the end of one list
		if(*first1 < *first2){ // find the smaller of the 2 and insert it into the result
			*result = *first1;
			first1++;
		}
		else{
			*result = *first2;
			first2++;
		}
		result++;
	}
	while(first1 < last1){ // For the list we havent reached the end of yet, fill the rest
		*result = *first1;
		first1++;
		result++;
	}
	while(first2 < last2){
		*result = *first2;
		first2++;
		result++;
	}
}

template <typename T, typename Pred>
T _partition(T first, T last, Pred p){
	while(first < last){
		while(p(*first)) first++;
		do{
			last--;
		} while(!p(*last));
		if(first > last) break;
		std::swap(*first, *last);
		first++;
	}
	return first;
}

template <typename T, typename Pred>
bool is_paritioned(T first, T last, Pred p){
	bool satisfies = true;
	while(first != last){
		if(!p(*first)) satisfies = false;
		if(!satisfies && p(*first)) return false;
		first++;
	}
	return true;
}
