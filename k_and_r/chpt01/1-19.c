/*
 * Exercise 1-19: Write a function reverse(s) that reverses the character string
 * s. Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input length line size */

int mygetline(char line[], int maxline);
void reverse(char s[]);

int main()
{
	int len; 
	char line[MAXLINE];

	while ((len = mygetline(line, MAXLINE) ) > 0) {
		reverse(line);
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

void reverse(char s[])
{
	int beg, end, c;

	/* Find the end of the string or first occurance of \n.
	 * Can't use strlen yet. */
	for (end = 0; end < MAXLINE && s[end] != '\n' && s[end] != '\0'; end++)
		;

	beg = 0;
	while (end - beg > 0) {
		c = s[beg];
		/* --end because s[end] is either \n or \0 */
		s[beg++] = s[--end];
		s[end] = c;
	}

}
