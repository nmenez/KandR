/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */

#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000


int getline2(char s[],int lim){
	int c, i;

	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
		s[i] = c;
	}

	s[i] = '\0';
	return i;
}

int htoi(char s[], int len){
	int starting_i = 0;
	int result = 0;
	char c;
	char offset;

	if ((len >= 2) && (s[0] == '0') && (s[1] == 'x')){
		starting_i = 2;
	}

	for (int i= starting_i; i < len; i ++){

		c = s[i];
		if ((c >= '0') && (c <='9'))
		{
			offset = '0';
		}
		else if ((c >= 'a')  && ( c <='f')){
			offset = 'a' - 10; 
		}
		else if ((c >='A') && ( c <= 'F')){
			offset = 'A' - 10;
		}
		else{
			printf("invalid \n");
			return INT_MIN;
	
		}

		result = result * 16 + (c - offset);
	}

	return result;
}



int main(){
	int len;
	int result;
	char string[MAXLINE];

	while ((len = getline2(string, MAXLINE)) > 0){
		result = htoi(string, len);
		printf("%s -> %i\n", string, result);
	}

}