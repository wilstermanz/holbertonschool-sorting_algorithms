#include "sort.h"
#include <stdlib.h>

void build_max_heap(int *array, size_t heapSize);
void heapify(int *array, size_t heapSize, size_t parentIndex);
void swap_nodes(int *array, size_t indexA, size_t indexB);

/**
 * heap_sort - Sorts an array of numbers using the heap method
 *
 * @array: array to sort
 * @size: length of array
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t heapSize;

	if (!array || size <= 1)
		return;

	build_max_heap(array, size);
	for (heapSize = size; heapSize > 0; heapSize--)
	{
		swap_nodes(array, 0, heapSize - 1);
		heapify(array, heapSize, 0);
	}
}

/**
 * build_max_heap - heapifies an unsorted array
 *
 * @array: array to heapify
 * @size: length of array
 *
 */
void build_max_heap(int *array, size_t size)
{
	int nodeIndex;

	for (nodeIndex = size / 2 - 1; nodeIndex >= 0; nodeIndex--)
		heapify(array, size, nodeIndex);
}

/**
 * heapify - heapifies a node and its children
 * and recursively sifts smaller values down
 *
 * @array: entire array
 * @heapSize: size of heap within array
 * @parentIndex: index of parent node
 *
 */
void heapify(int *array, size_t heapSize, size_t parentIndex)
{
	size_t leftNodeIndex = parentIndex * 2 + 1;
	size_t rightNodeIndex = leftNodeIndex + 1;
	size_t largestIndex = parentIndex;

	if (leftNodeIndex < heapSize - 1
			&& array[leftNodeIndex] > array[largestIndex])
		largestIndex = leftNodeIndex;

	if (rightNodeIndex < heapSize - 1
			&& array[rightNodeIndex] > array[largestIndex])
		largestIndex = rightNodeIndex;

	if (largestIndex != parentIndex)
	{
		swap_nodes(array, largestIndex, parentIndex);
		heapify(array, heapSize, largestIndex);
	}
}

/**
 * swap_nodes - Swaps two values in an int array
 *
 * @array: array of ints
 * @indexA: first value to swap
 * @indexB: second value to swap
 *
 */
void swap_nodes(int *array, size_t indexA, size_t indexB)
{
	int temp = array[indexA];

	array[indexA] = array[indexB];
	array[indexB] = temp;
	print_array(array, 10);
}
