#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	// ftok to gnerate unique key
	key_t key=ftok("shmfile", 67);


    //get the shmid
    int shmid=shmget(key, 1024, 0666);
  
    //attach to the memory segment
    char *shm=(char*) shmat(shmid,(void*)0, 0);
    
    //read data written previously
    printf("Data in memory = %s", shm);
    //detach and destroy the memory
    //int s=atoi(shm);
    //int d=s*2;
 
    shmdt(shm);
    
   
    shmctl(shmid, IPC_RMID, NULL);
	
	return 0;
}
