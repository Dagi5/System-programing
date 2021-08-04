#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// cltr + z
void signal_handler(int sig_number){
   printf("The caught signal numbers is: %d\n",sig_number);
   exit(sig_number);
}
int main(){
   signal(SIGTSTP, signal_handler);
   while(1){
      printf("Group members: Ashenafi Mohammed\n");
      printf("Group members: Dagim Shemelse\n");
      printf("Group members: Dagim Damtew\n");
      sleep(1);
   }
   return EXIT_SUCCESS;

}

