/*
 * Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations
 * like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally.
 */

#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[])
{
	char startchar, endchar;
	int offset;
	int j = 0;
	for (int i=0, n=strlen(s1); i<n; i++) {
		startchar = '\0';
		endchar = '\0';
		offset = 0;

		if (s1[i+1] != '-') 
			/* we are at second - of form a-b-c */
			if (i < n-1 && i > 2 && s1[i] == '-'){
				startchar = s1[i-1];
				endchar = s1[++i];
			/* lone characters */
			} else {
				s2[j++] = s1[i];
			}
		else if (i < n-2) {
			startchar = s1[i];
			endchar = s1[i+2];
			offset = 2;
		} else {
			s2[j++] = s1[i];
		}

		if (startchar != '\0') {
			for (char c=startchar; c<=endchar; c++)
				s2[j++] = c;
			i += offset;
		}
	}
	s2[j] = '\0';
}

int main(void)
{
	char teststr[] = "-a-zA-Z0-9a-b-c-";
	char expanded[1000];

	expand(teststr, expanded);

	printf("%s --> %s\n", teststr, expanded);
}
