#include "position.hpp"
#include <iostream>
using namespace std;
int main() {
	position a; //Ĭ������λ��Ϊԭ��
	position b(4, 5), c(b), d(-2, -7), e(1); //b��λ��Ϊx��ֵ4��y��ֵ5
	position* px;
	cout << "K1 = " << position::K() << endl;
	px = new position(-3.5, 9.8);
	(*px).show(); //����Ļ����� (-3.5,9.8)
	cout << "K2 = " << a.K() << endl;
	px->set(99, -48); //�������õ�
	cout << "K3 = " << position::K() << endl;
	delete px;
	cout << "K4 = " << b.K() << endl;
	px = new position[3]{ position(5,15),position(-4.5,16.7),position(-10.8) };
	cout << "b:"; b.show();
	cout << "c:"; c.show();
	c.set(-10, -100);
	cout << "c:"; c.show();
	e.set();//Ĭ��Ϊԭ��
	cout << "e:"; e.show();
	cout << a.distance() << endl;
	cout << c.distance() << endl;//Ĭ������ԭ��ľ���
	cout << a.slope() << endl; //��ԭ�㹹��ֱ�ߵ�б��
	cout << a.slope(d) << endl;  //��d����ֱ�ߵ�б��
	a.move(3);//��x��ƽ��
	cout << "a:"; a.show();
	b.move(-4, 5);
	cout << "b:"; b.show();
	c.move(0, 6.3);//��y��ƽ��
	cout << "c:"; c.show();
	cout << "K5 = " << position::K() << endl;
	delete[]px;
	cout << "K6 = " << position::K() << endl;
	return 0;
}
