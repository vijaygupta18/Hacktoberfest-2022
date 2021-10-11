#include<stdio.h>  //for printf,scanf
#include<stdlib.h>  //for dyanamic memory allocation
#include<string.h>   //for using strcpy for name copying

struct queue
{
    int id;
	char name[20];
	struct queue *next;
};

int menu(void);
int enqueue(struct queue **front,struct queue **rear, int id,char str[]);
int dequeue(struct queue **front,int *id,char str[]);
int display(struct queue **front,struct queue **rear,int flag);
void removeQueue(struct queue **front,struct queue **rear);
int display_front(struct queue *front,int flag);
int isFull(struct queue **newnode);
int isEmpty(struct queue **front);

int main(void)
{
	int choice=0;
	int idgenerator = 0;
	int id = 0;
    char str[20]= {'\0'};
	int succ = 0;
    int priority = 0;
    int flag = 0;

	struct queue *front1 = NULL;
	struct queue *rear1 = NULL;  //queue of top priority

	struct queue *front2 = NULL;
	struct queue *rear2 = NULL;  //queue of medium priority

	struct queue *front3 = NULL;
	struct queue *rear3 = NULL;  //queue of general priority
	do
	{
		choice = menu();
		switch(choice)
		{
		case 0: removeQueue(&front1,&rear1);
		        removeQueue(&front2,&rear2);
		        removeQueue(&front3,&rear3);
                printf("\n\n\t\t Thank you!\n\n");
			    break;
		case 1: printf("\nEnter name of patient\n");
			    scanf("%19s",str);
			    id = ++idgenerator;
			    printf("\nNOTE : top priority is 1, medium is 2, least is 3\n");
			    printf("\nEnter priority : ");
			    scanf("%d",&priority);
			    if(priority == 1)
                {
                    succ = enqueue(&front1,&rear1,id,str);
                    if(succ == 1)
                    {
                        printf("\nQueue is full. No insertion done\n");
                    }
                    else
                    {
                         printf("\nInserted successfully in top priority queue\n");
                    }
                }
			    else if(priority == 2)
                {
                    succ = enqueue(&front2,&rear2,id,str);
                    if(succ == 1)
                    {
                        printf("\nQueue is full. No insertion done\n");
                    }
                    else
                    {
                         printf("\nInserted successfully in medium priority queue\n");
                    }
                }
                else if(priority == 3)
                {
                    succ = enqueue(&front3,&rear3,id,str);
                    if(succ == 1)
                    {
                        printf("\nQueue is full. No insertion done\n");
                    }
                    else
                    {
                         printf("\nInserted successfully in general priority queue\n");
                    }
                }
                else
                {
                    printf("\nInvalid Priority entered - unsuccessful insertion\n");
                }
			    break;
		case 2: succ = dequeue(&front1,&id,str);
			    if(succ == 1)
			    {
			        //top queue is empty
				    succ = dequeue(&front2,&id,str);
				    if(succ == 1)
			        {
			           //medium priority queue is also empty
				       succ = dequeue(&front3,&id,str);
				       if(succ == 1)
                       {
                           //general queue is also empty
                           printf("\nNo patients- no treatment done - all queues are empty\n");
                       }
                       else
                       {
				          printf("\nTreated patient from general priority queue\n");
				          printf("\npatient id : %d patient name : %s\n",id,str);
			           }
			        }
			        else
                    {
				       printf("\nTreated patient from medium priority queue\n");
				       printf("\npatient id : %d patient name : %s\n",id,str);
			        }
			    }
			    else
                {
				   printf("\nTreated patient from top priority queue\n");
				   printf("\npatient id : %d patient name : %s\n",id,str);
			    }
			    break;
		case 3: flag = 1;
		        succ = display(&front1,&rear1,flag);
			    if(succ==1)
			    {
				   printf("\nTop Queue is empty\n");
			    }
			    flag = 2;
			    succ = display(&front2,&rear2,flag);
			    if(succ==1)
			    {
				   printf("\nMedium Queue is empty\n");
			    }
			    flag = 3;
			    succ = display(&front3,&rear3,flag);
			    if(succ==1)
			    {
				   printf("\nGeneral Queue is empty\n");
			    }
			    break;
        case 4: flag = 1;
                succ = display_front(front1,flag);
			    if(succ == 1)
			    {
			        //top queue empty
			        flag = 2;
			        succ = display_front(front2,flag);
			        if(succ == 1)
			        {
			             //medium queue empty
                        flag = 3;
                        succ = display_front(front3,flag);
			            if(succ == 1)
                        {
                           printf("\nNo patients - All queues are empty\n");
                        }
			        }
			    }
			   break;
       }
	}while(choice!=0);
	return 0;
}

