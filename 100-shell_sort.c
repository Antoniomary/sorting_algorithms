#include "sort.h"

void swap(int *a, int *b);

/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: the array to sort.
 * @size: the size of array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	for ( ; gap >= 1; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; ++i)
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
				swap(&array[j], &array[j - gap]);
		print_array(array, size);
	}
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
