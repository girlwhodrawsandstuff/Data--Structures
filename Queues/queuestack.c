/* implementation of a queue using two stacks */

#include <stdio.h>
#define CAPACITY 5

void enqueue();
void push1();
void dequeue();
int pop1();
int pop2();
void push2();
void display();

int firstStack[CAPACITY], secondStack[CAPACITY];
int top1 = -1, top2 = -1;
int count = 0;

void main() {
    enqueue(5);
    dequeue();
    enqueue(10);
    enqueue(15);
    display();
}

void enqueue(int value) {
    push1(value);
    count++;
}

void push1(int data) {
    if(top1 == CAPACITY - 1) {
        printf("The queue is full.\n");
    } else {
        top1++;
        firstStack[top1] = data;
    }
}

void dequeue() {
    int i, a, b;
    if(top1 == -1 && top2 == -1) {
        printf("The queue is empty.\n");
    } else {
        for(i = 0; i < count; i++) {
            a = pop1();
            push2(a);
        }

        b = pop2();
        printf("'%d' was deleted from the queue.\n", b);
        count--;

        for(i = 0; i < count; i++) {
            a = pop2();
            push1(a);
        }
    }
}

int pop1() {
    if(top1 == -1 && top2 == -1) {
        printf("The queue is empty.\n");
    } else {
        int a;
        a = firstStack[top1];
        top1--;
        return a;
    }
}

int pop2() {
    if(top1 == -1 && top2 == -1) {
        printf("The queue is empty.\n");
    } else {
        int a;
        a = secondStack[top2];
        top2--;
        return a;
    }
}

void push2(int value) {
    if(top2 == CAPACITY - 1) {
        printf("The queue is full.\n");
    } else {
        top2++;
        secondStack[top2] = value;
    }
}

void display() {
    if (top1 == -1) {
        printf("The queue is empty.\n");
    } else {
        printf("Elements of the queue are:\n");
        for (int i = 0; i <= top1; i++)
        {
            printf("%d\n", firstStack[i]);
        }
    }
}