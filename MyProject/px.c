#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "include_pua.h"

void px(int n)
{
    STU a;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(stu[i].stu_num,stu[j].stu_num)>0)
            {
                a=stu[i];
                stu[i]=stu[j];
                stu[j]=a;
            }
        }
    }
}

