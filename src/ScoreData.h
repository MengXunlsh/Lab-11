#pragma once
#define MAX_LEN 20

//保存每个学生信息
typedef struct Student
{
	int num;//学生学号
	char* pstu_name;//学生姓名
	float *pstu_score;//学生各科成绩
	float stu_sum;//学生总成绩
	float stu_average;//学生平均成绩
}STU;

//保存其余信息
typedef struct SysInfo
{
	char** pcourse_name;//课程名称
	int course_num;//课程总数
	int stu_num;//学生总数
	float* course_sum;//课程总分
}SYS;

STU* p_stu_data;
SYS sys_info;