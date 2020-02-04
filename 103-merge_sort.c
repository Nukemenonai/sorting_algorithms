#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, size_t size, size_t m)
{
	size_t i, j, k;
	int *copy = malloc(size * sizeof (int));

	printf("Merging...\n");
	for (i = 0, j = m, k = 0; k < size; k++)
	{
		copy[k] = j == size ? array[i++]
		: i == m ? array[j++]
		: array[j] < array[i] ? array[j++]
		: array[i++];
	}

	printf("[left]: ");
	print_array(array, m);

	printf("[right]: ");
	print_array(array + m, size - m);

	for (i = 0; i < size; i++)
	{
		array[i] = copy[i];
	}

	printf("[Done]: ");
	print_array(array, size);

	free(copy);
}

void merge_sort(int *array, size_t size)
{
	size_t m;

	if (size < 2)
		return;
	m = size / 2;

	merge_sort(array, m);
	merge_sort(array + m, size - m);
	merge(array, size, m);

}
