#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void classify(int log_n, int n){
	int ERROR_NUMBER = 9;
	int got_error = 0;
	int q = n;
	while(q != 0){
		int digit = q % 10;
		q /= 10;
		if(digit == ERROR_NUMBER){
			fprintf(stderr, "log #%d: %d\n", log_n, n);
			got_error = 1;
			break;
		}
	}
	if(!got_error){
		printf("log #%d: %d\n", log_n, n);
	}
}

int main(void){
	srand(time(0));		// initialize the random number generator
	for(int i=0; i<10000; i++){
		classify(i, rand());
	}
}

