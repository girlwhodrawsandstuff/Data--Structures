#include <stdio.h>

#include <stdlib.h>

#define CAPACITY 5

void push(int);
int pop();
void traverse();
void peek();

//Global variables
int stack[CAPACITY], top = -1;

void main() {

  while (1) {
    int choice, item;

    printf("Choose an option: \n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. Traverse \n");
    printf("4. Peek \n");
    printf("5.Quit \n");
    scanf("%d", & choice);

    switch (choice) {
    case 1:
      printf("Enter the item to be inserted:\n");
      scanf("%d", & item);
      push(item);
      break;
    case 2:
      pop();
      break;
    case 3:
      traverse();
      break;
    case 4:
      peek();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("Invalid Option");
    };
  }
}

void push(int item) {
  if (top >= CAPACITY - 1) {
    printf("Stack is overflowed.\n\n");
  } else {
    top++;
    stack[top] = item;
    printf("Element pushed\n\n");
  }
}

int pop(void) {
  if (top == -1) {
    printf("Stack is empty\n\n");
  } else {
    printf("Popped item: %d\n\n", stack[top]);
    top--;
  }
}

void traverse(void) {
  if(top == -1) {
    printf("Stack is empty\n\n");
  } else {
    printf("Elements of the stack are (from top to bottom): \n");
      for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
      }
  }
}

void peek(void) {
  if(top == -1) {
    printf("Stack is empty\n\n");
  } else {
    printf("The topmost element of the stack is:\n\n");
    printf("%d\n", stack[top]);
  }
}