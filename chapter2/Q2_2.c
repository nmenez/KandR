/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.


for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
s[i] = c;


*/

#include <stdio.h>

int main(){
	int lim = 16;
	int s[lim];
	int c;
	int i;
	for (i = 0; i < lim - 1; i++){
		if ((c=getchar()) != '\n'){
			if (c != EOF){
				s[i] = c;
			} else {
				i = lim;
			}

		} else {
			i = lim;
		}
	}

}