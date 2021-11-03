/* Write a menu driven program to perform the following operations in a circular doubly linked list by using suitable user defined 
    functions for each case.
    a) Traverse the list 
    b) Insert a node at the certain position
    c) Delete a node at the certain position 
    d) Delete a node for the given key
    e) Count the total number of nodes 
    f) Search for an element in the linked list */

#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *prev, *next;
} *head = NULL;

void display()
{
    struct node *ptr;
    ptr = head;
    do
    {
        printf("Node = %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

void create(int n)
{
    int i, data;
    struct node *curr, *ptr;
    for (i = 0; i < n; i++)
    {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Data for node %d : ", i + 1);
        scanf("%d", &data);
        curr->data = data;
        curr->next = NULL;
        curr->prev = NULL;
        if (head == NULL)
        {
            head = curr;
            curr->next = curr;
            curr->prev = curr;
            ptr = curr;
        }
        else
        {
            curr->prev = ptr;
            ptr->next = curr;
            head->prev = curr;
            curr->next = head;
            ptr = ptr->next;
        }
    }
}

void delete_given_position(int size)
{
    int i = 1, pos;
    printf("\nEnter the position to be deleted : ");
    scanf("%d", &pos);
    struct node *ptr = head, *curr, *temp;
    temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    if (pos == 1)
    {
        head = head->next;
        head->prev = temp;
        temp->next = head;
        free(temp);
    }
    if (pos > 1 && pos <= size)
    {
        do
        {
            if (i == pos)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
                break;
            }
            else
            {
                ptr = ptr->next;
            }
            i++;
        } while (ptr != head);
    }

}

void insert_given_position(int pos, int size)
{
    int i = 1, data;
    struct node *ptr = head, *curr, *temp;
    curr = (struct node *)malloc(sizeof(struct node));
    printf("Data to insert : ");
    scanf("%d", &data);
    curr->data = data;
    curr->next = NULL;
    curr->prev = NULL;
    temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    if (pos == 1)
    {
        curr->next = head;
        head->prev = curr;
        curr->prev = temp;
        temp->next = curr;
        head = curr;
    }
    if (pos > 1 && pos <= size && head != NULL)
    {
        do
        {
            if (i == pos - 1) // 1 2 3 4
            {
                curr->next = ptr->next;
                curr->prev = ptr;
                ptr->next = curr;
                curr->next->prev = curr;
            }
            else
            {
                ptr = ptr->next;
            }
            i++;

        } while (ptr != head);
    }
   
}

void deleteNode()
{
    struct node *current;
    struct node *del;
    current = head;
    int key;
    printf("\nEnter data to delete: ");
    scanf("%d", &key);

    while (current != NULL)
    {
        if (current->data == key)
        {
            del = current;
            break;
        }
        current = current->next;
    }
    if (head == NULL || del == NULL)
        return;

    if (head == del)
        head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

int countNode()
{
    int x = 0;
    struct node *ptr;
    ptr = head;
    do
    {
        ptr = ptr->next;
        x++;
    } while (ptr != head);
    return x;
}

void search_element(int s)
{
    int flag = 0;
    struct node *ptr;
    ptr = head;
    do
    {
        if (ptr->data == s)
        {
            flag = 1;
            break;
        }
        else
        {
            ptr = ptr->next;
        }

    } while (ptr != head);
    if (flag)
    {
        printf("<<------------------ELEMENT FOUND------------------>>\n");
    }
    else
    {
        printf("<<------------------ELEMENT NOT FOUND------------------>>\n");
    }
}

int main()
{
    int n, pos, item, data, choice = 1;
    head = NULL;
    while (choice != 0)
    {
        printf("\n\n\t\tCIRCULAR DOUBLY LINKED LIST BASIC OPERATIONS\n\n");
        printf("1. Create List\n");
        printf("2. Insert at any position\n");
        printf("3. Delete at any position\n");
        printf("4. Delete node with given key\n");
        printf("5. Count node\n");
        printf("6. Search Element\n");
        printf("7. Traverse\n");
        printf("0. Exit\n");
        printf("\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the total number of nodes in list: ");
            scanf("%d", &n);
            create(n);
            printf("\nLIST CREATED !");
            break;
        case 2:
            printf("Enter node position: ");
            scanf("%d", &pos);
            insert_given_position(pos, n);
            display();
            break;
        case 3:
            if (head == NULL)
            {
                printf("\nThe list is empty\n");
            }
            else
            {
                delete_given_position(n);
                display();
            }
            break;
        case 4:
            deleteNode();
            display();
            break;
        case 5:
            printf("\nNumber of nodes in the list : %d", countNode());

            break;
        case 6:
            printf("\nEnter the element to be searched : ");
            scanf("%d", &data);
            search_element(data);
            break;
        case 7:
            display();
            break;
        case 0:
            break;
        default:
            printf("Error! Invalid choice.");
        }
        printf("\n");
    }
    return 0;
}