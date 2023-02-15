#include "sort.h"

/**
 * count_sort - Uses count sort to sort an array by LSD
 *
 * @array: Array to sort, contains only numbers >= 0
 * @size: Number of items in array
 * @sig_dig: significant digit to sort by
 */
void count_sort(int *array, size_t size, size_t sig_dig)
{
	int key_arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int index_arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *buffer = malloc(sizeof(*array) * size);
	size_t i, key;

	for (i = 0; i < size; i++)
	{
		key = array[i] % (sig_dig * 10) / sig_dig;
		key_arr[key]++;
	}

	for (i = 0; i < 9; i++)
	{
		index_arr[i + 1] = index_arr[i] + key_arr[i];
	}

	for (i = 0; i < size; i++)
	{
		key = array[i] % (sig_dig * 10) / sig_dig;
		buffer[index_arr[key]] = array[i];
		index_arr[key]++;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = buffer[i];
	}
	free(buffer);
}

/**
 * get_max - gets max value in array
 *
 * @array: array of ints
 * @size: length of array
 * Return: max int
 */
size_t get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * radix_sort - Uses LSD Radix to sort an array of integers in ascending order
 *
 * @array: Array to sort, contains only numbers >= 0
 * @size: Number of items in array
 */
void radix_sort(int *array, size_t size)
{
	size_t sig_dig;
	int max;

	if (array && size > 1)
	{
		max = get_max(array, size);
		for (sig_dig = 1; max / sig_dig > 0; sig_dig *= 10)
		{
			count_sort(array, size, sig_dig);
			print_array(array, size);
		}
	}
}
