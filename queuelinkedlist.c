#include <stdio.h>
#include <stdlib.h>

void addElement();
void deleteElement();
void displayElements();

struct node {
    int data;
    struct node * next;
};

struct node * front = 0;
struct node * rear = 0;

void main() {
    addElement(5);
    displayElements();
    deleteElement();
    addElement(5);
    displayElements();
}

void addElement(int value) {
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = 0;

    if(front == 0 && rear == 0) {
        front = rear = newNode;
        printf("Element added!\n");
    } else {
        rear -> next = newNode;
        rear = newNode;
        printf("Element added!\n");
    }
}

void deleteElement() {
    struct node * temp;
    if(front == 0 && rear == 0) {
        printf("The queue is empty.\n");
    } else if (front -> next == 0) {
        printf("Element '%d' was deleted. The queue is now empty.\n", front -> data);
        front = front -> next;
        rear = front;
    } else {
        printf("Element '%d' was deleted.\n", front -> data);
        front = front -> next;
        free(temp);
    }
}

void displayElements()
{
    struct node *temp;
    temp = front;
    if (front == 0)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The elements are: \n");
        while (temp != 0)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}