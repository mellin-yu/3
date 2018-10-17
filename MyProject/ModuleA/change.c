#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pua.h"
#include "main.h"

int xh(int n,int dw,char num[])
{
    int i=0;
    n=del(n,dw);
    while(i<n)
    {
        if(strcmp(num,stu[i].stu_num)==0)
        {
            printf("学号已存在，请重新输入：");
            scanf("%s",num);
            getchar();
            i=-1;
        }
        i++;
    }
    strcpy(t[dw].stu_num,num);
    fprintf(fs,"new:%s %s %s %d\n",t[dw].stu_num,t[dw].stu_name,t[dw].stu_C_al,t[dw].stu_credit);
    stu[n]=t[dw];
    n++;
    px(n);
    return 0;
}

int xm(int n,int dw,char name[])
{
    n=del(n,dw);
    strcpy(t[dw].stu_name,name);
    fprintf(fs,"new:%s %s %s %d\n",t[dw].stu_num,t[dw].stu_name,t[dw].stu_C_al,t[dw].stu_credit);
    stu[n]=t[dw];
    n++;
    px(n);
    return 0;
}

int kc(int n,int dw,char les[],int k)
{
    int j,i,a;
    FILE *fq;
    char course[5][10]={"\0"};
    char new_cou[10]={"\0"};
        for(j=0;j<strlen(les);j++)
        {
            i=0;
            a=0;
            while(les[j]!='-'&&j<strlen(les))
            {
                course[a][i]=les[j];
                j++;
                i++;
            }
            a++;
        }
        strcpy(les,"\0");
        for(j=0;j<a;j++)
        {
            for(i=0;i<k;i++)
            {
                if(strcmp(course[j],cou[i].cou_name)==0)
                {
                    cou[i].cou_stu_num_al--;
                    if(cou[i].cou_stu_num_al<cou[i].cou_num_limit)
                    {
                        cou[i].cou_stu_num_al++;
                        strcat(les,course[j]);
                        strcat(les,"-");
                    }
                    else
                    {
                        printf("%s:该课程人数已达上限，请重新选择课程\n",course[j]);
                        printf("输入新课程名字：");
                        scanf("%s",new_cou);
                        getchar();
                        strcpy(course[j],new_cou);
                        j--;
                    }
                }
            }
        }
        les[strlen(les)-1]='\0';
    n=del(n,dw);
    strcpy(t[dw].stu_C_al,les);
    fprintf(fs,"new:%s %s %s %d\n",t[dw].stu_num,t[dw].stu_name,t[dw].stu_C_al,t[dw].stu_credit);
    stu[n]=t[dw];
    n++;
    px(n);
    if((fq=fopen("cou.txt","w"))==NULL)
        exit(0);
    fprintf(fq,"编号 课程名   课程性质（必修/选修） 所占学时  所占学分  已选人数  人数上限");
    for(i=0;i<k;i++)
    {
        fprintf(fq,"\n%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,cou[i].cou_time,cou[i].cou_credit,cou[i].cou_stu_num_al,cou[i].cou_num_limit);
    }
    fclose(fq);
    return 0;
}

int change(int n,int k)
{
    char ch;
    char name[10]={"\0"},num[3]={"\0"};
    char lesson[100]={"\0"};
    int x,a,m,i,dw=0;
    printf("++++++++++信息修改++++++++++\n");
    printf("+       1、输入姓名        +\n");
    printf("+       2、输入学号        +\n");
    printf("+       3、返回上一级      +\n");
    printf("++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    while(x!=3)
    {
        switch(x)
        {
            case 1:
                printf("输入要修改同学的姓名：");
                scanf("%s",name);
                m=xingming(n,name);//按姓名
                break;
            case 2:
                printf("输入要修改同学的学号：");
                scanf("%s",num);
                m=xuehao(n,num);//按学号
                break;
            default :
		fprintf(fs,"%s\n","返回上一级");
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
            getchar();
            for(i=0;i<m;i++)
            {
                if(strcmp(num,t[i].stu_num)==0)
                {
                    dw=i;//定位具体的某一个学生
                    break;
                }
            }
            printf("%s %s %s %d",t[dw].stu_num,t[dw].stu_name,t[dw].stu_C_al,t[dw].stu_credit);
	    
        }
        getchar();
        printf("是否进行修改（Y/N）：");
        scanf("%c",&ch);
        if('Y'==ch)
        {
	    fprintf(fs,"old:%s %s %s %d\n",t[dw].stu_num,t[dw].stu_name,t[dw].stu_C_al,t[dw].stu_credit);
            printf("++++++++++信息修改++++++++++\n");
            printf("+       1、修改学号        +\n");
            printf("+       2、修改姓名        +\n");
            printf("+       3、修改课程        +\n");
            printf("++++++++++++++++++++++++++++\n");
            printf("进入选项：");
            scanf("%d",&a);
            switch(a)
            {
                case 1:
                    printf("输入新学号：");
                    scanf("%s",num);
                    xh(n,dw,num);
                    break;
                case 2:
                    printf("输入要新名字：");
                    scanf("%s",name);
                    xm(n,dw,name);

                    break;
                case 3:
                    printf("输入要新课程：");
                    scanf("%s",lesson);
                    kc(n,dw,lesson,k);

                default :
                    break;
            }
        }
        getchar();
        printf("是否继续更改：（Y/N）：");
        scanf("%c",&ch);
         getchar();
        if('Y'==ch)
        {
            printf("++++++++++信息修改++++++++++\n");
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
    system("cls");
    return 0;
}

