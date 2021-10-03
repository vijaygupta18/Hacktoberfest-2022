/* Program of sorting through heapsort*/
# include <stdio.h>

int arr[20],n;

main()
{
	int i;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Entered list is :\n");
	display();

	create_heap();

	printf("Heap is :\n");
	display();

	heap_sort();
	printf("Sorted list is :\n");
	display();
}/*End of main()*/

display()
{       int i;
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
}/*End of display()*/

create_heap()
{
	int i;
	for(i=0;i<n;i++)
		insert(arr[i],i);
}/*End of create_heap()*/

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
	arr[0]=num;
}/*End of insert()*/


heap_sort()
{
	int last;
	for(last=n-1; last>0; last--)
	   del_root(last);
}/*End of del_root*/

del_root(int last)
{
	int left,right,i,temp;
	i=0; /*Since every time we have to replace root with last*/
	/*Exchange last element with the root */
	temp=arr[i];
	arr[i]=arr[last];
	arr[last]=temp;

	left=2*i+1; /*left child of root*/
	right=2*i+2;/*right child of root*/

	while( right < last)
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
	if( left==last-1 && arr[i]<arr[left] )/*right==last*/
	{
		temp=arr[i];
		arr[i]=arr[left];
		arr[left]=temp;
	}
}/*End of del_root*/
