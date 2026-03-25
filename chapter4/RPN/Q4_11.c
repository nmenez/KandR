#include<stdio.h>
#define MAXOPS 128
int getop(char []);


int main(){

	int type;
	char s[MAXOPS];

	while ((type = getop(s)) != EOF){
		printf("type: %c, val %s\n", type, s);
	} 

	// type = getop(s);
	// printf("type: %c, val %s\n", type, s);

	// type = getop(s);
	// printf("type: %c, val %s\n", type, s);

	return 0;
}