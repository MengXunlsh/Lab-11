#include "ScoreSystem.h"

void CourseSumAverage(STU *p_stu_data, SYS sys_info) // 打印课程总分平均分
{
	int j = 0;

	if (p_stu_data[0].num <= 0)
	{
		printf("请录入学生成绩后操作！");
		return;
	}
	printf("%-20s%-20s%-20s\n", "科目", "总分", "平均分");
	for (j = 0; j < sys_info.course_num; j++)
	{
		printf("%-20s%-18.1f%-18.1f\n", sys_info.pcourse_name[j], sys_info.course_sum[j], sys_info.course_sum[j] / sys_info.stu_num);
	}
}

void StudentSumAverage(STU *p_stu_data, SYS sys_info) //	打印学生总分平均分
{
	int i = 0;

	if (p_stu_data[0].num <= 0)
	{
		printf("请录入学生成绩后操作！");
		return;
	}
	printf("%-20s%-20s%-20s%-20s\n", "学号", "姓名", "总分", "平均分");
	for (i = 0; i < sys_info.stu_num; i++)
	{
		printf("%-18d%-20s%-18.1f%-18.1f\n", p_stu_data[i].num, p_stu_data[i].pstu_name, p_stu_data[i].stu_sum, p_stu_data[i].stu_average);
	}
}

void ScoreSortHigh(STU *p_stu_data, SYS sys_info) //		按总分排序_降序
{
	int i = 0, j = 0;
	STU temp = {0};

	if (p_stu_data[0].num <= 0)
	{
		printf("请录入学生成绩后操作！\n");
		return;
	}
	temp.pstu_name = (char *)malloc(MAX_LEN * sizeof(char));
	if (temp.pstu_name == NULL)
	{
		printf("Memory allocation failed for temp.pstu_name.\n");
		exit(0);
	}
	temp.pstu_score = (float *)malloc(sys_info.course_num * sizeof(float));
	if (temp.pstu_score == NULL)
	{
		printf("Memory allocation failed for temp.pstu_score[%d].\n", i);
		exit(0);
	}
	for (i = 0; i < sys_info.stu_num; i++)
	{
		for (j = i + 1; j < sys_info.stu_num; j++)
		{
			if (p_stu_data[i].stu_sum < p_stu_data[j].stu_sum)
			{
				temp = p_stu_data[i];
				p_stu_data[i] = p_stu_data[j];
				p_stu_data[j] = temp;
			}
		}
	}
}

void ScoreSortLow(STU *p_stu_data, SYS sys_info) //		按总分排序_升序
{
	int i = 0, j = 0;
	STU temp = {0};

	if (p_stu_data[0].num <= 0)
	{
		printf("请录入学生成绩后操作！");
		return;
	}
	temp.pstu_name = (char *)malloc(MAX_LEN * sizeof(char));
	if (temp.pstu_name == NULL)
	{
		printf("Memory allocation failed for temp.pstu_name.\n");
		exit(0);
	}
	temp.pstu_score = (float *)malloc(sys_info.course_num * sizeof(float));
	if (temp.pstu_score == NULL)
	{
		printf("Memory allocation failed for temp.pstu_score[%d].\n", i);
		exit(0);
	}
	for (i = 0; i < sys_info.stu_num; i++)
	{
		for (j = i + 1; j < sys_info.stu_num; j++)
		{
			if (p_stu_data[i].stu_sum > p_stu_data[j].stu_sum)
			{
				temp = p_stu_data[i];
				p_stu_data[i] = p_stu_data[j];
				p_stu_data[j] = temp;
			}
		}
	}
	ShowScore(p_stu_data, sys_info);
}

