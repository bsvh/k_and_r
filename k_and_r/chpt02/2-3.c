/*
 * Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x of 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int htoi(char s[]);
int mygetline(char s[], int lim);

int main(int argc, char *argv[])
{
	int lim = 1000;
	char s[lim];
	char c;

	mygetline(s, lim);

	int num = htoi(s);

	printf("%d\n", num);
}

int htoi(char s[])
{
	int value = 0;
	int len = strlen(s);
	int digit = len - 1;

	/* offset for strings starting with 0x or 0X */
	int start = 0;
	if (s[0] == '0' && tolower(s[1]) == 'x') {
		start = 2;
		digit -= 2;
	}

	int i;
	for (i = start; i < len; i++){
		if (isdigit(s[i]))
			value += (int) pow(16, digit) * (s[i] - '0');
		else if (isalpha(s[i]))
			value += (int) pow(16, digit) * (toupper(s[i]) - 'A' + 10);
		else {
			printf("Invalid character '%c'. Can't convert.\n", s[i]);
			return 0;
		}
		digit--;
	}
	return value;
}

int mygetline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;
}
