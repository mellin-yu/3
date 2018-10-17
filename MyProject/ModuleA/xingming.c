#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pua.h"
#include "main.h"
int xingming(int n,char name[])
{

    int i,m=0;

    for(i=0;i<n;i++)
    {
        if(strcmp(name,stu[i].stu_name)==0)
            t[m++]=stu[i];
    }
    return m;
}

