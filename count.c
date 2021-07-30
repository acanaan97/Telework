#include <stdio.h>
#include <ctype.h>

//This program displays letters, digits, and special characters within a sentence.
void count(int *num_letters, int *num_digits, int *num_special);

int main()
{
	int num_letters = 0;
	int num_digits = 0;
	int num_special = 0;

	count(&num_letters, &num_digits, &num_special);

	printf("There are %d letters, %d digits, and %d special characters.", num_letters, num_digits, num_special);

	return 0;
}

void count(int *num_letters, int *num_digits, int *num_special)
{
	char c, input[100];
	int i = 0, j = 0;
	//Counts letters, digits, and special chars
	int countL = 0, countD = 0, countS = 0;

	printf("Enter a sentence: ");
	while ((c = getchar()) != '\n')
	{
		input[i] = c;
		i++;
	}
	input[i] = '\0';

	for (j = 0; j < i; j++)
	{
		//If given character is within A-Z or a-z
		if ((input[j] >= 'A' && input[j] <= 'Z') || (input[j] >= 'a' && input[j] <= 'z'))
		{
			countL++;
		}
		//If given value is a digit
		if (isdigit(input[j]))
		{
			countD++;
		}
		//If given value is not within A-Z, a-z, or is not a digit
		if (!(input[j] >= 'A' && input[j] <= 'Z') && !(input[j] >= 'a' && input[j] <= 'z'))
		{
			if (!isdigit(input[j]))
			{
				countS++;
			}
		}
	}
	*num_digits = countD;
	*num_letters = countL;
	*num_special = countS;
}
