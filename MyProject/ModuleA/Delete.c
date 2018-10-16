#include <stdio.h>
#include <stdlib.h>
#include "include_pua.h"
#include "main.h"
int Delete(int n,int k)
{
    char ch;
    char name[10]={"\0"},num[3]={"\0"};
    char lesson[100]={"\0"};
    char course[5][10]={"\0"};
    int x,l,a,m,i,j,dw=0;
    FILE *fq;
    printf("++++++++++信息删除++++++++++\n");
    printf("+       1、输入姓名        +\n");
    printf("+       2、输入学号        +\n");
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
                printf("输入要删除同学的姓名：");
                scanf("%s",name);
                m=xingming(n,name);//按姓名
                break;
            case 2:
                printf("输入要删除同学的学号：");
                m=xuehao(n,num);//按学号
                break;
            default :

                break;          //返回
        }
        getchar();
        printf("是否显示搜索到的同学的当前信息（Y/N）：");
        scanf("%c",&ch);
        if('Y'==ch)
        {
            for(i=0;i<m;i++)
                printf("%s %s %s %d\n",t[i].stu_num,t[i].stu_name,t[i].stu_C_al,t[i].stu_credit);
        }
        if(m>1)
        {
            getchar();
            printf("输入其中操作的具体某一个学生的学号：");
            scanf("%s",num);
            for(i=0;i<m;i++)
            {
                if(strcmp(num,t[i].stu_num)==0)
                {
                    dw=i;//定位具体的某一个学生
                    break;
                }
            }
            printf("%s %s %s %d\n",t[dw].stu_num,t[dw].stu_name,t[dw].stu_C_al,t[dw].stu_credit);
        }

        getchar();
        printf("是否进行删除（Y/N）：");
        scanf("%c",&ch);
        if('Y'==ch)
        {
            a=0;
            for(j=0;j<strlen(t[dw].stu_C_al);j++)
            {
                l=0;

                while(t[dw].stu_C_al[j]!='-'&&j<strlen(t[dw].stu_C_al))
                {
                    course[a][l]=t[dw].stu_C_al[j];
                    j++;
                    l++;
                }
                a++;
            }
        }
        for(j=0;j<a;j++)
        {
            for(l=0;l<k;l++)
            {
                if(strcmp(course[j],cou[l].cou_name)==0)
                {
                    cou[l].cou_stu_num_al--;
                    break;
                }
            }

        }
        n=del(n,dw);
        getchar();
        printf("是否继续删除：（Y/N）：");
        scanf("%c",&ch);
         getchar();
        if('Y'==ch)
        {
            printf("++++++++++信息删除++++++++++\n");
            printf("+       1、输入姓名        +\n");
            printf("+       2、输入学号        +\n");
            printf("+       3、返回上一级      +\n");
            printf("++++++++++++++++++++++++++++\n");
            printf("进入选项：");
            scanf("%d",&x);
        }
        else
            break;

    }
    if((fq=fopen("cou.txt","w"))==NULL)
        exit(0);
    fprintf(fq,"编号 课程名   课程性质（必修/选修） 所占学时  所占学分  已选人数  人数上限");
    for(i=0;i<k;i++)
    {
        fprintf(fq,"\n%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,cou[i].cou_time,cou[i].cou_credit,cou[i].cou_stu_num_al,cou[i].cou_num_limit);
    }
    fclose(fq);
    system("cls");
    return n;
}

