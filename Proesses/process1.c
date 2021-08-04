//In this example, we will print natural numbers 
//from 1 to 10 using for loop and we will create a fork()
//you will see numbers will be printed twice, because of for()
//it will create duplicate copy of the process.

#include <stdio.h>
#include <unistd.h>
 
int main()
{
    int id,i;
     
    printf("Start of main...\n");
     
    id=fork();
    if(id < 0){
        /*fork creation failed*/
        printf("\nfork creation failed!!!\n");
    }
    else if(id==0)
    {
        /*child process*/
        printf("\nChild created...\n");
    }
    else{
        /*parent process*/
        printf("Parent section...\n");
    }

    printf("Printing the numbers from 1 to 10\n");
    for(i=1; i<=10; i++)
        printf("%d ",i);
    printf("\n");
    printf("End of the main function...\n");
 
    return 0;
}