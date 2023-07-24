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
	int pivot = array[lb + (up - lb) / 2];
	ssize_t start = lb;
	ssize_t end = up;
	int temp;

	while (start <= end)
	{
		while (array[start] < pivot)
		{
			start++;
		}
		while (array[end] > pivot)
		{
			end--;
		}
		if (start <= end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			start++;
			end--;
		}
	}
	print_array(array, size);
	return (start - 1);
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
		quicksort(array, size, lb, loc);
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
