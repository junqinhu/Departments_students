#include <string>

using namespace std;

class DataGenerating
{
public:
	void toGenerate();       //生成定制输入数据的主方法
private:
	bool used[21];           //标志数组
	int n_students = 300;    //学生数量
	int n_freeTime = 21;    //预设空闲时间数量
	string freeTime[21];     //预设的空闲时间段

	int n_departments = 20;  //部门数量
	int n_EventSchedules = 21; //预设部门活动时间数量
	string departments[20];    //预设部门编号
	string eventSchedules[21];//预设的部门时间段
	string tags[21];          //预设部门标签

	void setUsedFalse();          //设置used数组的值为false
	void createStudents(int *a);   //定制生成学生信息
	void createDepartments(int a); //定制生成部门信息
	void initDepartments();     //用以初始化预设部门编号
	void initFreeTime();     //用以初始化预设空闲时间段
	void initTags();        //用以初始化预设部门标签
	void initEventSchedules();  //用以初始化预设部门活动时间段
};

