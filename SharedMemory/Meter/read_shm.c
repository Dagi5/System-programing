#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	// ftok to gnerate unique key
	key_t key=ftok("shmfile", 67);
    key_t key2=ftok("shmfi",68);

    //get the shmid
    int shmid=shmget(key, 1024, 0666);
    int shmid2=shmget(key2,1024, 0667);
    //attach to the memory segment
    char *shm=(char*) shmat(shmid,(void*)0, 0);
    
    //read data written previously
    printf("Data in memory = %s", shm);
    //detach and destroy the memory
    int s=atoi(shm);
    int cent=s*100;
    int milli=s*1000;
    int foot=s*3.2;
    printf("Height in meter Recieved From The Server : %d",s);
    printf("\n");
    printf("Height in Centemeters %d : ",cent);
    printf("\n");
    printf("Height in MilliMeters %d : ",milli);
    printf("\n");
    printf("Height in Foot %d : ",foot);
    printf("\n");
    shmdt(shm);
    
   
    shmctl(shmid, IPC_RMID, NULL);
	
	return 0;
}
