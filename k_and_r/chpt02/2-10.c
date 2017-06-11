/*
 * Exercise 2-10: Rewrite the function lower, which converts upper case letters
 * to lower case, with a conditional expression instead of if-else.
 */


#include <stdio.h>
#include <ctype.h>

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main(int argc, char *argv[])
{
	for (char c='A'; c <= 'z'; c++) {
		printf("Original: %c\tLowered: %c\n", c, lower(c));
	}
}
