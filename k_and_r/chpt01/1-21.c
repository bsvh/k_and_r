/*
 * Exercise 1-21: Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input length line size */
#define TABSTOP 8

int mygetline(char line[], int maxline);
int getnumadj(char c, char s[], int start, int len);

int main()
{
	int i, col, len, spaces, stop; 
	char line[MAXLINE];

	while ((len = mygetline(line, MAXLINE)) > 0) {
		col = 0;
		while (col < len) {
			spaces = getnumadj(' ', line, col, len);
			if (spaces > 1) {
				/* number of columns next tab will land */
				stop = TABSTOP - col % TABSTOP;
				if (stop < spaces) {
					putchar('\t');
					col += stop;
					spaces -= stop;
				} else {
					for (i = 0; i < spaces; i++)
						putchar(' ');
					col += spaces;
				}
			} else
				putchar(line[col++]);
		}
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

int getnumadj(char c, char s[], int start, int len)
{
	int i = start;
	while (i < len)
		if (s[i] != c)
			break;
		else
			i++;
	return i - start;
}
