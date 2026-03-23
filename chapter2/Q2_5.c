/* Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. */


#include <stdio.h>
#include <limits.h>

int find_pos_c(char s[], char c){
	for (int i =0; s[i] != '\0'; i++){
		if (s[i] == c){
			return i;
		}

	}
	return -1;
}


int min(int a, int b){
	if (a < b){
		return a;
	}
	else{
		return b;
	}
}

int any(char s[], char s2[]){
	int pos = INT_MAX;
	for (int k =0; s2[k] != '\0'; k++){
		pos = min(pos, find_pos_c(s, s2[k]));
	}

	if (pos == INT_MAX){
		return -1;
	}
	else{
		return pos;
	}

}

int main(){
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	char s1[] = "tsr";

	printf("%i\n", any(s, s1));
}