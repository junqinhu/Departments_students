#include <string>

using namespace std;

class DataGenerating
{
public:
	void toGenerate();       //���ɶ����������ݵ�������
private:
	bool used[21];           //��־����
	int n_students = 300;    //ѧ������
	int n_freeTime = 21;    //Ԥ�����ʱ������
	string freeTime[21];     //Ԥ��Ŀ���ʱ���

	int n_departments = 20;  //��������
	int n_EventSchedules = 21; //Ԥ�貿�Żʱ������
	string departments[20];    //Ԥ�貿�ű��
	string eventSchedules[21];//Ԥ��Ĳ���ʱ���
	string tags[21];          //Ԥ�貿�ű�ǩ

	void setUsedFalse();          //����used�����ֵΪfalse
	void createStudents(int *a);   //��������ѧ����Ϣ
	void createDepartments(int a); //�������ɲ�����Ϣ
	void initDepartments();     //���Գ�ʼ��Ԥ�貿�ű��
	void initFreeTime();     //���Գ�ʼ��Ԥ�����ʱ���
	void initTags();        //���Գ�ʼ��Ԥ�貿�ű�ǩ
	void initEventSchedules();  //���Գ�ʼ��Ԥ�貿�Żʱ���
};

