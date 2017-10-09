// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

struct student {
	vector<pair<int, int> >freeTime[10];//��ѧ���Ŀ���ʱ��
	vector<string>applicationsDepartment;//��ʾѧ���Ĳ���־Ը
	vector<string>tags;//��ʾѧ������Ȥ��ǩ
	string no;//ѧ��
	int now;//�Ѿ�����Ĳ�������
}students[310];

map<string, int>studentNoToInt;//ѧ�Ŷ�Ӧ�����±�

struct department {
	vector<pair<int, int> >eventSchedules[10];//�沿�ŵĻʱ��
	int limit;//��ʾ������������
	int now;//��ʾ������������
	vector<string>tags;//��ʾ���ű�ǩ
	string no;//��ʾ���ű��
}departments[30];

int departmentSize = 0;//������
int studentSize = 0;//ѧ����

bool studentTime[400][10][3000];//ѧ������ʱ��

								//�ѧ���Ŀ���ʱ��
void getStudentFreeTime()
{
	string str;
	while (cin >> str)
	{
		if (str[0] == ']')
		{
			return;
		}

		int dayCheck;
		//�ж������ڼ�
		if (str.find("Mon.") != -1)
		{
			dayCheck = 1;
		}
		if (str.find("Tues.") != -1)
		{
			dayCheck = 2;
		}
		if (str.find("Wed.") != -1)
		{
			dayCheck = 3;
		}
		if (str.find("Thur.") != -1)
		{
			dayCheck = 4;
		}
		if (str.find("Fri.") != -1)
		{
			dayCheck = 5;
		}
		if (str.find("Sat.") != -1)
		{
			dayCheck = 6;
		}
		if (str.find("Sun.") != -1)
		{
			dayCheck = 7;
		}
		int strSize = str.size();
		int pos;
		int left, right;
		for (int i = 0; i < strSize - 1; i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				pos = i;
				break;
			}
		}
		int hour, minute;
		hour = minute = 0;
		for (int i = pos; i < strSize - 1; i++)
		{
			if (str[i] == ':')
			{
				pos = i;
				break;
			}
			hour = hour * 10 + str[i] - '0';
		}
		for (int i = pos + 1; i < strSize - 1; i++)
		{
			if (str[i] == '~')
			{
				pos = i;
				break;
			}
			minute = minute * 10 + str[i] - '0';
		}
		left = hour * 60 + minute;
		hour = minute = 0;
		for (int i = pos + 1; i < strSize - 1; i++)
		{
			if (str[i] == ':')
			{
				pos = i;
				break;
			}
			hour = hour * 10 + str[i] - '0';
		}
		for (int i = pos + 1; i < strSize - 1; i++)
		{
			if (str[i] == '\"')
			{
				break;
			}
			minute = minute * 10 + str[i] - '0';
		}
		right = hour * 60 + minute;
		students[studentSize].freeTime[dayCheck].push_back(make_pair(left, right));
	}
}

//���ѧ����־Ը
void getApplicationsDepartment()
{
	string str;
	int pos = 0;
	while (cin >> str)
	{
		if (str[0] == ']')
		{
			return;
		}
		for (int i = str.size() - 1; i; i--)
		{
			if (str[i] == '\"')
			{
				pos = i;
				break;
			}
		}
		string temp = "";
		for (int i = 1; i < pos; i++)
		{
			temp += str[i];
		}
		students[studentSize].applicationsDepartment.push_back(temp);
	}
}

//���ѧ����Ȥ��ǩ
void getStudentTags()
{
	string str;
	int pos = 0;
	while (cin >> str)
	{
		if (str[0] == ']')
		{
			return;
		}
		for (int i = str.size() - 1; i; i--)
		{
			if (str[i] == '\"')
			{
				pos = i;
				break;
			}
		}
		string temp = "";
		for (int i = 1; i < pos; i++)
		{
			temp += str[i];
		}
		students[studentSize].tags.push_back(temp);
	}
}


