#include "sort.h"

/**
 * swap-swap elemnts
 * @array:array to swap el
 * @size:size of array
 * @i:1 elemnt
 * @j:second
 */
void swap(int *array, size_t size, int *i, int *j)
{
	if (*i != *j)
	{
		*i = *i + *j;
		*j = *i - *j;
		*i = *i - *j;
		print_array((const int *)array, size);
	}
}

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
	int k, j, pivot = array[up];

	for (k = j = lb; j < up; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[k++]);
	swap(array, size, &array[k], &array[up]);

	return (k);
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
