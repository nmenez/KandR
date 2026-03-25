/* Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent. */


#include <ctype.h>
#include <stdio.h>


double atof(char s[]){
	double val, power;
	int i, sign;
	double mantissa;
	double exponent;
	int exponent_sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	
	mantissa = sign * val / power;

	if ((s[i] == 'e') || (s[i] == 'E')){
		i++;

		exponent_sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '-'){
			i++;
		}


		for (exponent = 0.0; isdigit(s[i]); i++){
			exponent = 10.0 * exponent + (s[i] - '0');
		}


	}
	else{
		exponent = 1;
		exponent_sign = 1;
	}

	// can't use pow just yet because math.h not introduced at this stage in K&R
	float base =1.0;
	for (int exponent_iterator = 0; exponent_iterator < exponent; exponent_iterator++){
		base *= 10;
	}

	float result = (exponent_sign ==1) ? mantissa * base : mantissa / base;

	return result;
}


int main(){
	char test[] = "-123.45e-1";

	float result = atof(test);
	printf("%f\n", result);
}