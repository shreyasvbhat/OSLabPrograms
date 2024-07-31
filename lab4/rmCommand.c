#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
        if(argc<2)
        {
                printf("ERROR:Cannot remove file\n");
                exit(EXIT_FAILURE);
        }
        else
        {
                char *filename=argv[1];
                if(remove(filename)==0)
                {
                        printf("\nFILE REMOVED...\n");
                }
                else
                {
                        printf("\nCannot REMOVE FILE\n");
                }
                return(EXIT_SUCCESS);
        }
}