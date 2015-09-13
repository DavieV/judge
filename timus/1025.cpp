#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void lowestSum(vector <int>, int);

int main(void){
	int split;
	vector <int> groups;

	cin >> split;

	int tmp;
	for(int i = 0; i < split; i++){
		cin >> tmp;
		groups.push_back(tmp);
	}

	int majority;
	if(split % 2 == 0) majority = (split / 2) + 1;
	else majority = int(ceil(double(split) / 2));

	lowestSum(groups, majority);
}

void lowestSum(vector <int> groups, int needed){
	int sum = 0;
	int min, pos;
	vector <int> tmp = groups;
	int size = tmp.size();
	for(int i = 0; i < needed; i++){
		min = tmp[0];
		pos = 0;
		for(int j = 0; j < size - i; j++){
			if(tmp[j] < min){
				min = tmp[j];
				pos = j;
			}
		}
		if(min % 2 == 0) sum += (min / 2) + 1;
		else sum += int(ceil(double(min) / 2));
		tmp.erase(tmp.begin() + pos);
	}
	cout << sum << endl;
}