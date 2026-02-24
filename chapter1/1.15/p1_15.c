#include <stdio.h>

int fahrenheit_to_celsius(int fahrenheit);


void main(){
   int lower =0;
   int upper = 300;
   int step = 10;
   int celsius;
   for (int fahr = lower; fahr<= upper; fahr+=step){
      celsius = fahrenheit_to_celsius(fahr);
      printf("f: %i, c:  %i\n", fahr, celsius);
   } 
}


int fahrenheit_to_celsius(int fahrenheit){
    int celsius;
    celsius  = 5 * (fahrenheit -32) /9 ;
    return celsius;

}
