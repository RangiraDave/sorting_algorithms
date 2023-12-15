#include "sort.h"

/**
 * bubble_sort - Function to implement bubble sort algorithm.
 * @array: Pointer to array to be sorted.
 * @size: Size of the array.
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);

				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}

