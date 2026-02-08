/*  Exercise 1-3. Modify the temperature conversion program to print a heading above the table. */

#include <stdio.h>

int main(){
    float fahr, celsius;
    float upper, lower, step;

    lower = 0;
    upper = 300;
    step = 2;
    
    celsius = lower;
    printf("-C- | --F--|\n");
    printf("____|______|\n");
    while (celsius <= upper){
        // celsius  = (5.0/ 9.0) * (fahr - 32.0);
	fahr =  (celsius  * (9.0 /5.0)) + 32.0;

        printf("%3.0f | %6.2f\n", celsius, fahr);
        celsius = celsius + step;

    }

}
