/* implementation of a queue using two stacks */

#include <stdio.h>
#define CAPACITY 5

void addToQueue();
void pushToFirstStack();

int firstStack[CAPACITY], secondStack[CAPACITY];
int top1 = -1, top2 = -1;
int count = 0;

void main() {
    addToQueue(5);
}

void addToQueue(int value) {
    pushToFirstStack(value);
    count++;
}

void pushToFirstStack(int data) {
    if(top1 == CAPACITY - 1) {
        printf("The queue is full.\n");
    } else {
        top1++;
        firstStack[top1] = data;
        printf("'%d' was added to the queue.\n", data);
    }
}