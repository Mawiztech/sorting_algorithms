#include "sort.h"

/**
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
 * partition - Partitions the array and returns the pivot index.
 * @array: Pointer to the array to be partitioned.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 *
 * Return: Index of the pivot element.
 */
int partition(int *array, int low, int high)
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
            /* Print array after each swap */
            for (int k = low; k <= high; k++)
            {
                if (k != low)
                    printf(", ");
                printf("%d", array[k]);
            }
            printf("\n");
        }
    }
    swap(&array[i + 1], &array[high]);
    /* Print array after each swap */
    for (int k = low; k <= high; k++)
    {
        if (k != low)
            printf(", ");
        printf("%d", array[k]);
    }
    printf("\n");
    return (i + 1);
}

/**
 * quicksort - Sorts the array using the Quick sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 */
void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *               the Quick sort algorithm with Lomuto partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1);
}
