#include "sort.h"

void comp_swap(int *array, int i, int j, int dir)
{
	int save;

	if (dir == (array[i] > array[j]))
	{
		save = array[i];
		array[i] = array[j];
		array[j] = save;
	}
}

void bitonic_merge(int *array, int start, int num_elem, int dir, size_t size_a)
{
	int i, k;

	if (num_elem > 1)
	{
		k = num_elem / 2;
		for (i = start; i < (start + k); i++)
		{
			comp_swap(array, i, (i + k), dir);
		}
		bitonic_merge(array, start, k, dir, size_a);
		bitonic_merge(array, (start + k), k, dir, size_a);
	}
}

void bitonic_sort_rec(int *array, int start, int n_el, int dir, size_t size_a)
{
	int k, j;

	if (n_el > 1)
	{
		k = n_el / 2;
		if (dir == 1)
			printf("Merging [%d/%lu] (UP)\n", n_el, size_a);
		else
			printf("Merging [%d/%lu] (DOWN)\n", n_el, size_a);
		for (j = start; j < start + n_el; j++)
		{
			printf("%d", array[j]);
			if (j < start + n_el - 1)
				printf(", ");
		}
		printf("\n");
		bitonic_sort_rec(array, start, k, 1, size_a);
		bitonic_sort_rec(array, (start + k), k, 0, size_a);
		bitonic_merge(array, start, n_el, dir, size_a);
		if (dir == 1)
			printf("Result [%d/%lu] (UP)\n", n_el, size_a);
		else
			printf("Result [%d/%lu] (DOWN)\n", n_el, size_a);

		for (j = start; j < start + n_el; j++)
		{
			printf("%d", array[j]);
			if (j < start + n_el - 1)
				printf(", ");
		}
		printf("\n");

	}
}
/**
 *bitonic_sort - sort and array based in bitonic sort method
 *@array: unordered array
 *@size: size of given array
 *
 *Return: Nothing, it's a void function
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_rec(array, 0, (int)size, 1, size);
}
