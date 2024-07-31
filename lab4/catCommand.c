#include<stdio.h>
#include<stdlib.h>

void main(int argc,char *argv[])
{
        FILE *fp;
        char ch;
        if(argc<2)
        {
                printf("\nError:File not entered\n");
                exit(1);
        }
        else
        {
                fp=fopen(argv[1],"r");
                if(fp==NULL)
                {
                        printf("\nError:File not found error...\n");
                        exit(1);
                }
                while((ch=fgetc(fp))!=EOF)
                {
                        printf("%c",ch);
                }
                fclose(fp);
                printf("\n");
        }
}