#include "sort.h"

/**
 * swap - Swaps two elements
 * @a: first element
 * @b: second element
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions a given list of unsorted numbers using
 *Lomuto's method
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 * @size: size of the array
 *
 * Return: Nothing
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: Pointer to an array
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Nothing
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order using the Q\
uick
* sort algorithm
* @array: Pointer to an array
* @size: Size of the array
*
* Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
