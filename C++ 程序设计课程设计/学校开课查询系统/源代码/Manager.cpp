#include "Manager.hpp"
#include"string"
#include<iostream>
Manager::Manager(string account, string password){
	this->account = account;
	this->password = password;
}

Manager::~Manager(){}
bool Manager::login(){
	string account, password;
	cout << "�������˺�: "; cin >> account;
	cout << "����������: "; cin >> password;
	if (this->account == account && this->password == password){
		cout << "��½�ɹ�" << endl;
		return true;
	}
	cout << "��½ʧ��" << endl;
	return false;
}
void Manager::setPassword(){
	cout << "�������µ�����";
	cin >> password;
	cout << "�޸ĳɹ�" << endl;
}
