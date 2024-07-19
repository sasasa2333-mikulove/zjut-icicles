#include "CourseList.hpp"
#include<iostream>
#include<fstream>
double getSamePercentage(string a, string b) {
	//���� ��ƥ�䴮
	int x = a.length(), y = b.length();
	int cnt = 0;
	for (int i = 0; i < x; i+=2)
		for (int j = 0; j < y; j+=2)
			if (a[i] == b[j]&&a[i+1]==b[j+1])cnt++;
	//cout << a << " " << b << endl;
	//cout << a.size() << " " << b.size() << endl;
	//for (int i = 0; i < x; i += 2)
	//	for (int j = 0; j < y; j += 2)
	//		if (a[i] == b[j] && a[i + 1] == b[j + 1]) {
	//			cout << i << " " << j << endl;
	//			cout << a[i] << " " << b[j] << endl;
	//		}
	return 1.0 * cnt / y;
}
CourseList::CourseList() {
	head = nullptr;
	size = 0;
}
CourseList::~CourseList() {}

void CourseList::add(Course& course) {
	Course* nowCourse = new Course(course);
	if (head == nullptr) { head = nowCourse; size++; return; }
	Course* p = head;
	while (p->next != nullptr) { p = p->next; }
	p->next = nowCourse; size++; return;
}
//�ĸ����Һ���
Course* CourseList::findByCourseId(int id) {
	Course* p = head;
	if (p == nullptr) {
		cout << "δ���˿γ�" << endl;
		return nullptr;
	}
	while (p->getNumber() != id && p->next != nullptr)
		p = p->next;
	if (p->getNumber() == id) {
		p->showStudentInfo();
		return p;
	}
	cout << "δ���˿γ�" << endl;
	return nullptr;
}
void CourseList::findByCourseName(string n) {
	Course* p = head;
	while (p != nullptr) {
		if (p->getCourseName() == n) {
			p->showStudentInfo();
			return;
		}
		p = p->next;
	}
	if (p == nullptr) {
		Course* nowslected = nullptr;
		double maxSame = -1;
		p = head;
		while (p != nullptr) {
			double nowSame = getSamePercentage(n, p->getCourseName());
			if (nowSame > maxSame) {
				maxSame = nowSame;
				nowslected = p;
			}
			p = p->next;
		}
		if (nowslected == nullptr) {
			cout << "δ�ҵ����������ļ�¼��" << endl;
			return;
		}
		cout << "ģ��ƥ��ɹ����¼�¼��\n";
		nowslected->showStudentInfo();
	}
}
void CourseList::findByCourseDepartment(string department) {
	Course* p = head;
	bool find = false;
	while (p != nullptr) {
		if (p->getDepartment() == department) {
			p->showStudentInfo();
			find = true;
		}
		p = p->next;
	}
	if (find)return;
	double maxSame = -1;
	if (p == nullptr) {
		p = head;
		while (p != nullptr) {
			double nowSame = getSamePercentage(department, p->getDepartment());
			maxSame = max(maxSame, nowSame);
			p = p->next;
		}
		if (maxSame <= 1e-3) {
			cout << "δ�ҵ����������ļ�¼��" << endl;
			return;
		}
		cout << "ģ��ƥ��ɹ����¼�¼��\n";
	}
	//�ҵ���¼��ȫ����ӡ
	p = head;
	while (p != nullptr) {
		double nowSame = getSamePercentage(department, p->getDepartment());
		if (nowSame > (maxSame - (1e-4)))
			p->showStudentInfo();
		p = p->next;
	}
}
void CourseList::findByLecturer(string teacher) {
	Course* p = head;
	bool find = false;
	while (p != nullptr) {
		if (p->getLecturerName() == teacher) {
			p->showStudentInfo();
			find = true;
		}
		p = p->next;
	}
	if (find)return;
	double maxSame = -1;
	if (p == nullptr) {
		p = head;
		while (p != nullptr) {
			double nowSame = getSamePercentage(teacher, p->getLecturerName());
			maxSame = max(maxSame, nowSame);
			p = p->next;
		}
		if (maxSame <= 1e-3) {
			cout << "δ�ҵ����������ļ�¼��" << endl;
			return;
		}
		cout << "ģ��ƥ��ɹ����¼�¼��\n";
	}
	//�ҵ���¼��ȫ����ӡ
	p = head;
	while (p != nullptr) {
		double nowSame = getSamePercentage(teacher, p->getLecturerName());
		if (nowSame > (maxSame - (1e-4)))
			p->showStudentInfo();
		p = p->next;
	}
}

