/*
 * Exercise 2-2. Write a loop equivalent to the for loop below without using &&
 * or ||.
 *
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *     s[i] = c;
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int lim = 1000;
	char s[lim];
	char c;

	int i;
	for (i=0; i<lim-1; i++) {
		c = getchar();
		if (c == '\n')
			break;
		else if (c == EOF)
			break;
		else
			s[i] = c;
	}
	printf("%s\n", s);
}
