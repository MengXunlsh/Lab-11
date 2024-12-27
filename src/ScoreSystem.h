#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ScoreData.h"

void allocDataSpace();
void freeDataSpace();
void InputScore(STU* p_stu_data, SYS sys_info);
void Sum(STU* p_stu_data, SYS sys_info);
void Statistic(STU* p_stu_data, SYS sys_info);
void ShowScore(STU* p_stu_data, SYS sys_info);
void CourseSumAverage(STU* p_stu_data, SYS sys_info);
void StudentSumAverage(STU* p_stu_data, SYS sys_info);
void ScoreSortHigh(STU* p_stu_data, SYS sys_info);
void ScoreSortLow(STU* p_stu_data, SYS sys_info);
void NumSort(STU* p_stu_data, SYS sys_info);
void DictSort(STU* p_stu_data, SYS sys_info);
void SearchNum(STU* p_stu_data, SYS sys_info);
void SearchName(STU* p_stu_data, SYS sys_info);
void Reset();
void WriteStudentInfoToFile(const char* studentFileName, const char* systemFileName);
void ReadStudentInfoFromFile(const char* studentFileName, const char* systemFileName);