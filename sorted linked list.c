/* Program of sorted linked list*/

# include <stdio.h>
# include <malloc.h>

struct node
{
	int info;
	struct node *link;
}*start;

main()
{
	int choice,n,m,i;
	start=NULL;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display \n");
		printf("4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("Enter the element to be inserted : ");
			scanf("%d",&m);
			insert(m);
			break;
		 case 2:
			printf("Enter the element to be deleted : ");
			scanf("%d",&m);
			del(m);
			break;
		 case 3:
			display();
			break;
		 case 4:
			exit();
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
} /*end of main */

insert(int num)
{
	struct node *q,*tmp;
	tmp= malloc(sizeof(struct node));
	tmp->info=num;

	/*list empty or item to be added in begining */
	if(start == NULL || num < start->info)
	{
		tmp->link=start;
		start=tmp;
		return;
	}
	else
	{
		q=start;
		while(q->link != NULL && q->link->info < num)
			q=q->link;
		tmp->link=q->link;
		q->link=tmp;
	}
}/*End of insert()*/

del(int num)
{
	struct node *tmp,*q;
	if(start->info==num)
	{
		tmp=start;
		start=start->link;  /*first element deleted*/
		free(tmp);
		return;
	}
	q=start;
	while(q->link->link!=NULL)
	{
		if(q->link->info==num)     /*element deleted in between*/
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			return;
		}
		q=q->link;
	}/*End of while */
	if(q->link->info==num)    /*last element deleted*/
	{
		tmp=q->link;
		free(tmp);
		q->link=NULL;
		return;
	}
	printf("Element %d not found\n",num);
}/*End of del()*/

display()
{
	struct node *q;
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	q=start;
	printf("List is :\n");
	while(q != NULL)
	{
		printf("%d ", q->info);
		q=q->link;
	}
	printf("\n");
}/*End of display() */
