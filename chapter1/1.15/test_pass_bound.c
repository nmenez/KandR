#include <stdio.h>

void main(){
    int N = 10;
    int myarray[N];

    for (int i = 0; i < N; i++){
        myarray[i] = i * 2;
    }

    for (int i = 0; i <=N*2; i++){
        printf("%i, %i\n", i, myarray[i]);

    }

}
