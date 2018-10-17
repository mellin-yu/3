#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pub.h"
#include "main.h"
int bianhao(int n,char num[])
{

    int i;

    for(i=0;i<n;i++)
    {
        if(strcmp(num,cou[i].cou_num)==0)
            return i;
    }
    return i;

}

