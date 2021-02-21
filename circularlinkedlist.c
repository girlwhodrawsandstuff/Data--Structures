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

struct node *tail = NULL;

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
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: \n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (tail == 0)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void addInBetween()
{
    struct node *newNode, *temp;
    int location, i = 1, len;

    printf("Enter the location: \n");
    scanf("%d", &pos);

    len = length();
    
    if (location < 0 || location > len)
    {
        printf("Invalid position.\n");
        printf("List has %d nodes\n");
    }
    else if (location == 1)
    {
        addAtBegin();
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: \n");
        scanf("%d", &newNode->data);
        newNode->next = 0;

        temp = tail->next;
        while (i < location - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void addAtEnd()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: \n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (tail == 0)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

int length()
{
    struct node *temp;
    int count = 0;

    if (tail == 0)
    {
        printf("List is empty.\n");
    }
    else
    {
        while (temp->next != tail)
        {
            count++;
            temp = tail;
            temp = temp->next;
        }
    }

    return count;
}

void display()
{
    struct node *temp;
    if (tail == 0)
    {
        printf("List is empty. \n");
    }
    else
    {
        while (temp->next != tail)
        {
            temp = tail;
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

void reverse()
{

}

void delete ()
{

}