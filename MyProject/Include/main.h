#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <stdio.h>
FILE *fs;
typedef struct{
    char stu_num[3];//学号
    char stu_name[10];//姓名
    char stu_C_al[100];//已选课程
    int stu_credit;//共计学分
}STU;

typedef struct{
    char cou_num[4];//课程编号
    char cou_name[10];//课程名称
    char cou_nature[10];//课程性质
    int cou_time;//课程学时
    int cou_credit;//课程学分
    int cou_stu_num_al;//课程已选人数
    int cou_num_limit;//课程人数上限
}COU;
STU stu[50];//学生操作结构体
STU t[50];//查询学生信息存放的结构体
COU cou[100];//课程操作的结构体
COU c[100];//查询课程信息存放的结构体
//函数声明
int student_system();//学生信息
int course_system();//课程信息
void SX(int n);
void px(int n);
#endif // MAIN_H_INCLUDED












