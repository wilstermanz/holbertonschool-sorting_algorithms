#include "sort.h"
#include <stdio.h>

void merge(int *leftArray, size_t leftSize, int *rightArray, size_t rightSize);

/**
 * merge_sort - merge sort recursively
 *
 * @array: int array to sort
 * @size: size of array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *leftArray = &array[0];
	int *rightArray = &array[size / 2];
	int leftSize = size / 2;
	int rightSize = size - leftSize;

	if (!array || size <= 1)
		return;

	merge_sort(leftArray, leftSize);
	merge_sort(rightArray, rightSize);

	merge(leftArray, leftSize, rightArray, rightSize);
}

/**
 * merge - merges arrays
 *
 * @leftArray: left array
 * @leftSize: size of left array
 * @rightArray: right array
 * @rightSize: size of right array
 * Return: void
 */

void merge(int *leftArray, size_t leftSize, int *rightArray, size_t rightSize)
{
	int tempArray[1024];
	int tempSize = leftSize + rightSize;
	int i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	print_array(leftArray, leftSize);
	printf("[right]: ");
	print_array(rightArray, rightSize);
	while (leftSize && rightSize)
	{
		if (leftArray[i] < rightArray[j])
		{
			tempArray[k] = leftArray[i];
			i++, k++, leftSize--;
		}
		else
		{
			tempArray[k] = rightArray[j];
			j++, k++, rightSize--;
		}
	}
	while (leftSize)
	{
		tempArray[k] = leftArray[i];
		i++, k++, leftSize--;
	}
	while (rightSize)
	{
		tempArray[k] = rightArray[j];
		j++, k++, rightSize--;
	}
	for (i = 0; i < tempSize; i++)
		leftArray[i] = tempArray[i];
	printf("[Done]:");
	print_array(leftArray, tempSize);
}
