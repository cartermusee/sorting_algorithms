#include "sort.h"

/**
 * lomuto_partition- function to partion array
 * @array:array to partion
 * @size:size of array
 * @lb:lower bound of array
 * @up:upper bound of arrray
 */
size_t Lomuto_partition(int *array, size_t size, ssize_t lb, ssize_t up)
{
	int pivot = array[lb];
	int temp, tmp;

	while (lb < up)
	{
		while (array[lb] <= pivot)
		{
			lb++;
		}
		while (array[up] > pivot)
		{
			up--;
		}
		if (lb < up)
		{
			temp = array[lb];
			array[lb] = array[up];
			array[up] = temp;
		}
	}
	tmp = array[lb];
	array[lb] = array[up];
	array[up] = tmp;
	print_array(array, size);
	return (up);
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
		quicksort(array, size, lb, loc -1);
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
	quicksort(array, size, 0, size-1);
}	
