/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally. */

#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1024

unsigned int expand_inner(char start, char end, unsigned int s2_index, char s2[]){
	char iterator = ++start;
	while (iterator < end){
		s2[s2_index++] = iterator++;

	}
	return s2_index;
}

int isdescending(char a, char b){
	return a < b;
}

int issameclass(char start, char end){
	return ((islower(start) && (islower(end))) || ((isupper(start) && isupper(end))) || (isdigit(start) && (isdigit(end))));

}

int iswindow(unsigned int s1_index, char s1[]){
	char start;
	char end;
	if ((s1_index == 0) || (s1[s1_index + 1] == '\0')){
		return 0;
	}

	start = s1[s1_index - 1];
	end = s1[s1_index + 1];

	return (isdescending(start, end) && (s1[s1_index] == '-') && (issameclass(start, end)));
		 
}

void expand(char s1[], char s2[]){
	unsigned int s1_index = 0;
	unsigned int s2_index = 0;

	while (s1[s1_index] != '\0'){
		if (iswindow(s1_index, s1)){
			s2_index = expand_inner(s1[s1_index - 1], s1[s1_index +1], s2_index, s2);

		}
		else{
			s2[s2_index++] = s1[s1_index];
		}
		s1_index++;

	}
	s2[s2_index] = '\0';
}

int main(){
	char s1[] = "-a-z0-6-";
	char s2[MAXLINE];

	expand(s1, s2);
	printf("%s\n", s2);


}
