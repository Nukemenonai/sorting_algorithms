#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: the poiter to the array to sort
 * @size: the size of the array
 *
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int exch;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				exch = array[j + 1];
				array[j + 1] = array[j];
				array[j] = exch;
				print_array(array, size);
			}
		}
	}
}
