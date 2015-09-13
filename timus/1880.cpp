#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int tmp1, tmp2, eig = 0;
	vector <int> v1, v2, v3;
	cin>>tmp1;
	for(int i = 0; i < tmp1; i++){
		cin>>tmp2;
		v1.push_back(tmp2);
	}

	cin>>tmp1;
	for(int j = 0; j < tmp1; j++){
		cin>>tmp2;
		v2.push_back(tmp2);
	}

	cin>>tmp1;
	for(int k = 0; k < tmp1; k++){
		cin>>tmp2;
		v3.push_back(tmp2);
	}

	for(auto x:v1){
		if(find(v2.begin(), v2.end(), x) != v2.end() && find(v3.begin(), v3.end(), x) != v3.end()) eig++;
	}
	cout<<eig<<endl;
}