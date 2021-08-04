#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    int pid = fork();
    if(pid == -1){
        return 1;
    }

    if(pid == 0){
        while(1){
            printf("Group member: Ashenafi Mohammed \n");
            printf("Group member: Dagim Shemlse \n");
            printf("Group member: Dagim Damtew \n");
            usleep(50000);
        }
    }
    else{
        sleep(1);
        kill(pid,SIGKILL);
        wait(NULL);
    }
}