#include "sort.h"

void swap ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
/*
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme.
 * @array: Pointer to the array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: Index of the pivot element after partitioning.
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

/**
 * lomuto_sort - Sorts the array using Lomuto sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 */
void lomuto_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high);

        lomuto_sort(array, low, pi - 1);
        lomuto_sort(array, pi + 1, high);
    }
}

/**
 * quick_sort - Sorts the array using Quick sort algorithm with Lomuto partition scheme.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 */
void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high);

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}
