#include <iostream>

using namespace std;

class Person
{
public:
	Person() :age(new int(0)) 
	{
		cout << "无参构造" << endl;
	} //无参构造

	Person(int age)	//有参构造
	{
		cout << "有参构造" << endl;
		this->age = new int(age);
		cout << this->age << endl;
	}

	Person(const Person& p)	//拷贝构造
	{
		cout << "拷贝构造" << endl;
		age = new int(*p.age);
	}

	Person(Person&& p)noexcept : age(p.age)	//移动构造
	{
		cout << "移动构造" << endl;
		p.age = nullptr;
	}

	Person& operator=(const Person& p)
	{
		cout << "拷贝赋值" << endl;
		if (&p == this)	return *this;
		*age = *p.age;
		return *this;
	}

	Person& operator=(Person&& p) noexcept
	{	
		cout << "移动赋值" << endl;
		if (&p == this)	return *this;
		delete age;
		age = p.age;
		p.age = nullptr;
		return *this;
	}


	~Person()
	{
		cout << "析构函数" << endl;
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
