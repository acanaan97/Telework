#include <stdio.h>

//This program converts array elements as the sum of the element plus six modulus 10

void convert(int *a1, int n, int *a2);

int main()
{
	int n, i;
	//Declaring pointers to a1 and a2
	printf("Please enter the array length: ");
	scanf("%d", &n);
	int arr1[n];
	int *a1 = arr1;

	printf("Please enter array elements: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", a1 + i);
	}

	int arr2[n];
	int *a2 = arr2;

	convert(a1, n, a2);
	printf("Output: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a2[i]);
	}

	return 0;
}

void convert(int *a1, int n, int *a2)
{
	int *p, *q = a2;
	//Calculations using local pointers to a1 and a2
	for (p = a1; p < a1 + n; p++)
	{
		*p = (*p + 6) % 10;
		*q = *p;
		q++;
	}
}
