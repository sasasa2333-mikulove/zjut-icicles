#include "position.hpp"
#include <iostream>
using namespace std;

int main() {
	position a, b, c, d, e;
	a.set(5, 15);
	a.show();//���(5,15)
	cout << a.quadrant() << endl; //���a������ 
	b.set(-4.5, 6.7);
	b.show();
	cout << b.quadrant() << endl; //���b������
	c.set(-10, -100);
	c.show();
	cout << c.quadrant() << endl; //���c������
	d.set(20.5, 5.5);
	d.show();
	cout << d.quadrant() << endl; //���b������
	e.set();//Ĭ��Ϊԭ��
	e.show();
	cout << distance(a,b) << endl;
	cout << distance(c) << endl;//Ĭ������ԭ��ľ���
	cout << a.slope() << endl;//��ԭ�㹹��ֱ�ߵ�б��
	cout << a.slope(d) << endl;//��d����ֱ�ߵ�б��
	a.move(3);//��x��ƽ��
	a.show();
	b.move(-4, 5);
	b.show();
	c.move(0, 6);//��y��ƽ��
	c.show();
	return 0;
}
