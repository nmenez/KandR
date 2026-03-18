 
#include <stdio.h>

#define MAXSTACK 1000
#define CODE  0
#define INBLOCK  1
#define INLINE   2
#define INSTRING  3
#define INCHAR 4
#define WAITING 5


int is_open(int c){
    return ((c == '(') || (c=='[') || (c =='{'));
}

int is_close(int c){
    return ((c == ')') || (c==']') || (c =='}'));
}

int match(int c, int prev){
    if (((prev == '(') && (c == ')')) || ((prev == '[')  && (c == ']')) || ((prev == '{') || (c==')'))){
        return 1;
    }
    else{
        return 0;
    }

}

int main(void)
{
    int c;
    int prev; 
    int line_number;
    int stack[MAXSTACK];
    int stack_idx = -1;
    int buf[2];
    int current_state = CODE;
    int prev_state = CODE;


    while ((c = getchar()) != EOF) {
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
            else if ((prev == '\"') && (prev_state == CODE)){
                current_state = INSTRING;
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
            else if ((prev== '\'') &&  (prev_state == CODE)){
                current_state = INCHAR;
            }

            prev_state = WAITING;

        }
        else{
                prev_state = current_state;
            }

    

        if (is_open(c) && (current_state == CODE)){
            stack_idx++;
            stack[stack_idx] = c;
        }
        else if (is_close(c) && (current_state== CODE) && (match(c, stack[stack_idx]))){
            stack[stack_idx] = 0;
            stack_idx--;

        }
        else if (is_close(c) && (current_state == CODE)){
            stack_idx++;
            stack[stack_idx] = c;
        }

        prev = c;



    }
    if (stack_idx != -1){
        printf("unbalanced code somewhere");
    }

    return 0;
}
