#include <stdio.h>
#include <math.h>

int insertion_sort(int array[10], int array_length)
{
	int num1, key, num2;
	for (num1 = 1; num1 < array_length; num1++)
	{
		key = array[num1];
		num2 = num1 - 1;

		while (num2 >= 0 && array[num2] > key)
		{
			array[num2 + 1] = array[num2];
			num2--;
		}
	array[num2 + 1] = key;
	}
	
	return 0;
}


void print_array(int array[10], int array_length)
{
	int i;
	for (i = 0; i < array_length; i++)
		printf("%d\n", array[i]);
}
int main(void)
{
	int unsorted_array[10] = {99, 76, 1, 20001, 900001, 69, 3737, 77, 8, 2001};
	int array_length = sizeof(unsorted_array) / sizeof(unsorted_array[0]);

	insertion_sort(unsorted_array, array_length);
	print_array(unsorted_array, array_length);

	return 0;
}
