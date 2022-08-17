#include <iostream>

using namespace std;

//template
class Person
{
public:
    void run()
    {
        step1();
        step2();
        step3();
    }
    virtual ~Person() {}

private:
    void step1()
    {
        cout << __FUNCTION__ << endl;
    }

protected:
    virtual void step2() = 0;
    virtual void step3() = 0;
};


class Student :public Person
{
private:
    void step2() override
    {
        cout << __FUNCTION__ << endl;
    }

    void step3() override
    {
        cout << __FUNCTION__ << endl;
    }
};


int main()
{
    Person* p = new Student;
    p->run();
}
