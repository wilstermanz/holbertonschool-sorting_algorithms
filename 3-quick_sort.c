#include "sort.h"

/**
 *
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = (int)size - 1;

	quick_sort_recursive(array, low, high, size);
}

int *quick_sort_recursive(int *array, int low, int high, int size)
{
	int j, i, pivot, temp;

	if (low >= high)
		return array;

	pivot = array[high];
	j = low;
	for (i = low; i <+ high; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array,size);
			}
			j += 1;
		}
	}
	if (j != high)
	{
		temp = array[high];
		array[high] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	quick_sort_recursive(array, low, j - 1, size);
	quick_sort_recursive(array, j + 1, high, size);
	return (array);

}
