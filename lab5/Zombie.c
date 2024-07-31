#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
        pid_t my_pid, child_pid, parent_pid;
        child_pid = fork();
        if(child_pid < 0 ){
                printf("Fork failed. Exiting.\n");
                exit(1);
        }
        if(child_pid == 0){
                printf("\n[CHILD] This is child process.\n");
                my_pid = getpid();
                parent_pid = getppid();
                printf("[CHILD] My pid is %d\n", my_pid);
                printf("[CHILD] My parent's pid is %d\n", parent_pid);
                printf("[CHILD] Exiting\n");
                exit(1);
        }else{
                printf("\n[PARENT] This is the parent process.\n");
                my_pid = getpid();
                parent_pid = getppid();
                printf("[PARENT] My pid is %d\n", my_pid);
                printf("[PARENT] My parent's pid is %d\n", parent_pid);
                printf("[PARENT] Sleeping for 10 seonds.\n");
                sleep(10);
                printf("\n[PARENT] Child process with pid=%d has ended, but still has an entry in the process table.\n", child_pid);
                printf("[PARENT] It is therefore a Zombie process.\n");
        }
        return 0;
}