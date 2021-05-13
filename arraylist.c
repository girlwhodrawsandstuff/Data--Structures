#include <stdio.h>

#include <stdlib.h>

#define MAX_SIZE 50

void traverse();
void delete(int);
void insert(int);

void main() {
  int array[MAX_SIZE], size, i, number, position, choice;
  printf("Enter size of array:\n");
  scanf("%d", & size);
  printf("Enter the elements of the array:\n");

  for (i = 0; i < size; i++) {
    scanf("%d", & array[i]);
  }

  printf("Choose an option (number): \n");
  printf("1. Traverse array \n");
  printf("2. Insert an element into the array \n");
  printf("3. Delete an element from the array \n");
  printf("4. Quit \n");
  scanf("%d", & choice);

  while (1) {
    switch (choice) {
    case 1:
      traverse();
      break;
    case 2:
      insert(2);
      break;
    case 3:
      delete(3);
      break;
    case 4:
      exit(0);
      break;
    default:
      printf("Invalid choice");
    };
  }

}

void traverse() {
  printf("traverse");
}

void delete(int deletedPosition) {
  printf("delete");
}

void insert(int insertedNumber) {
  printf("insert");
}