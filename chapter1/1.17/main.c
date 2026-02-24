/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */


#include <stdio.h>
#define MAXLINE 1000
#define PRINTLIMIT 80
int getline2(char s[], int maxline);
void copy(char to[], char from[]); 

int main(){
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0){
		if (len > PRINTLIMIT)
	    	printf("line length %i: %s\n\n", len, line);
	}
	
	
	return 0;

} 

int getline2(char s[], int maxline){
	int c, i;
	for (i=0; i < maxline-1 && (c=getchar())!=EOF && c!='\n'; ++i)
	{	s[i] = c;
	}
	
	if (c == '\n'){
		s[i] = c;
		++i;
		s[i] = '\0';

	}

	else if (c != EOF && c != '\n'){
		while ((c = getchar()) != EOF && c != '\n'){
			++i;
		}
		if (c == '\n')
			++i;

		s[maxline-1] = '\0';
		s[maxline-2] = '\n';

	}

	return i;	
}