#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std; 
int main() {
    // ��ʼ�����������
    srand(static_cast<unsigned int>(time(nullptr)));

    // ��һ������
    int data1[10];
    for (int i = 0; i < 10; ++i) 
	{
        data1[i] = rand() % 100; // ���跶Χ��0-99
    }

    // д��data1.txt
    ofstream file1("data1.txt");
    for (int i = 0; i < 10; ++i) 
	{
        file1 << data1[i] << endl;
    }
    file1.close();

    // �ڶ�������
    int data2[10];
    for (int i = 0; i < 10; ++i) 
	{
        data2[i] = rand() % 100;
    }

    // д��data2.txt
    ofstream file2("data2.txt");
    for (int i = 0; i < 10; ++i) 
	{
        file2 << data2[i] << endl;
    }
    file2.close();

    return 0;
}
