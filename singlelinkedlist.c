#include <stdio.h>
#include <stdlib.h>

void addAtBegin();
void addInBetween();
void addAtEnd();
int length();
void display();
void reverse();
void swap();
void delete();

struct node
{
    int data;
    struct node *next;
};

struct node *root = NULL;
int choice, len;

void main()
{
    while(1)
    {
        printf("Choose an option: \n");
        printf("1. Insert at the beginning \n");
        printf("2. Insert at in between \n");
        printf("3. Insert at end\n");
        printf("4. Length \n");
        printf("5. Display elements \n");
        printf("6. Reverse List \n");
        printf("7. Swap nodes \n");
        printf("8. Delete node \n");
        printf("9. Quit \n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: addAtBegin();
                break;

            case 2: addInBetween();
                break;

            case 3: addAtEnd();
                break;

            case 4: printf("Length: %d\n", length());
                break;

            case 5: display();
                break;

            case 6: reverse();
                break;

            case 7: swap();
                break;

            case 8: delete();
                break;

            case 9: exit(0);
            
            default: printf("Invalid choice\n");

        }
    }
}

void addAtBegin()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter node data: \n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        // right side connection
        temp->next = root;
        // left side connection
        root = temp;
    }

    printf("Node added!\n");
}

void addInBetween()
{
    struct node *temp, *p;
    temp = (struct node*)malloc(sizeof(struct node));
    int location, len, i = 1;

    printf("Enter the location for insertion: \n");
    scanf("%d", &location);

    len = length();
    if(location > len)
    {
        printf("Invalid location!\n");
        printf("List has %d nodes\n", len);
    }
    else
    {
        p = root;
        while(i < location)
        {
            p = p->next;
            i++;
        }

        printf("Enter the data to be inserted: \n");
        scanf("%d", &temp->data);

        // read node data and store the value
        temp->next = p->next;
        p->next = temp;

    }
}

void addAtEnd()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: \n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(root == NULL)
    {
        // temp contains the address of the node
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }

    printf("Node added!\n");
}

int length()
{
    // iterative method
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = root;

    int count = 0;

    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void display()
{
    struct node *temp;
    temp = root;
    if(temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
}

void reverse()
{
    struct node *p, *q, *temp;
    int i, j, k, len;
    len = length();

    // i = first node
    i = 0;
    // j = last node
    j = len - 1;

    p = q = root;
    
    while(i<j)
    {
        k = 0;
        while(k < j)
        {
            q = q->next;
            k++;
        }

        temp = p->data;
        p->data = q->data;
        q->data = temp;

        i++;
        j--;

        // p moves to the next node
        // q moves back to the root as it can't move backwards
        p = p-> next;
        q = root;
    }
    printf("List reversed!\n");
}

void swap()
{
    struct node *p, *q, *r;
    int location, len, i = 1;
    
    len = length();

    p = root;
    
    printf("Enter the location of the node to be swapped\n");
    scanf("%d", &location);

    if(location > len)
    {
        printf("Invalid location.\n");
        printf("The list has %d nodes", len);
    }
    else
    {
        // p  moves to a position before the node to be swapped
        while(i < location - 1)
        {   
            p = p->next;
            i++;
        }
    }

    // q and r move to the nodes to be swapped
    q = p->next;
    r = q->next;

    q->next = r->next;
    r->next = q;
    p->next = r;
    
    printf("Nodes swapped!\n");
}

void delete()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    int location, len;
    len = length();

    printf("Enter the location of the node to be deleted\n");
    scanf("%d", &location);

    if(location > len)
    {
        printf("Invalid location.\n");
        printf("The list has %d nodes", len);
    }
    else if(location == 1)
    {
        temp = root;
        // assigning new right side connection
        root = temp->next;

        // removing the old connection
        temp->next = NULL;
        free(temp);
    }
    else
    {
        struct node *p = root, *q;
        int i = 1;
        while(i < location - 1)
        {
            p = p->next;
            i++;
        }

        q = p->next;
        // right side connection
        p->next = q->next;
        
        // removing old connection
        q ->next = NULL;
        free(q);

    }
    printf("Node deleted!\n");
}