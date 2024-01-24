#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm.
 * @array: the array to sort.
 * @size: the size of array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	bool swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		swapped = false;
		for (j = 0; j < size - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