//��ò��Żʱ��
void getDepartmentFreeTime()
{
	string str;
	while (cin >> str)
	{
		if (str[0] == ']')
			return;
		//cout<<s<<endl;
		int dayCheck;
		//�ж������ڼ�
		if (str.find("Mon.") != -1)
		{
			dayCheck = 1;
		}
		if (str.find("Tues.") != -1)
		{
			dayCheck = 2;
		}
		if (str.find("Wed.") != -1)
		{
			dayCheck = 3;
		}
		if (str.find("Thur.") != -1)
		{
			dayCheck = 4;
		}
		if (str.find("Fri.") != -1)
		{
			dayCheck = 5;
		}
		if (str.find("Sat.") != -1)
		{
			dayCheck = 6;
		}
		if (str.find("Sun.") != -1)
		{
			dayCheck = 7;
		}
		int strSize = str.size();
		int pos;
		int left, right;
		for (int i = 0; i < strSize - 1; i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				pos = i;
				break;
			}
		}
		int hour, minute;
		hour = minute = 0;
		for (int i = pos; i < strSize - 1; i++)
		{
			if (str[i] == ':')
			{
				pos = i;
				break;
			}
			hour = hour * 10 + str[i] - '0';
		}
		for (int i = pos + 1; i < strSize - 1; i++)
		{
			if (str[i] == '~')
			{
				pos = i;
				break;
			}
			minute = minute * 10 + str[i] - '0';
		}
		left = hour * 60 + minute;
		hour = minute = 0;
		for (int i = pos + 1; i < strSize - 1; i++)
		{
			if (str[i] == ':')
			{
				pos = i;
				break;
			}
			hour = hour * 10 + str[i] - '0';
		}
		for (int i = pos + 1; i < strSize - 1; i++)
		{
			if (str[i] == '\"')
			{
				break;
			}
			minute = minute * 10 + str[i] - '0';
		}
		right = hour * 60 + minute;
		departments[departmentSize].eventSchedules[dayCheck].push_back(make_pair(left, right));
	}
}

//��ò��ű�ǩ
void getDepartmentTags()
{
	string s;
	int pos = 0;
	while (cin >> s)
	{
		if (s[0] == ']') return;
		for (int i = s.size() - 1; i; i--)
		{
			if (s[i] == '\"')
			{
				pos = i; break;
			}
		}
		string temp = "";
		for (int i = 1; i < pos; i++) temp += s[i];
		departments[departmentSize].tags.push_back(temp);
	}
}


//��ʼ��ѧ��ʱ�䣬�����жϳ�ͻ
void initTime()
{
	for (int i = 1; i <= studentSize; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			int sz = students[i].freeTime[j].size();
			for (int k = 0; k < sz; k++)
			{
				int l = students[i].freeTime[j][k].first;
				int r = students[i].freeTime[j][k].second;
				for (int tt = l; tt <= r; tt++)
					studentTime[i][j][tt] = 1;
			}
		}
	}
}

void init()
{
	freopen("input_data.txt", "r", stdin);
	freopen("output_data.txt", "w", stdout);
	string str;
	getchar();
	cin >> str;
	cin >> str;
	while (cin >> str)
	{
		if (str[1] == 'd'&&str[2] == 'e'&&str[3] == 'p'&&str[4] == 'a'
			&&str[5] == 'r'&&str[6] == 't'&&str[7] == 'm'&&str[8] == 'e'
			&&str[9] == 'n'&&str[10] == 't'&&str[11] == 's')
		{
			break;
		}
		if (str[0] == ']')
		{
			continue;
		}
		if (str[0] == '{')
		{
			studentSize++;
			students[studentSize].now = 0;
			continue;
		}
		if (str.find("free_time") != -1)
		{
			cin >> str;
			getStudentFreeTime();
		}
		cin >> str;
		cin >> str;
		int pos = 0;
		for (int i = str.size() - 1; i; i--)
		{
			if (str[i] == '\"')
			{
				pos = i; break;
			}
		}
		
		string tempNo = "";
		for (int i = 1; i < pos; i++)
		{
			tempNo += str[i];
		}
		studentNoToInt[tempNo] = studentSize;
		students[studentSize].no = tempNo;
		
		cin >> str;
		cin >> str;
		getApplicationsDepartment();
		cin >> str;
		cin >> str;
		getStudentTags();
		
		cin >> str;
	}
	
	cin >> str;
	while (cin >> str)
	{
		if (str[0] == ']')
		{
			cin >> str;
		}
		if (str[0] == '}')
		{
			break;
		}
		if (str[0] == '{')
		{
			departmentSize++;
			departments[departmentSize].now = 0;
			continue;
		}
		cin >> str;
		getDepartmentFreeTime();
		cin >> str;
		cin >> str;
		int sz = str.size();
		int num = 0;
		for (int i = 0; i < sz - 1; i++)
		{
			num = num * 10 + (str[i] - '0');
		}
		departments[departmentSize].limit = num;
		cin >> str;
		cin >> str;
		int pos = 0;
		for (int i = str.size() - 1; i; i--)
		{
			if (str[i] == '\"')
			{
				pos = i;
				break;
			}
		}
		
		string tempNo = "";
		for (int i = 1; i < pos; i++)
		{
			tempNo += str[i];
		}
		departments[departmentSize].no = tempNo;
		
		cin >> str;
		cin >> str;
		getDepartmentTags();
		cin >> str;
	}
}

