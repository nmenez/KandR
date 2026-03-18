/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter? */

#include <stdio.h>
#define TAB '\t'
#define TABSTOP 4
#define SPACE '#'

int main(){

	int column = 0;
	int spaces;
	int c; 

	while ((c=getchar()) != EOF){

		if (c == TAB){
			spaces = TABSTOP - (column % TABSTOP);
			while (spaces > 0 ){
				putchar(SPACE);
				column++;
				spaces--;
			}


		} else if (c == '\n'){
			putchar(c);
			column = 0;
		} else{
			putchar(c);
			column++;
		}

	}
	return 0;
}

