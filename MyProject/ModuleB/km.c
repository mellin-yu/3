#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pub.h"
#include "main.h"
int km(int n,int dw,char name[])
{
    int i,k,a,j;
    char course[5][10]={"\0"};
    for(i=0;i<n;i++)
    {
        a=0;
        for(j=0;j<strlen(stu[i].stu_C_al);j++)
        {
            k=0;

            while(stu[i].stu_C_al[j]!='-'&&j<strlen(stu[i].stu_C_al))
            {
                course[a][k]=stu[i].stu_C_al[j];
                j++;
                k++;
            }

            a++;
        }
        for(j=0;j<a;j++)
        {
            if(strcmp(course[j],cou[dw].cou_name)==0)
            {
                strcpy(course[j],name);
                break;
            }
        }
        strcpy(stu[i].stu_C_al,"\0");
        for(j=0;j<a;j++)
        {
            if(strcmp("\0",course[j])!=0)
            {
                strcat(stu[i].stu_C_al,course[j]);
                strcat(stu[i].stu_C_al,"-");
            }
        }
        stu[i].stu_C_al[strlen(stu[i].stu_C_al)-1]='\0';
    }
    if(strcmp("\0",course[j])!=0)
        strcpy(cou[dw].cou_name,name);
    return 0;
}

