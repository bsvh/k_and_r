/*
 * Brian Kernighan and Dennis Ritchie's The C Programming Language
 * Exercise 1-13. Write a program to print a histogram of the lengths of
 * words in its input. It is easy to draw the histogram with the bars
 * horizontal; a vertical orientation is more challenging.  
 */

#include <stdio.h>

#define MAXWORD 50

int main()
{
	int i, c, wl, maxword;
	int wlens[MAXWORD];
	for (i = 0; i < MAXWORD; i++)
		wlens[i] = 0;

	wl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			wlens[wl]++;
			wl = 0;
		} else {
			wl++;
		}
	}

	maxword = 0;
	for (i = 0; i < MAXWORD; i++) {
		if (wlens[i] > maxword)
			maxword = wlens[i];
	}

	int j;
	for (j = maxword; j > 0; j--) {
		for (i = 0; i < MAXWORD; i++) {
			if (wlens[i] >= j)
				printf("  #");
			else if (wlens[i] > 0)
				printf("   ");
		}
		putchar('\n');
	}

	for (i = 0; i < MAXWORD; i++)
		if (wlens[i] != 0)
			printf("---");
	putchar('\n');

	for (i = 0; i < MAXWORD; i++)
		if (wlens[i] != 0)
			printf("%3d", i);

	putchar('\n');


	return 0;
}
