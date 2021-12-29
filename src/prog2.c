#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef enum lib_type{
	DERIVATIVE,
	TRANSLATION
} lib_type;

void reverse_type(lib_type *type){
	if (*type == DERIVATIVE)
		*type = TRANSLATION;
	else 
		*type = DERIVATIVE;
	return;
}

void help(){
	printf("Input 1 to use method 1\n");
	printf("Input 2 to use method 2\n");
	printf("Input 0 to change lib\n"); 
}

int main(){
	lib_type type = DERIVATIVE;
	void *handle1 = dlopen("libderivative.so", RTLD_LAZY);
	if (!handle1){
		perror("dlopen1 error");
		exit(-1);
	}
	void *handle2 = dlopen("libtranslation.so", RTLD_LAZY);
	if (!handle1){
		perror("dlopen1 error");
		exit(-1);
	}
	float(*fun11)(float A, float deltaX) = dlsym(handle1, "Derivative1");
	float(*fun12)(float A, float deltaX) = dlsym(handle1, "Derivative2");
	char*(*fun21)(long x) = dlsym(handle2, "translation1");
	char*(*fun22)(long x) = dlsym(handle2, "translation2");
	int command;
	while (scanf("%d", &command) != EOF){
		if (command == 1){
			if (type == DERIVATIVE){
				printf("Type A and deltaX: ");
				float A, deltaX;
				scanf("%f %f", &A, &deltaX);
				printf("Result of Derivative1: %f\n", (*fun11)(A, deltaX));
			}
			else if (type == TRANSLATION){
				printf("Type x: ");
				long x;
				scanf("%ld", &x);
				printf("Result of translation1: %s\n", (*fun21)(x));
			}
		}
		else if (command == 2){
			if (type == DERIVATIVE){
				printf("Type A and deltaX: ");
				float A, deltaX;
				scanf("%f %f", &A, &deltaX);
				printf("Result of Derivative2: %f\n", (*fun12)(A, deltaX));
			}
			else if (type == TRANSLATION){
				printf("Type x: ");
				long x;
				scanf("%ld", &x);
				printf("Result of translation1: %s\n", (*fun22)(x));
			}
		}
		else if (command == 0){
			reverse_type(&type);
			printf("Lib has been changed\n");
		}
	}

}
