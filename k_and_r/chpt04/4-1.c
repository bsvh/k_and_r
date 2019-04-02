/* 
 * Exercise 4-1. Write the function strrindex(s,t), which returns the position
 * of the rightmost occurence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int mygetline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void)
{
	char line[MAXLINE];
	int index = 0;

	while (mygetline(line, MAXLINE) > 0)
		if ((index=strrindex(line, pattern)) >= 0) {
			printf("%d\n", index);
			int i;
			for (i = index; i < strlen(line); i++)
				putchar(line[i]);
		}
}

int strrindex(char s[], char t[])
{
	int i, j, k, send, tend;

	/* ignore \0 */
	send = strlen(s) - 1;
	tend = strlen(t) - 1;

	if (s[send] == '\n')
		send--;

	for (i = send - tend; i >=0; i--) {
		for (j = i, k = 0; t[k] != '\0'  && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
