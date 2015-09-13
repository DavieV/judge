#include <iostream>

using namespace std;

int main(void){
	int k, n, tmp, curr = 0;
	cin>>k;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>tmp;
		curr+=tmp;
		curr -= k;
		if(curr < 0) curr = 0;
	}
	cout<<curr<<endl;
}