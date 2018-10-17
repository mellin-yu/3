#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pua.h"
#include "main.h"
int xuehao(int n,char num[])
{

    int i,m=0;

    for(i=0;i<n;i++)
    {
        if(strcmp(num,stu[i].stu_num)==0)
            t[m++]=stu[i];
    }
    return m;

}

