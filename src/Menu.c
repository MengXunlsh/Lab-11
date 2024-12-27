#include "Menu.h"
#include "ScoreSystem.h"

void StartApp()
{
	int op = 0, flag = 1;
	_Bool a = 1;
	char b = 'n';
	
	printf("请问是否从文件中读取学生成绩(y/n): ");
	scanf(" %c", &b);
	if (b == 'y' || b == 'Y')
	{
		ReadStudentInfoFromFile("StudentInfo.txt","SystemInfo.txt");
		Clear();
	}
	else
	{
		printf("请输入录入课程数：");
		if (scanf("%d", &sys_info.course_num));
		printf("请输入学生人数：");
		if (scanf("%d", &sys_info.stu_num));
		allocDataSpace();
	}
	
	do
	{
		ShowMenu();
		if (scanf("%d", &op))
		{
			switch (op)
			{
			case 1: system("cls");
				InputScore(p_stu_data, sys_info);
				ShowScore(p_stu_data, sys_info);
				Clear();
				break;
			case 2: system("cls");
				CourseSumAverage(p_stu_data, sys_info);
				Clear();
				break;
			case 3: system("cls");
				StudentSumAverage(p_stu_data, sys_info);
				Clear();
				break;
			case 4: system("cls");
				ScoreSortHigh(p_stu_data, sys_info);
				ShowScore(p_stu_data, sys_info);
				Clear();
				break;
			case 5: system("cls");
				ScoreSortLow(p_stu_data, sys_info);
				Clear();
				break;
			case 6: system("cls");
				NumSort(p_stu_data, sys_info);
				Clear();
				break;
			case 7: system("cls");
				DictSort(p_stu_data, sys_info);
				Clear();
				break;
			case 8: system("cls");
				SearchNum(p_stu_data, sys_info);
				Clear();
				break;
			case 9: system("cls");
				SearchName(p_stu_data, sys_info);
				Clear();
				break;
			case 10: system("cls");
				Statistic(p_stu_data, sys_info);
				Clear();
				break;
			case 11: system("cls");
				ShowScore(p_stu_data, sys_info);
				Clear();
				break;
			case 12: system("cls");
				Reset();
				Clear();
				break; 
			case 13: system("cls");
				WriteStudentInfoToFile("StudentInfo.txt","SystemInfo.txt");
                Clear();
				break; 
			case 14: system("cls");
				ReadStudentInfoFromFile("StudentInfo.txt","SystemInfo.txt");
				Clear();
				break;
			case 0: flag = 0;
				a = 0;
				break;
			default: printf("请输入正确的序号！\n");
				Clear();
				break;
			}
			if (flag == 0)
			{
				printf("程序结束！\n");
			}
		}
		else
		{
			printf("请正确输入！！");
			Clear();
		}
	} while (a);
	freeDataSpace();
}

void ShowMenu()
{
	system("cls");
	printf("\n\t----------学生成绩管理系统5.0-------------\n");
	printf("\t1.录入学生每门课的成绩\n");
	printf("\t2.计算总分和平均分(每门课程)\n");
	printf("\t3.计算总分和平均分(每个学生)\n");
	printf("\t4.按每个学生总分排序(降序)\n");
	printf("\t5.按每个学生总分排序(升序)\n");
	printf("\t6.显示学生成绩(按学号升序)\n");
	printf("\t7.显示学生成绩(按姓名的字典顺序)\n");
	printf("\t8.查询学生排名及各科成绩(按学号查询)\n");
	printf("\t9.查询学生排名及各科成绩(按姓名查询)\n");
	printf("\t10.统计每门课程各分数段人数与百分比\n");
	printf("\t11.显示每个学生每门课程成绩\n");
	printf("\t12.重新设置学生人数与课程信息\n");
	printf("\t13.将学生成绩导出到文件\n");
	printf("\t14.从文件导入学生成绩\n");
	printf("\t0.退出程序\n");
	printf("\t--------------------------------------------\n");
	printf("请输入要操作程序的序号 >> ");
}

void Clear()
{
	if (getchar())
	{
		printf("\n按回车返回上一界面");
		if (getchar());
	}
}
