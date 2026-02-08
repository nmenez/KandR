/* write a program to count blanks, tabs, and newlines */

#include <stdio.h>


int main(){
    int count = 0;
    int c; 

    while ((c = getchar()) != EOF){
        putchar(c);
        if ((c == ' ') | (c == '\t') | (c== '\n')){
            count++;
        }

    }
    printf("%i\n", count);
}
