#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: pointer to an array
 * @size: size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin, temp;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[jMin] > array[j])
				jMin = j;
		}
		if (jMin != i)
		{
			temp = array[i];
			array[i] = array[jMin];
			array[jMin] = temp;
			print_array(array, size);
		}
	}
}
