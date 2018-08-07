/*
 * Exercise 3-3. Write a function itob(n,s,b) that converts the integer n into
 * a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s.
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

int iotb(int n, char s[], int b)
{
	if (b < 2 || b > 62) {
		printf("Invalid base.\n");
		return -1;
	}


	int i, sign, magnitude;

	sign = 1;
	if (n < 0)
		sign = -1;
	i = 0;
	do {
		magnitude = sign * (n % b);
		s[i++] = digits[magnitude];
	} while ((n /= b) != 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	return 0;
}

int main(void)
{
	for (int i = '0', j = 0; i <= 'z'; i++)
		if (i <= '9' || (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
			digits[j++] = i;
	for (int i = 0; i < 62; i++)
		printf("%c\n", digits[i]);
	char n_str[25];
	iotb(15, n_str, 16);
	printf("Base 16: %d\t->\t%s\n", 15, n_str);
	iotb(16, n_str, 16);
	printf("Base 16: %d\t->\t%s\n", 16, n_str);
	iotb(32, n_str, 32);
	printf("Base 32: %d\t->\t%s\n", 32, n_str);
	iotb(-31, n_str, 32);
	printf("Base 32: %d\t->\t%s\n", -31, n_str);
}
