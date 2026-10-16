
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
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }

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

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    printf("Node inserted at end.\n");
}

// Insert at a given position (positions start from 1)
void insertPosition()
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

    if (head == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1)
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
    struct node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;
    }

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

    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    printf("Last node deleted.\n");
}

// Delete from a given position
void deletePosition()
{
    struct node *temp, *delnode, *last;
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

    for (i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1 || temp->next == head)
    {
        printf("Invalid position!\n");
        return;
    }

    delnode = temp->next;
    temp->next = delnode->next;

    free(delnode);

    printf("Node at position %d deleted.\n", pos);
}

// Display circular linked list
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(back to head)\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CIRCULAR SINGLY LINKED LIST ---\n");
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
                insertPosition();
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                deletePosition();
                break;

            case 7:
                display();
                break;

            case 8:
                while (head != NULL)
                {
                    struct node *temp = head;

                    if (head->next == head)
                    {
                        head = NULL;
                    }
                    else
                    {
                        struct node *last = head;

                        while (last->next != head)
                        {
                            last = last->next;
                        }

                        head = head->next;
                        last->next = head;
                    }

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
