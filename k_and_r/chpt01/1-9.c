/*
 * Exercise 1-9: Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main()
{
	int c, inspace;

	inspace = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') { 
			if (inspace == 0)
				putchar(' ');
			inspace = 1;
		}
		else {
			inspace = 0;
			putchar(c);
		}
	}
}
