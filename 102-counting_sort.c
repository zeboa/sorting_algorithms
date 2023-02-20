#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: Pointer to list of integers
 * @size: Size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int i, j, range, max = 0, input_size = size;
	int *copyarray, *count;

	if (!array || input_size < 2)
		return;
	/* Find max value */
	for (i = 0; i < input_size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	range = max + 1;
	count = malloc(range * sizeof(int));
	for (i = 0; i < range; i++)
		count[i] = 0;
	for (i = 0; i < range; i++)
	{
		for (j = 0; j < input_size; j++)
		{
			if (i == array[j])
				count[i]++;
		}
	}
	/* Loop thru count array and update the sum of occurences */
	for (i = 1; i < range; i++)
		count[i] += count[i - 1];
	print_array(count, range);

	copyarray = malloc(input_size * sizeof(int));
	for (i = 0; i < input_size; i++)
		copyarray[i] = array[i];
	/* Loop thru original array and update with the sorted number */
	for (i = 0; i < input_size; i++)
	{
		array[count[copyarray[i]] - 1] = copyarray[i];
		copyarray[i]--;
	}
	free(count);
	free(copyarray);
}
