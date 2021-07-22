/* implementation of a binary tree using doubly linked list*/
/* recursive method */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * create() {
    int value;
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data for the node. Enter -1 if you don't want to enter any value.\n");
    scanf("%d", &value);

    if (value == -1) {
        return 0;
    } else {
        newNode -> data = value;

        printf("Enter the data for the left node. Enter -1 if you don't want to enter any value.\n");
        newNode -> left = create();

        printf("Enter the data for the right node. Enter -1 if you don't want to enter any value.\n");
        newNode -> right = create();

        return newNode;
    }
}

void preorder(struct node * root) {
    if(root == 0) {
        printf("Empty node!\n");
    } else {
        printf("%d\n", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(struct node * root) {
    if(root == 0) {
        printf("Empty node!\n");
    } else {
        preorder(root -> left);
        printf("%d\n", root -> data);
        preorder(root -> right);
    }
}

void main() {
    struct node * root;
    root = create();
    printf("Pre-order is: \n");
    preorder(root);
    printf("Inorder is: \n");
    inorder(root);
}