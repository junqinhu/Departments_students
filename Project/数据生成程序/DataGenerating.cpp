/**
DataGenerating���������������
	�����з���toGenerate()��������������˽���ӷ������ɶ�������
	��˽�з���createStudents(int a)����������ѧ������
	��˽�з���createDepartments(int a)���������ɲ�������
���˽�б�������˵�����ͷ�ļ�"DataGenerating.h"
˵��������ע���г��ֵġ����ơ�����˼�ǡ�������ҵҪ��Ĺ̶���ʽ���˸�ʽ�ǹ̶��ģ���
*/

#include "DataGenerating.h"
#include<iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <string>
#include<sstream>

using namespace std;

ofstream outfile("./input_data.txt", ios::out);    //��������ļ�������

void DataGenerating::toGenerate()
{
	int mark[1000];    //�������
	for (int i = 0; i < 1000; i++)
	{
		mark[i] = 0;
	}

	srand((unsigned)time(NULL));    //��ȡ��������ӣ�����Ҫ��
	
	//����ѧ����Ϣ����������ļ���
	if (outfile.is_open())
	{                              
		outfile << "{" << endl << "    \"students\": [" << endl;
	}                   
	else     //�ļ�δ�򿪵Ĵ�����ͬ
	{
		cout << "The file does not open!" << endl;
	}

	initDepartments();     //��ʼ��Ԥ�貿�ű��

	for (int i = 1; i < n_students; i++)
	{
		createStudents(mark);         //�����ӷ������������ɲ����ѧ������
		outfile << "," << endl;
	}
	createStudents(mark);
	

	//���Ʋ�����Ϣ����������ļ���
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
		createDepartments(i);         //�����ӷ������������ɲ������������
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


//��ʼ�����ű�ŵĺ���
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


//��������ѧ�����ݵķ���
//�õ�˽�к���initFreeTime()��initTags()��
//�ֱ�Կ���ʱ��κͱ�ǩ���г�ʼ��
void DataGenerating::createStudents(int *a)
{
	initFreeTime();     //��ʼ������ʱ���
	initTags();         //��ʼ����ǩ
	string str_no = "\"031502";  //ѧ��ѧ�ţ��������
	int temp;      //��ʱ����
	int no;     //��ʱ����
	string str;    //��ʱ����
	stringstream stream;
	int num;    //���ɵ����������ʾ����

	//�������ѧ�ţ�����stream���Խ�����ת��string�ַ���
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

	//�޶�ÿ���˵Ŀ���ʱ���������2~21��
	num = rand() % (n_freeTime - 3) + 2;
	setUsedFalse();

	if (outfile.is_open())
	{
		outfile << "        {" << endl << "            \"free_time\": [" << endl;

		for (int i = 1; i < num; i++)
		{
			//����ʱ����ظ��Ĵ�ʩ
			while (1)
			{
				no = rand() % n_freeTime;
				if (!used[no])
				{
					used[no] = true;
					break;
				}
			}
			//�����������ʱ���
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
			//�������ѧ��
			<< "            " << "\"student_no\": " << str_no << "\"," << endl
			//�������������Ը
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

		//�޶�ÿ���˵ı�ǩ������2~4��
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
			//�������ѧ����ǩ
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


//��ʼ��Ԥ�����ʱ���
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

	//����Ԥ�����ʱ���
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			freeTime[k++] = "\"" + date[i] + time[j] + "\"";
		}
	}
}


//��ʼ��Ԥ���ǩ
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


//��������������ݵķ���
//�õ�˽�к���initEventSchedules()��initTags()��
//�ֱ�Բ��Żʱ��κͱ�ǩ���г�ʼ��
void DataGenerating::createDepartments(int a)
{
	initEventSchedules();    //��ʼ�����Żʱ��
	initTags();              //��ʼ����ǩ
	int temp;      //��ʱ����
	int no;      //��ʱ����
	string str;    //��ʱ����
	stringstream stream;
	int num;    //���ɵ����������ʾ����

	//�޶����Żʱ��������2~5��
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
			//����������Żʱ��
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
			//������ɲ��ŵ��޶�������10~15���������
			<< "            " << "\"member_limit\": " << rand() % 6 + 10 << "," << endl
			//����������ű��
			<< "            " << "\"department_no\": \"" << departments[a-1] << "\"," << endl
			<< "            " << "\"tags\": [" << endl;
		//�޶����ű�ǩ������2~4��
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
			//����������ű�ǩ
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


//��ʼ��Ԥ�貿�Żʱ���
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

	//��ʼ��Ԥ�貿��ʱ���
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			eventSchedules[k++] = "\"" + date[i] + time[j] + "\"";
		}
	}
}


//����used��־�����ֵΪfalse
void DataGenerating::setUsedFalse()
{
	for (int i = 0; i < 21; i++)
	{
		used[i] = false;
	}
}
