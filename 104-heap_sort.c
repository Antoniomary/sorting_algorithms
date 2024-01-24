#include "sort.h"

void swap(int *a, int *b);
void heapify(int *array, size_t count, size_t size);
void sift_down(int *array, size_t count, size_t size, size_t parent);
void delete_max(int *array, size_t size);

/**
 * heap_sort - a function that sorts an array of integers
 * in ascending order using the Heap sort algorithm.
 * @array: the array to sort.
 * @size: the size of array.
 *
 * Description: It uses the sift-down heap sort algorithm.
 */
void heap_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	heapify(array, size, size);
	delete_max(array, size);
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
 * sift_down - a function that maintains the heap property.
 * @array: the array to sort.
 * @count: the immediate size of array.
 * @size: the original size of array.
 * @i: a supposed parent node.
 */
void sift_down(int *array, size_t count, size_t size, size_t i)
{
	size_t max = i;
	size_t left_node = i * 2 + 1;
	size_t right_node = i * 2 + 2;

	if (left_node < count && array[max] < array[left_node])
		max = left_node;

	if (right_node < count && array[max] < array[right_node])
		max = right_node;

	if (max != i)
	{
		swap(&array[max], &array[i]);
		print_array(array, size);
		sift_down(array, count, size, max);
	}
}

/**
 * heapify - a function that determines where to call sift-down.
 * @array: the array to sort.
 * @count: the immediate size of array.
 * @size: the original size of array.
 */
void heapify(int *array, size_t count, size_t size)
{
	size_t i;

	for (i = (count - 1) / 2; i < count; --i)
		sift_down(array, count, size, i);
}

/**
 * delete_max - a function that deletes the max element of an array;
 * @array: the array.
 * @size: the size of the array.
 */
void delete_max(int *array, size_t size)
{
	size_t i;

	for (i = size - 1; i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, size);
	}
}
