#include <stdio.h>

#include <stdlib.h>

#define MAX_SIZE 50

void traverse();
void insert();
void delete();

int array[MAX_SIZE], size, i, number, position;

void main() {
  printf("Enter size of array:\n");
  scanf("%d", & size);
  printf("Enter the elements of the array:\n");

  for (i = 0; i < size; i++) {
    scanf("%d", & array[i]);
  }

  while (1) {
  int choice;
    printf("Choose an option (number): \n");
    printf("1. Traverse array \n");
    printf("2. Insert an element into the array \n");
    printf("3. Delete an element from the array \n");
    printf("4. Quit \n");
    scanf("%d", & choice);

    switch (choice) {
    case 1:
      traverse();
      break;
    case 2:
      insert();
      break;
    case 3:
      delete();
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
  printf("Elements of the array are:\n");
  for(i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insert() {
  printf("Enter the number to be inserted:\n");
  scanf("%d", &number);
  printf("Enter the position of the number to be inserted:\n");
  scanf("%d", &position);
  size++;

  if(position <= 0 || position > size + 1) {
    printf("Invalid position!\n");
  } else {
    for(i = size -1; i >= position - 1; i--) {
      array[i + 1] = array[i];
    }
    array[position - 1] = number;
    printf("Element inserted!\n");
  }
}

void delete() {
  printf("Enter the position of the number to be deleted: \n");
  scanf("%d", &position);
  
  if(position <= 0 || position > size) {
    printf("Invalid position");
  } else {
    for(i = position-1; i <= size; i++) {
      array[i] = array[i + 1];
    }
    size--;
    printf("Item deleted!\n");
    traverse();
  }
}