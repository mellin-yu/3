#include <stdio.h>
#include <stdlib.h>
#include "include_pub.h"
#include "main.h"
int DELE(int n,int k)
{
    char ch;
    char name[10]={"\0"},num[3]={"\0"};
    int x,a,m,i=0,j,dw=0;
    FILE *fq;
    printf("++++++++++信息删除++++++++++\n");
    printf("+       1、输入课程        +\n");
    printf("+       2、输入编号        +\n");
    printf("+       3、返回上一级      +\n");
    printf("++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    getchar();
    while(x!=3)
    {
        switch(x)
        {
            case 1:
                printf("输入要删除课程的课名：");
                scanf("%s",name);
                dw=keming(n,name);//按姓名
                break;
            case 2:
                printf("输入要删除课程的编号：");
                scanf("%s",num);
                dw=bianhao(n,num);//按学号
                break;
            default :

                break;          //返回
        }

        getchar();
        printf("是否显示搜索到的课程的当前信息（Y/N）：");
        scanf("%c",&ch);
        if('Y'==ch)
        {
            printf("%s %s %s %d %d %d %d\n",cou[dw].cou_num,cou[dw].cou_name,cou[dw].cou_nature,cou[dw].cou_time,cou[dw].cou_credit,cou[dw].cou_stu_num_al,cou[dw].cou_num_limit);
        }
        getchar();
        printf("是否进行删除（Y/N）：");
        scanf("%c",&ch);
        if('Y'==ch)
        {
            xf(k,dw,0);
            km(k,dw,"\0");
            n=dell(n,dw);
        }
        getchar();
        printf("是否继续删除：（Y/N）：");
        scanf("%c",&ch);
         getchar();
        if('Y'==ch)
        {
            printf("++++++++++信息删除++++++++++\n");
            printf("+       1、输入课程        +\n");
            printf("+       2、输入编号        +\n");
            printf("+       3、返回上一级      +\n");
            printf("++++++++++++++++++++++++++++\n");
            printf("进入选项：");
            scanf("%d",&x);
        }
        else
            break;

    }
    if((fq=fopen("stu.txt","w"))==NULL)
        exit(0);
    for(i=0;i<k;i++)
    {
        fprintf(fq,"%s %s %s %d\n",stu[i].stu_num,stu[i].stu_name,stu[i].stu_C_al,stu[i].stu_credit);
    }
    fclose(fq);
    system("cls");
    return n;
}

