#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();
 
    // Parent process 
    if (child_pid > 0){
        printf("The proesses is created");
        sleep(30);
    }
 
    // Child process
    else    
        exit(0);
 
    return 0;
}