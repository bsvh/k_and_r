/*
 * Exercise 1-8: Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>

int main()
{
	int c, bl, tab, nl;

	bl = tab = nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			bl++;
		if (c == '\t')
			tab++;
		if (c == '\n')
			nl++;
	}

	printf("Blanks: %d\n", bl);
	printf("Tabs: %d\n", tab);
	printf("Newlines: %d\n", nl);
}
