#include "sort.h"

/**
 * selection_sort - Function to implement the selection sort.
 * @array: Array of elements to be sorted.
 * @size: Size of the array.
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, s, t;
	int temp;

	if (!array || size == 1)
		return;

	for (i = 0; i < size; i++)
	{
		s = i;
		for (t = i + 1; t < size; t++)
		{
			if (array[s] > array[t])
				s = t;
		}
		if (s != i)
		{
			temp = array[i];
			array[i] = array[s];
			array[s] = temp;
			print_array(array, size);
		}
	}
}
