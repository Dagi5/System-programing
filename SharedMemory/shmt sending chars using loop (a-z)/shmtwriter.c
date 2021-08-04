//SHMServer.C
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE     27


int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
    {
                perror("Success");

    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
      perror("error");

    }
        
    /*
     *      * Put some things into the memory for the
     *        other process to read.
     *        */
    s = shm;

    for (c = 't'; c <= 'z'; c++)
    {   
        *s++ = c;
    }
     

    /*
     * Wait until the other process
     * changes the first character of our memory
     * to '*', indicating that it has read what
     * we put there.
     */
    if (*shm != '*')
    {
       perror("Result");
    }
    exit(0);
}

