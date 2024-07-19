//list_demo2.cpp
//2������Ľ��׹���

#include<iostream>
#include "LinkedList.hpp" //����node�Ķ��� ��ʵ������1�� 1��-8���������� + ʵ������2 ��1)-8)��������


int main() {
	node* head1;
	node* head2;
	dataType xdata;

	head1 = NULL;
	//���������������   
	head1 = buildListForward();//����1 2 3 4 5 6 7 8 9���򹹽�����
	cout << "The result of buildListForward:";
	display(head1);//�������1,2,3,4,5,6,7,8,9

	node* p, * pre;
	search(head1, 5, p, pre);//����15
	addAfterP(head1, p, 11);//�����15֮ǰ
	addBeforeP(head1, pre, p, 22);//�����15֮��
	display(head1);//�������1,2,3,4,22,5,11,6,7,8,9

	search(head1, 10, p, pre);//����10
	addAfterP(head1, p, 33);//pΪ�գ�����ڱ���
	addBeforeP(head1, pre, p, 44);//pΪ�գ�����ڱ���
	display(head1);//�������44,33,1,2,3,4,22,5,11,6,7,8,9

	search(head1, 44, p, pre);//����44
	addAfterP(head1, p, 55);//�����44֮��
	addBeforeP(head1, pre, p, 66);//�����44֮ǰ
	display(head1);//�������66,44,55,33,1,2,3,4,22,5,11,6,7,8,9

	search(head1, 44, p, pre);//����44
	deleteP(head1, pre, p);
	display(head1);//�������66,55,33,1,2,3,4,22,5,11,6,7,8,9

	search(head1, 66, p, pre);//����66
	deleteP(head1, pre, p);
	display(head1);//�������55,33,1,2,3,4,22,5,11,6,7,8,9

	reverseList(head1);//��������
	display(head1);//�������9,8,7,6,11,5,22,4,3,2,1,33,55

	head2 = copyList(head1);//����head1

	selectSortList(head1);
	display(head1);//�������1,2,3,4,5,6,7,8,9,11,22,33,55

	display(head2);//�������9,8,7,6,11,5,22,4,3,2,1,33,55
	bubbleSortList(head2);
	display(head2);//�������1,2,3,4,5,6,7,8,9,11,22,33,55

	while (cin >> xdata) {//��������-10 4 10  100  56  4 44 0
		if (xdata == 0) break;
		add2OrderedList(head1, xdata);
	}
	display(head1);//-10,1,2,3,4,4,4,5,6,7,8,9,10,11,22,33,44,55,56,100

	search(head1, -10, p, pre);//����-10
	deleteP(head1, pre, p);//ɾ��-10
	display(head1);//�����1,2,3,4,4,4,5,6,7,8,9,10,11,22,33,44,55,56,100

	search(head1, 44, p, pre);//����44
	deleteP(head1, pre, p);//ɾ��44
	display(head1);//�����1,2,3,4,4,4,5,6,7,8,9,10,11,22,33,55,56,100

	search(head1, 22, p, pre);//����22
	addAfterP(head1, p, 4);
	addBeforeP(head1, pre, p, 4);
	display(head1);//�����1,2,3,4,4,4,5,6,7,8,9,10,11,4,22,4,33,55,56,100

	search(head1, 1, p, pre);//����1
	addAfterP(head1, p, 4);
	addBeforeP(head1, pre, p, 4);
	display(head1);//�����4,1,4,2,3,4,4,4,5,6,7,8,9,10,11,4,22,4,33,55,56,100

	deleteAllValues(head1, 4);
	display(head1);//�����1,2,3,5,6,7,8,9,10,11,22,33,55,56,100

	deleteList(head1);
	deleteList(head2);

	return 0;
}