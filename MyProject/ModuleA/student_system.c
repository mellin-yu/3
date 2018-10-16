#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "include_pua.h"
int student_system()
{
    int x,n=0,k,i=0;
    FILE *fp;
    char dataname[100]={"\0"};
    FILE *fq;
    if((fq=fopen("class.txt","r"))==NULL)
        exit(0);
    while(!feof(fq))
    {
        fscanf(fq,"%s",cou[i].cou_num);
        fscanf(fq,"%s",cou[i].cou_name);
        fscanf(fq,"%s",cou[i].cou_nature);
        fscanf(fq,"%d",&cou[i].cou_time);
        fscanf(fq,"%d",&cou[i].cou_credit);
        fscanf(fq,"%d",&cou[i].cou_stu_num_al);
        fscanf(fq,"%d",&cou[i].cou_num_limit);
        i++;
    }
    k=i;
    fclose(fq);
    SX(i);
    system("cls");
    printf("++++++++++学生信息管理模块++++++++++\n");
    printf("+        1、初始化学生信息         +\n");
    printf("+        2、新增学生信息           +\n");
    printf("+        3、修改学生信息           +\n");
    printf("+        4、删除学生信息           +\n");
    printf("+        5、查看学生信息           +\n");
    printf("+        6、保存并返回             +\n");
    printf("+        7、返回上一级             +\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    if(x==7)
    {
        system("cls");
        return 0;
    }
    while(x<6)
    {
        switch(x)
        {
            case 1:
                n=Initialization(k);//初始化学生信息
                break;
            case 2:
                n=ADD(n,k);//新增学生信息
                break;
            case 3:
                change(n,k);//修改学生信息
                break;
            case 4:
                n=Delete(n,k);//删除学生信息
                break;
            case 5:
                Find(n);//查看学生信息
                break;
            default :

                break;
        }

        printf("++++++++++学生信息管理模块++++++++++\n");
        printf("+        1、初始化学生信息         +\n");
        printf("+        2、新增学生信息           +\n");
        printf("+        3、修改学生信息           +\n");
        printf("+        4、删除学生信息           +\n");
        printf("+        5、查看学生信息           +\n");
        printf("+        6、保存并返回             +\n");
        printf("+        7、返回上一级             +\n");
        printf("++++++++++++++++++++++++++++++++++++\n");
        printf("进入选项：");
        scanf("%d",&x);

    }
    if(x==6)
    {
        system("cls");
        printf("请输入保存路径/文件名：");
        scanf("%s",dataname);
        if((fp=fopen(dataname,"w"))==NULL)
            exit(0);
        fprintf(fp,"学号 姓名       已选课程              共计学分");
        for(i=0;i<n;i++)
        {
            fprintf(fp,"\n%s %s %s %d",stu[i].stu_num,stu[i].stu_name,stu[i].stu_C_al,stu[i].stu_credit);
        }
        fclose(fp);
        system("cls");
    }
    if(x==7)
    {
        system("cls");
    }
    return 0;
}

