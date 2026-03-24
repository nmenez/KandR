/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/


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
void itoa(int n, char s[], int min_width){
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
	

	while (i < min_width){
		s[i++] = 's'; // use 's' to mark a space so it's easier to verify
	}
	s[i] = '\0';
	reverse(s);
}

int MAXLINE = 1024;
int main(){
	char s[MAXLINE];
	int n = 102;
	
	itoa(123456, s, 7);
	printf("%s\n", s);

}