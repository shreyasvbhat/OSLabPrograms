//ls command simulation

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

void main(int argc,char *argv[])
{
        DIR *dp;
        struct dirent *dirp;
        if(argc<2)
        {
                printf("\nERROR:Directory name not passed...\n");
                exit(1);
        }
        if((dp=opendir(argv[1]))==NULL)
        {
                printf("\nERROR:Directory not found...\n");
                exit(EXIT_FAILURE);
        }
        while((dirp=readdir(dp))!=NULL)
        {
                printf("%s\n",dirp->d_name);
        }
        closedir(dp);
}