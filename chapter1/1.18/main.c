/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */

/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text. */


#include <stdio.h>
#include <string.h>
#define MAXLINE 900
#define PRINTLIMIT 80
int getline2(char s[], int maxline);
int removetrailingspace(char s[], int len);

int min(int a, int b){
    if (a > b){
    	return b;	
    }
    else if (b > a){
    	return a;
    }
    else{
    	return a;
    }

}

int main(){
	int len;
	int max;
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0){
		len = removetrailingspace(line, min(len, MAXLINE));
		printf("%s", line);
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



int removetrailingspace(char s[], int len){
	int i = len -1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] =='\0' || s[i] == '\n') &&  (i >=0)) {
		i--;
		printf("i: %i\n", i);
	}
	if (i <  0){
		s[0] = '\0';
	}
	else {
	s[++i] = '\n';
	s[++i] = '\0';
	}
	return i;
}