#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFFER_SIZE 800
int main(){
        int n;
        char buffer[BUFFER_SIZE];
        int fd1 = open("testFile.txt", O_RDONLY);
        int fd2 = open("copy.txt", O_CREAT | O_WRONLY, 0666);
        printf("File desciptor for testFile.txt is %d and copy.txt is %d\n",fd1,fd2);
        if(!(fd1+1) && (fd2+1)){
                printf("Failed to open file.\n");
                exit(1);
        }
        n=read(fd1, buffer, BUFFER_SIZE);
        write(fd2,buffer,n);
        printf("File has been created and the contents are copied successfully.\n");
        return 0;
}