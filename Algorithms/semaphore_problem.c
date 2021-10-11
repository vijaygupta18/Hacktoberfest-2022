#include<stdio.h>
#include<sys/types.h>
#include<semaphore.h>
#include<pthread.h>
int table_used=1,generated_item[2],generated=0;
char *item[]={"water","ice","glass"};
sem_t table;
void *person(void *arg)
{
 int i,j,k=0;
 while(1)
 {
 sleep(1);
 sem_wait(&table);
 if(table_used==1)
 {
 i=k;
 j=i+1;
 if(j==3)
 j=0;
 k=j;
 generated_item[0]=i;
 generated_item[1]=j;
 printf("Third person has produced %s and %s\n",item[i],item[j]);
 generated=1;
 table_used=0;
 }
 sem_post(&table);
 }
 }
 void *personi(int i)
 {
 while(1)
 {
 sleep(1);
 sem_wait(&table);
 if(table_used==0)
 {
 if(generated && generated_item[0]!=i &&
 generated_item[1]!=i)
 {
 printf("Thirsty Person %d has completed drinking\n", i+1);
 table_used=1;
 generated=0;
 }
 }
 sem_post(&table);
 }
}
main()
{
 pthread_t person0,person1,person2,person;
 sem_init(&table,0,1);
 pthread_create(&agnt,0,person,0);
 pthread_create(&person0,0,personi,0);
 pthread_create(&person1,0,personi,1);
 pthread_create(&person2,0,personi,2);
 while(1);
}
