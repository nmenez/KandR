/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.*/

#include <stdio.h>
#include <limits.h>

void printBinary(unsigned int num) {
    // Determine the number of bits in an unsigned int portably
    const int bits = sizeof(unsigned int) * CHAR_BIT;

    for (int i = bits - 1; i >= 0; i--) {
        // Use bitwise right shift (>>) and AND (&) to check each bit
        unsigned int bit = (num >> i) & 1;
        printf("%u", bit); // Print the bit (0 or 1)

        // Optional: Add a space for readability in groups of 4 or 8
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int rightrot(unsigned int x, unsigned int n){
	const int mov_right_edge = (32 - n) % 32;
	const int right_piece = x << mov_right_edge;
	const int left_piece = x >> n;
	printBinary(left_piece |right_piece);
	return left_piece | right_piece;
}


int main(){
	const unsigned int a = 64+ 3;
	printBinary(a);
	for (int i = 0; i<=64; i++){
		printf("%i:", i);
		

		rightrot(a, i);
	}

	return 0;
}
