
#include <stdio.h>

int main(){
    int c;
    int d;
    c = getchar();
    while (c != EOF){
        putchar(c);
        d = c + 1;
        putchar(d);
        c = getchar();
    }    
   

  
}
