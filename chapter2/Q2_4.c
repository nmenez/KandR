/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2. */

#include <stdio.h>


void squeeze_inner(char s[], int c){
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++){
		printf("i: %i, j: %i\n", i, j);

		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}


void squeeze(char s[], char s2[]){
	
	for (int k=0; s2[k] != '\0'; k++){
		squeeze_inner(s, s2[k]);
	}
}

int main(){
	char s[] = "hello world";
	char s2[] = "hello";
	squeeze(s, s2);
	printf("%s\n", s);
	
}