/*
 * Brian Kernighan and Dennis Ritchie's The C Programming Language
 * Chapter 01
 * Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

#include <stdio.h>

#define CHARSET 256 - 65
#define OFFSET 65

int main()
{
	int i, c;
	int chist[CHARSET];

	for (i = 0; i < CHARSET; i++)
		chist[i] = 0;
	
	while ((c = getchar()) != EOF)
		chist[c - OFFSET]++;

	int maxchar = 0;
	for (i = 0; i < CHARSET; i++) {
		if (chist[i] > maxchar)
			maxchar = chist[i];
	}

	int j;
	for (j = maxchar; j > 0; j--) {
		for (i = 0; i < CHARSET; i++) {
			if (chist[i] >= j)
				printf("  #");
			else if (chist[i] > 0)
				printf("   ");
		}
		putchar('\n');
	}

	for (i = 0; i < CHARSET; i++)
		if (chist[i] != 0)
			printf("---");
	putchar('\n');

	for (i = 0; i < CHARSET; i++)
		if (chist[i] != 0)
			printf("  %c", i + OFFSET);

	putchar('\n');
	return 0;
}
