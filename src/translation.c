#include <stdlib.h>
#include <string.h>
void rotation(char *str){
	int n = strlen(str);
	for (int i = 0; i < n / 2; i++){
		char saved = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = saved;
	}
}

char* translation1(long x){
	char *rvl = malloc(35 * sizeof(char));
	int i = 0;
	while(x != 0){
		rvl[i] = x % 2 + '0';
		x /= 2;
		i++;
	}
	rotation(rvl);
	return rvl;
}

char* translation2(long x){
	char *rvl = malloc(35 * sizeof(char));
	int i = 0;
	while(x != 0){
		rvl[i] = x % 3 + '0';
		x /= 3;
		i++;
	}
	rotation(rvl);
	return rvl;
}

