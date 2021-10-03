#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
void create(struct node **);
void display(struct node *);
int survivor(struct node **, int);
 
int main()
{
    struct node *head = NULL;
    int survive, skip;
 
    create(&head);
    printf("The persons in circular list are:\n");
    display(head);
    printf("Enter the position of person to be killed: ");
    scanf("%d", &skip);
    skip+=1;
    survive = survivor(&head, skip);
    printf("The person to survive is : %d\n\n", survive);
    free(head);
 
    return 0;
}
 
int survivor(struct node **head, int k)
{
    struct node *p, *q;
    int i;
 
    q = p = *head;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d has been killed.\n", p->num);
        free(p);
        p = q->next;
    }
    *head = p;
 
    return (p->num);
}
 
void create (struct node **head)
{
    struct node *temp, *rear;
    int a,n, ch;
    printf("\nEnter number of persons: ");
    scanf("%d", &n);
    for(int i=1;i<n+1;i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = i;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
    }
    rear->next = *head;
}
 
void display(struct node *head)
{
    struct node *temp;
 
    temp = head;
    printf("%d   ", temp->num);
    temp = temp->next;
    while (head != temp)
    {
        printf("%d   ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}
