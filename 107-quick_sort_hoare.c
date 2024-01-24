#include "sort.h"

void swap(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void quick_sort_recursion(int *array, int low, int high, size_t size);

/**
 * quick_sort_hoare - a function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: the array to sort.
 * @size: the size of array.
 *
 * Description: The Hoare partition scheme was used.
 * Here, the last index is used as the pivot.
 * Also, it set two variables at start and end and updates them based
 * on the position of the elements in the array, <= pivot or > pivot.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - a recursive function to continuously sort array.
 * @ar: the array being sorted.
 * @low: the upper bound.
 * @high: the lower bound.
 * @size: the size of array.
 */
void quick_sort_recursion(int *ar, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(ar, low, high, size);
		quick_sort_recursion(ar, low, pivot_index - 1, size);
		quick_sort_recursion(ar, pivot_index, high, size);
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

/**
 * partition - it sorts an array around a pivot using Hoare scheme.
 * @array: the array to sort.
 * @low: the start point.
 * @high: the end point.
 * @size: the size of array.
 *
 * Return: the index of the pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int start = low - 1;
	int end = high + 1;

	while (start < end)
	{
		do {
			++start;
		} while (array[start] < pivot);

		do {
			--end;
		} while (array[end] > pivot);

		if (start < end)
		{
			swap(&array[start], &array[end]);
			print_array(array, size);
		}
	}

	return (start);
}
