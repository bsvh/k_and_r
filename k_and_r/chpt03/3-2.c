/*
 * Exercise 3-2. Write a function escape(s,t) that converts characters like
 * newline and tab into visibleescape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other direction as
 * well, converting escape sequences into real characters.
 */

#include <stdio.h>
#include <string.h>


/* 
 * Copies string t to s and replaces tabs, newlines, slashes with visible escape
 * sequences. Assumes s is large enough to contain everything.
 */
void escape(char s[], char t[])
{
	int i, j, n;
	for (i=0, j=0, n=strlen(t); i<n; i++){
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\\':
				s[j++] = '\\';
				s[j++] = '\\';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
}

void unescape(char s[], char t[])
{
	int i, j, n;
	for (i=0, j=0, n=strlen(t); i<n; i++) {
		if (t[i] == '\\')
			switch (t[i + 1]) {
				case 'n':
					s[j++] = '\n';
					i++;
					break;
				case 't':
					s[j++] = '\t';
					i++;
					break;
				case '\\':
					s[j++] = '\\';
					i++;
					break;
				default:
					s[j++] = t[i];
					break;
			}
		else
			s[j++] = t[i];
	}
}

int main(void)
{
	char t[] = "This\t is a test\n string.\t That it is\n";
	char s[100];

	escape(s, t);

	printf("Original:\n%s\n", t);
	printf("Escaped:\n%s\n", s);

	unescape(t, s);
	printf("Unescaped:\n%s\n", t);
}
