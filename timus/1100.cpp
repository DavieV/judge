#include <iostream>

using namespace std;

void swap(int *, int *);

int main(void){
	int n;
	cin >> n;
	int scores[n], ids[n];

	for(int i = 0; i < n; i++){
		cin >> ids[i] >> scores[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = 1; j < n- i; j++){
			if(*(scores + j) > *(scores + j - 1)){
				swap(scores + j, scores + j - 1);
				swap(ids + j, ids + j - 1);
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << ids[i] << " " << scores[i] << endl;
	}
}

void swap(int * x, int * y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}