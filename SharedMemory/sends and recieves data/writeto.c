#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
	//create ftok key
	key_t key=ftok("shmfile",67);
	//get shmid using the shmget function
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	//attach the memory segment using shmat
	char *shm=(char*) shmat(shmid,(void*)0,0);
	
	//accept input from the user
	printf("Write a data: ");
	fgets(shm, sizeof(shm), stdin);
	

	printf("\nData written in memory: %s\n", shm);
	//detach the shm

	shmdt(shm);
		

	return 0;
}
