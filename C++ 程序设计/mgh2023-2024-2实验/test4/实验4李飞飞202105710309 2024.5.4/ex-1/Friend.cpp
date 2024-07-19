#include "Friend.hpp"
Clock::Clock(int h, int m, int s) :hour(h), minute(m), second(s) {}
void Clock::display(const Date& d) {
	//����Date������е�˽������
	cout << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << endl; 
	//���ñ�������е�˽������
	cout << hour << ":" << minute << ":" << second << endl;
}
Date::Date(int m, int d, int y) :month(m),day(d),year(y){}