void NumSort(STU *p_stu_data, SYS sys_info) //		按学号排序
{
	int i = 0, j = 0;
	STU temp = {0};

	if (p_stu_data[0].num <= 0)
	{
		printf("请录入学生成绩后操作！");
		return;
	}
	temp.pstu_name = (char *)malloc(MAX_LEN * sizeof(char));
	if (temp.pstu_name == NULL)
	{
		printf("Memory allocation failed for temp.pstu_name.\n");
		exit(0);
	}
	temp.pstu_score = (float *)malloc(sys_info.course_num * sizeof(float));
	if (temp.pstu_score == NULL)
	{
		printf("Memory allocation failed for temp.pstu_score[%d].\n", i);
		exit(0);
	}
	for (i = 0; i < sys_info.stu_num; i++)
	{
		for (j = i + 1; j < sys_info.stu_num; j++)
		{
			if (p_stu_data[i].num > p_stu_data[j].num)
			{
				temp = p_stu_data[i];
				p_stu_data[i] = p_stu_data[j];
				p_stu_data[j] = temp;
			}
		}
	}
	ShowScore(p_stu_data, sys_info);
}

void DictSort(STU *p_stu_data, SYS sys_info) //		按字典排序
{
	int i = 0, j = 0;
	STU temp = {0};

	if (p_stu_data[0].num <= 0)
	{
		printf("请录入学生成绩后操作！");
		return;
	}
	temp.pstu_name = (char *)malloc(MAX_LEN * sizeof(char));
	if (temp.pstu_name == NULL)
	{
		printf("Memory allocation failed for temp.pstu_name.\n");
		exit(0);
	}
	temp.pstu_score = (float *)malloc(sys_info.course_num * sizeof(float));
	if (temp.pstu_score == NULL)
	{
		printf("Memory allocation failed for temp.pstu_score[%d].\n", i);
		exit(0);
	}
	for (i = 0; i < sys_info.stu_num; i++)
	{
		for (j = i + 1; j < sys_info.stu_num; j++)
		{
			if (strcmp(p_stu_data[i].pstu_name, p_stu_data[j].pstu_name) > 0)
			{
				temp = p_stu_data[i];
				p_stu_data[i] = p_stu_data[j];
				p_stu_data[j] = temp;
			}
		}
	}
	ShowScore(p_stu_data, sys_info);
}

void SearchNum(STU *p_stu_data, SYS sys_info) //		学号查询学生成绩
{
	int i = 0, j = 0;
	int a = 0;

	if (p_stu_data[0].num <= 0)
	{
		printf("请录入学生成绩后操作！");
		return;
	}

	printf("请输入学生学号： ");
	if (scanf("%d", &a))
		;
	ScoreSortHigh(p_stu_data, sys_info);
	for (i = 0; i < sys_info.stu_num; i++)
	{
		if (p_stu_data[i].num == a)
		{
			printf("%-20s%-20s", "学号", "姓名");
			for (j = 0; j < sys_info.course_num; j++)
			{
				printf("%-20s", sys_info.pcourse_name[j]);
			}
			printf("%-20s%-20s\n", "总分", "排名");
			printf("%-18d%-20s", p_stu_data[i].num, p_stu_data[i].pstu_name);
			for (j = 0; j < sys_info.course_num; j++)
			{
				printf("%-18.1f", p_stu_data[i].pstu_score[j]);
			}
			printf("%-18.1f%d\n", p_stu_data[i].stu_sum, i + 1);
			return;
		}
	}
	printf("未找到该学生！\n");
}

void SearchName(STU *p_stu_data, SYS sys_info) //		名字查询学生成绩
{
	int i = 0, j = 0;
	char *a = (char *)malloc(MAX_LEN * sizeof(char));

	if (p_stu_data[0].num <= 0)
	{
		printf("请录入学生成绩后操作！");
		return;
	}

	if (sys_info.stu_num <= 0)
	{
		printf("请输入学生成绩后操作！\n");
		return;
	}

	printf("请输入学生姓名： ");
	if (scanf("%s", a))
		;
	ScoreSortHigh(p_stu_data, sys_info);
	for (i = 0; i < sys_info.stu_num; i++)
	{
		if (strncmp(p_stu_data[i].pstu_name, a, MAX_LEN) == 0)
		{
			printf("%-20s%-20s", "学号", "姓名");
			for (j = 0; j < sys_info.course_num; j++)
			{
				printf("%-20s", sys_info.pcourse_name[j]);
			}
			printf("%-20s%-20s\n", "总分", "排名");
			printf("%-18d%-20s", p_stu_data[i].num, p_stu_data[i].pstu_name);
			for (j = 0; j < sys_info.course_num; j++)
			{
				printf("%-18.1f", p_stu_data[i].pstu_score[j]);
			}
			printf("%-18.1f%d\n", p_stu_data[i].stu_sum, i + 1);
			free(a);
			return;
		}
	}
	printf("未找到该学生！\n");
	free(a);
	return;
}

