/* implementation of a queue using an array */

#include <stdio.h>
#define CAPACITY 5

void addToQueue();

int queue[CAPACITY];
int front = -1;
int rear = -1;

void main() {
    addToQueue(5);
}

void addToQueue(int value) {
    if(rear == (CAPACITY - 1))
    {
        printf("The queue is full.\n");
    } else if(rear == -1 && front == -1) {
        rear = front = 0;
        queue[rear] = value;
        printf("Element added!\n");
    } else {
        rear++;
        queue[rear] = value;
        printf("Element0. added!\n");
    }
}

