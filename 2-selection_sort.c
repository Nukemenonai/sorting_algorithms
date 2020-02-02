#include "sort.h"

/**
 *selection_sort - sort an array by selection sort method
 *@array: array to sort
 *@size: size of the array
 *
 *Return: Nothing, it's a void function
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, pos_min;
	int min;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		pos_min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				pos_min = j;
			}

		}
		if (pos_min == i)
			continue;
		array[pos_min] = array[i];
		array[i] = min;
		print_array(array, size);
	}
}
