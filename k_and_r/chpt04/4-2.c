/*
 * Exercise 4-2. Extend atof to handle scientific notation of the form
 *       1.2345e-6
 * where a floating point number may be followed by e or E and optionally
 * signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(void)
{
	char s1[] = "123.2321e-3";
	char s2[] = "123.2321e+3";
	char s3[] = "123.2321e3";
	char s4[] = "0.001232321e3";
	printf("%s -> %f\n", s1, atof(s1));
	printf("%s -> %f\n", s2, atof(s2));
	printf("%s -> %f\n", s3, atof(s3));
	printf("%s -> %f\n", s4, atof(s4));
}



/* atof: converty string s to double */
double atof(char s[])
{
	double val, prod, exponent;
	int i, sign, expsign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (prod = 10.0; isdigit(s[i]); i++) {
		val = val + (s[i] - '0')/prod;
		prod *= 10.0;
	}

	if (tolower(s[i]) == 'e') {
		i++;
		exponent = atof(&s[i]);
		expsign = (exponent < 0) ? -1 : 1;
		exponent *= expsign;
		prod = 1.0;
		for (i = 1; i <= exponent; i++)
			prod *= 10;
		if (expsign == -1)
			prod = 1/prod;
		val = val * prod;
	}
	return sign * val;
}
