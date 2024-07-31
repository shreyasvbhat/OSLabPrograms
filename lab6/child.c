#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>

typedef struct
{
        int n;
        int arr[100];
}pack_t;

int main()
{
        key_t key=1234;
        int shmid=shmget(key,sizeof(pack_t),0666);
        pack_t* shm_ptr=(pack_t*)shmat(shmid,NULL,0666);
        printf("[CHILD]Attached to shared memory with key = %d, id=%d ,address= %p\n",key,shmid,shm_ptr);
        for(int i=0;i<shm_ptr->n;i++)
                shm_ptr->arr[i]=2*i+1;
        printf("[CHILD]Finished generating first %d odd numbers\n",shm_ptr->n);
        shmdt((void*)shm_ptr);
        return 0;
}