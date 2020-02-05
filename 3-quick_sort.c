#include "sort.h"

/**
 * partition - crates a partition following the louto partition scheme
 *
 * @array: the array to sort
 * @low: the lowest position of the partition
 * @high: the highes position of the partition
 * @size: the size of the array
 *
 * Return: the position to perform recursion
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, save;

	pivot = array[high];
	i = low;
	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				save = array[i];
				array[i] = array[j];
				array[j] = save;
				print_array(array, size);
				i++;
			}
		}
	}
	if (array[i] != array[high])
	{
		save = array[i];
		array[i] = array[high];
		array[high] = save;
		if (i != high)
			print_array(array, size);
	}
	return (i);
}

/**
 * quick - performs the recursion of the quicksort algorithm
 *
 * @array: array to sort
 * @low: lowest position
 * @high: highest position
 * @size: size of the array
 */

void quick(int *array, int low, int high, size_t size)
{
	int pos;

	if (low < high)
	{
		pos  = partition(array, low, high, size);
		quick(array, low, pos - 1, size);
		quick(array, pos + 1, high, size);
	}
}

/**
 * quick_sort - sort an array by quicksort method
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing, it's a void functions
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick(array, 0, (int)size - 1, size);
}
