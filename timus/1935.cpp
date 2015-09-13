#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n, tmp, total = 0;
	vector <int> sheets;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		sheets.push_back(tmp);
	}

	sort(sheets.begin(), sheets.end());


	int size = sheets.size();
	total += 2 * sheets[size - 1];
	for(int i = size - 2; i >= 0; i--){
		total += sheets[i];
	}
	cout << total << endl;
}