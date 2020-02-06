#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * shell sort algorithm and the knuth sequence to create gaps (h = h * 3 + 1)
 * ...
 * h = (h-1)/3
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, out, in;
	int value;

	if (size < 2)
		return;

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	if (gap > size)
		gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (out = gap; out  < size; out++)
		{
			value = array[out];
			for (in = out;
			     in >= gap - 1 && array[in - gap] >= value;
			     in -= gap)
			{
				array[in] = array[in - gap];
			}
			array[in] = value;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}

}
