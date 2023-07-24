#include "sort.h"

/**
 * Lomuto_partition- function to partion array
 * @array:array to partion
 * @size:size of array
 * @lb:lower bound of array
 * @up:upper bound of arrray
 * Return:upper bound
 */
size_t Lomuto_partition(int *array, size_t size, ssize_t lb, ssize_t up)
{
	int pivot = array[up];
	ssize_t start = lb - 1;
	ssize_t j;
	int temp;

	for (j = lb; j <= up - 1; j++)
	{
		if (array[j] <= pivot)
		{
			start++;
			temp = array[start];
			array[start] = array[j];
			array[j] = temp;
		}
	}
	temp = array[start + 1];
	array[start + 1] = array[up];
	array[up] = temp;
	print_array(array, size);
	return (start + 1);
}

/**
 * quicksort - function to sort
 * @array:the array to sort
 * @size:size of array
 * @lb:lower bound
 * @up:upper bound
 */
void quicksort(int *array, size_t size, ssize_t lb, ssize_t up)
{
	size_t loc;

	if (lb < up)
	{
		loc = Lomuto_partition(array, size, lb, up);
		quicksort(array, size, lb, loc - 1);
		quicksort(array, size, loc + 1, up);
	}
}
/**
 * quick_sort - function to sort by partion
 *@array:array to sort
 *@size:size of arrray
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}
	quicksort(array, size, 0, size - 1);
}
