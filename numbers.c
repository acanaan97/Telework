#include <stdio.h>
//This program displays repeated value in an array, if one exits.
int three_numbers(int a[], int n, int *number);

int main()
{
	int n, i;
	int number = 0;

	printf("Enter the length of the array: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter the elements of the array: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	if (three_numbers(a, n, &number) == 1)
		printf("The sentence has repeated value: %d", number);
	else
		printf("The array has no repeated values.");

	return 0;
}

int three_numbers(int a[], int n, int *number)
{
	int i, j;
	int counter = 0;

	for (i = 0; i < n - 1; i++)
	{

		if (counter == 2)
			break;
		counter = 0;
		for (j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				*number = a[i];
				counter++;
			}
		}
	}
	if (counter == 2)
		return 1;
	else
		return 0;
} //if counter = 2 then the array has repeated value: (value), otherwise the array has no repeated values
