/*
 * Exercise 1-22: Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input length line size */
#define FOLDAT 80

int mygetline(char line[], int maxline);

int main()
{
	int i, col, len, last;
	char line[MAXLINE];

	while ((len = mygetline(line, MAXLINE)) > 0) {
		col = 0;
		last = 0;
		if (len > FOLDAT) {
			while (col + FOLDAT < len) {
				for (i = col + FOLDAT - 1; i >= 0; i--) {
					if (line[i] == ' ' || line[i] == '\t') {
						last = i;
						break;
					}
				}
				if (last > col) {
					for (i = col; i < last; i++)
						putchar(line[i]);
					putchar('\n');

					/* last + 1 skips trailing space */
					col = last + 1;
				} else {
					for (i = col; i < FOLDAT; i++)
						putchar(line[i]);
					col += FOLDAT;
				}
			}
			if (col < len)
				for (i = col; i < len; i++)
					putchar(line[i]);
		}
		else
			printf("%s", line);
		
	}
	return 0;
}

int mygetline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
