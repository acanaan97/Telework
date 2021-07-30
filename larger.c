#include <stdio.h>

//This program compares the first and last, second and second to last etc integers in an array, storing the larger.
int main()
{
	int i, n; //n used to let user determine array length

	printf("Enter the length of the array: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter the elements of the array: ");

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("\n");

	int length = 0;
	//This if else is to determine size of array 2 depending on if n is even/odd
	if ((n % 2) == 0)
		length = n / 2;
	else
		length = (n / 2) + 1;

	int a2[length];
	printf("Output array: ");

	if ((n % 2) == 0)
	{
		//Comparing values in first array, and setting those values into array 2
		for (i = 0; i < (n / 2); i++)
		{
			if (a[n - 1 - i] > a[i])
			{
				a2[i] = a[n - 1 - i];
				printf("%d ", a2[i]);
			}
			else
			{
				a2[i] = a[i];
				printf("%d ", a2[i]);
			}
		}
	}

	else
	{
		for (i = 0; i < (n / 2); i++)
		{
			if (a[n - 1 - i] > a[i])
			{
				a2[i] = a[n - 1 - i];
				printf("%d ", a2[i]);
			}
			else
			{
				a2[i] = a[i];
				printf("%d ", a2[i]);
			}
		}

		//Prints the middle value of an array with odd index
		a2[n / 2] = a[n / 2];
		printf("%d ", a2[(n / 2)]);
	}

	return 0;
}
