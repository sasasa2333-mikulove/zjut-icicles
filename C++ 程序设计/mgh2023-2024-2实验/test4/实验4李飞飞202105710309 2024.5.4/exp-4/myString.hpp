//myString.hpp
#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class myString {
public:
	//���ݲ��Գ���д���캯��ԭ��
	myString();//Ĭ�Ϲ��캯��

	myString(const myString& a); //�������캯��

	myString(const char* str); //���캯��

	myString(int length, const char c); //���캯��

	myString(const char* s, int index, int length); //���캯��

	~myString(); //��������

	void display() const;//��ʾ�ַ���

	void input(); // �����ַ���

	int len() const;//���ַ�����
	//�����±���������
	char& operator[](int index);

	//���������
	myString& operator=(const myString& a); //��ֵ����

	bool operator!=(const myString& a);//�ַ��������ڱȽ�

	bool operator==(const myString& a);//�ַ������ڱȽ�

	bool operator>(const myString& a); //�ַ������ڱȽ�

	myString operator+(const myString& a); //�ַ���ƴ��

private:
	char* str;
	int size;
};

//����ΪmyString����������������
//����<<�����
ostream& operator<<(ostream& out, const myString& a);
//����>>�����
istream& operator>>(istream& in, myString& a);