int menu(void)
{
	int choice =0;
	do
    {
        printf("\n\t1. Add patient\n");
        printf("\n\t2. Treat patient\n");
        printf("\n\t3. Display all patient\n");
        printf("\n\t4. Display the first patient to be treated \n");
        printf("\n\t0: Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
    }while(choice <0 || choice > 4);
	return choice;
}

int enqueue(struct queue **front,struct queue **rear, int id,char str[])
{
	int succ=0;
	struct queue *newnode = NULL;
	succ = isFull(&newnode);
	if(succ == 1)
	{
		//stack full
	}
	else if(*front == NULL)
	{
		newnode->id = id;
		strcpy(newnode->name,str);
		*front = newnode;
		*rear = newnode;
	}
	else
	{
		newnode->id = id;
		strcpy(newnode->name,str);
		(*rear)->next=newnode;
		*rear = newnode;
	}
	return succ;
}
int isFull(struct queue **newnode)
{
    int succ = 0;
    *newnode=(struct queue*)calloc(1,sizeof(struct queue));
	if(*newnode == NULL)
	{
		succ=1; //stack full
	}
	else
    {
        succ = 0;
    }
    return succ;
}
int dequeue(struct queue **front,int *id,char str[])
{
	int succ=0;
	struct queue *dnode=NULL;
	succ = isEmpty(front);
	if(succ == 1)
    {
        //queue empty
    }
	else
	{
		dnode = *front;
		*front = (*front)->next;
		dnode->next=NULL;
		*id = dnode->id;
		strcpy(str,dnode->name);
		free(dnode);
		dnode = NULL;
		succ = 0;
	}
	return succ;
}
int isEmpty(struct queue **front)
{
    int succ = 0;
    if(*front == NULL)
	{
		succ=1; //queue is empty
	}
	else
    {
        succ = 0;
    }
    return succ;
}
int display(struct queue **ffront,struct queue **frear,int flag)
{
    struct queue *tfront = NULL;
    struct queue *trear = NULL;
	int succ = 0;
	int id  = 0;
	char str[20] = {'\0'};
	if(*ffront == NULL)
	{
		succ = 1;   //queue is empty
	}
	else
	{
	    if(flag == 1)
        {
             printf("\nTop Queue :\n");
        }
        else if(flag == 2)
        {
             printf("\nMedium Queue :\n");
        }
        else
        {
            printf("\nGeneral Queue :\n");
        }
		while(*ffront != NULL)
        {
             succ = dequeue(ffront,&id,str);
			 printf("\npatient id : %d patient name : %s\n",id,str);
             succ = enqueue(&tfront,&trear,id,str);
        }
        while(tfront != NULL)
        {
              succ = dequeue(&tfront,&id,str);
              succ = enqueue(ffront,frear,id,str);
        }
        printf("\n");
        succ = 0;
	}
	return succ;
}
int display_front(struct queue *front,int flag)
{
    int succ = 0;
    if(front == NULL)
    {
        succ = 1;
    }
    else
    {
       succ = 0;
        if(flag == 1)
        {
             printf("\nPatient from Top Queue\n ");
        }
        else if(flag == 2)
        {
             printf("\nPatient from Medium Queue\n");
        }
        else
        {
            printf("\nPatient from General Queue\n");
        }
        printf("\npatient id : %d patient name : %s\n",front->id,front->name);
    }
    return succ;
}
void removeQueue(struct queue **head, struct queue **last)
{
	struct queue *dnode=NULL;
	while(*head!=NULL)
	{
		dnode=*head;
		*head=(*head)->next;
		dnode->next=NULL;
		free(dnode);
		dnode=NULL;
	}
	*head=NULL;
	*last=NULL;
}


