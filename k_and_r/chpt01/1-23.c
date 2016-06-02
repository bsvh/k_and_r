/*
 * Exercise 1-23: Write a program to remove all comments from a C program. Don't
 * forget to handle quoted strings and character constants properly. C comments
 * do not nest.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input length line size */
#define FOLDAT 80

int mygetline(char line[], int maxline);

int main()
{
	int i, len, incomment, inquote, inchar;
	char line[MAXLINE];

	incomment = inquote = inchar= 0;
	while ((len = mygetline(line, MAXLINE)) > 0) {
		for (i = 0; i < len; i++)
			if (inquote == 0 && incomment == 0 && inchar == 0) {
				if (line[i] == '"') {
					inquote = 1;
					putchar(line[i]);
				} else if (line[i] == '/' && line[i+1] == '*') {
					incomment = 1;
					i++;
				} else if (line[i] == '\'') {
					inchar = 1;
					putchar(line[i]);
				} else
					putchar(line[i]);
			} else if (inquote == 1) {
				if (line[i] == '"')
					inquote = 0;
				putchar(line[i]);
			} else if (incomment == 1) {
				if (line[i] == '*' && line[i+1] == '/') {
					incomment = 0;
					i++;
				}
			} else {
				putchar(line[i]);
				inchar = 0;
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
