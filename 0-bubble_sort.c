#include "sort.h"

/**
 *bubble_sort - function to sort by bubble
 *@array:array to sort
 *@size:size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swap = 0;

	if (array == NULL || !size)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - 1 - i ; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (swap == 0)
		{
			break;
		}
	}
}
