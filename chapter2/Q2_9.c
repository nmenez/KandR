/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.*/

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


int bitcount(int n){
	int count = 0;
	while (n != 0){
		n =  n & (n-1) ;
		count++;
	}	
	return count;
}


int main(){

	int n;
	int result;

	for (n=0; n<=64; n++){
		result = bitcount(n);
		printf("%i %i: ",n, result);
		printBinary(n); 

	}
	return 0;
}