#include "sort.h"

size_t lomuto_partition(int *array, size_t low, size_t high) {
    int pivot = array[high], temp;
    size_t j, i = low;

    printf("Partitioning array from %lu to %lu:\n", low, high);
    printf("Pivot: %d\n", pivot);

    for (j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
        }
    }

    temp = array[i];
    array[i] = array[high];
    array[high] = temp;

    printf("Array after partition: ");
    print_array(array, high + 1);

    return i;
}


void quick_sort_recursive(int *array, size_t low, size_t high) {
	size_t pivot_index;

    if (low < high) {
        pivot_index = lomuto_partition(array, low, high);
        quick_sort_recursive(array, low, pivot_index);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

void quick_sort(int *array, size_t size) {
    quick_sort_recursive(array, 0, size - 1);
}
