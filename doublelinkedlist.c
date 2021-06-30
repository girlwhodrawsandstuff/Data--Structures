#include <stdio.h>

#include <stdlib.h>

void addAtBegin();
void addInBetween();
void addAtEnd();
int length();
void display();
void reverse();
void deleteFromBeginning();
void deleteInBetween();
void deleteAtEnd();

struct node {
  int data;
  struct node * prev;
  struct node * next;
};

struct node * root = NULL;

void main() {
  int choice;

  while (1) {
    printf("Choose an option: \n");
    printf("1. Insert at the beginning \n");
    printf("2. Insert in between \n");
    printf("3. Insert at end \n");
    printf("4. Length \n");
    printf("5. Display elements \n");
    printf("6. Reverse List \n");
    printf("7. Delete from beginning\n");
    printf("8. Delete in between \n");
    printf("9. Delete at end \n");
    printf("10. Quit \n");
    scanf("%d", & choice);

    switch (choice) {
    case 1:
      addAtBegin();
      break;

    case 2:
      addInBetween();
      break;

    case 3:
      addAtEnd();
      break;

    case 4:
      printf("Length: %d\n", length());
      break;

    case 5:
      display();
      break;

    case 6:
      reverse();
      break;

    case 7:
      deleteFromBeginning();
      break;

    case 8:
      deleteInBetween();
      break;

    case 9:
      deleteAtEnd();
      break;

    case 10:
      exit(0);

    default:
      printf("Invalid choice\n");
    }
  }
}

void addAtBegin() {
  struct node * temp;
  temp = (struct node * ) malloc(sizeof(struct node));

  printf("Enter the node data: \n");
  scanf("%d", & temp -> data);
  temp -> prev = NULL;
  temp -> next = NULL;

  if (root == NULL) {
    root = temp;
  } else {
    // next side connection
    temp -> next = root;
    // prev side connection
    root -> prev = temp;
    root = temp;
  }

  printf("Node added!\n");
}

void addInBetween() {
  struct node * temp, * p;
  int location, len, i = 1;
  len = length();

  printf("Enter the location for insertion: \n");
  scanf("%d", & location);

  if (location > len) {
    printf("Invalid location. \n");
    printf("Length of the list is %d\n", len);
  } else if (len < 2) {
    printf("The list must have at least 2 nodes to insert in between\n");
  } else {
    temp = (struct node * ) malloc(sizeof(struct node));
    p = root;

    printf("Enter the node data: \n");
    scanf("%d", & temp -> data);
    temp -> next = NULL;
    temp -> prev = NULL;

    while (i < location) {
      p = p -> next;
      i++;
    }

    // next side connection for temp
    temp -> next = p -> next;
    // next node's prev side
    p -> next -> prev = temp;
    // prev side connection for temp
    temp -> prev = p;
    // previous node's next side
    p -> next = temp;
    printf("Node added!\n");
  }
}

void addAtEnd() {
  struct node * temp;
  temp = (struct node * ) malloc(sizeof(struct node));

  printf("Enter the node data: \n");
  scanf("%d", & temp -> data);
  temp -> prev = NULL;
  temp -> next = NULL;

  if (root == NULL) {
    root = temp;
  } else {
    struct node * p;
    p = root;

    while (p -> next != NULL) {
      p = p -> next;
    }

    p -> next = temp;
    temp -> prev = p;
    printf("Node added!\n");
  }
}

int length() {
  struct node * temp = root;

  int count = 0;

  while (temp != NULL) {
    temp = temp -> next;
    count++;
  }

  return count;
}

void display() {
  struct node * temp = root;

  if (temp == NULL) {
    printf("List is empty.\n");
  } else {
    while (temp != NULL) {
      printf("%d -> ", temp -> data);
      temp = temp -> next;
    }
    printf("\n");
  }
}

void reverse() {
  struct node * current = root;
  struct node * nextNode = current -> next;

  current -> next = NULL;
  current -> prev = nextNode;

  while (nextNode != NULL) {
    nextNode -> prev = nextNode -> next;
    nextNode -> next = current;
    current = nextNode;
    nextNode = nextNode -> prev;
  }

  root = current;
  printf("List reversed!\n");
}

void deleteFromBeginning() {
  struct node * temp;

  if (root == NULL) {
    printf("List is empty.\n");
  } else {
    temp = root;

    root = root -> next;

    if (root != NULL)
      root -> prev = NULL;

    free(temp);
  }
  printf("Node deleted!\n");
}

void deleteInBetween() {
  int i = 1;
  int location, len = length();
  struct node * temp = root;
  struct node * p = NULL;

  printf("Enter the location to be deleted: \n");
  scanf("%d", & location);

  if (0 >= location > len) {
    printf("Invalid location! \n");
    printf("The list had %d nodes", len);
  } else if (location == 1) {
    deleteFromBeginning();
  } else {
    while (i < location) {
        temp = temp -> next;
        i++;
    }

    if (temp -> next == NULL) {
        deleteAtEnd();
    } else {
        p = temp -> prev;
        p -> next = temp -> next;
        temp -> next -> prev = p;
        free(temp);
        printf("Node deleted!\n");
    }
  }
}

void deleteAtEnd() {
  struct node * temp = root, * p = NULL;

  while (temp -> next != NULL) {
    temp = temp -> next;
  }

  p = temp -> prev;
  p -> next = NULL;
  free(temp);
  temp = NULL;
  printf("Node deleted! \n");
}