#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include_pub.h"
#include "main.h"

int bh(int n,int dw,char num[])
{
    int i=0;
    while(i<n)
    {
        if(strcmp(num,cou[i].cou_num)==0)
        {
            printf("编号已存在，请重新输入：");
            scanf("%s",num);
            getchar();
            i=-1;
        }
        i++;
    }
    strcpy(cou[dw].cou_num,num);
    fprintf(fs,"new:%s %s %s %d %d %d %d\n",cou[dw].cou_num,cou[dw].cou_name,cou[dw].cou_nature,cou[dw].cou_time,cou[dw].cou_credit,cou[dw].cou_stu_num_al,cou[dw].cou_num_limit);
    SX(n);
    return 0;
}


int CHAN(int n,int k)
{
    char ch;
    char name[10]={"\0"},num[3]={"\0"};
    char new_nature[10]={"\0"};
    int x,a,m,i=0,dw=0;
    int new_time,new_credit,new_limit;
    FILE *fq;
    printf("++++++++++信息修改++++++++++\n");
    printf("+       1、输入课名        +\n");
    printf("+       2、输入编号        +\n");
    printf("+       3、返回上一级      +\n");
    printf("++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    while(x!=3)
    {
        switch(x)
        {
            case 1:
                printf("输入要修改课程的姓名：");
                scanf("%s",name);
                dw=keming(n,name);//按课名
                while(dw==n)
                {
                    getchar();
                    printf("无此课程，请重新输入：");
                    scanf("%s",name);
                    dw=keming(n,name);
                }
                break;
            case 2:
                printf("输入要修改课程的编号：");
                scanf("%s",num);
                dw=bianhao(n,num);//按编号
                while(dw==n)
                {
                    getchar();
                    printf("无此课程，请重新输入：");
                    scanf("%s",num);
                    dw=keming(n,num);
                }
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
        printf("是否进行修改（Y/N）：");
        scanf("%c",&ch);
        if('Y'==ch)
        {
	    fprintf(fs,"old:%s %s %s %d %d %d %d\n",cou[dw].cou_num,cou[dw].cou_name,cou[dw].cou_nature,cou[dw].cou_time,cou[dw].cou_credit,cou[dw].cou_stu_num_al,cou[dw].cou_num_limit);
            printf("++++++++++信息修改++++++++++\n");
            printf("+       1、修改编号        +\n");
            printf("+       2、修改课名        +\n");
            printf("+       3、修改性质        +\n");
            printf("+       4、修改学时        +\n");
            printf("+       5、修改学分        +\n");
            printf("+       6、修改上限        +\n");
            printf("++++++++++++++++++++++++++++\n");
            printf("进入选项：");
            scanf("%d",&a);
            switch(a)
            {
                case 1:
                    printf("输入新编号：");
                    scanf("%s",num);
                    bh(n,dw,num);
                    break;
                case 2:
                    printf("输入新课名：");
                    scanf("%s",name);
                    km(k,dw,name);
		    fprintf(fs,"new:%s %s %s %d %d %d %d\n",cou[dw].cou_num,cou[dw].cou_name,cou[dw].cou_nature,cou[dw].cou_time,cou[dw].cou_credit,cou[dw].cou_stu_num_al,cou[dw].cou_num_limit);
                    break;
                case 3:
                    printf("输入新性质：");
                    scanf("%s",new_nature);
                    strcpy(cou[dw].cou_nature,new_nature);
		    fprintf(fs,"new:%s %s %s %d %d %d %d\n",cou[dw].cou_num,cou[dw].cou_name,cou[dw].cou_nature,cou[dw].cou_time,cou[dw].cou_credit,cou[dw].cou_stu_num_al,cou[dw].cou_num_limit);
                case 4:
                    printf("输入新学时：");
                    scanf("%d",&new_time);
                    cou[dw].cou_time=new_time;
		    fprintf(fs,"new:%s %s %s %d %d %d %d\n",cou[dw].cou_num,cou[dw].cou_name,cou[dw].cou_nature,cou[dw].cou_time,cou[dw].cou_credit,cou[dw].cou_stu_num_al,cou[dw].cou_num_limit);
                case 5:
                    printf("输入新学分：");
                    scanf("%d",&new_credit);
                    xf(k,dw,new_credit);
		    fprintf(fs,"new:%s %s %s %d %d %d %d\n",cou[dw].cou_num,cou[dw].cou_name,cou[dw].cou_nature,cou[dw].cou_time,cou[dw].cou_credit,cou[dw].cou_stu_num_al,cou[dw].cou_num_limit);
                case 6:
                    printf("输入新上限：");
                    scanf("%d",&new_limit);
                    cou[dw].cou_num_limit=new_limit;
		    fprintf(fs,"new:%s %s %s %d %d %d %d\n",cou[dw].cou_num,cou[dw].cou_name,cou[dw].cou_nature,cou[dw].cou_time,cou[dw].cou_credit,cou[dw].cou_stu_num_al,cou[dw].cou_num_limit);
                default :
		    fprintf(fs,"%s\n","返回上一级");
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
            printf("+       1、输入课名        +\n");
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
        fprintf(fq,"%s %s %s %d",stu[i].stu_num,stu[i].stu_name,stu[i].stu_C_al,stu[i].stu_credit);
    }
    fclose(fq);
    system("clear");
    return 0;
}

