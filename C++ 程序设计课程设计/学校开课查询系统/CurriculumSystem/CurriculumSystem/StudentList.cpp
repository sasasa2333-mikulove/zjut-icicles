#include "StudentList.hpp"
#include<iostream>
#include<fstream>
StudentList::StudentList() {
	size = 0;
	head = nullptr;
}
StudentList::~StudentList() {}

void StudentList::addStudent(Student& student) {
	Student* now = new Student(student);
	if (head == nullptr) {
		head = now; size++; 
		return;
	}
	now->next = head->next;
	head->next = now;
	size++; 
	return;

}
Student* StudentList::login() {
	string sno, password;
	cout << "������ѧ��:";cin >> sno;
	cout << "����������:";cin >> password;
	Student* p = head;
	while (p != nullptr) {
		if (p->getid() == sno && p->getPassword() == password) {
			cout << "��½�ɹ�" << endl;
			return p;
		}
		p = p->next;
	}
	cout << "��½ʧ��" << endl;
	return nullptr;
}

void StudentList::write() {
	ofstream outstu("Student.txt");
	Student* p = head;
	while (p != nullptr) {
		outstu << p->getid() << " " << p->getCourseName() << " " << p->getAge()
			<< " " << p->getGreade() << " " << p->getPassword() << " " << p->getSelectedCourseCnt() << " ";
		//¼��ѡ�μ�¼
		for (int i = 0; i < p->getSelectedCourseCnt(); i++)
			outstu << p->mySelectedCourses[i] << " ";
		outstu << endl;
		p = p->next;
	}
	outstu.close();
	cout << "ѧ���б���Ϣ����ɹ�" << endl;
}

void StudentList::deletecourseId(int id) {
	int m;
	Student* p = head;
	while (p != nullptr) {
		if (p->getSelectedCoursePlaceById(id) != -1) {
			m = p->getSelectedCoursePlaceById(id);
			p->cancelCourseByPlaceId(m);
		}
		p = p->next;
	}
}
Student* StudentList::findStudentById(string id) {
	Student* p = head;
	while (p->getid() != id && p->next != nullptr)
		p = p->next;
	if (p!=nullptr&&p->getid() == id)return p;
	else  cout << "���޴���" << endl;
	return nullptr;
}
void StudentList::updateStudentInfo(string studentId) {
	string id, name, password;
	int age, grade;
	Student* p2 = findStudentById(studentId);
	if (p2 == nullptr)return;
	cout << "׼��Ҫ�޸ĸ���";
	p2->showStudentInfo();
	cout << "������ѧ�ţ����������䣬��ѧʱ�䣬����" << endl;
	cin >> id >> name >> age >> grade >> password;
	p2->setData(id, name, age, grade, password);
	cout << "�����ɹ�" << endl;
	return;

}
void StudentList::deleteStudentByName(string name) {
	Student* p2 = findStudentById(name);
	if (p2 == nullptr)return;
	cout << "׼��Ҫɾ������";
	p2->showStudentInfo();
	Student* pre = head;
	Student* p = head;
	if (p->getid() == name) {
		head = p->next;
		pre->~Student();
		return;
	}
	p = p->next;
	while (p != nullptr) {
		if (p->getid() == name) {
			pre->next = p->next;
			p->~Student();
			return;
		}
		p = p->next;
		pre = p->next;
	}
}
