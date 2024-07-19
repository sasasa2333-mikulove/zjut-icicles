#pragma once
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
class position {
public:
	position(double a = 0, double b = 0) :x(a), y(b) {
		count++;
		update(*this);
	};
	~position();
	position(const position& other) {
		this->x = other.x;
		this->y = other.y;
		count++;
		update(*this);
	}
	void set(double x = 0, double y = 0);
	void show()const;
	//�жϵڼ�����
	string quadrant()const;
	double distance()const;
	double distance(const position& other)const;
	double slope()const;
	double slope(const position& other)const;
	void move(double distX, double distY = 0);
	//����ĺ���
	static double K();
private:
	static int count;
	static double up, down, right, left;
	double x;
	double y;
	static void update(position &now);
};
double distance(const position& other) {
	return other.distance();
}
double distance(const position& a, const position& b) {
	return a.distance(b);
}

//��ʼ��
int position::count = 0;
double position::up = -1e9;
double position::down = 1e9;
double position::right = -1e9;
double position::left = 1e9;

void position::update(position& now) {
	//cout << "JJJ\n";
	//cout << now.x << "  " << now.y << endl;
	up = max(up, now.y);
	down = min(down,now.y);
	left = min(left, now.x);
	right = max(right, now.x);

	//cout << up << "  " << down << "  " << left << "  " << right << endl;
}
double position::K() {
	//�޵�
	if (!count)return 0;
	//δ��ʼ��
	if (right < left || up < down)return 0;
	double width = right - left;
	double height = up - down;
	//����һ����
	if (width < 1e-5 || height < 1e-5)return 0;
	//cout << "����:" << count << endl;
	//cout<<"�߽�" << up << "  " << down << "  " << left << "  " << right << endl;
	return count / (width * height);
}
position::~position() {
	this->count--;
}

inline void position::set(double x, double y) {
	this->x = x; this->y = y;
	update(*this);
}

inline void position::show()const {
	cout << "�����꣺" << x << " �����꣺" << y << endl;
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
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

inline double position::slope()const {
	return y / x;
}

inline double position::slope(const position& other)const {
	return (other.y - y) / (other.x - x);
}

inline void position::move(double distX, double distY) {
	x += distX; y += distY;
	update(*this);
}
