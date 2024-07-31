#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
        char fn[20],pat[10],temp[200];
        FILE *fp;
        printf("Enter the file name:\n");
        scanf("%s",fn);
        printf("Enter the pattern to be searched:\n");
        scanf("%s",pat);
        fp=fopen(fn,"r");
        while(!feof(fp))
        {
                fgets(temp,100,fp);
                if(strstr(temp,pat))
                        printf("%s",temp);
        }
        fclose(fp);
}