//�жϲ���dep��ѧ��stu�Ƿ���ʱ����ƥ�䣬��ƥ�䣬�ж�ƥ��̶�
pair<double, bool> timeMatch(int dep, int stu)
{
	double totalDepartment = 0.0;
	double totalStudent = 0.0;
	for (int i = 1; i <= 7; i++)
	{
		int timeSize = departments[dep].eventSchedules[i].size();
		int studentTimeSize = students[stu].freeTime[i].size();
		for (int j = 0; j < timeSize; j++)
		{
			int l = departments[dep].eventSchedules[i][j].first;
			int r = departments[dep].eventSchedules[i][j].second;
			
			totalDepartment += 1.0;
			double temp = 0;
			for (int k = l; k <= r; k++)
			{
				if (studentTime[stu][i][k])
				{
					temp += 1.0;
				}
			}
			if (temp > 0.8*(r - l))
			{
				totalStudent += 1.0;
			}
		}
	}
	bool flag = 1;
	if (totalStudent < 0.5*totalDepartment)
	{
		flag = 0;
	}
	
	return make_pair(1.0*totalStudent / totalDepartment, flag);
}

set<string>studentSet;  //û��ѡ�е�ѧ������
set<int>departmentSet;     //û��ѡ�еĲ��ż���
vector<string>DepartmentStudent[30];//DepartmentStudent[i]�沿��iѡ���ѧ��

									//ѧ����ʱ�ṹ�壬��������
struct temp_student {
	int rank;	//�ڼ�־Ը���������
	string no;  //ѧ��
	int match;	//��Ȥƥ����
	double timeMatch;//ʱ��ƥ��̶�
	int now;	//���벿����
}tempStudent[310];

//sort��cmp����
bool cmp(temp_student a, temp_student b)
{
	if (a.rank == b.rank)
	{
		if (a.timeMatch == b.timeMatch)
		{
			if (a.match == b.match)
			{
				if (a.now == b.now) return a.no < b.no;
				return a.now < b.now;
			}
			return a.match > b.match;
		}
		return a.timeMatch > b.timeMatch;
	}
	return a.rank > b.rank;
}

//ѧ��st���벿��de���޸ĸ�ѧ���Ŀ���ʱ��
void changeTime(int st, int de)
{
	for (int i = 1; i <= 7; i++)
	{
		int timesz = departments[de].eventSchedules[i].size();
		for (int j = 0; j < timesz; j++)
		{
			int ld = departments[de].eventSchedules[i][j].first;
			int rd = departments[de].eventSchedules[i][j].second;
			for (int k = ld; k <= rd; k++)
				studentTime[st][i][k] = 0;
		}
	}
}

//min,ȡ�������н�С����
int min(int a, int b)
{
	if (a > b) return b;
	return a;
}

