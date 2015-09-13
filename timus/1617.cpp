#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numWheels(vector <int>, int);

int main(void){
	int n, tmp;
	vector <int> diameters;
	vector <int> wheels;
	
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		wheels.push_back(tmp);
		if(find(diameters.begin(), diameters.end(), tmp) == diameters.end()) diameters.push_back(tmp);
	}

	int cars = 0;

	for(int i = 0; i < diameters.size(); i++){
		cars += numWheels(wheels, diameters[i]) / 4;
	}

	cout << cars << endl;
}

int numWheels(vector <int> wheels, int diam){
	int num = 0;
	for(int i = 0; i < wheels.size(); i++){
		if(diam == wheels[i]) num++;
	}
	return num;
}