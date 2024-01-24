#include "sort.h"

/**
 * counting_sort - a function that sorts an array of integers in
 * ascending order using the Counting sort algorithm.
 * @array: the array to sort.
 * @size: the size of array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i, count_size;
	int k, *count, *array_temp;

	if (!array || size < 2)
		return;

	/* find the max, i.e k, element */
	for (k = array[0], i = 1; i < size; ++i)
		k = (array[i] > k) ? array[i] : k;
	count = (int *) malloc(sizeof(int) * (count_size = k + 1));
	if (!count)
		return;

	/* initial all elements in count to 0 */
	for (i = 0; i < count_size; ++i)
		count[i] = 0;
	/* get the frequency of the elements in array */
	for (i = 0; i < size; ++i)
		count[array[i]] += 1;

	/* turn count to track the index */
	for (i = 1; i < count_size; ++i)
		count[i] = count[i - 1] + count[i];
	/* print the counting array to stdout */
	print_array(count, count_size);

	array_temp = (int *) malloc(sizeof(int) * size);
	if (!array_temp)
	{
		free(count);
		return;
	}

	/* sort elements into their right position in a temp array */
	for ( ; i != 0; --i)
		array_temp[count[i - 1] - 1] = i - 1;
	/* copy sorted to the original array */
	for (i = 0; i < size; ++i)
		array[i] = array_temp[i];
	free(array_temp);
}
