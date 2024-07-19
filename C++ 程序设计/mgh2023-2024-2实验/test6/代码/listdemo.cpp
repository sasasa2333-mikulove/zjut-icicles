//list_demo1.cpp
//l������Ļ��������ͷ���
#include<iostream>
#include "LinkedList.hpp" //����node�Ķ��� ��ʵ������1�� 1��-8����������
int main() {
	node* head1, * tail1;
	node* head2, * tail2;
	dataType xdata;

	head1 = NULL;
	//���������������   
	head1 = buildListForward();//����1 2 3 4 5 6 7 8 9���򹹽�����
	cout << "The result of buildListForward:";
	display(head1);//�������1,2,3,4,5,6,7,8,9	

	head2 = buildListReverse();//����1 2 3 4 5 6 7 8 9���򹹽�����
	cout << "The result of buildListReverse:";
	display(head2);//�������9,8,7,6,5,4,3,2,1

	tail1 = findListTail(head1);//�ҵ���1�ı�β
	tail2 = findListTail(head2);//�ҵ���2�ı�β

	add2tail(head1, tail1, 11);
	add2head(head1, tail1, 33);
	display(head1);//�������33,1,2,3,4,5,6,7,8,9,11

	add2tail(head2, tail2, 22);
	add2head(head2, tail2, 44);
	display(head2);//�������44,9,8,7,6,5,4,3,2,1,22

	//���ձ�2
	deleteList(head2);
	tail2 = NULL;//ͬ�����±�β

	display(head2);//�����

	add2tail(head2, tail2, 22);
	add2tail(head2, tail2, 33);
	add2head(head2, tail2, 44);
	add2head(head2, tail2, 55);
	add2tail(head2, tail2, 66);
	display(head2);//�������55,44,22,33,66

	//���ձ�1
	deleteList(head1);
	tail1 = NULL;//ͬ�����±�β

	//���ձ�2
	deleteList(head2);
	tail2 = NULL;//ͬ�����±�β

	//���򹹽������������β
	while (cin >> xdata) {//����22  96  47  13  15   19  12  24  0
		if (xdata == 0) break;//����0����
		add2tail(head1, tail1, xdata);
	}
	display(head1);//�������22,96,47,13,15,19,12,24

	//���򹹽��������������
	while (cin >> xdata) {//����22  96  47  13  15   19  12  24  0
		if (xdata == 0) break;//����0����
		add2head(head2, tail2, xdata);
	}
	display(head2);//�������24,12,19,15,13,47,96,22

	node* p, * pre;
	search(head1, 15, p, pre);
	if (p) {
		if (pre) cout << pre->data;//Ŀ���ǰ��
		cout << ',' << p->data;//Ŀ��
		if (p->next) cout << ',' << p->next->data; //Ŀ��ĺ��
		cout << endl;
	}

	//����½���ڲ��ҵ��
	p->next = new node(77, p->next);
	//����½���ڲ��ҵ�ǰ
	pre->next = new node(88, p);
	display(head1);//�������22,96,47,13,88,15,77,19,12,24

	//ɾ��15
	search(head1, 15, p, pre);
	pre->next = p->next;
	delete p;
	display(head1);//�������22,96,47,13,88,77,19,12,24

	search(head1, 99, p, pre);
	if (!p) cout << "99 is not in the list head1";

	deleteList(head1);
	deleteList(head2);

	return 0;
}

