#include <iostream>

using namespace std;

class Operation
{
public:
    virtual int operate(int,int) = 0;
    virtual ~Operation() {};
};


//策略模式 strategy
class Calculator
{
public:
    void run(Operation* op)
    {
        cout << op->operate(a,b) << endl;
        delete op;
    }

private:
    int a = 10;
    int b = 20;
};

class AddOperation :public Operation
{
private:
    int operate(int a, int b) override
    {
        return a + b;
    }
    ~AddOperation()
    {
        cout << __FUNCTION__ << endl;
    }
};

class SubOperation :public Operation
{
private:
    int operate(int a, int b) override
    {
        return a - b;
    }
    ~SubOperation()
    {
        cout << __FUNCTION__ << endl;
    }
};


int main()
{
    Calculator c;
    c.run(new AddOperation);
    c.run(new SubOperation);
}

