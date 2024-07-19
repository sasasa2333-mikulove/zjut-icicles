#pragma once
#include <iostream>

typedef int dataType;
class node {
public:
	node(dataType d, node* ptr = nullptr) { data = d; next = ptr; }
	dataType data;
	node* next;
};

class linked_list {
public:
	linked_list();
	linked_list(const linked_list& other);
	linked_list& operator=(const linked_list& right);
	int list_size() const;
	//���ϲ�����Ҳ���Կ������Ϊ���⺯��
	linked_list operator+(const linked_list& right); //�����ϲ�
	linked_list operator-(const linked_list& right);//�����ϲ�
	linked_list intersectionSet(const linked_list& right); //�����Ͻ�
	node* find(dataType value); //����
	bool  find(dataType value, node*& pre, node*& p);
	//�����޸ģ�bool  find(dataType value,node*& pre,node*&p);
	//�ҵ������棺pΪĿ��㣬preΪǰ����; �Ҳ������ؼ٣�p��pre��Ϊnullptr
	void add_front(dataType value); //��ӵ���
	void add_tail(dataType value);//��ӵ�β
	void add_pos_after(dataType value, node* pos); //��ӵ�ָ��λ��֮��
	void add_pos_before(dataType value, node* pos);//��ӵ�ָ��λ��֮ǰ
	void Delete(dataType value);//ɾ��ָ��ֵ
	void delete_pos_after(node* pos);//ɾ��ָ��λ��֮��
	void delete_pos_before(node* pos);//ɾ��ָ��λ��֮ǰ
	void delete_all (dataType value);//ɾ�������ظ�ֵ
	void delete_repeat();
	void reverse();//��������
	void sort();//�������е�ǰ����   
	void display();//��������
	~linked_list();
private:
	node* head, * tail;
	int size; //��ʹ���ڱ��������ʹ���ڱ������������size
}; //���Կ�����ƴ��ڱ��������ڱ�������Ϣ���Դ���size �洢���н��ĸ���
