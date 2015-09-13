#include <iostream>
#include <cstdlib>

using namespace std;

int main(void){
	int n;
	cin>>n;
	int pix [n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>pix[i][j];
		}
	}

	int len = (2 * n) - 1, x = 0, y = 0;
	for(int k = 0; k <= len; k++){
		for(int l = k; l >= 0; l--){
			if(l < n && k - l < n){
				cout<<pix[l][k - l]<<" ";
			}
		}
	}
	cout<<endl;
}