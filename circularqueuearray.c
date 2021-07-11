/* implementation of a circular queue using an array */
#include <stdio.h>
#define CAPACITY 5

void addElement();

int queue[CAPACITY];
int front = -1;
int rear = -1;

void main() {
    addElement(5);
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