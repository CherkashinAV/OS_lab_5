#include <stdio.h>
#include "lib.h"
int main(void){
	int command;
	printf("1 A deltaX to use method 1\n");
	printf("2 A deltaX to use method 2\n");
	while(scanf("%d", &command) != EOF){
		float A, deltaX;
		scanf("%f %f", &A, &deltaX);
		if (command == 1){
			printf("Derivative1 result is: %f\n", Derivative1(A, deltaX));
			fflush(stdout);
		}
		else if (command == 2){
			printf("Derivative2 result is: %f\n", Derivative2(A, deltaX));
			fflush(stdout);
		}
	}
	return 0;
}
