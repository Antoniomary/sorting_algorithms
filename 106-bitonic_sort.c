#include "sort.h"

void swap(int *a, int *b);
void bitonic_seq(int *ar, size_t size, size_t low, size_t count, int ord);
void bitonic_merge(int *ar, size_t size, size_t low, size_t count, int ord);

/**
 * bitonic_sort - a function that sorts an array of integers
 * in ascending order using the Bitonic sort algorithm.
 * @array: the array to sort
 * @size: the size of array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, size, 0, size, ASCENDING);
}

/**
 * swap - a function that swaps two elements.
 * @a: the first element.
 * @b: the second element.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_seq - a function that recursively breaks an array into subarrays.
 * @ar: the array to breakdown
 * @size: the original size of the array.
 * @low: the low index.
 * @count: the number of elements in the array or subarray.
 * @ord: the sorting order whether ascending or descending.
 */
void bitonic_seq(int *ar, size_t size, size_t low, size_t count, int ord)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;

		printf("Merging [%lu/%lu] (%s):\n", count, size, ord ? "UP" : "DOWN");
		print_array(ar, count);
		bitonic_seq(ar, size, low, k, ASCENDING);
		bitonic_seq(ar, size, low + k, k, DESCENDING);
		bitonic_merge(ar, size, low, count, ord);
		printf("Result [%lu/%lu] (%s):\n", count, size, ord ? "UP" : "DOWN");
		print_array(ar, count);
	}
}

/**
 * bitonic_merge - a function that recursively breaks an array into subarrays.
 * @ar: the array to breakdown
 * @size: the original size of the array.
 * @low: the low index.
 * @count: the number of elements in the array or subarray.
 * @ord: the sorting order whether ascending or descending.
 */
void bitonic_merge(int *ar, size_t size, size_t low, size_t count, int ord)
{
	size_t i, k;

	if (count > 1)
	{
		k = count / 2;

		for (i = low; i < low + k; ++i)
		{
			if (ord == ASCENDING && (ar[i] > ar[i + k]))
				swap(&ar[i], &ar[i + k]);
			else if (ord == DESCENDING && (ar[i] < ar[i + k]))
				swap(&ar[i], &ar[i + k]);
		}

		bitonic_merge(ar, size, low, k, ord);
		bitonic_merge(ar, size, low + k, k, ord);
	}
}