void Reset()
{
	printf("请输入录入课程数：");
	if (scanf("%d", &sys_info.course_num))
		;
	printf("请输入学生人数：");
	if (scanf("%d", &sys_info.stu_num))
		;
	allocDataSpace();
	printf("设置成功！\n");
}

// 动态分配内存
void allocDataSpace() 
{
	int i;

	p_stu_data = (STU *)malloc(sys_info.stu_num * sizeof(STU));
	if (p_stu_data == NULL) {
		printf("Memory allocation failed for p_stu_data.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < sys_info.stu_num; i++) {
		p_stu_data[i].pstu_name = (char *)malloc(MAX_LEN * sizeof(char));
		p_stu_data[i].pstu_score = (float *)malloc(sys_info.course_num * sizeof(float));
		
		if (p_stu_data[i].pstu_name == NULL || p_stu_data[i].pstu_score == NULL) {
			printf("Memory allocation failed for p_stu_data[%d].\n", i);
			freeDataSpace(); // 防止内存泄漏
			exit(EXIT_FAILURE);
		}
	}

	sys_info.course_sum = (float *)malloc(sys_info.course_num * sizeof(float));
	sys_info.pcourse_name = (char **)malloc(sys_info.course_num * sizeof(char *));
	if (sys_info.course_sum == NULL || sys_info.pcourse_name == NULL) {
		printf("Memory allocation failed for system arrays.\n");
		freeDataSpace();
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < sys_info.course_num; i++) {
		sys_info.pcourse_name[i] = (char *)malloc(MAX_LEN * sizeof(char));
		if (sys_info.pcourse_name[i] == NULL) {
			printf("Memory allocation failed for sys_info.pcourse_name[%d].\n", i);
			freeDataSpace();
			exit(EXIT_FAILURE);
		}
	}
}

void freeDataSpace() 
{
	int i;

	for (i = 0; i < sys_info.stu_num; i++) {
		free(p_stu_data[i].pstu_name);
		free(p_stu_data[i].pstu_score);
	}
	free(p_stu_data);

	for (i = 0; i < sys_info.course_num; i++) {
		free(sys_info.pcourse_name[i]);
	}
	free(sys_info.pcourse_name);
	free(sys_info.course_sum);
}

void InputScore(STU *p_stu_data, SYS sys_info) 
{
	int i, j;

	printf("开始录入课程信息\n");
	for (i = 0; i < sys_info.course_num; i++) {
		printf("第%i门科目： ", i + 1);
		scanf("%s", sys_info.pcourse_name[i]);
	}

	printf("开始录入学生成绩\n");
	for (i = 0; i < sys_info.stu_num; i++) {
		printf("请输入学生学号<第%d位学生>(学号为正整数) :  ", i + 1);
		scanf("%d", &p_stu_data[i].num);
		printf("请输入学生姓名:  ");
		scanf("%s", p_stu_data[i].pstu_name);
		printf("请输入各科目成绩\n");
		for (j = 0; j < sys_info.course_num; j++) {
			printf("%s: ", sys_info.pcourse_name[j]);
			scanf("%f", &p_stu_data[i].pstu_score[j]);
		}
	}
	Sum(p_stu_data, sys_info);
}

void Sum(STU *p_stu_data, SYS sys_info) 
{
	int i, j;

	for (i = 0; i < sys_info.course_num; i++) {
		sys_info.course_sum[i] = 0;
		for (j = 0; j < sys_info.stu_num; j++) {
			sys_info.course_sum[i] += p_stu_data[j].pstu_score[i];
		}
	}

	for (i = 0; i < sys_info.stu_num; i++) {
		p_stu_data[i].stu_sum = 0;
		for (j = 0; j < sys_info.course_num; j++) {
			p_stu_data[i].stu_sum += p_stu_data[i].pstu_score[j];
		}
		p_stu_data[i].stu_average = p_stu_data[i].stu_sum / sys_info.course_num;
	}
}

void Statistic(STU *p_stu_data, SYS sys_info) 
{
	int **Count;
	int i, j;

	if (p_stu_data[0].num <= 0) {
		printf("请录入学生成绩后操作！\n");
		return;
	}

	Count = (int **)malloc(sys_info.course_num * sizeof(int *));
	if (Count == NULL) {
		printf("Memory allocation failed for Count.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < sys_info.course_num; i++) {
		Count[i] = (int *)calloc(5, sizeof(int)); //使用 calloc 清零
		if (Count[i] == NULL) {
			printf("Memory allocation failed for Count[%d].\n", i);
			free(Count);
			exit(EXIT_FAILURE);
		}
	}

	for (i = 0; i < sys_info.course_num; i++) {
		for (j = 0; j < sys_info.stu_num; j++) {
			if (p_stu_data[j].pstu_score[i] >= 90) {
				Count[i][4]++;
			} else if (p_stu_data[j].pstu_score[i] >= 80) {
				Count[i][3]++;
			} else if (p_stu_data[j].pstu_score[i] >= 70) {
				Count[i][2]++;
			} else if (p_stu_data[j].pstu_score[i] >= 60) {
				Count[i][1]++;
			} else {
				Count[i][0]++;
			}
		}
	}

	for (i = 0; i < sys_info.course_num; i++) {
		printf("\n%s统计\n", sys_info.pcourse_name[i]);
		for (j = 0; j < 5; j++) {
			const char *categories[] = {"不及格人数(60以下)", "及格人数(60-70)", "中等人数(70-80)", "良好人数(80-90)", "优秀人数(90以上)"}; 
			printf("%s: %d   百分比： %.2f%%\n", categories[j], Count[i][j], (float)Count[i][j] / sys_info.stu_num * 100);
		}
	}

	for (i = 0; i < sys_info.course_num; i++) {
		free(Count[i]);
	}
	free(Count);
}

void ShowScore(STU *p_stu_data, SYS sys_info) 
{
	int i, j;

	if (p_stu_data == NULL || p_stu_data[0].num <= 0) {
		printf("请录入学生成绩后操作！\n");
		return;
	}

	printf("%-8s%-20s", "学号", "姓名");
	for (i = 0; i < sys_info.course_num; i++) {
		printf("%-20s", sys_info.pcourse_name[i]);
	}
	printf("%-8s\n", "总分");

	for (i = 0; i < sys_info.stu_num; i++) {
		if (p_stu_data[i].pstu_name == NULL || p_stu_data[i].pstu_score == NULL) {
			printf("学生信息未初始化！\n");
			continue;
		}

		printf("%-6d%-20s", p_stu_data[i].num, p_stu_data[i].pstu_name);
		for (j = 0; j < sys_info.course_num; j++) {
			printf("%-18.1f", p_stu_data[i].pstu_score[j]);
		}
		printf("%-8.1f\n", p_stu_data[i].stu_sum);
	}
}
void WriteStudentInfoToFile(const char *studentFileName, const char *systemFileName) 
{
    FILE *p1 = fopen(studentFileName, "wb");
    FILE *p2 = fopen(systemFileName, "wb");
    if (p1 == NULL || p2 == NULL) {
        printf("文件打开失败！\n");
        if (p1) fclose(p1);
        if (p2) fclose(p2);
        return;
    }

    // 写入学生信息
    for (int i = 0; i < sys_info.stu_num; i++) {
        // 写入学生学号
        fwrite(&p_stu_data[i].num, sizeof(int), 1, p1);
        // 写入学生姓名长度
        size_t name_len = strlen(p_stu_data[i].pstu_name) + 1;
        fwrite(&name_len, sizeof(size_t), 1, p1);
        // 写入学生姓名
        fwrite(p_stu_data[i].pstu_name, sizeof(char), name_len, p1);
        // 写入学生各科成绩
        fwrite(p_stu_data[i].pstu_score, sizeof(float), sys_info.course_num, p1);
        // 写入学生总成绩
        fwrite(&p_stu_data[i].stu_sum, sizeof(float), 1, p1);
        // 写入学生平均成绩
        fwrite(&p_stu_data[i].stu_average, sizeof(float), 1, p1);
    }

    // 写入系统信息
    fwrite(&sys_info.stu_num, sizeof(int), 1, p2);
    fwrite(&sys_info.course_num, sizeof(int), 1, p2);
    fwrite(sys_info.course_sum, sizeof(float), sys_info.course_num, p2);

    for (int i = 0; i < sys_info.course_num; i++) {
        // 写入课程名称长度
        size_t course_name_len = strlen(sys_info.pcourse_name[i]) + 1;
        fwrite(&course_name_len, sizeof(size_t), 1, p2);
        // 写入课程名称
        fwrite(sys_info.pcourse_name[i], sizeof(char), course_name_len, p2);
    }

    fclose(p1);
    fclose(p2);
    printf("写入成功！\n");
}

void ReadStudentInfoFromFile(const char *studentFileName, const char *systemFileName) 
{
    FILE *p1 = fopen(systemFileName, "rb");
    FILE *p2 = fopen(studentFileName, "rb");
    if (p1 == NULL || p2 == NULL) {
        printf("文件打开失败！\n");
        if (p1) fclose(p1);
        if (p2) fclose(p2);
        return;
    }

    // 读取系统信息
    fread(&sys_info.stu_num, sizeof(int), 1, p1);
    fread(&sys_info.course_num, sizeof(int), 1, p1);

    int i;

    p_stu_data = (STU *)malloc(sys_info.stu_num * sizeof(STU));

    for (i = 0; i < sys_info.stu_num; i++) {
        p_stu_data[i].pstu_name = (char *)malloc(MAX_LEN * sizeof(char));
        p_stu_data[i].pstu_score = (float *)malloc(sys_info.course_num * sizeof(float));
        
        if (p_stu_data[i].pstu_name == NULL || p_stu_data[i].pstu_score == NULL) {
            printf("Memory allocation failed for p_stu_data[%d].\n", i);
            freeDataSpace(); // 防止内存泄漏
            exit(EXIT_FAILURE);
        }
    }

    sys_info.course_sum = (float *)malloc(sys_info.course_num * sizeof(float));
    sys_info.pcourse_name = (char **)malloc(sys_info.course_num * sizeof(char *));
    if (sys_info.course_sum == NULL || sys_info.pcourse_name == NULL) {
        printf("Memory allocation failed for system arrays.\n");
        freeDataSpace();
        exit(EXIT_FAILURE);
    }
    
    for (i = 0; i < sys_info.course_num; i++) {
        sys_info.pcourse_name[i] = (char *)malloc(MAX_LEN * sizeof(char));
        if (sys_info.pcourse_name[i] == NULL) {
            printf("Memory allocation failed for sys_info.pcourse_name[%d].\n", i);
            freeDataSpace();
            exit(EXIT_FAILURE);
        }
    }

    fread(sys_info.course_sum, sizeof(float), sys_info.course_num, p1);

    for (int i = 0; i < sys_info.course_num; i++) {
        size_t course_name_len;
        fread(&course_name_len, sizeof(size_t), 1, p1);
        fread(sys_info.pcourse_name[i], sizeof(char), course_name_len, p1);
    }

    // 读取学生信息
    for (int i = 0; i < sys_info.stu_num; i++) {
        // 读取学生学号
        fread(&p_stu_data[i].num, sizeof(int), 1, p2);
        // 读取学生姓名长度
        size_t name_len;
        fread(&name_len, sizeof(size_t), 1, p2);
        // 读取学生姓名
        fread(p_stu_data[i].pstu_name, sizeof(char), name_len, p2);
        // 读取学生各科成绩
        fread(p_stu_data[i].pstu_score, sizeof(float), sys_info.course_num, p2);
        // 读取学生总成绩
        fread(&p_stu_data[i].stu_sum, sizeof(float), 1, p2);
        // 读取学生平均成绩
        fread(&p_stu_data[i].stu_average, sizeof(float), 1, p2);
    }

    fclose(p1);
    fclose(p2);

    printf("读取成功！学生信息如下：\n");
    for (int i = 0; i < sys_info.stu_num; i++) {
        printf("学号: %d, 姓名: %s\n", p_stu_data[i].num, p_stu_data[i].pstu_name);
    }
}