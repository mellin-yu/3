#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "include_pub.h"

void SX(int n)
{
    COU a;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(cou[i].cou_num,cou[j].cou_num)>0)
            {
                a=cou[i];
                cou[i]=cou[j];
                cou[j]=a;
            }
        }
    }
}

