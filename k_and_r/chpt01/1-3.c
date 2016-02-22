/*
 * Exercise 1-3: Modify the temperature conversion program to print a heading
 * about the table.
 */

#include <stdio.h>

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
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}