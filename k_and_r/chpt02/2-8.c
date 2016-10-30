/*
 * Exercise 2-8: Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
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

unsigned rightrot(unsigned x, int n);

int main(int argc, char *argv[])
{
	unsigned x = 37;
	unsigned z;
	z = rightrot(x, 3);

	printf("Test x: %s\n", byte_to_binary(x));

	printf("Result (n 3): %s\n", byte_to_binary(z));
}

/* This function assumes n and p make sense (i.e. n + p < 8) */
unsigned rightrot(unsigned x, int n)
{
	unsigned mask = ~0 << n;

	return  ((x & mask) >> n) | ((x & ~mask) << (8 - n));
}
