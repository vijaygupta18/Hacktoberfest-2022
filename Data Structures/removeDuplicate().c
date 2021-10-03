#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* create(int a[],int n)
{
    struct node *newnode,*head=NULL,*t;
    int i;
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(head==NULL)
        {
            newnode->data=a[i];
            newnode->next=NULL;
            head=newnode;
            t=head;
        }
        else
        {
            newnode->data=a[i];
            newnode->next=NULL;
            t->next=newnode;
            t=t->next;
        }
    }
    return head;
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void removeDuplicate(struct node *p)
{   
    struct node *t;
    t=p;
    int flag=0;
    while(p->next!=NULL)
    {   flag=0;
        if(p->data==(p->next)->data)
        {
            p->next=(p->next)->next;
            flag=1;
        }
        if(flag==1)
            p=p;
        else
        p=p->next;
        
    }
    
    display(t);
}




int main()
{  struct node *p;
   int a[]={1,2,2,2,3,4,4,4,6,7,8,8,8};
   
   p=create(a,13);
   
   removeDuplicate(p);
   //display(p);

    return 0;
}
