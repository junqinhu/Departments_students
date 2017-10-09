/**
DataGenerating类包含三个方法：
	·公有方法toGenerate()：调用以下两个私有子方法生成定制数据
	·私有方法createStudents(int a)：定制生成学生数据
	·私有方法createDepartments(int a)：定制生成部门数据
相关私有变量及其说明详见头文件"DataGenerating.h"
说明：下面注释中出现的“定制”，意思是“按照作业要求的固定格式（此格式是固定的）”
*/

#include "DataGenerating.h"
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <string>
#include<sstream>

using namespace std;

ofstream outfile("./input_data.txt", ios::out);    //创建输出文件流对象

void DataGenerating::toGenerate()
{
	int mark[1000];    //标记数组
	for (int i = 0; i < 1000; i++)
	{
		mark[i] = 0;
	}

	srand((unsigned)time(NULL));    //获取随机数种子，下面要用
	
	//定制学生信息，并输出到文件上
	if (outfile.is_open())
	{                              
		outfile << "{" << endl << "    \"students\": [" << endl;
	}                   
	else     //文件未打开的处理，下同
	{
		cout << "The file does not open!" << endl;
	}

	initDepartments();     //初始化预设部门编号

	for (int i = 1; i < n_students; i++)
	{
		createStudents(mark);         //调用子方法，定制生成并输出学生数据
		outfile << "," << endl;
	}
	createStudents(mark);
	

	//定制部门信息，并输出到文件上
	if (outfile.is_open())
	{
		outfile << endl << "    ]," << endl << "    \"departments\": [" << endl;
	}
	else
	{
		cout << "The file does not open!" << endl;
	}

	for (int i = 1; i < n_departments; i++)
	{
		createDepartments(i);         //调用子方法，定制生成并输出部门数据
		outfile << "," << endl;
	}
	createDepartments(n_departments);

	if (outfile.is_open())
	{
		outfile << endl << "    ]" << endl << "}" << endl;
	}
	else
	{
		cout << "The file does not open!" << endl;
	}

	outfile.close();
}


//初始化部门编号的函数
void DataGenerating::initDepartments()
{
	departments[0] = "D001";
	departments[1] = "D002";
	departments[2] = "D003";
	departments[3] = "D004";
	departments[4] = "D005";
	departments[5] = "D006";
	departments[6] = "D007";
	departments[7] = "D008";
	departments[8] = "D009";
	departments[9] = "D010";
	departments[10] = "D011";
	departments[11] = "D012";
	departments[12] = "D013";
	departments[13] = "D014";
	departments[14] = "D015";
	departments[15] = "D016";
	departments[16] = "D017";
	departments[17] = "D018";
	departments[18] = "D019";
	departments[19] = "D020";
}


//定制生成学生数据的方法
//用到私有函数initFreeTime()和initTags()，
//分别对空闲时间段和标签进行初始化
void DataGenerating::createStudents(int *a)
{
	initFreeTime();     //初始化空闲时间段
	initTags();         //初始化标签
	string str_no = "\"031502";  //学生学号，随机产生
	int temp;      //临时变量
	int no;     //临时变量
	string str;    //临时变量
	stringstream stream;
	int num;    //生成的随机数，表示数量

	//随机生成学号，变量stream用以将数字转成string字符串
	while (1)
	{
		temp = rand() % 800 + 100;
		if (a[temp] == 0)
		{
			a[temp] = 1;
			break;
		}
	}
	stream.clear();
	stream << temp;
	stream >> str;
	str_no += str;

	//限定每个人的空闲时间段数量在2~21个
	num = rand() % (n_freeTime - 3) + 2;
	setUsedFalse();

	if (outfile.is_open())
	{
		outfile << "        {" << endl << "            \"free_time\": [" << endl;

		for (int i = 1; i < num; i++)
		{
			//避免时间段重复的措施
			while (1)
			{
				no = rand() % n_freeTime;
				if (!used[no])
				{
					used[no] = true;
					break;
				}
			}
			//定制输出空闲时间段
			outfile << "                " << freeTime[no]<<"," << endl;
		}
		while (1)
		{
			no = rand() % n_freeTime;
			if (!used[no])
			{
				used[no] = true;
				break;
			}
		}
		outfile << "                " << freeTime[no] << endl 
			<< "            " << "]," << endl
			//定制输出学号
			<< "            " << "\"student_no\": " << str_no << "\"," << endl
			//定制输出部门意愿
			<< "            " << "\"applications_department\": [" << endl;

		num = rand() % 5+1;
		setUsedFalse();

		for (int i = 1; i < num; i++)
		{
			while (1)
			{
				no = rand() % 20;
				if (!used[no])
				{
					used[no] = true;
					break;
				}
			}
			
			outfile << "                \"" << departments[no] << "\"," << endl;
		}
		while (1)
		{
			no = rand() % 20;
			if (!used[no])
			{
				used[no] = true;
				break;
			}
		}
		outfile << "                \"" << departments[no] << "\"" << endl
			    << "            ]," << endl 
			    << "            " << "\"tags\": [" << endl;

		//限定每个人的标签数量在2~4个
		num = rand()%3+2;
		setUsedFalse();
		for (int i = 1;i<num; i++)
		{
			while (1)
			{
				no = rand() % 21;
				if (!used[no])
				{
					used[no] = true;
					break;
				}
			}
			//定制输出学生标签
			outfile << "                \"" << tags[no] << "\"," << endl;
		}
		while (1)
		{
			no = rand() % 21;
			if (!used[no])
			{
				used[no] = true;
				break;
			}
		}
		outfile << "                \"" << tags[no] << "\"" << endl
			<< "            ]" << endl << "        }";
	}
	
	else
	{
		cout << "The file does not open!" << endl;
	}
}


