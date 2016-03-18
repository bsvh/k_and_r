/*
 * Exercise 1-18: Write a program to remove trailing blanks and tabs from each
 * line of input and delete entirely blank lines.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input length line size */

int mygetline(char line[], int maxline);

int main()
{
	int len, i, lastchar, nl;
	char line[MAXLINE];

	while ((len = mygetline(line, MAXLINE) ) > 0) {
		lastchar = nl = 0;
		for (i = len - 1; i >= 0 && lastchar == 0; i--){
			if (line[i] == '\n')
				nl = 1;
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
				line[i+1] = '\0';
				lastchar = i;
			}
		}
		if (line[0] != '\n') {
			printf("%s", line);
			if (nl == 1)
				putchar('\n');
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
