/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/


#include<stdio.h>
#include<limits.h>


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

int invert(unsigned int x, unsigned int p, unsigned int n){
	unsigned int mov = p + 1 - n;
	unsigned int mask = (~(~0 << n)) << mov;
	// printBinary(mask);
	unsigned int inverted_extract= ~(x & mask);
	
	// printBinary(inverted_extract);

	unsigned int same_x = x | mask;
	// printBinary(same_x);
	// unsigned int inverted_x = ~(x & mask);
	// printBinary(inverted_x);
	// printBinary(same_x & inverted_x);
	unsigned int result = same_x & inverted_extract;
}


int main(){
	int n = 5;
	int p = 7;
	// int y=  128 + 64 + 32+ 7;
	// int y = 128+64+32+ 16 +7;
	// int x = 43690+1+4;
	// printBinary(x);

	// unsigned result = invert(x, p, n);
	// printBinary(result);

	const int bits = sizeof(unsigned int) * CHAR_BIT;
	printf("%i, %i\n", bits, CHAR_BIT);
}