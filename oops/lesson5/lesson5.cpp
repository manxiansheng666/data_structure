#include <iostream>

using namespace std;

class Messagehd
{
public:
    virtual void playsound() = 0;
};

class Message
{
protected:
    Messagehd* mhd;
public:
    Message(Messagehd* mhd) :mhd(mhd) {}
    virtual void login() = 0;
};

class Pcmhd :public Messagehd
{
private:
    void playsound() override
    {
        cout << "pc hardware" << endl;
    }
};

class Moblehd :public Messagehd
{
private:
    void playsound() override
    {
        cout << "moble hardware" << endl;
    }
};

class Lite :public Message
{
public:
    using Message::Message;
    void login() override
    {
        cout << "lite login" << endl;
        mhd->playsound();
    }
};

class Prefect :public Message
{
public:
    using Message::Message;
    void login() override
    {
        cout << "Prefect login" << endl;
        mhd->playsound();
    }
};

int main()
{
    Messagehd* mhd = new Pcmhd;
    Lite* lpc = new Lite(mhd);
    lpc->login();
    Prefect* ppc = new Prefect(mhd);
    ppc->login();
    return 0;
}
