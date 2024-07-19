//myString.cpp
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "myString.hpp"
#include <iostream>
#include <cstring>
using namespace std;
//���ݲ��Գ���д���캯��ԭ��
myString::myString() {
	str = new char[1];
	str[0] = '\0';
	size = 1;
}

myString::myString(const myString& a) {
	str = new char[a.size];
	size = a.size;
	strcpy(str, a.str);
}

myString::myString(const char* str){
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
	size = strlen(str)+1;
}
//���캯��
myString::myString(int length, const char c) {
	str = new char[length + 1];
	size = length;
	for (int i = 0; i < size; ++i)
		str[i] = c;
	str[size] = '\0';

}
//���캯��
myString::myString(const char* s, int index, int length) //���캯��
{
	str = new char[length + 1];
	size = length + 1;
	for (int i = 0; i < length; ++i)
		str[i] = s[index + i];
	str[length] = '\0';

}
myString::~myString() {
	if (str != nullptr) {
		str = nullptr;
		delete[] str;
	}
}

void myString::display() const {
	cout << str << endl;
}

void myString::input() {
	// ʹ��getline��ȡһ����
	char c[1000];
	cin.getline(c, 1000);
	size = strlen(c)+1;
	strcpy(str, c);
	str[size - 1] = '\0';
}
int myString::len() const {
	return size;
}
//�����±���������
char& myString::operator[](int index) {
	return str[index];
}
//���������
myString& myString::operator=(const myString& a) {
	if (this != &a) {
		if (str != nullptr)
			delete[] str;
		str = new char[a.size];
		strcpy(str, a.str);
		size = a.size;
	}
	return *this;
}

bool myString::operator!=(const myString& a) //�ַ��������ڱȽ�
{
	if (strcmp(a.str, str) != 0) return true;
	return false;
}
bool myString::operator==(const myString& a) //�ַ������ڱȽ�
{
	if (strcmp(a.str, str) == 0) return 1;
	return 0;
}
bool myString::operator>(const myString& a) //�ַ������ڱȽ�
{
	if (strcmp(str, a.str) > 0) return 1;
	return 0;
}
myString myString::operator+(const myString& a) {
	int len = a.size + size-1;
	char* c = new char[len];
	size = len;
	strcpy(c, str);
	strcat(c, a.str);
	delete[] str;
	str = c;
	return (*this);
}