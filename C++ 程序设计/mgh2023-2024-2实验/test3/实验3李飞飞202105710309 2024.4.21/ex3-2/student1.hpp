//student1.hpp
class Student {
public:
	Student();//��������Ϊʲô��ȱʡ�޲ι���?
	Student(const char* n);
	//Student(const Student & other);
	//Student& operator=(const Student& right);  
	//~Student( );
	const char* GetName();  //��ȡ����
	void  ChangeName(const char* n);  //����
private:
	char name[20];
};
