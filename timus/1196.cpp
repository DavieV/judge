#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n1, n2, tmp;
	vector <int> pList;

	cin >> n1;

	for(int i = 0; i < n1; i++){
		cin >> tmp;
		pList.push_back(tmp);
	}

	cin >> n2;

	int count = 0;
	for(int i = 0; i < n2; i++){
		cin >> tmp;
		if(binary_search(pList.begin(), pList.end(), tmp)) count++;
	}

	cout << count << endl;
}