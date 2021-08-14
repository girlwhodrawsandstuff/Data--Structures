#include <stdio.h>
void search();

void main()
{
	int array[] = { 2, 3, 4, 10, 40 };
	int number;
	int numberOfElements = sizeof(array) / sizeof(array[0]);
	printf("Enter the number you're looking for:\n");
    scanf("%d", &number);
	search(array, numberOfElements, number);
}

void search(int array[], int numberOfElements, int number)
{
    int flag = 0;
    int left = 0;
    int right = numberOfElements - 1;
	while (left <= right) {
		int midValue = left + (right - left) / 2;

		if (array[midValue] == number) {
			printf("Number '%d' was found at index position '%d'.\n", number, midValue);
			flag = 1;
			break;
		}

		if (array[midValue] < number) {
			left = midValue + 1;
		} else {
			right = midValue - 1;
		}
	}
	
	if(flag == 0) {
	printf("Sorry, but the number wasn't found.\n");
	}
}