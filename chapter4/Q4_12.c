 /* Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.*/


#include <stdio.h>
#define MAXLINE 1024
char s[MAXLINE];

int itoa_inner(int s_idx, int n, char s[]){
	/* avoid using n = -n due to min int issue descrbied in earlier problems */
	if ( n<0){
		s[s_idx++] = '-';
		s_idx = itoa_inner(s_idx, n / (-10), s);
	}
	else if (n / 10){
		s_idx =itoa_inner(s_idx, n/ 10, s);	

	}
	int digit = n % 10;
	if (digit < 0){
		digit = -digit;
	} /* can't use abs because stdlib had not been introduced yet */
	s[s_idx] = digit + '0';

	return s_idx +1;

}

void itoa(int n, char s[]){
	int s_idx =itoa_inner(0, n, s);
	s[s_idx] = '\0';

}

int main(){
	int n = -1234;
	int s_idx;
	itoa(n, s);
	printf("%s\n", s);

	return 0;
}