/*
 * Exercise 3-3. In a two's complement number representation, our version of
 * ito does not handle the largest negative number, that is, the value of n
 * equal to -(2^(wordsize-1)). Explain why not. Modify it to prine that
 * value correctly regardless of the machine on which it runs.*/

/*
 * Explanation: The smallest number in the two's complement system is
 * represented by a 1 in the 'sign' bit and zeros elsewhere. The negative of
 * this is achieved by taking the ones complement and adding 1. The ones
 * complement results in a 0 in the 'sign' bit and ones elsewhere. Adding 1
 * to this causes carryover which results in a 1 in the 'sign' bit and zeros
 * elsewhere. This results in the original number. So the magnitude of the most
 * negative number in a two's complement system has no representation.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void iota(int n, char s[])
{
	int i, sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	i = 0;
	do {
		s[i++] = sign * (n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main(void)
{
	char n_str[25];
	iota(INT_MIN, n_str);
	printf("%d\t->\t%s\n", INT_MIN, n_str);
	iota(INT_MIN/2, n_str);
	printf("%d\t->\t%s\n", INT_MIN/2, n_str);
	iota(0, n_str);
	printf(" %d\t\t->\t %s\n", 0, n_str);
	iota(INT_MAX/2, n_str);
	printf(" %d\t->\t %s\n", INT_MAX/2, n_str);
	iota(INT_MAX, n_str);
	printf(" %d\t->\t %s\n", INT_MAX, n_str);
}
