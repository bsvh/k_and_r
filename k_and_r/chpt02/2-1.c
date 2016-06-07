/*
 * Write a program to determine the ranges of char, short, int, and long
 * variables, both signed and unsigned, by printing the appropriate values from
 * standard headers and by direct commputation. Harder if you compute them:
 * determine the ranges of the various floating point types.
 */

#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("char types:\n\n");
	printf("signed char min: %d\n", SCHAR_MIN);
	printf("signed char max: %d\n", SCHAR_MAX);
	printf("unsigned char max: %d\n", UCHAR_MAX);
	printf("char min: %d\n", CHAR_MIN);
	printf("char max: %d\n\n\n", CHAR_MAX);

	printf("int types:\n\n");
	printf("short min: %d\n", SHRT_MIN);
	printf("short max: %d\n", SHRT_MAX);
	printf("unsigned short max: %u\n\n", USHRT_MAX);

	printf("int min: %d\n", INT_MIN);
	printf("int max: %d\n", INT_MAX);
	printf("uint max: %u\n\n", UINT_MAX);

	printf("long min: %ld\n", LONG_MIN);
	printf("long max: %ld\n", LONG_MAX);
	printf("unsigned long max: %lu\n\n", ULONG_MAX);

	printf("long long min: %lld\n", LLONG_MIN);
	printf("long long max: %lld\n", LLONG_MAX);
	printf("unsigned long long max: %llu\n\n\n", ULLONG_MAX);

	return 0;
}

