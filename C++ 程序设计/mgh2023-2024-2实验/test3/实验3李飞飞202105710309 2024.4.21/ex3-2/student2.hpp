//student2.hpp
class Student {
public:
	Student();
	Student(const char* n);
	Student(const Student& other);
	void operator=(const Student& right);
	//Student& operator=(const Student& right);
	~Student();
	char* GetName(); //��ȡ����
	void  ChangeName(const char* n); //����
private:
	char* name;
};
