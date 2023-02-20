#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble
 * sort algorithm
 * @array: pointer to a list of array
 * @size: size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t c, d, temp;

	if (array != NULL)
	{
		for (c = 0; c < size - 1; c++)
		{
			for (d = 0; d < size - c - 1; d++)
			{
				if (array[d] > array[d + 1])
				{
					temp = array[d];
					array[d] = array[d + 1];
					array[d + 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
