#pragma once
//DateTime������,��Ϊ�γ̲����е�clock��
class  DateTime {
public:
    void showDateTime();
    void setDateTime();
    double diff(const DateTime& T); //ע�ⳣ���ö��β�T��Լ��
private:
    long normalize() const; //ע��const�ڴ˵ı�Ҫ��
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};
