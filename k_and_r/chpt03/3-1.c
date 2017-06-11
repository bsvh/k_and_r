/*
 * Our binary search makes two tests inside the loop, when only one would
 * suffice. Write a version with only one test inside the loop and measure the
 * difference in run-time.
 */

#include <stdio.h>
#include <time.h>

#define ARRY_SIZE 1000000
#define LOOPS 100000

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (x == v[mid]) ? mid : -1;

}

int main(void)
{
	/* make our test array */
	int numbers[ARRY_SIZE];
	for (int i=0; i<ARRY_SIZE; i++)
		numbers[i] = i;

	/* just generate a few numbers for testing */
	int search[100];
	for (int i=0; i<ARRY_SIZE; i++)
		search[i]=i * ARRY_SIZE / LOOPS;

	/* for runtime calulations */
	clock_t begin, end;
	double time_one, time_two;

	begin = clock();
	for (int i=0; i<100; i++)
		for (int j=0; j<LOOPS; j++)
			binsearch(search[i], numbers, ARRY_SIZE);
	end = clock();

	time_one = (double)(end - begin) / CLOCKS_PER_SEC;

	begin = clock();
	for (int i=0; i<100; i++)
		for (int j=0; j<LOOPS; j++)
			binsearch2(search[i], numbers, ARRY_SIZE);
	end = clock();

	time_two = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Inside Loop: %e sec.\n", time_one);
	printf("Outside Loop: %e sec.\n", time_two);
	printf("Difference: %e sec.\n", time_two - time_one);
}
