/*
 * Exercise 2-9: In a two's complement number system, x&= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 */

/*
 * Explanation: Subtracting 1 from x changes the right most 1 bit to a 0 and
 * every bit to the right of it to 1. ANDing x and x-1 does not affect bits to
 * the left of the first 1 bit since these bits are the same in x and x-1. Since
 * the first 1 bit is changed to a zero, ANDing x and x-1 will result in 1 AND 0
 * at this position, which gives a zero. All bits to the right of the first one
 * are by definition zero, so ANDing them gives a zero bit, which is the
 * original. Thus, the only change is removing the rightmost 1 bit to a zero.
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

int bitcount(unsigned x);

int main(int argc, char *argv[])
{
	for (unsigned int i=0; i<200; i+=23) {
		printf("Test number: %s\n", byte_to_binary(i));
		printf("Result: %d 1-bits\n", bitcount(i));
	}
}

int bitcount(unsigned x)
{
	int count = 0;
	while (x != 0) {
		count++;
		x &= (x-1);
	}
	return count;
}
