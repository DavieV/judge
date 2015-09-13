#include <iostream>

using namespace std;

int main(void){
	int n, k, tmp1, tmp2, sum1 = 0, sum2 = 0;
	cin >> n >> k;
	sum1 += k;
	for(int i = 0; i < n; i++){
		cin >> tmp1 >> tmp2;
		sum1 += tmp1;
		sum2 += tmp2;
	}

	int dif = 2 * (n + 1);
	int target = sum1 - dif;
	if(target - sum2 > 0) cout << target - sum2 << endl;
	else cout << "Big Bang!\n";
}