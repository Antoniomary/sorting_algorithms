#include "sort.h"

void merge_sort_recursion(int *array, size_t low, size_t high, int *temp);
void merge(int *array, size_t low, size_t mid, size_t high, int *temp);

/**
 * merge_sort - a function that sorts an array of integers in
 * ascending order using the Merge sort algorithm.
 * @array: the array to sort.
 * @size: the size of array.
 */
void merge_sort(int *array, size_t size)
{
	int *new_array;

	if (!array || size < 2)
		return;

	new_array = (int *) malloc(sizeof(int) * size);
	if (!new_array)
	{
		printf("memory allocation error\n");
		return;
	}

	merge_sort_recursion(array, 0, size, new_array);

	free(new_array);
}


void merge_sort_recursion(int *array, size_t low, size_t high, int *temp)
{
	size_t mid;

	if (high - low > 1)
	{
		mid = low + (high - low) / 2;

		merge_sort_recursion(array, low, mid, temp);
		merge_sort_recursion(array, mid, high, temp);
		merge(array, low, mid, high, temp);
	}
}

void merge(int *array, size_t low, size_t mid, size_t high, int *temp)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low);

	printf("[right]: ");
	print_array(array + mid, high - mid);

	i = k = low;
	j = mid;

	while (i < mid && j < high)
		temp[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

	while (i < mid)
		temp[k++] = array[i++];

	while (j < high)
		temp[k++] = array[j++];

	printf("[Done]: ");
	for (i = low; i < high; ++i)
	{
		array[i] = temp[i];
		printf("%d%s", temp[i], i + 1 == high ? "\n" : ", ");
	}
}
