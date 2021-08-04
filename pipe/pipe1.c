#include <stdio.h>
#include <unistd.h>
#define MSGSIZE 20
char* msg1 = "1.Ashenafi Mohammed";
char* msg2 = "2.Dagim Shemels";
char* msg3 = "3.Dagim Damtew";

// Write and then read from the pipe
int main()

    char inbuf[MSGSIZE];
    int p[2], i;
  
    if (pipe(p) < 0){
        return 1;
    }

    write(p[1], msg1, MSGSIZE);
    write(p[1], msg2, MSGSIZE);
    write(p[1], msg3, MSGSIZE);
  
    for (i = 0; i < 3; i++) {
        read(p[0], inbuf, MSGSIZE);
        printf("The Members are: %s\n", inbuf);
    }
    return 0;
    
}