#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *temp)
{
    printf("Your list : ");
    while (temp != 0)
    {
        // printf("||%d|%d||->",temp->data,temp->next);
        printf("||%d||->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Insert at the begining
// it will return address of node and i will update the head and the print
struct node *insertAtBeg(struct node *head)
{
    int val;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &val);
    temp->data = val;
    temp->next = head;
    return temp;
}

// insertion at the index
struct node *insertAtIndex(struct node *head)
{
    int val, pos;
    struct node *temp, *ptr;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Index : ");
    scanf("%d", &pos);

    printf("Enter data : ");
    scanf("%d", &val);

    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    temp->data = val;
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

// Insert at the end
struct node *insertAtEnd(struct node *head)
{
    int val;
    struct node *temp, *ptr;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &val);

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->data = val;
    ptr->next = temp;
    temp->next = 0;
    printf("%d", temp->next);

    return head;
}

// delete node at start
struct node *deleteAtbeg(struct node *head)
{
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

// delete node at start
struct node *deleteAtIndex(struct node *head)
{
    struct node *temp, *temp2;
    int pos;
    temp = head;
    temp2 = head->next;
    printf("Enter Index : ");
    scanf("%d", &pos);
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    free(temp2);

    return head;
}

struct node *deleteAtEnd(struct node *head)
{
    struct node *temp1, *temp2;
    temp1 = head;
    temp2 = head->next;
    while(temp2->next != 0)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = 0;
    free(temp2);
    return head;
}

struct node *deleteValue(struct node *head)
{
    struct node *temp1, *temp2;
    temp1 = head;
    temp2 = head->next;
    int val;
    printf("Enter value : ");
    scanf("%d",&val);
    while(temp2->data != val && temp2->next != 0)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(temp2->data == val)
    {
        temp1->next = temp2->next;
        free(temp2);
    }
    else{
        printf("Element is not there\n");
    }

    

    
    
    return head;
}

int main()
{
    typedef struct node Node;
    Node *head, *temp, *ptr;
    ptr = 0;
    int choice = 1, count = 0, value, input;
    printf("Create Linked List... \n");
    while (choice)
    {
        temp = (Node *)malloc(sizeof(Node));
        printf("Enter value : ");
        scanf("%d", &value);
        temp->data = value;
        if (ptr == 0)
        {
            ptr = head = temp;
        }
        else
        {
            ptr->next = temp;
            ptr = temp;
        }
        fflush(stdin);
        printf("Do You want to continue(type 0 or 1) : ");
        scanf("%d", &choice);
    }
    temp->next = 0;
    temp = head;
    // traverse the list
    printf("Created...\n");
    traversal(head);

    input = 1;
    while (input)
    {
        printf("1. Insert At beginning \n2. Insert At Index \n3. Insert At End \n4. Delete the beginning \n5. Delete node at Index \n6. Delete the last node \n7. Delete a node with value \n0. Exit \n");
        printf("Please Choose : ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("Inserting at beginning... \n");
            head = insertAtBeg(head);
            traversal(head);
            break;

        case 2:
            printf("Inserting at Index... \n");
            head = insertAtIndex(head);
            traversal(head);
            break;

        case 3:
            printf("Inserting at End... \n");
            head = insertAtEnd(head);
            traversal(head);

            break;
        case 4:
            printf("Deleting at Start... \n");
            head = deleteAtbeg(head);
            traversal(head);

            break;
        case 5:
            printf("Deleting at Index... \n");
            head = deleteAtIndex(head);
            traversal(head);
            break;
        case 6:
            printf("Deleting at End... \n");
            head = deleteAtEnd(head);
            traversal(head);
            break;
        case 7:
            printf("Deleting Value... \n");
            head = deleteValue(head);
            traversal(head);
            break;

        case 0:
            printf("Exiting... \n");
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}
