//Creating process to be killed: 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
int main() 
{ 
 int i; 
 printf("Hello...\n"); 
 printf("My process ID is %d\n", getpid()); 
 for(i = 0 ; i < 100 ; i++ ) 
 sleep(1); 
 return 0; 
} 
//Killing the Process: 
#include<stdio.h> 
#include<stdlib.h> 
#include<signal.h> 
int main(int argc, char * argv[]) 
{ 
 kill(atoi(argv[1]), SIGKILL); 
 return 0; 
}
