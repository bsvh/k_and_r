/*
 * Exercise 2-7: Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted, leaving the others unchanged.
 */

#include <stdio.h>
#include <string.h>

/* This function code taken from 
 * http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format#112956
 */
const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

unsigned invert(unsigned x, int p, int n);

int main(int argc, char *argv[])
{
	unsigned x = 37;
	unsigned z;
	z = invert(x, 1, 3);

	printf("Test x: %s\n", byte_to_binary(x));

	printf("Result (p 1, n 3): %s\n", byte_to_binary(z));
}

/* This function assumes n and p make sense (i.e. n + p < 8) */
unsigned invert(unsigned x, int p, int n)
{
	/* bits p to p+n are 1, else 0 */
	unsigned mask = (~0 << p) ^ (~0 << (n+p));

	/* x & ~mask turns bits from p to n+p to zero
	 * x & mask saves only the bits from p to n+p.
	 * xoring those bits with the mase inverts them.
	 * when we OR the first part with the second part,
	 * we invert only bits p to n+p.
	 */
	return  (x & ~mask)  | ((x & mask) ^ mask);
}
