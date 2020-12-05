#include <stdio.h>
#include <stdlib.h>

void addAtBegin();
void addInBetween();
void addAtEnd();
int length();
void display();
void reverse();

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void main()
{
    int choice;

    while(1)
    {
        printf("Choose an option: \n");
        printf("1. Insert at the beginning \n");
        printf("2. Insert at in between \n");
        printf("3. Insert at end\n");
        printf("4. Length \n");
        printf("5. Display elements \n");
        printf("6. Reverse List \n");
        printf("7. Quit \n");
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

            case 7: exit(0);
            
            default: printf("Invalid choice\n");

        }
    }
}

void addAtBegin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the node data: \n");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        // right side connection
        temp->right = root;
        // left side connection
        root->left = temp;
        root = temp;
    }
    
}

void addInBetween()
{
    struct node *temp, *p;
    int location, len, i;
    len = length();

    printf("Enter the location for insertion: \n");
    scanf("%d", &location);

    if(location > len)
    {
        printf("Invalid location. \n");
        printf("Length of the list is %d", len);
    }
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        p = root;

        printf("Enter the node data: \n");
        scanf("%d", &temp->data);
        temp->right = NULL;
        temp->left = NULL;

        while(p < location)
        {
            p = p->right;
        }

        // right side connection for temp
        temp->right = p->right;
        // next node's left side
        p->right->left = temp;
        // left side connection for temp
        temp->left = p;
        // previous node's right side
        p->right = temp;
    }
    
}

void addAtEnd()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the node data: \n");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;

        while(p->right != NULL)
        {
            p = p->right;
        }

        p->right = temp;
        temp->left = p;
    }
}

int length()
{
    struct node *temp = root;;
    int count = 0;
    

    while(temp != NULL)
    {
        temp = temp->right;
        count++;
    }
    
    return count;
}

void display()
{
    struct node *temp = root;

    if(temp == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp->right;
        }
    }
    
}

void reverse()
{

}
