/*
 * Exercise 1-20: Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 */

#include <stdio.h>
#define TABSTOP 8

int main()
{
	int c, col, spaces; 

	col = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			col = 0;
			putchar(c);
		} else if (c == '\t') {
			spaces = TABSTOP - col % TABSTOP;
			col += spaces;
			while (spaces-- > 0)
				putchar(' ');
		} else {
			putchar(c);
			col++;
		}

	}
	return 0;
}
