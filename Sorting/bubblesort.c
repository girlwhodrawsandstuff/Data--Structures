#include <stdio.h>

void bubbleSort();
void printSortedList();
void swap();

void main() {
    int array[] = {1, 50, 25, 40, 88, 22, 31};
    int arraySize = sizeof(array) / sizeof(array[0]);

    bubbleSort(array, arraySize);
    printf("The sorted list is:\n");
    printSortedList(arraySize, array);
}

void bubbleSort(int array[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {    
       for (j = 0; j < size - i - 1; j++) {
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
       }
    }
}

void swap(int *currentValue, int *nextValue) {
    int temp = *currentValue;
    *currentValue = *nextValue;
    *nextValue = temp;
}

void printSortedList(int size, int array[]) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}