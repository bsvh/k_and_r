/*
 * Exercise 1-16: Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrarily long input lines, and as much as
 * possible of the text.
 */

#include <stdio.h>
#define MAXLINE 10    /* maximum input length line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	int curlen;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = curlen = 0;
	while ((len = mygetline(line, MAXLINE) ) > 0) {
		curlen += len;
		if (line[len - 1] == '\n') { 
			if(len > max) {
				max = curlen;
				copy(longest, line);
			}
			curlen = 0;
		}

	}
	if (max > 0)
		printf("The longest string is\n%s\nwith length %d.\n",
				longest, max);
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

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
