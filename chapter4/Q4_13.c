/* Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place. */


#include<stdio.h>
#include<string.h>


void reverse_inner(char s[], int first, int last){
	if (first >= last){
		return;
	}

	char temp = s[first];
	s[first] = s[last];
	s[last] = temp;

	reverse_inner(s, first+1, last-1);

}


void reverse(char s[]){
	int last = strlen(s) - 1;
	reverse_inner(s, 0, last);
}



int main(){
	char s[] = "abcdefghijklmnopqrstuvwxyz";

	reverse(s);

	printf("%s\n", s);
}