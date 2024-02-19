#include "sort.h"

/**
 * swap - Swaps two integer values.
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
 * partition - Lomuto partition scheme.
 * @array: Array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: Index of the pivot element after partitioning.
 */
size_t partition(int *array, size_t low, size_t high)
{
	int pivot = array[high]; /* Pivot is always the last element */
	size_t i = low - 1;

	for (size_t j = low; j <= high - 1; j++)
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
 * quick_sort_helper - Recursive function to implement Quick sort.
 * @array: Array to be sorted.
 * @low: Starting index of the array or partition.
 * @high: Ending index of the array or partition.
 */
void quick_sort_helper(int *array, size_t low, size_t high)
{
	if (low < high)
	{
		size_t pi = partition(array, low, high);

		/* Print the array after each swap */
		printf("After swap: ");
		for (size_t k = low; k <= high; ++k)
			printf("%d ", array[k]);
		printf("\n");

		quick_sort_helper(array, low, pi - 1);
		quick_sort_helper(array, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	for (size_t i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	quick_sort(arr, size);

	printf("Sorted array: ");
	for (size_t i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return (0);
}
