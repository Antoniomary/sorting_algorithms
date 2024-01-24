#include "sort.h"

void zero_initializer(int *array, size_t size);

/**
 * radix_sort - a function that sorts an array of integers
 * in ascending order using the Radix sort algorithm.
 * @array: the array to sort.
 * @size: the size of array.
 *
 * Description: The LSD radix sort algorithm is what is usedhere.
 */
void radix_sort(int *array, size_t size)
{
	size_t i, d = 0, place_value = 1;
	int max, temp, count[10], *array_temp;

	if (!array || size < 2)
		return;

	/* find the max element in the array to sort */
	for (max = array[0], i = 1; i < size; ++i)
		max = array[i] > max ? array[i] : max;
	/* count number of digits in max element */
	temp = max;
	do {
		d += 1;
	} while ((temp /= 10) != 0);

	array_temp = (int *) malloc(sizeof(int) * size);
	if (!array_temp)
		return;

	for ( ; d != 0; place_value *= 10, --d)
	{
		/* initial count array to zero */
		zero_initializer(count, 10);
		/* get the face value of LSD and use for counting */
		for (i = 0; i < size; ++i)
			count[array[i] / place_value % 10] += 1;
		/* update count from frequency to index tracker */
		for (i = 1; i < 10; ++i)
			count[i] = count[i - 1] + count[i];
		/* sort the array according to order of magnitude of LSD */
		for ( ; i != 0; --i)
		{
			temp = array[i - 1] / place_value % 10;
			count[temp] -= 1;
			array_temp[count[temp]] = array[i - 1];
		}
		/* copy to original array */
		for (i = 0; i < size; ++i)
			array[i] = array_temp[i];

		print_array(array, size);
	}

	free(array_temp);
}

/**
 * zero_initializer - a funtion that sets all indices in an array to zero.
 * @array: the array.
 * @size: the size of array.
 */
void zero_initializer(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		array[i] = 0;
}
