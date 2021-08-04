#include <stdio.h>
#include <sys/mman.h>
//Points the index of an array to the address of each index
int main(){

int N=5;
int *ptr = mmap ( NULL, N*sizeof(int),PROT_READ| PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 ); 
//Points due to the size of integer N with param(addr,size,prot,fd(0/1),offset)
//address is null the kernel chooses a suitable address
//offset the starting poin of mapping in this case 0
if(ptr == MAP_FAILED){
    printf("Mapping Failed\n");
    return 1;
}

printf("Points array elements to each pointer of the array starting form offset and multiplied by ten >>> : ");
for(int i=0; i<N; i++)
    ptr[i] = i*10;

for(int i=0; i<N; i++)//for displaying
    printf("[%d] ",ptr[i]);

printf("\n");
int err = munmap(ptr, 10*sizeof(int));//unmapping failed if munmap is different from 0 since offset is 0
if(err != 0){
    printf("UnMapping Failed\n");
    return 1;
}

return 0;
}