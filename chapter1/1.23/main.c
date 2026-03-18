/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest. */
#include <stdio.h>
#define CODE  0
#define INBLOCK  1
#define INLINE   2
#define INSTRING  3
#define INCHAR 4
#define WAITING 5

int main(){
    int c; 
    int prev = 0;
    int current_state = CODE;
    int prev_state = CODE;
    
	while ((c=getchar()) != EOF){
        if ((current_state == CODE) && ((c =='/') || (c == '\"') || (c == '\''))){
            prev_state = current_state;
            current_state = WAITING;
        }
        else if (current_state == INBLOCK){
            if (c== '*'){
                current_state = WAITING;
                prev_state = INBLOCK;
            }

        }

        else if (current_state == INLINE){
            if (c == '\n'){
                current_state = CODE;
                prev_state = INLINE;
            }
        }

        else if (current_state == INSTRING){    
            if ((c == '\"') && (prev != '\\')){
                current_state = CODE;
                prev_state = INSTRING;
            }
          
        }


        else if (current_state == INCHAR){
            if ((c  == '\'') && (prev != '\\')){
                current_state = CODE;
                prev_state = INCHAR;
            }

        }


        else if (current_state == WAITING){

            if ((prev == '/') && (c == '/') && (prev_state == CODE)){
                current_state = INLINE;
            }
            else if ((prev == '/')  && (c == '*') && (prev_state == CODE)){
                current_state = INBLOCK;
            }
            else if ((prev == '/')){
                putchar(prev);
                current_state = CODE;   
            }
            else if ((prev == '\"')&& (prev_state == CODE)){
                putchar(prev);
                current_state = INSTRING;
            }
            else if ((prev== '\'') &&  (prev_state == CODE)){
                putchar(prev);
                current_state = INCHAR;
            }
            else if ((prev == '*') && (c== '/') && (prev_state==INBLOCK)){
                current_state = CODE;
                c = 0;
            }
            else if ((prev == '*') && ( c!= '/') && (prev_state == INBLOCK)){
                current_state = INBLOCK;    
            }
            else if ((prev_state == INSTRING) && (c ==  '\"')){
                current_state == INSTRING;
                prev_state =WAITING;
            }

            prev_state = WAITING;

        }
        else{
                prev_state = current_state;
            }


        if ((current_state ==  CODE) || (current_state == INSTRING) || (current_state == INCHAR)){
            putchar(c); 
        }

        prev = c;

	}

    if (current_state == WAITING){
        putchar(prev);
    }

}   