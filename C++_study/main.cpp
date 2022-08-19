#include <iostream>
#include <string>
using namespace std;

class Person
{
	
public:
	Person(int age) :age(age) {}
	int age;
};


class Student :public Person
{
public:
	using Person :: Person;
};

int main()
{
	Student s(10);


	return 0;
}