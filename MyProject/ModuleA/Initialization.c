#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "include_pua.h"

/*******键盘输入*******/
int keyboard(int n)
{
    int m,i=0;
    int j,k,a;

    char course[5][10]={"\0"};
    printf("输入学生个数：");
    scanf("%d",&m);
    printf("输入学生信息：\n");
    printf("学号 姓名       已选课程              共计学分\n");
    for(i=0;i<m;i++)
    {
        scanf("%s %s %s %d",stu[i].stu_num,stu[i].stu_name,stu[i].stu_C_al,&stu[i].stu_credit);
       for(j=0;j<strlen(stu[i].stu_C_al);j++)
        {
            k=0;
            a=0;
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
            for(k=0;k<n;k++)
            {
                if(strcmp(course[j],cou[k].cou_name)==0)
                {
                    if(cou[k].cou_stu_num_al<cou[k].cou_num_limit)
                        cou[k].cou_stu_num_al++;
                }
            }
        }
    }
    px(m);
    return m;
}
/*********End**********/

/*******文件输入*******/
int data(int n)
{
    char dataname[100]={"\0"};
    char course[5][10]={"\0"};
    FILE *fp;
    int i=0,j,k,a;
    printf("输入学生信息文件名：");
    scanf("%s",dataname);
    if((fp=fopen(dataname,"r"))==NULL)
        exit(0);

    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %d",stu[i].stu_num,stu[i].stu_name,stu[i].stu_C_al,&stu[i].stu_credit);

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
            for(k=0;k<n;k++)
            {
                if(strcmp(course[j],cou[k].cou_name)==0)
                {
                    if(cou[k].cou_stu_num_al<cou[k].cou_num_limit)
                        cou[k].cou_stu_num_al++;
                }
            }
        }
        i++;
    }
    fclose(fp);
    px(i);
    return i;
}
/**********End*********/


int Initialization(int k)
{
    int x,n=0,i;
    FILE *fq;
    system("clear");
    printf("++++++++++++信息初始化++++++++++\n");
    printf("+          1、键盘输入         +\n");
    printf("+          2、文件输入         +\n");
    printf("+          3、返回上一级       +\n");
    printf("++++++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    if(x==3)
        system("clear");
    switch(x)
    {
        case 1:
	    fprintf(fs,"%s\t","键盘输入:");
            n=keyboard(k);//键盘输入
	    fprintf(fs,"n=%d\t",n);
            break;
        case 2:
	    fprintf(fs,"%s\t","文件输入:");
            n=data(k);//文件输入
	    fprintf(fs,"n=%d\t",n);
            break;
        default :
            system("clear");
            break;       //返回
    }
    if((fq=fopen("cou.txt","w"))==NULL)
        exit(0);
    fprintf(fq,"编号 课程名   课程性质（必修/选修） 所占学时  所占学分  已选人数  人数上限");
    for(i=0;i<k;i++)
    {
        fprintf(fq,"\n%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,cou[i].cou_time,cou[i].cou_credit,cou[i].cou_stu_num_al,cou[i].cou_num_limit);
    }
    fclose(fq);
    return n;
}

