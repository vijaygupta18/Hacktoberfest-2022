#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<string.h>
int main( ) {
        int shmDesc;
        char msg[100];
        void * address;
        shmDesc = shm_open("SharedMemory1", O_RDONLY , 0666);
        if ( shmDesc == -1) {
                perror("shm_open");
                exit( -1 );
        }

 

        address = mmap(NULL, 512, PROT_READ, MAP_SHARED, shmDesc, 0 );
        if ( address == MAP_FAILED ) {
                perror("mmap");
                exit( -1 );
        }

 

        //strcpy(msg , "Shared Memory Reader_Code");
        memcpy ( msg ,address,  sizeof(msg));
        printf("The Reader process has read  ....  %s  \n... from the Shared Memory\n  ", msg);
        return 0;

 

}
