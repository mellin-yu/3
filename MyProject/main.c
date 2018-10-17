#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int main()
{
    int x;
    if((fs=fopen("./operation.log","a+"))==NULL)
    {
        printf("can not open operation.log");
        exit(1);
    }
    printf("++++++++++学生选课系统++++++++++\n");
    printf("+     1、学生信息管理模块      +\n");
    printf("+     2、可选课程管理模块      +\n");
    printf("+     3、退出系统              +\n");
    printf("++++++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    while(x!=3)
    {
        switch(x)
        {
            case 1:
		fprintf(fs,"%s\n\t","进入学生信息:");
                student_system();//进入学生信息
                break;
            case 2:
		fprintf(fs,"%s\n\t","进入选课信息:");
                course_system();//进入选课信息
                break;
            default :
		fprintf(fs,"%s\n","退出系统");
                system("clean");
                break;          //退出
        }

        printf("++++++++++学生选课系统++++++++++\n");
        printf("+     1、学生信息管理模块      +\n");
        printf("+     2、可选课程管理模块      +\n");
        printf("+     3、退出系统              +\n");
        printf("++++++++++++++++++++++++++++++++\n");
        printf("进入选项：");
        scanf("%d",&x);
    }
    printf("*********感谢使用**********");
    fclose(fs);
    return 0;
}

