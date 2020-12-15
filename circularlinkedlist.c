#include <stdio.h>
#include <stdlib.h>

void addAtBegin();
void addInBetween();
void addAtEnd();
int length();
void display();
void reverse();
void delete ();

struct node
{
    int data;
    struct node *next;
};

struct node *root = NULL;

void main()
{
    int choice;

    while (1)
    {
        printf("Choose an option: \n");
        printf("1. Insert at the beginning \n");
        printf("2. Insert in between \n");
        printf("3. Insert at end\n");
        printf("4. Length \n");
        printf("5. Display elements \n");
        printf("6. Reverse List \n");
        printf("7. Delete from beginning\n");
        printf("8. Quit \n");
        scanf("%d", &choice);

        switch (choice)
        {
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
            delete ();
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}

void addAtBegin()
{

}

void addInBetween()
{

}

void addAtEnd()
{

}

int length()
{

}

void display()
{

}

void reverse()
{

}

void delete ()
{

}