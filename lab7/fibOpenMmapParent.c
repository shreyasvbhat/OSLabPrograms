#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(int argc,char *argv[]){
 int i,k,n1,n2,n3,shm_fd;
 pid_t pid;
 const int SIZE=4096;
 void *ptr;

 if(argc>1){
  sscanf(argv[1],"%d",&i);
  if(i<1){
   printf("Error input : %d\n",i);
   return 0;
  }
 }else{
  printf("Error: Not passing N in command line\n");
  exit(0);
 }

 pid=fork();
 if(pid==0){
  execlp("./fibopen","fibopen",argv[1],NULL);
 }else if(pid>0){
  wait(NULL);
  printf("\nPARENT : Child Completed\n");
  shm_fd=shm_open("Vss",O_RDONLY,0666);
  ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
  printf("Parent printing\n");
  printf("%s",(char*)ptr);
  printf("\n");
  shm_unlink("Vss");
 }
 return 0;
}