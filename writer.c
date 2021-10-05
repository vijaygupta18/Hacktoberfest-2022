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
        shmDesc = shm_open("SharedMemory1", O_RDWR | O_CREAT, 0666);
        if ( shmDesc == -1) {
                perror("shm_open");
                exit( -1 );
        }
        if ( ftruncate ( shmDesc , 512 ) < 0 ) {
                perror("ftruncate");
                exit( -1 );
        }

 

        address = mmap(NULL, 512, PROT_WRITE, MAP_SHARED, shmDesc, 0 );
        if ( address == MAP_FAILED ) {
                perror("mmap");
                exit( -1 );
        }

 

        strcpy(msg , "Shared Memory Code");
        memcpy (address, msg , strlen(msg)+1);
        printf("The Writer process had written ....  %s  \n... to the Shared Memory\n  ", msg);
        return 0;

 

}
