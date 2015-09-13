#include <iostream>

using namespace std;

int main(void){
	int N;
	int sum = 0;
	cin>>N;
	if(N < 1){
		for(int i = 1; i >= N; i--) sum += i;
	}
	else{
		for(int i = 1; i <= N; i++) sum += i;
	}
	cout<<sum<<endl;
}