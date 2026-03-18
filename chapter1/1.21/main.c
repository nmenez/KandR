/*  Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference? */

#include <stdio.h>
#define TAB '#'
#define SPACE  ' '
#define TABSTOP 8


int main(){
	int c;
	int column = 0;
	int space_count = 0;

	while((c=getchar()) != EOF){
		if (c == SPACE){
			space_count++;
			column++;

			if (column % TABSTOP == 0){
				putchar(TAB);
				space_count = 0;
			}
		} else {
			while (space_count > 0 ){
				putchar(' ');
				space_count --;
			}


			if (c == '\n'){
				space_count = 0;
				column = 0;
			}
			else{
				column++;
			}

			putchar(c);

		}

	}

	return 0;
}