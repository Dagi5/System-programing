#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void errexit(char *errMsg){
  printf("\n About to exit: %s\n", errMsg);
  fflush(stdout);
  exit(1);
}
 
int main()
{
    int ret;
    pid_t pid;
    int value;
    char fifoName[]="testfifo";
    char errMsg[1000];
    FILE *cfp;
    FILE *pfp;

    ret = mknod(fifoName, S_IFIFO | 0600, 0); 
    /* 0600 gives read, write permissions to user and none to group and world */
    if(ret < 0){
      sprintf(errMsg,"Unable to create fifo: %s",fifoName);
      errexit(errMsg);
    }

    pid=fork();
    if(pid == 0){
      cfp = fopen(fifoName,"w");
      if(cfp == NULL) 
	    errexit("Unable to open fifo for writing");
      ret=fprintf(cfp,"%d",1000);
      fflush(cfp);
      exit(0);
    } 
    else{
      pfp = fopen(fifoName,"r");
      if(pfp == NULL) 
	    errexit("Unable to open fifo for reading");
      ret=fscanf(pfp,"%d",&value);
      if(ret < 0) 
	    errexit("Error reading from named pipe");
      fclose(pfp);
      printf("This is the parent. Received value %d from child on fifo \n", value);
      unlink(fifoName); /* Delete the created fifo */
      exit(0);
    }
}

