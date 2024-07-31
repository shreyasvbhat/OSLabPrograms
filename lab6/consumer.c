#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
 void *psm;
 int shmid;
 shmid=shm_open("trying",O_RDONLY,0666);
 ftruncate(shmid,1024);
 psm=mmap(0,1024,PROT_READ,MAP_SHARED,shmid,0);
 printf("Key/ID/fs of the shared memory %d\n",shmid);
 printf("shared memory for consumer is attached at : %p\n",psm);
 printf("%s",(char*)psm);
 printf("\n");
 shm_unlink("trying");
 return 0;
}