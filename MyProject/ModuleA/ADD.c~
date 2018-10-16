#include <stdio.h>
#include <stdlib.h>
#include "include_pua.h"
#include "main.h"

int ADD(int n,int k)
{
    int m,i=0,j,l,a;
    char new_cou[10]={"\0"};
    char course[5][10]={"\0"};
    FILE *fq;
    printf("输入添加的学生个数：");
    scanf("%d",&m);
    printf("输入学生信息：\n");
    printf("学号 姓名   已选课程   共计学分\n");
    for(i=n;i<m+n;i++)
    {
        scanf("%s %s %s %d",stu[i].stu_num,stu[i].stu_name,stu[i].stu_C_al,&stu[i].stu_credit);
        a=0;
        for(j=0;j<strlen(stu[i].stu_C_al);j++)
        {
            l=0;

            while(stu[i].stu_C_al[j]!='-'&&j<strlen(stu[i].stu_C_al))
            {
                course[a][l]=stu[i].stu_C_al[j];
                j++;
                l++;
            }
            a++;
        }
        strcpy(stu[i].stu_C_al,"\0");
        for(j=0;j<a;j++)
        {
            for(l=0;l<k;l++)
            {
                if(strcmp(course[j],cou[l].cou_name)==0)
                {
                    if(cou[l].cou_stu_num_al<cou[l].cou_num_limit)
                    {
                        cou[l].cou_stu_num_al++;
                        strcat(stu[i].stu_C_al,course[j]);
                        strcat(stu[i].stu_C_al,"-");
                    }
                    else
                    {
                        printf("%s:该课程人数已达上限，请重新选择课程\n",course[j]);
                        printf("输入新课程名字：");
                        scanf("%s",new_cou);
                        strcpy(course[j],new_cou);
                        j--;
                    }
                }
            }
        }
        stu[i].stu_C_al[strlen(stu[i].stu_C_al)-1]='\0';
    }
    px(m+n);
    for(i=0;i<m+n;i++)
        printf("%s %s %s %d\n",stu[i].stu_num,stu[i].stu_name,stu[i].stu_C_al,stu[i].stu_credit);

    if((fq=fopen("cou.txt","w"))==NULL)
        exit(0);
    fprintf(fq,"编号 课程名   课程性质（必修/选修） 所占学时  所占学分  已选人数  人数上限");
    for(i=0;i<k;i++)
    {
        fprintf(fq,"\n%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,cou[i].cou_time,cou[i].cou_credit,cou[i].cou_stu_num_al,cou[i].cou_num_limit);
    }
    fclose(fq);
    return n+m;
}


