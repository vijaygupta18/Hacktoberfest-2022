#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void count(struct node *head)
{
    struct node *p;
    int c=0;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        c++;
    }
    printf("Number of elements are %d",c);
}
void search(struct node *head,int item)
{
    struct node *p;
    p=head;
    int pos=1;
    while(p->next!=NULL)
    {
        if(p->data==item)
        {
            printf("Item %d found at %d",item,pos);
            return;
        }
        p=p->next;
        pos++;
    }
}
void display(struct node* s)
{
    struct node *p;
    if (s==NULL)
    {
        printf("List is empty \n");
    //  return NULL;   
    }
    p=s;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n\n");

}
struct node *insert_at_beg(struct node *head,int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    head=temp;
    return head;
}//time complexity O(1)
struct node *insert_at_end(struct node *head,int x)
{
    struct node *p,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    p=head;
    if(p)
    {
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
    }
    else
    head=temp;
    return head;
    
}//time complexity O(n)
struct node *insert_after_given_node(struct node *head,int x,int item)
{
    struct node *head,*p;
    p=head;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=x;
            temp->next= p->next;
            p->next=temp;
            return head;
        }
        p=p->link;
    }
    printf("%d is nor present in the list",item);
    return head;
}
struct node *insert_at_pos(struct node *head,int x,int pos)
{
    struct node *temp,*p;
    int i;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    if(pos==1)
    {
        temp->next=head;
        head=temp;
        return head;
    }
    p=head;
    for(i=1;i<pos-1;i++)
    p=p->next;
    if(p==NULL)
    printf("There are less than %d elements\n",pos);
    else
    {
        temp->next=p->next;
        p->next=temp;
    }
    return head;
}
struct node *del(struct node *head,int x)
{
    struct node *temp,*p;
    if(head==NULL)
    {
        printf("list is empty");
        return head;
    }
    //delete the 1st element or node
    if(head->data==x)
    {
        temp=head;
        head=head->data;
        free(temp);
        return head;
    }
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->data==x)
        {
            temp=p->next;
            p->next=temp->next;
            free(temp);
            return head;
        }
        p=p->next;
    }
    printf("element %d not found",data);
    return head;

}
struct node *reverse(struct node *head)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
   	ptr=head;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head=prev;
	return head;
}/*End of reverse()*/




int main()
{
	struct node *head=NULL;	
	int choice,data,item,pos;
		
	while(1)
	{
		printf("1.Display\n");
		printf("2.Count list\n");
		printf("3.Search element\n");
		printf("4.Insert new node at the beginning\n");
		printf("5.Insert new node at the end\n");
		printf("6.Insert new node after the given node\n");
		printf("7.Insert new node at the given position\n");
		printf("8.Delete node\n");
		printf("9.Reverse list\n");
		printf("10.Quit\n\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
		 
		 case 1:
			display(head);
			break;
		 case 2:
			count(head);
			break;
		 case 3:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search(head,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			head=insert_at_beg(head,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			head=insert_at_end(head,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			head=insert_after_given_node(head,data,item);
			break;
		 
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&pos);
			head = insert_at_pos(head,data,pos);
			break;
		 case 8:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			head=del(head, data);	
			break;
		 case 9:
			head=reverse(head);
			break;
		 case 10:
			 exit(1);
		 default:
			 printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/