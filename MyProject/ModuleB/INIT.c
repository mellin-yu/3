#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "include_pub.h"

/*******键盘输入*******/
int Keyboard()
{
    int m,i=0;
    printf("输入课程个数：");
    scanf("%d",&m);
    printf("输入课程信息：\n");
    printf("编号 课程名   课程性质（必修/选修） 所占学时  所占学分  已选人数  人数上限");
    for(i=0;i<m;i++)
    {
        scanf("%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,&cou[i].cou_time,&cou[i].cou_credit,&cou[i].cou_stu_num_al,&cou[i].cou_num_limit);
    }
    SX(m);
    return m;
}
/*********End**********/

/*******文件输入*******/
int Data()
{
    char dataname[100]={"\0"};
    FILE *fp;
    int i=0;
    printf("输入课程信息文件名：");
    scanf("%s",dataname);
    if((fp=fopen(dataname,"r"))==NULL)
        exit(0);

    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,&cou[i].cou_time,&cou[i].cou_credit,&cou[i].cou_stu_num_al,&cou[i].cou_num_limit);
        i++;
    }
    fclose(fp);
    SX(i);
    return i;
}
/**********End*********/


int INIT()
{
    int x,n=0,i=0;
    FILE *fq;
    system("cls");
    printf("++++++++++++信息初始化++++++++++\n");
    printf("+          1、键盘输入         +\n");
    printf("+          2、文件输入         +\n");
    printf("+          3、返回上一级       +\n");
    printf("++++++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    if(x==3)
        system("cls");
    switch(x)
    {
        case 1:
            n=Keyboard();//键盘输入
            break;
        case 2:
            n=Data();//文件输入
            break;
        default :
            system("cls");
            break;       //返回
    }
    if((fq=fopen("cou.txt","w"))==NULL)
        exit(0);
    fprintf(fq,"编号 课程名   课程性质（必修/选修） 所占学时  所占学分  已选人数  人数上限");
    for(i=0;i<n;i++)
    {
        fprintf(fq,"\n%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,cou[i].cou_time,cou[i].cou_credit,cou[i].cou_stu_num_al,cou[i].cou_num_limit);
    }
    fclose(fq);
    return n;
}

