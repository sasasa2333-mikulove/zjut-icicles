//���Գ���
#include<iostream>
#include "linkedList.hpp"
using namespace std;
int main()
{
    linked_list a1, a2, b, c;
    dataType data;
    //���������������
    //����2 ,6, 7, 3, 5, 9,12, 4 ,0     [2 6 7 3 5 9 12 4 0
    while (cin >> data) {
        if (data == 0) break; //����0����
        a1.add_front(data);
        a2.add_tail(data);
    }
    a1.display();
    a2.display();
    //����ת�ò���
    //����2 ,16, 3, 8, 15, 4, 9, 7 ,0    [2 16 3 8 15 4 9 7 0
    while (cin >> data) {
        if (data == 0) break; //����0����
        b.add_tail(data);
    }
    b.display();
    b.reverse();
    b.display();

    c=a1+b; //���Լ��ϲ�
    c.display();
    c=a1-b; //���Լ��ϲ�
    c.display();
    c=a1.intersectionSet(b); //���Լ��Ͻ�
    c.display();
    a1.sort(); //������������
    a1.display();

    //˼����Ҫ���������������
    b.add_tail(16); b.add_tail(3); b.display();
    b.delete_repeat();                  b.display();
    node* pos = b.find(15);
    b.add_pos_after(18, pos);   b.display();
    b.add_pos_before(23, pos); b.display();
    b.delete_pos_after(pos);     b.display();
    b.delete_pos_before(pos);  b.display();
    b.Delete(8);                         b.display();

    return 0;
}