void CourseList::show() {
	Course* p = head;
	while (p != nullptr) { p->showStudentInfo(); p = p->next; }
}
void CourseList::findCourseMenu() {
	cout << "------------------�ָ���------------------------\n";
	cout << "1.����Ų���" << endl;
	cout << "2.���γ����Ʋ���" << endl;
	cout << "3.����ʦ��������" << endl;
	cout << "4.��ԺѧԺ������" << endl;
	cout << "��ѡ��1/2/3/4,����-1�����ϼ�Ŀ¼����" << endl;
	int order,id;
	string temp; cin >> temp;
	bool noValue = true;
	while (temp != "1" && temp != "2" && temp != "3" && temp != "4" && temp != "-1") {
		cout << "������������������~\n";
		cin >> temp;
	}
	if (temp == "-1")order = -1;
	else if (temp == "1")order = 1;
	else if (temp == "2")order = 2;
	else if (temp == "3")order = 3;
	else order = 4;
	string name;
	switch (order) {
		case 1:cout << "��������:"; cin >> id; findByCourseId(id); break;
		case 2:cout << "������γ���:"; cin >> name; findByCourseName(name); break;
		case 3:cout << "�������ʦ��:"; cin >> name; findByLecturer(name); break;
		case 4:cout << "������ѧԺ��:"; cin >> name; findByCourseDepartment(name); break;
	}
	cout << "�������뷵��";
	cin >> name; return;
}

void CourseList::write() {
	ofstream outcourse("Course.txt");
	Course* p = head;
	while (p != nullptr)
	{
		outcourse << p->getNumber() << " " << p->getCourseName() << " " << p->getLecturerName()
			<< " " << p->getCredit() << " " << p->getcourseType() << " " << p->getDepartment()
			<< " " << p->getSelectedCnt() << " " << p->getMaxCnt() << endl;
		p = p->next;
	}
	outcourse.close();
}

void CourseList::sortByCourseCredit() {
	Course temp;
	Course* p1, * p2;
	for (p1 = head; p1->next != nullptr; p1 = p1->next) {
		for (p2 = p1->next; p2 != nullptr; p2 = p2->next) {
			if (p1->getCredit() > p2->getCredit()) {
				temp = (*p1);
				(*p1) = (*p2);
				(*p2) = temp;
			}
		}
	}
}

void CourseList::sortByCourseDepartment() {
	Course temp;
	Course* p1, * p2;
	for (p1 = head; p1->next != nullptr; p1 = p1->next) {
		for (p2 = p1->next; p2 != nullptr; p2 = p2->next) {
			if (p1->getDepartment() > p2->getDepartment()) {
				temp = (*p1);
				(*p1) = (*p2);
				(*p2) = temp;
			}
		}
	}
}
void CourseList::sortCourseMenu() {
	string m;
	cout << "--------------����ҽзָ���--------------------\n";
	cout << "1.��ѧ�ֽ�������" << endl;
	cout << "2.������Ժϵ��������" << endl;
	cout << "��ѡ��1/2,����-1�����ϲ�ṹ����" << endl;
	cin >> m;
	system("cls");
	while (m!="1"&&m!="2"&&m!="-1"){
		cout << "�����������������룡\n";
		cin >> m;
	}
	int t;
	if (m == "-1")t = -1;
	else t = (m == "1" ? 1 : 2);
	switch (t) {
	case 1:sortByCourseCredit(); break;
	case 2:sortByCourseDepartment(); break;
	case -1:break;
	}
}


void CourseList::updateCourseInfo(Course* target) {
	cout << "�������µ����֣���ʦ���֣�ѧ�֣��γ����ʣ�����ѧԺ��" << endl;
	string nm, tnm, natu, fa;
	double s;
	cin >> nm >> tnm >> s >> natu >> fa;
	target->updateCourseInfo(nm, tnm, s, natu, fa);
	cout << "�޸ĳɹ�" << endl;
}
void CourseList::removeCourse(int id) {
	Course* pre = head;
	Course* p = head;
	if (p->getNumber() == id) {
		head = p->next;
		pre->~Course();
		return;
	}
	p = p->next;
	while (p != nullptr) {
		if (p->getNumber() == id) { pre->next = p->next; p->~Course(); return; }
		p = p->next;
		pre = p->next;
	}
	cout << "�޴˿�" << endl;

}

