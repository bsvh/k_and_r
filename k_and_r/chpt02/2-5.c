/*
 * Write the function any(s1, s2), which returns the first location the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2.
 */

#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main(int argc, char *argv[])
{

	char s1[] = "Helly my name is Jimmy John.\n";
	printf("The original string is:\n%s", s1);
	printf("Comparison is: adfjl\n");
	printf("1st occurance: %d\n", any(s1, "adfjl"));

	printf("Comparison is: zpw\n");
	printf("1st occurance: %d\n", any(s1, "zpw"));

	return 0;
}

int any(char s1[], char s2[])
{
	int s1len, s2len;
	s1len = strlen(s1);
	s2len = strlen(s2);
	for (int i=0; i<s1len; i++)
		for (int j=0; j<s2len; j++)
			if (s1[i] == s2[j])
				return i;
	return -1;
}
