#include <iostream>

using namespace std;

class Person
{
public:
	Person() :age(new int(0)) 
	{
		cout << "�޲ι���" << endl;
	} //�޲ι���

	Person(int age)	//�вι���
	{
		cout << "�вι���" << endl;
		this->age = new int(age);
		cout << this->age << endl;
	}

	Person(const Person& p)	//��������
	{
		cout << "��������" << endl;
		age = new int(*p.age);
	}

	Person(Person&& p)noexcept : age(p.age)	//�ƶ�����
	{
		cout << "�ƶ�����" << endl;
		p.age = nullptr;
	}

	Person& operator=(const Person& p)
	{
		cout << "������ֵ" << endl;
		if (&p == this)	return *this;
		*age = *p.age;
		return *this;
	}

	Person& operator=(Person&& p) noexcept
	{	
		cout << "�ƶ���ֵ" << endl;
		if (&p == this)	return *this;
		delete age;
		age = p.age;
		p.age = nullptr;
		return *this;
	}


	~Person()
	{
		cout << "��������" << endl;
		delete age;
	}

	int* age = nullptr;
};


Person test()
{
	Person p(10);
	return p;
}


int main()
{

	Person p1 = Person::Person();
	return 0;
}
