//Time���Ӧ��

#include "Date.hpp" //+����Date���Ӧ��

#include "Time.hpp"
#include <iostream>
#include<cmath>
using namespace std;

double parkingFee(double day,double mint); //����ͣ��ʱ���շ�,�����Ϊ������ʵ��ͣ��ʱ�������ܰ������ڲʱ���)�շ�
int main(){  
	Date arriveDate,leaveDate;
	Time arriveTime, leaveTime;
	double parkingTime, Fee;
	double parkingDate;

	cout << "Please set the arriveDate:";
	arriveDate.setDate();
	cout << "Please set the arrivetime(24 hour format):";
	arriveTime.setTime();

	cout << "Please set the leaveDate:";
	leaveDate.setDate();
	cout << "Please set leavetime(24 hour format):";
	leaveTime.setTime();

	parkingTime = leaveTime.diff(arriveTime);
	//�������ͣ�������ڲ�
	parkingDate = leaveDate.diff(arriveDate);

	Fee=parkingFee(parkingDate,parkingTime); //����ԭ�е��շѼ���

	cout << "The Parking time from ";
	arriveDate.showDate();
	cout << " ";
	arriveTime.showTime();
	cout << " to ";
	leaveDate.showDate();
	cout << " ";
	leaveTime.showTime();
	cout << endl;

	cout << "The parking fee is:" << Fee << endl;
	return   0;
}
double parkingFee(double day, double mint) {
	double ans = 0;
	//������ӹ���
	ans += min(30.0, 4 * mint);
	//�������ڹ���
	ans += day * 30;
	if (day > 365)return ans * 0.8;
	if (day > 30)return ans * 0.9;
	return ans;
}
