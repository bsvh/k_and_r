/*
 * Exercise 1-24: Write a program to to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments. (This program
 * is hard if you do it in full generality.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input length line size */
#define FOLDAT 80

int mygetline(char line[], int maxline);
int findend(char s[], int start, int end, char quote);
void matcherror(int line, int index, char c);
void matchbegin(int match[], int line, int col);
void matchend(int match[], int line, int col, char ending);

int main()
{
	int i, len, incomment, inquote, inchar, linenum, end;
	char line[MAXLINE];

	/* {# unmatched, outer line number, outer column} */
	int brace[] = {0, 0, 0};
	int paren[] = {0, 0, 0};
	int bracket[] = {0, 0, 0};

	linenum = 1;
	incomment = inquote = inchar = 0;
	while ((len = mygetline(line, MAXLINE)) > 0) {
		for (i = 0; i < len; i++)
			if (incomment == 1) {
				if (line[i] == '*' && line[i+1] == '/') {
					incomment = 0;
					i++;
				}
			} else if (line[i] == '/' && line[i+1] == '*') {
				incomment = 1;
				i++;
			} else if (line[i] == '*' && line[i+1] == '/') {
				printf("%d:%d Invalid expression. ", linenum, i+1);
				printf("Is this an unmatched comment?\n");

			} else if (line[i] == '\'') {
				end = findend(line, i, len, '\'');
				if (end < 0) { 
					matcherror(linenum, i, '\'');
					return 1;
				} else
					i = end;
			} else if (line[i] == '"') {
				end = findend(line, i, len, '"');
				if (end < 0) {
					matcherror(linenum, i, '"');
					return 1;
				}
				else
					i = end;
			} else if (line[i] == '[')
				matchbegin(brace, linenum, i);
			else if (line[i] == ']')
				matchend(brace, linenum, i, '[');
			else if (line[i] == '(')
				matchbegin(paren, linenum, i);
			else if (line[i] == ')')
				matchend(paren, linenum, i, '(');
			else if (line[i] == '{')
				matchbegin(bracket, linenum, i);
			else if (line[i] == '}')
				matchend(bracket, linenum, i, '{');
		linenum++;
	}
	if (brace[0] > 0)
		matcherror(brace[1], brace[2], '[');
	if (paren[0] > 0)
		matcherror(paren[1], paren[2], '(');
	if (bracket[0] > 0)
		matcherror(bracket[1], bracket[2], '{');
	if (paren[0] > 0 || brace[0] > 0 || bracket[0] > 0)
		return 1;
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

int findend(char s[], int start, int end, char quote)
{
	int i;
	for (i = start + 1; i < end; i++)
		if (s[i] == '\\')
			/* skip escape sequences */
			i++;
		else if (s[i] == quote)
			return i;
	return -1;
}

void matcherror(int line, int index, char c)
{
	printf("%d:%d No match for %c\n", line, index + 1, c);
}

void matchbegin(int match[], int line, int col)
{
	/* save the line and column for outermost unmatched */
	if (match[0] == 0) {
		match[1] = line;
		match[2] = col;
	}
	match[0]++;
}

void matchend(int match[], int line, int col, char c)
{
	if (match[0] == 0)
		matcherror(line, col, c);
	else
		match[0]--;
}
