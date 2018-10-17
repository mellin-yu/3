#include <stdio.h>
#include <stdlib.h>
#include "include_pub.h"
#include "main.h"

int FIN(int n)
{
    int x,i;
    int m;
    char ch;
    char name[10]={"\0"},num[3]={"\0"};
    printf("++++++++++信息查询++++++++++\n");
    printf("+       1、按课名查找      +\n");
    printf("+       2、按编号查找      +\n");
    printf("+       3、返回上一级      +\n");
    printf("++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    while(x!=3)
    {
        switch(x)
        {
            case 1:
                printf("输入要查找的课名：");
                scanf("%s",name);
                m=xingming(n,name);//按姓名
                break;
            case 2:
                printf("输入要查找的编号：");
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
            printf("%s %s %s %d %d %d %d\n",cou[m].cou_num,cou[m].cou_name,cou[m].cou_nature,cou[m].cou_time,cou[m].cou_credit,cou[m].cou_stu_num_al,cou[m].cou_num_limit);
	    fprintf(fs,"%s %s %s %d %d %d %d\n",cou[m].cou_num,cou[m].cou_name,cou[m].cou_nature,cou[m].cou_time,cou[m].cou_credit,cou[m].cou_stu_num_al,cou[m].cou_num_limit);
        }
        getchar();
        printf("是否继续查找（Y/N）：");
        scanf("%c",&ch);
        getchar();
        if('Y'==ch)
            {
                printf("++++++++++信息查询++++++++++\n");
                printf("+       1、按课名查找      +\n");
                printf("+       2、按编号查找      +\n");
                printf("+       3、返回上一级      +\n");
                printf("++++++++++++++++++++++++++++\n");
                printf("进入选项：");
                scanf("%d",&x);
            }
        else
        {
            system("cls");
            return 0;
        }
        if(x==3)
            system("cls");
    }
    return 0;
}

