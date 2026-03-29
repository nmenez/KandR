#include<stdio.h>
#define swap(t, x , y) do{ t temp = x; x = y; y = temp;} while (0); 

int main(){
	int a = 1;
	int b = 2;

	swap(int, a, b);
	printf("a: %i, b: %i\n", a, b);
}