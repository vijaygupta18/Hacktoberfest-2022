/*Write a program for sequential searching*/
# include<stdio.h>

main()
{
	int arr[20],n,i,item;
	printf("How many elements you want to enter in the array : ");
	scanf("%d",&n);

	for(i=0; i < n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}
	printf("Enter the element to be searched : ");
	scanf("%d",&item);
	for(i=0;i < n;i++)
	{
		if(item == arr[i])
		{
			printf("%d found at position %d\n",item,i+1);
			break;
		}
	}/*End of for*/
	if(i == n)
		printf("Item %d not found in array\n",item);

}
