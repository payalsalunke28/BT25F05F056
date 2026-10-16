
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insertBegin()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Node inserted at end.\n");
}

// Insert at a given position (positions start from 1)
void insertMiddle()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        insertBegin();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", pos);
}

// Delete from beginning
void deleteBegin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("First node deleted.\n");
}

// Delete from end
void deleteEnd()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last node deleted.\n");
}

// Delete from a given position
void deleteMiddle()
{
    struct node *temp, *delnode;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || head == NULL)
    {
        printf("Invalid position or empty list!\n");
        return;
    }

    if (pos == 1)
    {
        deleteBegin();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    delnode = temp->next;
    temp->next = delnode->next;

    free(delnode);

    printf("Node at position %d deleted.\n", pos);
}

// Display linked list
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
            case 1:
                insertBegin();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertMiddle();
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                deleteMiddle();
                break;

            case 7:
                display();
                break;

            case 8:
                while (head != NULL)
                {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }

                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
