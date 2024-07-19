#include "DateTime.h"
#include<cmath>
#include<iostream>
using namespace std;
double parkingFee(double hour) {
	//��ȡ����
	int day = ((int)(floor(hour))) / (24);
	hour -= day * 24;
	double ans = 0;
	//������ӹ���
	ans += min(30.0, 4 * hour);
	//�������ڹ���
	ans += day * 30;
	if (day > 365)return ans * 0.8;
	if (day > 30)return ans * 0.9;
	return ans;
}
int main() {
	DateTime a, b;
	cout << "�����뿪ʼʱ�䣺";
	a.setDateTime();
	cout << "�������뿪ʱ�䣺";
	b.setDateTime();
	double mints = b.diff(a);
	cout << "��ֹʱ�䣺";
	a.showDateTime();
	cout<< "��";
	b.showDateTime();
	cout<< endl;
	cout << "���ã�" << parkingFee(mints);
	return 0;
}