#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define BUFFER_SIZE 30
int main(){
        int fd, n;
        char buffer[BUFFER_SIZE];
        fd=open("testFile.txt", O_RDWR);
        printf("File description is %d\n", fd);
        if( !(fd+1)){
                printf("\nFailed to open file.\n");
                exit(1);
        }
        printf("Reading first 10 characters from the file.\n");
        n=read(fd,buffer,10);
        write(1,buffer,n);
        printf("\nSkipping 5 characters from current position in the file:\n");
        lseek(fd,5,SEEK_CUR);
        n=read(fd,buffer,10);
        write(1,buffer,n);
        printf("\nGoing to 5th last character in the file:\n");
        lseek(fd, -5, SEEK_END);
        n=read(fd,buffer,7);
        write(1,buffer,n);
        printf("\nGoing to 3rd character in the file:\n");
        lseek(fd,3,SEEK_SET);
        n=read(fd,buffer,5);
        write(1,buffer,n);
        printf("\n");
        return 0;
}