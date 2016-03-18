/*
 * Exercise 1-3: Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion.
 */

#include <stdio.h>

float fahr2c(float fahr);

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;
	printf("  F     C\n");
	while (fahr <= upper) {
		printf("%3.0f%6.1f\n", fahr, fahr2c(fahr));
		fahr = fahr + step;
	}
}

float fahr2c(float fahr)
{
	return (5.0/9.0) * (fahr - 32);
}
