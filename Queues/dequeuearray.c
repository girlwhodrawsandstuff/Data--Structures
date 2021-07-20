/* implementation of a dequeue using circular arrays */

#include <stdio.h>
#define CAPACITY 5

int deque[CAPACITY];
int front = -1;
int rear = -1;

void enqueueFront();

void main() {
    enqueueFront(5);
    enqueueFront(10);
    enqueueFront(15);
}

void enqueueFront(int value) {
    if ((front == 0 && rear == CAPACITY - 1) || (front == rear + 1)) {
        printf("The queue is full.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[front] = value;
        printf("'%d' was added to the front of the deque.\n", deque[front]);
    } else if (front == 0) {
        front = CAPACITY - 1;
        deque[front] = value;
        printf("'%d' was added to the front of the deque.\n", deque[front]);
    } else {
        front--;
        deque[front] = value;
        printf("'%d' was added to the front of the deque.\n", deque[front]);
    }
}