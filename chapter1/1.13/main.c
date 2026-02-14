/*  Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include<stdio.h>
#define IN 1
#define OUT 0 

void main(){
    int max_length = 10;
    int length_freq[max_length+1];
    int c;
    int state;
    int current_word_length = 0;

    for (int i = 0; i < max_length+1; i++){
        length_freq[i] = 0;

    }

    while ((c=getchar()) != EOF){
        if (c == ' '  || c == '\n' || c == '\n'){

             state = OUT;

             length_freq[current_word_length]++;
             current_word_length = 0;
        }
        else{
            state = IN;
            current_word_length++;

        }

    }

    for (int i = 1; i < 2*(max_length+1); i++){
        printf("_");
    }
    printf("\n");
    int max_freq=0;
    for (int i = 1; i < max_length+1; i++){
        if (length_freq[i] > max_freq)
            max_freq  = length_freq[i];
    }

    int current_level = max_freq;
    while (current_level > 0){
        for (int i =1; i< max_length+1; i++){
            if (length_freq[i] >= current_level){
                printf("|^");
            }else{
                printf("| ");
            }
        }
        current_level--;
        printf("\n");

    }

    for (int i = 1; i < max_length+1; i++){
        printf("|%i", i);
    }
    printf("\n");
}
