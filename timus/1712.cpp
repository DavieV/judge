#include <iostream>

using namespace std;

void turn(int [4][4]);

int main(void){
	char tmp;
	char cipher[4][4];
	int window[4][4];

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cin >> tmp;
			if(tmp == 'X') window[i][j] = 1;
			else window[i][j] = 0;
		}
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cin >> tmp;
			cipher[i][j] = tmp;
		}
	}

	for(int k = 0; k < 4; k++){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(window[i][j] == 1) cout << cipher[i][j];
			}
		}
		turn(window);
	}
	cout << endl;

}

void turn(int grid[4][4]){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(grid[i][j] == 1 && grid[3-j][i] != -1){ //check if this coord was just swapped
				grid[j][3-i] = 1;
				grid[i][j] = -1;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(grid[i][j] == -1) grid[i][j] = 0;
		}
	}
}