//ƥ����̺���
void work()
{
	for (int i = 1; i <= studentSize; i++)
		studentSet.insert(students[i].no);
	for (int i = 1; i <= departmentSize; i++)
		departmentSet.insert(i);
	for (int k = 1; k <= 5; k++)
	{
		for (int i = 1; i <= departmentSize; i++)
		{
			int tempsz = 0;
			if (departments[i].now == departments[i].limit)
				continue;
			int deptagsz = departments[i].tags.size();
			for (int j = 1; j <= studentSize; j++)
			{
				if (students[j].now == 5)
					continue;
				int up = min(k, students[j].applicationsDepartment.size());
				int ra = -1;
				for (int f = 0; f < up; f++)
				{
					if (students[j].applicationsDepartment[f] == departments[i].no)
					{
						ra = f + 1;
						break;
					}
				}
				if (ra == -1)
					continue;
				int sz = DepartmentStudent[i].size();
				bool flag = 0;
				for (int ss = 0; ss < sz; ss++)
				{
					if (DepartmentStudent[i][ss] == students[j].no)
					{
						flag = 1;
						break;
					}
				}
				if (flag)
					continue;
				pair<double, bool>tt = timeMatch(i, j);
				if (!tt.second)
					continue;
				int match = 0;
				int stutagsz = students[j].tags.size();
				for (int tagforstu = 0; tagforstu < stutagsz; tagforstu++)
				{
					for (int tagfordep = 0; tagfordep < deptagsz; tagfordep++)
					{
						if (students[j].tags[tagforstu] == departments[i].tags[tagfordep])
						{
							match++;
							break;
						}
					}
				}
				tempStudent[++tempsz].no = students[j].no;
				tempStudent[tempsz].now = students[j].now;
				tempStudent[tempsz].match = match;
				tempStudent[tempsz].timeMatch = tt.first;
				tempStudent[tempsz].rank = ra;
			}
			sort(tempStudent + 1, tempStudent + 1 + tempsz, cmp);
			int delta = departments[i].limit - departments[i].now;
			delta = min(delta, tempsz);
			for (int temps = 1; temps <= delta; temps++)
			{
				if (departmentSet.count(i))
				{
					departmentSet.erase(i);
				}
				if (studentSet.count(tempStudent[temps].no))
				{
					studentSet.erase(tempStudent[temps].no);
				}
				DepartmentStudent[i].push_back(tempStudent[temps].no);
				departments[i].now++;
				students[studentNoToInt[tempStudent[temps].no]].now++;
				changeTime(studentNoToInt[tempStudent[temps].no], i);
			}
		}
	}
}

//�������
void myPrint()
{
	puts("{");
	puts("    \"unlucky_student\": [");
	int stusetsz = studentSet.size();
	int cnt = 1;
	for (set<string>::iterator it = studentSet.begin(); it != studentSet.end(); ++it, ++cnt)
	{
		cout << "        \"" << *it << "\"";
		printf("%c", cnt != stusetsz ? ',' : ' ');
		puts("");
	}
	puts("    ],");
	puts("    \"admitted\": [");
	for (int i = 1; i <= departmentSize; i++)
	{
		puts("        {");
		puts("            \"member\": [");
		int member_sz = DepartmentStudent[i].size();
		for (int j = 0; j < member_sz; j++)
		{
			cout << "                \"" << DepartmentStudent[i][j] << "\"";
			printf("%c", j != member_sz - 1 ? ',' : ' ');
			puts("");
		}
		puts("            ],");
		printf("            \"department_no\": \"");
		cout << departments[i].no << "\"\n";
		printf("        }");
		printf("%c", i != departmentSize ? ',' : ' ');
		puts("");
	}
	puts("    ],");
	puts("    \"unlucky_department\": [");
	int depsetsz = departmentSet.size();
	cnt = 1;
	for (set<int>::iterator it = departmentSet.begin(); it != departmentSet.end(); ++it, ++cnt)
	{
		cout << "        \"" << departments[*it].no << "\"";
		printf("%c", cnt != depsetsz ? ',' : ' ');
		puts("");
	}
	puts("    ]");
	puts("}");
}



int main()
{
	init();
	initTime();
	work();
	myPrint();

	return 0;
}