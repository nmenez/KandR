#include<stdio.h>



void main(){
    int c;
    int num_letters = 26;
    int letter_freq[num_letters];
    int difference_A_to_a=32;

    for (int i =0;  i <  num_letters; i++){
        letter_freq[i] = 0;
    }

    while ((c=getchar()) != EOF){
        if ( c >='a'  & c <= 'z'){
            letter_freq[c-'a']++;

        }
        if (c >='A'  & c <='Z'){
            letter_freq[c+difference_A_to_a-'a']++;
        }

    }



    /* find maximum freq */
    int max_freq=0;
    for (int i = 1; i <= num_letters; i++){
        if (letter_freq[i] > max_freq)
            max_freq  = letter_freq[i];
    }


    for (int i = 1; i < 2*(num_letters+1); i++){
        printf("_");
    }
    printf("\n");
    int current_level = max_freq;
    while (current_level > 0){
        for (int i =0; i< num_letters; i++){
            if (letter_freq[i] >= current_level){
                printf("|^");
            }else{
                printf("| ");
            }
        }
        current_level--;
        printf("\n");

    }

    for (int i = 0; i < num_letters; i++){
       printf("|%c", i+'a');
    }
    printf("\n");
}


