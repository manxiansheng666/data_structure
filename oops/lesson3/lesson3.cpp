#include <iostream>
#include <list>

using namespace std;

//观察者模式
class Iobsersver
{
public:
    virtual void obsersve(int i,int num) = 0;
    virtual ~Iobsersver() {};
};


class Person
{
public:
    Person() = default;
    Person(int num) :num(num) {};

    void run()
    {
        for (int i = 0; i < num; i++)
        {
//            cout << "running!\r\n" << endl;
            observer(i,num);
        }
    }

    void add_ob(Iobsersver* ob)
    {
        observers.push_back(ob);
    }

    void remove_ob(Iobsersver* ob)
    {
        observers.remove(ob);
    }

private:
    int num = 0;
    list<Iobsersver*> observers;
    void observer(int i,int num)
    {
        for (const auto& ob : observers)
        {
            ob->obsersve(i,num);
        }
    }
};

class Student
{
public:
    void print_age()
    {
        cout << age << endl;
    }
private:
    int age = 10;
};

class ob1 :public Student, public Iobsersver
{
private:

    virtual void obsersve(int i, int num) override
    {
        cout << '.';
    }
};

class ob2 :public Student, public Iobsersver
{
private:

    virtual void obsersve(int i, int num) override
    {
        cout << '+';
    }
};

class ob3 :public Student, public Iobsersver
{
private:

    virtual void obsersve(int i, int num) override
    {
        cout << i << '*';
    }
};

int main()
{
    Person p(10);
    ob1 o1;
    ob2 o2;
    ob3 o3;
    o1.print_age();
    p.add_ob(&o1);
    p.add_ob(&o2);
    p.add_ob(&o3);
    p.remove_ob(&o2);
    p.run();
}
