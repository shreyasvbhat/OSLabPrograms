#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
 void *psm;
 char buf[10];
 int shmid;
 shmid=shmget((key_t)1122,1024,0666);
 printf("Key of the shared memory : %d\n",shmid);
 psm=shmat(shmid,NULL,0666);
 printf("process attached at : %p\n",psm);
 printf("data read from  the shared memory is : %s",(char*)psm);
 printf("\n");
 shmctl(shmid,IPC_RMID,NULL);
 return 0;
}