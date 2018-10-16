#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pub.h"
#include "main.h"
int xf(int n,int dw,int new_credit)
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
                stu[i].stu_credit=stu[i].stu_credit-cou[dw].cou_credit+new_credit;
                break;
            }
        }
    }
    if(new_credit!=0)
        cou[dw].cou_credit=new_credit;
    return 0;
}

