/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.

*/
#include <limits.h>
#include <float.h>
#include <stdio.h>

int main(){
	printf("-------------using limits.h-------------\n");
	printf("min char%i\n", CHAR_MIN);
	printf("max char %i\n", CHAR_MAX);

	printf("min schar%i\n", SCHAR_MIN);
	printf("max schar%i\n", SCHAR_MAX);
	printf("max uschar%u\n", UCHAR_MAX);
	printf("min signed short %i\n", SHRT_MIN);
	printf("max signed short %i\n", SHRT_MAX);
	printf("max unsigned short %i\n", USHRT_MAX);
	
	printf("min signed int %i\n", INT_MIN);
	printf("max signed int %i\n", INT_MAX);
	printf("max unsigned int %u\n", UINT_MAX);

	printf("min signed long %ld\n", LONG_MIN);
	printf("max signed long %ld\n", LONG_MAX);
	printf("max unsigned long %lu\n", ULONG_MAX);


	printf("----------------using direct computation ------\n");
	printf(" exponential operators have not been introduced in the book yet, can't use 2**n-1 to calculate ranges\n");	

	unsigned char min_uchar = 0;
	unsigned char max_uchar = min_uchar  - 1;
	printf("min unsigned char %u\n", min_uchar);
	printf("max uunsigned char %u\n", max_uchar);

	signed char min_schar  = (max_uchar / 2 + 1	) * (-1);
	signed char max_schar  = max_uchar / 2;
	printf("min signed char %i\n", min_schar);
	printf("max signed schar %i\n", max_schar);

	unsigned short min_ushort = 0;
	unsigned short max_ushort = min_ushort  - 1;
	printf("min unsigned short %u\n", min_ushort);
	printf("max unsigned short %u\n", max_ushort);

	signed short min_short  = (max_ushort / 2 + 1	) * (-1);
	signed short max_short  = max_ushort / 2;
	printf("min signed short %i\n", min_short);
	printf("max signed short %i\n", max_short);

	unsigned int min_uint = 0;
	unsigned int max_uint = min_uint  - 1;
	printf("min unsigned int %u\n", min_uint);
	printf("max unsigned int %u\n", max_uint);

	signed int min_int  = (max_uint / 2 + 1	) * (-1);
	signed int max_int  = max_uint / 2;
	printf("min signed int %i\n", min_int);
	printf("max signed int %i\n", max_int);

	unsigned long min_ulong = 0;
	unsigned long max_long = min_ulong - 1;
	signed long min_slong  = (max_long  / 2 + 1) * (-1);
	signed long max_slong = max_long / 2;
	printf("min signed long %ld\n", min_slong);
	printf("max signed long %ld\n", max_slong);
	printf("max usigned long %lu\n", max_long);


}