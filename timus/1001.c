#include <stdio.h>
#include <math.h>

#define MAX 100000

int main(){
	double entries[MAX];
	int i = 0;
	while(scanf("%lf", &entries[i]) != -1){
		i++;
	}
	int len = i;
	for(int j = len - 1; j >= 0; j--){
		printf("%.4lf\n", sqrt(entries[j]));
	}
	return 0;
}