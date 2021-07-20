/* implementation of a queue using two stacks */

#include <stdio.h>
#define CAPACITY 5

void addToQueue();
void pushToFirstStack();
void deleteFromQueue();
int popFromFirstStack();
int popFromSecondStack();
void pushToSecondStack();

int firstStack[CAPACITY], secondStack[CAPACITY];
int top1 = -1, top2 = -1;
int count = 0;

void main() {
    addToQueue(5);
    deleteFromQueue();
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

void deleteFromQueue() {
    int i, a, b;
    if(top1 == -1 && top2 == -1) {
        printf("The queue is empty.\n");
    } else {
        for(i = 0; i < count; i++) {
            a = popFromFirstStack();
            pushToSecondStack(a);
        }

        b = popFromSecondStack();
        printf("'%d' was deleted from the queue.\n", b);
        count--;

        for(i = 0; i < count; i++) {
            a = popFromSecondStack();
            pushToFirstStack(a);
        }
    }
}

int popFromFirstStack() {
    if(top1 == -1 && top2 == -1) {
        printf("The queue is empty.\n");
    } else {
        int a;
        a = firstStack[top1];
        top1--;
        return a;
    }
}

int popFromSecondStack() {
    if(top1 == -1 && top2 == -1) {
        printf("The queue is empty.\n");
    } else {
        int a;
        a = secondStack[top2];
        top2--;
        return a;
    }
}

void pushToSecondStack(int value) {
    if(top2 == CAPACITY - 1) {
        printf("The queue is full.\n");
    } else {
        top2++;
        secondStack[top2] = value;
    }
}