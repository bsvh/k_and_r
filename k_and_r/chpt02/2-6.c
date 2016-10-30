/*
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
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

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char *argv[])
{
	unsigned x = 37;
	unsigned y = 239;
	unsigned z;
	z = setbits(x, 1, 3, y);

	printf("Test x: %s\n", byte_to_binary(x));
	printf("Test y: %s\n", byte_to_binary(y));

	printf("Result (p 1, n 3): %s\n", byte_to_binary(z));
}

/* This function assumes n and p make sense (i.e. n + p < 8) */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	/* bits p to p+n are 1, else 0 */
	unsigned mask = (~0 << p) ^ (~0 << (n+p));

	/* bits 0 to n of y are kept */
	y = (mask >> p) & y;

	/* bits p to p + n of x are replaced with first n bits of y */
	return (x & ~mask) | (y<<p);
}
