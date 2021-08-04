#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Communicating between processes 
int main(){
    int p[2];
    if(pipe(p) == -1){
       printf("ERROR!!!");
       return 1;
    }

    int pid = fork();
    if(pid == -1){
        printf("ERROR!!!");
        return 2;
    }

    else if(pid == 0){
        close(p[0]);
        int x;
        printf("Enter any Number: ");
        scanf("%d", &x);
        write(p[1], &x, sizeof(int));
        close(p[1]);
    }
    else{
        close(p[1]);
        int y;
        read(p[0], &y, sizeof(int));
        close(p[0]);
        printf("Got from the child process: %d\n", y);
        
    }
    return 0;
}