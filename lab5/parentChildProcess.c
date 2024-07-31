#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
        pid_t child_pid, my_pid, parent_pid, wid;
        int i=0;
        child_pid = fork();
        if(child_pid < 0){
                printf("\nFork failed, exiting!!");
                exit(0);
        }
        if(child_pid == 0){
                printf("\n[CHILD] This is the child process.\n");
                my_pid = getpid();
                parent_pid = getppid();
                printf("[CHILD] My pid is %d\n", my_pid);
                printf("[CHILD] My parent's pid is %d\n", parent_pid);
                printf("[CHILD] i=%d\n", --i);
                printf("[CHILD] Child process is going to load another program using execlp system call\n");
                execlp("/bin/pwd", "pwd", NULL);
        }else{
                printf("\n[PARENT] This is the parent pocess.\n");
                my_pid = getpid();
                parent_pid = getppid();
                printf("[PARENT] My pid is %d\n", my_pid);
                printf("[PARENT] Wating for the child to terminate\n");
                wid = wait(NULL);
                printf("\n[PARENT] Resuming after termination of %d\n",wid);
                printf("[PARENT] My parent's pid is %d\n", parent_pid);
                printf("[PARENT] My child's pid is %d\n", child_pid);
                printf("[PARENT] i=%d\n", ++i);
        }
        return 0;
}