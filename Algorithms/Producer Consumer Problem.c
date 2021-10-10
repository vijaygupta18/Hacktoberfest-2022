#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,full=0,empty,x=0;
 
int main()
{
int n,ch;
void producer();
void consumer();
int wait(int);
int signal(int);
printf("Enter the size of buffer: ");
scanf("%d",&n);
empty=n;
printf("\n1.Producer\n2.Consumer\n3.Exit\n");
while(1)
{
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: if((mutex==1)&&(empty!=0))
producer();
else
printf("Buffer is full!\n");
break;
case 2: if((mutex==1)&&(full!=0))
consumer();
else
printf("Buffer is empty!!\n");
break;
case 3:
exit(0);
break;
}
}

return 0;
}
 
int wait(int s)
{
    s--;
return (s);
}
 
int signal(int s)
{
    s++;
return(s);
}
 
void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("Producer produces the item %d\n",x);
mutex=signal(mutex);
}
 
void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("Consumer consumes item %d\n",x);
x--;
mutex=signal(mutex);
}
