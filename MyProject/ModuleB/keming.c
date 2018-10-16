#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pub.h"
#include "main.h"
int keming(int n,char name[])
{

    int i;

    for(i=0;i<n;i++)
    {
        if(strcmp(name,cou[i].cou_name)==0)
            return i;
    }
    return i;
}

