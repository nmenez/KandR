#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNCTION 'f'
#define VARIABLE 'x'

int getop(char []);
void push(double);
double pop(void);
void peak(void);
void duplicate_top(void);
void swap(void);
void clear_stack(void);
int getline2(char s[], int lim);

/* reverse Polish calculator */
int RPC(){
	int type;
	double op2;
	char s[MAXOP];
	double variables[26];
	int variables_index;
	int last_var = -1;

	while ((type = getop(s)) != EOF) {
		// printf("type %c. op %s\n", type,  s);
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;

			case '+':
				push(pop() + pop());
				break;

			case '*':
				push(pop() * pop());
				break;

			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
	
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;

			// Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
			//the modulus (%) operator and provisions for negative numbers. */
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push( (int) pop() % (int) op2);
				else
					printf("error: zero divisor\n");
				break;

			case '\n':
				printf("\t%.8g\n", pop());
				break;

			case FUNCTION:
				/* Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4. */
				if (strcmp("sin", s) == 0){

					push(sin(pop()));
				}
				else if (strcmp("cos", s) == 0){

					push(sin(pop()));
				}
				else if (strcmp("pow", s) == 0){
					op2 = pop();
					push(pow(pop(), op2));
				}
				else if (strcmp("exp", s) == 0){
					push(exp(pop()));
				}
				else if (strcmp("peak", s) == 0){
					printf("peaking top value ");
					peak();
				}
				else if (strcmp("duplicate", s) == 0){
					duplicate_top();
				}
				else if (strcmp("swap", s) == 0){
					printf("swapping top two values in stack\n");
					swap();
				}
				else if (strcmp("clear", s) == 0){
					printf("clearing stack\n");
					clear_stack();
				}
				else{
					printf("error: unimplemented function %s\n", s);
				}

				break;

			//Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
			//with single-letter names.) Add a variable for the most recently printed value.

			case '=':
				pop(); //remove last variables. either it's garbage or its being overwritten
				variables[last_var] = pop();
				printf("assigning variable %f\n", variables[last_var]);
				break;

			case VARIABLE:
				variables_index = s[0] - 'A';
				last_var = variables_index;
				push(variables[variables_index]);
				break;
			
			default:
				printf("type %c\n", type);
				printf("error: unknown command %s\n", s);
				break;

		}
	}


	return 0;
}



#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void){
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack. */


void peak(){
	printf("%f\n", val[sp-1]);
}

void duplicate_top(void){
	double val = pop();
	push(val);
	push(val);
}

void swap(void){
	double top = pop();
	double top2 = pop();
	push(top);
	push(top2);
}
c
void clear_stack(void){
	sp = 0;
}


#include <ctype.h>
int getch();
void ungetch(int);
int line_index = 0;

int getop(char s[]){
	
	int i, c; 
	char type;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	/* Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4. */
	if (!isdigit(c) && c != '.' && c != '-' && !isalpha(c)){
		// printf("returning %c\n", c);
		return c;
	}
	i = 0;

	/* Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers. */

	if (c == '-'){
		s[i] = c;
	}

	if (islower(c)){
		while (islower(s[++i] = c = getch()))
			;
		type = FUNCTION;

	}

	if (isupper(c)){
		while (isupper(s[++i] = c = getch()))
			;
		type = VARIABLE;
	}

	if (isdigit(c) || (c == '-')){
		while (isdigit(s[++i] = c = getch()))
			;
		type = NUMBER;
	}
	
	if (c == '.'){ /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
		type = NUMBER;
	}

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	
	return type;
}


#define BUFSIZE 100
/*Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design. */
int  buf[BUFSIZE];
int bufp = 0;

int getch() /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch? */

int ungets(char s[]){
	int i;
	for (i=0; s[i] != '\0'; i++)
		;

	while (i > 0){
		ungetch(s[--i]);
	}
}

#include<limits.h>
int main(){
	char line[1024];

	while (getline2(line, 1024) > 0)
		printf("%s", line);
}