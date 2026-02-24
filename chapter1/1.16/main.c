/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text. */


#include <stdio.h>
#define MAXLINE 32
int getline2(char s[], int maxline);
void copy(char to[], char from[]); 

int main(){
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0){
	     printf("line length %i showing string up to maxlen: %s\n\n", len, line);
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


void copy(char to[], char from[]){
	int i;
    i = 0;
    while (from[i] != '\0'){
    	to[i] = from[i];
    	i++;
    }
    to[i] = '\0';
    
}