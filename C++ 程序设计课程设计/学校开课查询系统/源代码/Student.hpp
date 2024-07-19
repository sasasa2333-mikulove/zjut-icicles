#pragma once
#include<string>
using namespace std;
class Student {
public:
	Student(string, string, int, int, string, int, int*);
	Student(string, string, int, int, string);
	virtual ~Student();
	void showStudentInfo();//չʾ������Ϣ
	void add(int temp);//���γ̱�ű���mySelectedCoursesĩβ
	Student(const Student& student);
	Student* next;
	//ѡ�λ�ȡ����ѡ�Ŀ�
	int chooseCourse(int id, bool choiceable);
	//���ݿγ̺Ż�ȡ�Լ�ѡ�οε���ţ�û�з���-1
	int getSelectedCoursePlaceById(int id);
	//ȡ��ѡ��
	void cancelCourseByPlaceId(int id);
	int* mySelectedCourses;//���ѧ����ѡ�γ̵�ѧ�����

	//getter setter
	string getid();//�õ�ѧ��
	string getCourseName();
	int getAge();
	int getGreade();
	string getPassword();
	int getSelectedCourseCnt();
	void setPassword();//�޸�����
	void setData(string id, string na, int a, int ey, string pa);
protected:
	string studentId;//ѧ��
	string courseName;
	string password;//����
	int age;
	int studentGreade;//��ѧ���
	int selectedCourseCnt;//��ѡ�ο�Ŀ����
};
