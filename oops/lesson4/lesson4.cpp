#include <iostream>

using namespace std;

class Stream
{
public:
    virtual void read() = 0;
    virtual void write() = 0;
    virtual ~Stream() {};


};


class Filestream :public Stream
{
private:
    void read() override
    {
        cout << "fileread" << endl;
    }
    void write() override
    {
        cout << "filewrite" << endl;
    }
};


class Decorator :public Stream
{
public:
    Decorator(Stream* s) :stream(s) {}
protected:
    Stream* stream;
};

class Secret :public Decorator
{
public:
    Secret(Stream* s) :Decorator(s) {}
    void read()
    {
        cout << "secret decorator read" << endl;
        stream->read();
    }
    void write()
    {
        cout << "secret decorator write" << endl;
        stream->write();
    }
};

class Buffer :public Decorator
{
public:
    Buffer(Stream* s) :Decorator(s) {}
    void read()
    {
        cout << "Buffer decorator read" << endl;
        stream->read();
    }
    void write()
    {
        cout << "Buffer decorator write" << endl;
        stream->write();
    }
};

int main()
{
    Filestream* file = new Filestream;
    Secret* s1 = new Secret(file);
    Buffer* b1 = new Buffer(s1);

    b1->read();//执行结果太神奇了

    return 0;
}

