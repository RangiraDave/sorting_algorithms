#include "sort.h"

/**
 * swap - Function to swap two integers.
 * @a: Pointer to first integer.
 * @b: Pointer to second integer.
 * Return: Nothing.
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}


/**
 * lomuto_partition - Function to partition the array into two parts.
 * @array: Array to partition.
 * @low: Smaller element index.
 * @high: Higher element index.
 * Return: Partition index.
 */

size_t lomuto_partition(int *array, size_t low, size_t high)
{
	size_t i, j;
	int pivot;

	pivot = array[high];
	i = low;
	for (j = low; j <= high - 1; j++)
	{
		printf("i: %lu, j: %lu\n", (long unsigned int)i, (long unsigned int)j);
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, high);

	return (i + 1);
}


/**
 * recursive_partition - Function to recursively partition subarrays.
 * @array: A subarray to partition.
 * @low: Higher index of the smaller array.
 * @high: Higher index of the larger array.
 * Return: Nothing.
 */

void recursive_partition(int *array, size_t low, size_t high)
{
	size_t piv_index;

	if (low < high)
	{
		piv_index = lomuto_partition(array, low, high);

		recursive_partition(array, low, piv_index - 1);
		recursive_partition(array, piv_index + 1, high);
	}
}

/**
 * quick_sort - Function to implement quick sort sorting
 * algorithm with Lomuto partitioning scheme.
 * @array: Array to be quick sorted.
 * @size: Size of the array.
 * Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	recursive_partition(array, 0, size - 1);
}
