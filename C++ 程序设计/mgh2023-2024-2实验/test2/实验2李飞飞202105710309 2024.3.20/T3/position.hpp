#pragma once
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
class position{
public:
	position();
	~position();
	void set(double x=0,double y=0);
	void show()const;
	//�жϵڼ�����
	string quadrant()const;
	double distance()const;
	double distance(const position &other)const;
	double slope()const;
	double slope(const position& other)const;
	void move(double distX,double distY=0);
private:
	double x;
	double y;
};
double distance(const position& other) {
	return other.distance();
}
double distance(const position& a, const position& b) {
	return a.distance(b);
}
position::position(){
	x = 0, y = 0;
}

position::~position(){}

inline void position::set(double x, double y){
	this->x = x; this->y = y;
}

inline void position::show()const {
	cout << "�����꣺" << x << " �����꣺" << y<<endl;
}

string position::quadrant()const {
	if (x == 0 && y == 0)return "ԭ��";
	if (x == 0)return "y����";
	if (y == 0)return "x����";
	if (x > 0 && y > 0) return "һ����";
	if (x < 0 && y < 0) return "������";
	if (x > 0 && y < 0) return "������";
	if (x < 0 && y > 0) return "������";
}

inline double position::distance()const {
	return sqrt(x * x + y * y);
}

inline double position::distance(const position& other)const {
	return sqrt((x-other.x)* (x - other.x) + (y - other.y) * (y - other.y));
}

inline double position::slope()const {
	return y/x;
}

inline double position::slope(const position& other)const {
	return (other.y-y)/(other.x-x);
}

inline void position::move(double distX, double distY){
	x += distX; y += distY;
}
