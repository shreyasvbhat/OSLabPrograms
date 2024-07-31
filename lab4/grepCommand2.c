#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
        if(argc!=3)
        {
                printf("\nError:Cannot read pattern\n");
                exit(1);
        }
        else
        {
                FILE *fp=fopen(argv[2],"r");
                if(fp==NULL)
                {
                        printf("\nError:FILE NOT FOUND...\n");
                        exit(1);
                }
                char temp[200];
                while(!feof(fp))
                {
                        fgets(temp,100,fp);
                        if(strstr(temp,argv[1]))
                        {
                                printf("%s\n",temp);
                        }
                }
                fclose(fp);
        }
}