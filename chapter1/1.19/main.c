/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time. */


#include <stdio.h>
int getline2(char s[], int maxline);
void reverse(char s[]);
#define MAXLINE 900

int main(){
	char s[MAXLINE];
	int len; 

	while ((len = getline2(s, MAXLINE)) > 0 ){
		printf("%s\n", s);	
		reverse(s);
		printf("reversed %s\n", s);
	}
	
	
	
	return 0;
}


void reverse(char s[]){
	int len = 0;
	char temp;
	int i;
	int j;

	while (s[len] != '\0' && s[len] != '\n') 
		len++;

	for (i=0, j=len-1; i < j; i++, j--){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}



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
