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
		if ((val >= 0) || (val < b)){
			c = val + '0';
		}
		else {
			c = val + 'a';
		}
		printf("%c\n", c);

	
	} while ((n /= 10) != 0);
	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	
	s[i] = '\0';
	reverse(s);
}


int main(){
	int n = 10;
	char s[MAXLINE];
	int b = 8;
	itob(n, s, b);
	printf("%s\n", s);
	return 0 
}