/* implementation of a circular queue using an array */
#include <stdio.h>
#define CAPACITY 5

void addElement();
void deleteElement();
void displayElements();
void peek();

int queue[CAPACITY];
int front = -1;
int rear = -1;

void main() {
    addElement(5);
    deleteElement();
    addElement(10);
    addElement(15);
    displayElements();
    peek();
}

void addElement(int value) {
    if((rear + 1) % CAPACITY == front) {
        printf("The queue is full.\n");
    } else if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
        printf("Element added!\n");
    } else {
        rear = (rear + 1) % CAPACITY;
        queue[rear] = value;
        printf("Element added!\n");
    }
}

void deleteElement() {
    if(front == -1 && rear == -1) {
        printf("The queue is empty.\n");
    } else if(front == rear) {
        printf("'%d' was deleted.\n", queue[front]);
        front = rear = -1;
    } else {
        printf("'%d' was deleted.\n", queue[front]);
        front = (front + 1) % CAPACITY;
    }
}

void displayElements() {
    if(front == -1 && rear == -1) {
        printf("The queue is empty.\n");
    } else {
        int i = front;
        printf("The elements of the queue are: \n");
        while (i != rear)
        {
            printf("%d\n", queue[i]);
            i = (i + 1) % CAPACITY;
        }
        printf("%d\n", queue[rear]);
    }
}

void peek() {
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty.\n");
    } else {
        printf("The first element of the queue is '%d'.\n", queue[front]);
    }
    
}