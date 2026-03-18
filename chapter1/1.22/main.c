/* Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. */

#include <stdio.h>
#define MAXLEN 40

void printline(char line[], int start, int end);
int move_remainder(char line[], int blank, int column);
int find_last_blank(char line[], int column);

int main(){
	

	char line[MAXLEN + 1];
	int column = 0;
	int blank_position;
	int c;
	while ((c=getchar()) != EOF){
		if (c == '\n'){
			printline(line, 0, column);
			column = 0;
			continue;
		}

		line[column++] = c;

		if (column >= MAXLEN){
			blank_position = find_last_blank(line, column);
			if (blank_position >= 0){
				printline(line, 0, blank_position);
				column = move_remainder(line, blank_position, column);
			}
			else{
				printline(line, 0, column-1);
				column = 0;
			}
		} 
	}

	if (column > 0){
		printline(line, 0, column);
	}

	return 0;
}

void printline(char line[], int start, int end){
	for (int i = start; i < end; i++){
		// printf("position, char: %i, %c\n\n", i, line[i]);
		putchar(line[i]);
	}
	putchar('\n');
}

int move_remainder(char line[],  int blank, int column){
	int i = 0;
	for (int j = blank+1; j < column; j ++){
		line[i] = line[j];
		i++;
	}
	return i;

}

int find_last_blank(char line[], int column){
	for (int i = column; i>0; i--){
		if ((line[i] == ' ') | (line[i] == '\t')){
			return i;
		}

	}
	return -1;

}
