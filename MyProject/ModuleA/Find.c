#include <stdio.h>
#include <stdlib.h>
#include "include_pua.h"
#include "main.h"

int Find(int n)
{
    int x,i;
    int m;
    char ch;
    char name[10]={"\0"},num[3]={"\0"};
    printf("++++++++++信息查询++++++++++\n");
    printf("+       1、按姓名查找      +\n");
    printf("+       2、按学号查找      +\n");
    printf("+       3、返回上一级      +\n");
    printf("++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    while(x!=3)
    {
        switch(x)
        {
            case 1:
                printf("输入要查找的姓名：");
                scanf("%s",name);
                m=xingming(n,name);//按姓名
                break;
            case 2:
                printf("输入要查找的学号：");
                scanf("%s",num);
                m=xuehao(n,num);//按学号
                break;
            default :

                break;          //返回
        }
        getchar();
        printf("是否显示查找的信息（Y/N）：");
        scanf("%c",&ch);
        if('Y'==ch)
        {
            for(i=0;i<m;i++)
	    {
                printf("%s %s %s %d\n",t[i].stu_num,t[i].stu_name,t[i].stu_C_al,t[i].stu_credit);
	fprintf(fs,"%s %s %s %d\n",t[i].stu_num,t[i].stu_name,t[i].stu_C_al,t[i].stu_credit);
	    }
        }
        getchar();
        printf("是否继续查找（Y/N）：");
        scanf("%c",&ch);
        getchar();
        if('Y'==ch)
            {
                printf("++++++++++信息查询++++++++++\n");
                printf("+       1、按姓名查找      +\n");
                printf("+       2、按学号查找      +\n");
                printf("+       3、返回上一级      +\n");
                printf("++++++++++++++++++++++++++++\n");
                printf("进入选项：");
                scanf("%d",&x);
            }
        else
        {
            system("clear");
            return 0;
        }
        if(x==3)
            system("clear");
    }
    return 0;
}

