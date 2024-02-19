#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 *                   Selection sort algorithm.
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; ++i)
	{
		min_idx = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			int temp = array[i];

			array[i] = array[min_idx];
			array[min_idx] = temp;
			/* Print the array after each swap */
			printf("After swap: ");
			for (j = 0; j < size; ++j)
				printf("%d ", array[j]);
			printf("\n");
		}
	}
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int arr[] = {64, 25, 12, 22, 11};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	for (size_t i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	selection_sort(arr, size);

	printf("Sorted array: ");
	for (size_t i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return (0);
}
