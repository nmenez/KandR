/* Exercise 4-11. Modify getop so that it doesn't need to use ungetchar. Hint: use an internal
static variable. */


#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'

static  int last_char = 0;
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;

	if (last_char == 0){
		c = getchar();
	}
	else{
		c = last_char;
		last_char = 0;
	}

	while ((s[0] = c) == ' ' || c == '\t')
		c = getchar();

	s[1] = '\0';
	if (!isdigit(c) && c != '.') /* not a number */
		return c;

		i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getchar()))
			;

	if (c == '.')/* collect fraction part */
		while (isdigit(s[++i] = c = getchar()))
			;


	s[i] = '\0';
	if (c != EOF)
		last_char = c;

	printf("here\n");

	return NUMBER;

}