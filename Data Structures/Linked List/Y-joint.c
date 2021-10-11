/*Finding Y joint*/
#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	struct node*next;
};
void insertion(int,struct node**);
void display(struct node*);
int intersection(struct node*,struct node*,int);
int main(){
	int n1,n2,check=0;
	struct node*head1=NULL;
	struct node*head2=NULL;
	printf("Enter the value of number of nodes in the given linked list\n");
	scanf("%d",&n1);
	insertion(n1,&head1);
	display(head1);
	printf("\nEnter the value of number of nodes in the second linked list\n");
	scanf("%d",&n2);
	insertion(n2,&head2);
	display(head2);
	if(n1>n2)
		check=intersection(head1,head2,n1-n2);
	else
		check=intersection(head2,head1,n2-n1);
	if(check==0)
		printf("\nLinked lists are not joined in Y shape\n");
	else
		printf("\nThe node value where the two linked list is joined is %d",check);
	return 0;
}
void insertion(int n,struct node** head){
	struct node* temp=NULL;
	struct node* p=NULL;
	for(int i=0;i<n;i++){
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter the value of node %d ",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(*head==NULL)
			*head=temp;
		else{
			p=*head;
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
		}
	}
}
void display(struct node* head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
int intersection(struct node*head1,struct node*head2,int n){
	int flag=1;
	while(n>0){
		head1=head1->next;
		n--;
	}
	flag=head1->data;
	while(head1->next!=NULL && head2->next!=NULL){
		if(head1==head2){
			return head1->data;
		}
		head1=head1->next;
		head2=head2->next;
	}
	return flag;	
}
