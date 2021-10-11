/* Program for insertion and deletion in heap */
# include <stdio.h>
int arr[100],n;
main()
{
	int choice,num;
	n=0;/*Represents number of nodes in the heap*/
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num,n);
			n=n+1;
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			display();
			break;
		 case 4:
			exit();
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/

display()
{       int i;
	if(n==0)
	{
		printf("Heap is empty\n");
		return;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}/*End of display()*/

insert(int num,int loc)
{
	int par;
	while(loc>0)
	{
		par=(loc-1)/2;
		if(num<=arr[par])
		{
			arr[loc]=num;
			return;
		}
		arr[loc]=arr[par];
		loc=par;
	}/*End of while*/
	arr[0]=num; /*assign num to the root node */
}/*End of insert()*/

del(int num)
{
	int left,right,i,temp,par;

	for(i=0;i<n;i++)
	{
		if(num==arr[i])
		break;
	}
	if( num!=arr[i] )
	{
		printf("%d not found in heap\n",num);
		return;
	}
	arr[i]=arr[n-1];
	n=n-1;
	par=(i-1)/2;   /*find parent of node i */
	if(arr[i] > arr[par])
	{
		insert( arr[i],i);
		return;
	}
	left=2*i+1;  /*left child of i*/
	right=2*i+2; /* right child of i*/
	while(right < n)
	{
		if( arr[i]>=arr[left] && arr[i]>=arr[right] )
			return;
		if( arr[right]<=arr[left] )
		{
			temp=arr[i];
			arr[i]=arr[left];
			arr[left]=temp;
			i=left;
		}
		else
		{
			temp=arr[i];
			arr[i]=arr[right];
			arr[right]=temp;
			i=right;
		}
		left=2*i+1;
		right=2*i+2;
	}/*End of while*/
	if( left==n-1 && arr[i]<arr[left] ) /* right==n */
	{	temp=arr[i];
		arr[i]=arr[left];
		arr[left]=temp;
	}
}/*End of del()*/
