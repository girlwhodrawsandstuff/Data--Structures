#include <stdio.h>

void search();

void main() {
    int array[] = {30, 20, 40, 60, 70, 100};
    int number;
    int numberOfElements = sizeof(array) / sizeof(array[0]);

    printf("Enter the number you're looking for:\n");
    scanf("%d", &number);
    search(array, numberOfElements, number);
}

void search(int array[], int numberOfElements, int number) {
    int i, flag = 0;
    for(i = 0; i < numberOfElements; i++) {
        if (array[i] == number)
        {
            printf("Number '%d' was found at index position '%d'.\n", number, i);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Sorry, but the number wasn't found.\n");
    }   
}