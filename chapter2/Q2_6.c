/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.*/

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

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y){
	unsigned int filter =  ~(~0 << n);
	unsigned int mov = (p + 1 - n);
	unsigned int mask = filter << mov;

	int xcleaned = x & ~mask;
	int ycleaned = (y & filter) << mov;
	return xcleaned | ycleaned;
}

int main(){
	int n = 5;
	int p = 11;
	// int y=  128 + 64 + 32+ 7;
	int y = 128+64+32+ 16 +7;
	int x = 43690;
	printBinary(setbits(x, p, n, y));

}