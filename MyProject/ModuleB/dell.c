#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pub.h"
#include "main.h"
int dell(int n,int dw)
{
    int i,k;

    for(k=dw;k<n-1;k++)
    {
        cou[k]=cou[k+1];
        n--;
    }

    return n;
}

