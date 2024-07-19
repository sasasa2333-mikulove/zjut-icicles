#pragma once
#include<iostream>
#include"linkedList.hpp"
using namespace std;

linked_list::linked_list()
{
	head = tail = nullptr; size = 0;
}   //��ʼ�����캯��

linked_list::linked_list(const linked_list& other)
{
    head = tail = nullptr;
    size = other.size;
    node* p = other.head;
    while (p != nullptr)
    {
        add_tail(p->data);
        p = p->next;
    }
}

linked_list& linked_list::operator=(const linked_list& right)//��ֵ���������
{
    if (this == &right) return *this; // ������Ҹ�ֵ����ֱ�ӷ���

    // ɾ��ԭ��Ԫ��
    node* p = head;
    while (p != nullptr)
    {
        node* q = p->next;
        delete p;
        p = q;
    }
    head = tail = nullptr;
    size = 0;
    // ����ͷ��βָ��
    head = tail = nullptr;
    // ����Ԫ�ظ���
    size = right.size;
    // ����������
    for (node* p = right.head; p != nullptr; p = p->next)
    {
        add_tail(p->data); // ��β���Ԫ��
    }
    return *this; // ���ر�����
}

int linked_list::list_size() const
{
    return size;
}

//���ϲ�����Ҳ���Կ������Ϊ���⺯��
//linked_list linked_list::operator+(const linked_list& right); //�����ϲ�
//linked_list linked_list::operator-(const linked_list& right);//�����ϲ�
//linked_list linked_list::intersectionSet(const linked_list& right); //�����Ͻ�

node* linked_list::find(dataType value)//����
{
    node* p = head;
    while (p != nullptr && p->data != value)
    {
        p = p->next;
    }
    return p;
}

bool linked_list::find(dataType value, node*& pre, node*& p)
{
    p = head;
    while (p != nullptr && p->data != value)
    {
        pre = p;
        p = p->next;
    }
    if (p == nullptr) return false;
    else return true;
}
//�����޸ģ�bool  find(dataType value,node*& pre,node*&p);
//�ҵ������棺pΪĿ��㣬preΪǰ����; �Ҳ������ؼ٣�p��pre��Ϊnullptr
void linked_list::add_front(dataType value) //��ӵ���
{
    node* newNode = new node(value);
    newNode->next = head;
    if (head == nullptr) tail = newNode;
    head = newNode;
    size++;
}

void linked_list::add_tail(dataType value)//��ӵ�β
{
    node* newNode = new node(value);
    if (tail == nullptr) head = newNode;
    else tail->next = newNode;
    tail = newNode;
    size++;
}

void linked_list::add_pos_after(dataType value, node* pos) //��ӵ�ָ��λ��֮��
{
    node* newNode = new node(value);
    newNode->next = pos->next;
    pos->next = newNode;
    if (newNode->next == nullptr) tail = newNode;
    size++;
}

void linked_list::add_pos_before(dataType value, node* pos)
{//��ӵ�ָ��λ��֮ǰ
    node* newNode = new node(value);
    if (head == pos)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = pos;
        node* pre = nullptr;
        node* p = head;
        while (p != pos)
        {
            pre = p;
            p = p->next;
        }
        pre->next = newNode;
    }
    size++;
}

//ɾ��ָ��ֵ
void linked_list::Delete(dataType value)
{
    node* pre = nullptr, * p = head;
    while (p != nullptr && p->data != value)
    {
        pre = p;
        p = p->next;
    }
    if (p == nullptr) return;
    if (pre == nullptr) head = p->next;
    else pre->next = p->next;
    delete p;
    size--;
}

void linked_list::delete_pos_after(node* pos)//ɾ��ָ��λ��֮��
{
    if (pos == tail) return ;
    else
    {
        node* pre = pos;
        node* p = pre->next;
        pre->next = p->next;
        delete p;
        size--;
        
    }
}

void linked_list::delete_pos_before(node* pos)//ɾ��ָ��λ��֮ǰ
{
    if (pos == head) return ;
    else
    {
        node* pre = head;
        node* p = pre->next;
        while (p->next != pos)
        {
            p = p->next;
            pre = pre->next;
        }
        pre->next = p->next;
        delete p;
        size--;
    }
}

void linked_list::delete_all(dataType value)//ɾ�������ظ�ֵ
{
    node* p = head;
    while (p != nullptr)
    {
        node* q = p->next;
        if (p->data == value)
        {
            if (p == head) head = q;
            else p->next = q->next;
            delete p;
            size--;
        }
        p = q;
    }
}

void linked_list::delete_repeat()
{
    node* q = head;
    while (q != nullptr)
    {
        node* p = q->next;
        node* pre = q;
        while (p != nullptr)
        {
            if (p->data == q->data)
            {
                pre->next = p->next;
                delete p;
                size--;
                p = pre->next;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        
        q = q->next;
    }
    tail = q;
}

void linked_list::reverse()//��������
{
    node* p = head, * q = nullptr, * r = nullptr;
    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    tail = head;
    head = q;
}

void linked_list::sort()//�������е�ǰ����   
{
    node* p = head;
    dataType temp;
    while (p != nullptr)
    {
        node* q = p->next;
        while (q != nullptr)
        {
            if (p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void linked_list::display()//��������
{
    node* p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


linked_list::~linked_list()
{
    node* p = head;
    while (p != nullptr)
    {
        node* q = p->next;
        delete p;
        p = q;
    }
    head = tail = nullptr;
    size = 0;
}




linked_list linked_list::operator+(const linked_list& right)//�����ϲ�
{
    linked_list result;
    node* p = head;
    while (p != nullptr)
    {
        result.add_tail(p->data);
        p = p->next;
    }
    p = right.head;
    while (p != nullptr)
    {
        result.add_tail(p->data);
        p = p->next;
    }
    return result;
}
linked_list linked_list::operator-(const linked_list& right)//�����ϲ�
{
    linked_list result;
    node* p = head;
    while (p != nullptr)
    {
        result.add_tail(p->data);
        p = p->next;
    }
    p = right.head;
    while (p != nullptr)
    {
        result.Delete(p->data);
        p = p->next;
    }
    return result;
}
linked_list linked_list::intersectionSet(const linked_list& right) //�����Ͻ�
{
    linked_list result;
    node* p = head;
    while (p != nullptr)
    {
        result.add_tail(p->data);
        p = p->next;
    }
    p = right.head;
    while (p != nullptr)
    {
        result.find(p->data, result.head, result.tail);
        p = p->next;
    }
    return result;
}