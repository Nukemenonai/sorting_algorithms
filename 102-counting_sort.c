#include "sort.h"

/**
 *counting_sort - sort and array by counting sort method
 *@array: input array to be sorted
 *@size: size of the array
 *
 *Return: Nothing, it's a void function
 */
void counting_sort(int *array, size_t size)
{
	size_t k;
	int max_num, i;
	int *count_array, *sort_array;

	max_num = array[0];
	sort_array = malloc(size * sizeof(int));
	if (sort_array == NULL)
	{
		free(sort_array);
		return;
	}
	for (k = 0; k < size; k++)
		sort_array[k] = array[k];
	for (k = 0; k < size; k++)
	{
		if (array[k] > max_num)
			max_num = array[k];
	}
	count_array = malloc((max_num + 1) * sizeof(int));
	if (count_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i <= max_num; i++)
		count_array[i] = 0;
	for (k = 0; k < size; k++)
		count_array[array[k]]++;
	for (i = 1; i <= max_num; i++)
		count_array[i] = count_array[i] + count_array[i - 1];
	for (i = 0; i <= max_num; i++)
	{
		printf("%d", count_array[i]);
		if (i < max_num)
			printf(", ");
		else
			printf("\n");
	}
	for (k = 0; k < size; k++)
	{
		sort_array[count_array[array[k]] - 1] = array[k];
		count_array[array[k]] = count_array[array[k]] - 1;
	}
	for (k = 0; k < size; k++)
		array[k] = sort_array[k];
	free(count_array);
}
