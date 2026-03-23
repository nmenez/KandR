/*Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters. */


#include <stdio.h>
int MAXLINE = 1024;


void escape(char s[], char t[]){
	int s_index = 0;
	int t_index = 0;

	while (t[t_index] != '\0'){

		switch (t[t_index]){
			case '\t':
				s[s_index++] = '\\';
				s[s_index++] = 't';
				break;
			
			case '\n':
				s[s_index++] = '\\';
				s[s_index++] = 'n';	
				break;
			default:
				s[s_index] = t[t_index];
				s_index++;
				break;
		}

		t_index++;
	}
	s[s_index] = '\0';
}


void inverse_escape(char s[], char t[]){
	int s_index = 0;
	int t_index = 0;
	while (t[t_index] != '\0'){
		switch (t[t_index]){
			case '\\':
				t_index++;
				switch (t[t_index]){
					case 't':
						s[s_index] = '\t';
						break;
					case 'n':
						s[s_index] = '\n';
						break;
					default:
						s[s_index++] = '\\';
						s[s_index] = t[t_index];

				}
				break;
			default:
				s[s_index] = t[t_index];
				break;
		}
		s_index++;
		t_index++;

	}

}

int main(){
	// char t[] = "ello\t \' world\n";
	char t[] = "a\\bbc\\tb\\n\\n\\ncdab\\n";
	char s[MAXLINE];
	inverse_escape(s, t);
	printf("%s", s);
}