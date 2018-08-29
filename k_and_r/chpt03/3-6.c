/*
 * Exercise 3-6. Write a version of itoa that accepts three arguments instead
 * of two. The third argument is a minimum field width; the converted number
 * must be padded with blanks on the left if necessary to make it wide enough.
 */


#include <stdio.h>
#include <string.h>
char digits[10 + 26 + 26];


void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void iota(int n, char s[], int w)
{
	int i, sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	i = 0;
	do {
		s[i++] = sign * (n % 10) + '0';
	} while ((n /= 10) != 0);
	if (sign < 0)
		s[i++] = '-';
	int j;
	for (j=w-i; j>0; j--)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

int main(void)
{
	char n_str[25];
	iota(15, n_str, 4);
	printf("Number 15, padded to 4: %d\t->\t'%s'\n", 15, n_str);
	iota(15, n_str, 3);
	printf("Number 15, padded to 3: %d\t->\t'%s'\n", 15, n_str);
	iota(1583, n_str, 3);
	printf("Number 1583, padded to 3: %d\t->\t'%s'\n", 1583, n_str);
}
