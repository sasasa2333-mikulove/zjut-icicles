#pragma once
#include<string>
using namespace std;
class Course {
public:
	Course* next;
	Course() {};
	Course(int id, string name, string teacherName, double credit, string type, string department, int cnt, int s);
	virtual ~Course();
	void showStudentInfo();
	void updateCourseInfo(string, string, double, string, string);
	Course& operator =(Course& c);
	bool studentChooseable();
	void updateSelectedCnt(int x);

	//getter setter
	int getNumber();
	string getCourseName();
	string getLecturerName();
	double getCredit();
	string getcourseType();
	string getDepartment();
	int getSelectedCnt();
	int getMaxCnt();

protected:
	int courseId;//�γ̱��
	string courseName;
	string lecturerName;//�ον�ʦ
	double credit;//ѧ��
	string courseType;//�γ�����
	string department;//����Ժϵ
	int selectedCnt;//��ѡ�ÿε�����
	int maxCnt;//�ÿƿ�ѡ���������
};