//初始化预设空闲时间段
void DataGenerating::initFreeTime()
{
	string date[7] =
	{
		"Sun.","Mon.","Tues.","Wed.","Thur.","Fri.","Sat."
	};
	string time[3] =
	{
		"10:00~12:00","16:00~18:00","20:00~22:00"
	};

	int k = 0;

	//生成预设空闲时间段
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			freeTime[k++] = "\"" + date[i] + time[j] + "\"";
		}
	}
}


//初始化预设标签
void DataGenerating::initTags()
{
	tags[0] = "basketball";
	tags[1] = "chess";
	tags[2] = "dancing";
	tags[3] = "English";
	tags[4] = "film";
	tags[5] = "football";
	tags[6] = "singing";
	tags[7] = "Math";
	tags[8] = "music";
	tags[9] = "running";
	tags[10] = "computer";
	tags[11] = "programing";
	tags[12] = "painting";
	tags[13] = "performing";
	tags[14] = "study";
	tags[15] = "Japanese";
	tags[16] = "sports";
	tags[17] = "handwriting";
	tags[18] = "handsome";
	tags[19] = "beautiful";
	tags[20] = "writing";
}


//定制输出部门数据的方法
//用到私有函数initEventSchedules()和initTags()，
//分别对部门活动时间段和标签进行初始化
void DataGenerating::createDepartments(int a)
{
	initEventSchedules();    //初始化部门活动时间
	initTags();              //初始化标签
	int temp;      //临时变量
	int no;      //临时变量
	string str;    //临时变量
	stringstream stream;
	int num;    //生成的随机数，表示数量

	//限定部门活动时间数量在2~5个
	num = rand() % 4 + 2;

	if (outfile.is_open())
	{
		outfile << "        {" << endl << "            \"event_schedules\": [" << endl;
		setUsedFalse();
		for (int i = 1; i < num; i++)
		{
			while (1)
			{
				no = rand() % n_EventSchedules;
				if (!used[no])
				{
					used[no] = true;
					break;
				}
			}
			//定制输出部门活动时间
			outfile << "                " << eventSchedules[no] << "," << endl;
		}
		while (1)
		{
			no = rand() % n_EventSchedules;
			if (!used[no])
			{
				used[no] = true;
				break;
			}
		}
		outfile << "                " << eventSchedules[no] << endl
			<< "            " << "]," << endl
			//随机生成部门的限定人数（10~15个）并输出
			<< "            " << "\"member_limit\": " << rand() % 6 + 10 << "," << endl
			//定制输出部门编号
			<< "            " << "\"department_no\": \"" << departments[a-1] << "\"," << endl
			<< "            " << "\"tags\": [" << endl;
		//限定部门标签数量在2~4个
		num = rand() % 3 + 2;
		setUsedFalse();
		for (int i = 1; i<num; i++)
		{
			while (1)
			{
				no = rand() % 21;
				if (!used[no])
				{
					used[no] = true;
					break;
				}
			}
			//定制输出部门标签
			outfile << "                \"" << tags[no] << "\"," << endl;
		}
		while (1)
		{
			no = rand() % 21;
			if (!used[no])
			{
				used[no] = true;
				break;
			}
		}
		outfile << "                \"" << tags[no] << "\"" << endl
			<< "            ]" << endl << "        }";
	}

	else
	{
		cout << "The file does not open!" << endl;
	}
}


//初始化预设部门活动时间段
void DataGenerating::initEventSchedules()
{
	string date[7] =
	{
		"Sun.","Mon.","Tues.","Wed.","Thur.","Fri.","Sat."
	};
	string time[3] =
	{
		"10:30~11:30","16:30~18:00","20:00~21:30"
	};

	int k = 0;

	//初始化预设部门时间段
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			eventSchedules[k++] = "\"" + date[i] + time[j] + "\"";
		}
	}
}


//设置used标志数组的值为false
void DataGenerating::setUsedFalse()
{
	for (int i = 0; i < 21; i++)
	{
		used[i] = false;
	}
}
