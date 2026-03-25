/* Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none. */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline2(char line[], int max);
int strindex(char s[], char t[])
{	
	int i, j, k;
	int rightmost_index = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			if (i > rightmost_index)
				rightmost_index = i;
	}
	return rightmost_index;
}

char pattern[] = "ould";

int main(){
	char line[MAXLINE];
	int found = 0;
	int index;
	while (getline2(line, MAXLINE) > 0)
		if ( (index = strindex(line, pattern)) >= 0) {
			printf("index: %i ", index);
			printf("%s", line);
			found++;
		}
	printf("\n");
	return found;
}