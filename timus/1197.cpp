#include <iostream>
#include <stdio.h>

using namespace std;

int validMoves(int, int);

int main(void){
	int cases;
	cin>>cases;
	char coords[2];
	for(int i = 0; i < cases; i++){
		scanf("%s", coords);
		int x = (coords[0] - 'a') + 1;
		int y = (coords[1] - '0');
		cout<<validMoves(x, y)<<endl;
	}
}

int validMoves(int x, int y){
	int moves = 0;
	//moves to the right
	if(x + 2 <= 8 && y + 1 <= 8) moves++;
	if(x + 2 <= 8 && y - 1 >= 1) moves++;
	if(x + 1 <= 8 && y + 2 <= 8) moves++;
	if(x + 1 <= 8 && y - 2 >= 1) moves++;
	//moves to the left
	if(x - 2 >= 1 && y + 1 <= 8) moves++;
	if(x - 2 >= 1 && y - 1 >= 1) moves++;
	if(x - 1 >= 1 && y + 2 <= 8) moves++;
	if(x - 1 >= 1 && y - 2 >= 1) moves++;
 	return moves;
}