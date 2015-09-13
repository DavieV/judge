#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
	long long tmp;
	int count = 0;
	vector <long long> piles;
	for(int i = 0; i < 3; i++){
		cin >> tmp;
		piles.push_back(tmp);
	}

	long long smallest = 1000000000000000001;

	while(smallest){
		count++;
		sort(piles.begin(), piles.end(), greater<long long>());
		int size = piles.size();
		for(int i = 0; i < size - 1; i++){
			smallest = min(smallest, piles[i] - piles[i+1]);
		}
		piles.push_back(smallest);
	}
	cout << count << endl;
}