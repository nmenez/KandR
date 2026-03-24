/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.
*/

#include <string.h>
#include <stdio.h>

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


int MAXLINE = 1024;

void itob(int n, char s[], int b){
	int i, sign, val;
	char c;


	sign =  n < 0? -1 : 1;
	i = 0;
	do {
	/* generate digits in reverse order */
		val = sign * (n % b);/* get next digit */
		if ((val >= 0) && (val < 10)){
			c = val + '0';
		}
		else {
			c = (val - 10) + 'a';
		}
		
		s[i++] = c;
	
	} while ((n /= b) != 0);
	if (sign < 0)
		s[i++] = '-';
	
	s[i] = '\0';
	reverse(s);
}


int main(){

	char s[MAXLINE];
	int b = 16;
	for (int i = -b*2; i<=2*b; i ++){
		itob(i, s, b);
		printf("%i %s\n", i, s);
	}

	return 0 ;
}