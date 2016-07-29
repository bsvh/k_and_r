/*
 * Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes each
 * character in s1 that matches any character in s2.
 *
 * squeeze: delete all c from s
 * void squeeze(char s[], int c)
 * {
 * 	int i, j;
 *
 * 	for (i = j = 0; s[i] != '\0'; i++)
 * 		if (s[i] != c)
 * 			s[j++] = s[i];
 * 	s[j] = '\0';
 * }
 */

#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
	char s1[] = "This is the test string.";
	char s2[] = "ist";

	printf("The original string is:\n%s\n", s1);
	printf("We remove the following characters: %s\n", s2);
	squeeze(s1, s2);
	printf("And now have the following string:\n%s\n", s1);

	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k, len;
	len = strlen(s2);

	for (i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; k < len; k++)
			if (s1[i] == s2[k])
				break;

		if (k == len)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
