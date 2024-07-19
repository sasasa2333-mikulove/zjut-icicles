#pragma once
#include"Course.hpp"
using namespace std;
class CourseList{
    public:
        CourseList();
        virtual ~CourseList();
        //β�巨
        void add(Course &cou);
        //����Ų���
        Course *findByCourseId(int id);
        //�����ֲ���
        void findByCourseName(string n);
        //��Ժϵ����
        void findByCourseDepartment(string f);
        //����ʦ���ֲ���
        void findByLecturer(string t);
        //����
        void findCourseMenu();
        //չʾ���пγ���Ϣ
        void show();
        //д���ļ�
        void write();
        //��ѧ������
        void sortByCourseCredit();
        //������ѧԺ����
        void sortByCourseDepartment();

        void sortCourseMenu();//����
        //�޸���Ϣ
        void updateCourseInfo(Course *target);
        //ɾ���γ�
        void removeCourse(int id);
    protected:
        Course *head;
        int size;

};
