#include "sort.h"

/**
 * bubble_sort - sort an int array with bubble sort
 *
 * @array: array of integers
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, did_a_swap;

	do {
		did_a_swap = 0;

		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				did_a_swap++;

				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				print_array(array, size);
			}
		}
	} while (did_a_swap);
}
