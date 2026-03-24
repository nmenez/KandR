#include <stdio.h>
#include <string.h>
#include <limits.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
	int i, sign;
	sign =  n < 0? -1 : 1;
	i = 0;
	do {
	/* generate digits in reverse order */
		s[i++] = sign * (n % 10) + '0';/* get next digit */
	
	} while ((n /= 10) != 0);
	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	
	s[i] = '\0';
	reverse(s);
}

int MAXLINE = 1024;
int main(){
	// char s[] = "hello world\n";
	char s[MAXLINE];
	int n = INT_MIN;
	
	itoa(n, s);
	printf("%s\n", s);

}