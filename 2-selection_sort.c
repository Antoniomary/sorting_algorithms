#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order using the Selection sort algorithm.
 * @array: the array to sort.
 * @size: the size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int former_min;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for (j = i + 1; j < size; ++j)
			if (array[j] < array[min_index])
				min_index = j;

		if (min_index != i)
		{
			former_min = array[i];
			array[i] = array[min_index];
			array[min_index] = former_min;
			print_array(array, size);
		}
	}
}
