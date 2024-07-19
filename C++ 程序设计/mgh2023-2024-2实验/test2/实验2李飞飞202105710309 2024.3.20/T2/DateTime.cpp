//DateTime��ʵ��
#include "DateTime.h"
#include <iostream>
using namespace std;
int mp1[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
void DateTime::showDateTime() {
    cout << year << ":" << month << ":" << day;
    cout << " ";
    cout << hour << ":" << minute << ":" << second;
}

void DateTime::setDateTime() {
    do {
        cin >> year >> month >> day;
    } while (year < 0 || year>2024 || month < 0 || month>12 || day<0 ||
        day>((mp1[month] + (month == 2 && (year % 400 == 0 || (year % 4 == 0 && (year % 100))) ? 0 : 1))));
    do {
        cin >> hour >> minute >> second;
    } while (hour < 0 || hour>24 || minute < 0 || minute>59 || second < 0 || second>59);
}

double DateTime::diff(const DateTime& T) {
    //���һСʱ
    long d = normalize() - T.normalize();
    if (d % (24 * 60) > 60)d -= 60;
    if (d < 0) return 0;
    int h = d / 60, m = d % 60;
    if (m < 15) return h;
    if (m >= 15 && m < 30) return h + 0.5;
    if (m >= 30 && m < 60) return h + 1;
}

long DateTime::normalize()const {
    long totalDays = day; // �������ӵ���������
    // ������ݺ��·ݶ�Ӧ������
    for (int i = 1; i < month; ++i) {
        totalDays += mp1[i];
    }
    // ��������겢�ҵ�ǰ�·ݴ���2�£���2�¶��һ��
    if (month > 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
        totalDays += 1;
    }
    // ������ݶ�Ӧ������
    totalDays += (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    return totalDays*24*60+hour*60+minute;
}
