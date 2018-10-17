#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pua.h"
#include "main.h"
int del(int n,int dw)
{
    int i,k;

        for(i=0;i<n;i++)
        {
            if(strcmp(t[dw].stu_num,stu[i].stu_num)==0)
            {
                for(k=i;k<n-1;k++)
                {
                    stu[k]=stu[k+1];
                    n--;
                }
                break;
            }

        }

    return n;
}

