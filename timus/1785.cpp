#include <iostream>

using namespace std;

int main(void){
	int N;
	cin>>N;
	if(N <= 4) cout<<"few\n";
	else if(N <= 9) cout<<"several\n";
	else if(N <= 19) cout<<"pack\n";
	else if(N <= 49) cout<<"lots\n";
	else if(N <= 99) cout<<"horde\n";
	else if(N <= 249) cout<<"throng\n";
	else if(N <= 499) cout<<"swarm\n";
	else if(N <= 999) cout<<"zounds\n";
	else cout<<"legion\n";
}