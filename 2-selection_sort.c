#include "sort.h"

/**
 * selection_sort - sort data in array via selection sort algorithm
 *
 * @array: data
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	int x = 0, temp, smallest, small_idx;

	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		small_idx = i;
		for (x = i; x < (int)size; x++)
		{
			if (array[x] < smallest)
			{
				smallest = array[x];
				small_idx = x;
			}
		}

		if (small_idx != (int)i)
		{
			temp = array[i];
			array[i] = smallest;
			array[small_idx] = temp;

			print_array(array, size);
		}

	}
}
