#include <stdio.h>
#include <stdlib.h>
#include "include_pub.h"
#include "main.h"

int AND(int n)
{
    int m,i=0,j;
    printf("输入添加的课程个数：");
    scanf("%d",&m);
    printf("输入课程信息：\n");
    printf("编号 课程名   课程性质（必修/选修） 所占学时  所占学分  已选人数  人数上限\n");
    for(i=n;i<m+n;i++)
    {
        scanf("%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,&cou[i].cou_time,&cou[i].cou_credit,&cou[i].cou_stu_num_al,&cou[i].cou_num_limit);
    }
    SX(m+n);
    for(i=0;i<m+n;i++)
        printf("%s %s %s %d %d %d %d\n",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,cou[i].cou_time,cou[i].cou_credit,cou[i].cou_stu_num_al,cou[i].cou_num_limit);
    return n+m;
}

