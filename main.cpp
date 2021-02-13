#include <iostream>
#include <string>
using namespace std;

/*
    Bridge is a structural design pattern that lets you split a large
    class or a set of closely related classes into two separate
    hierarchies—abstraction and implementation—which can be
    developed independently of each other.

    remember about composition!
*/
class Amplifier
{
    string input;
    string _id;

public:
    Amplifier(string id) : _id(id) {}
    void SetInput(string in)
    {
        this->input = in;
    };
    void showIn()
    {
        cout << this->_id << " Amplifier Input: " << this->input << endl;
    }
};

class Orange : public Amplifier
{
public:
    Orange(string id) : Amplifier(id) {}
};
class Marshall : public Amplifier
{
public:
    Marshall(string id) : Amplifier(id) {}
};

// this is bridge
class InputDevices
{
protected:
    Amplifier *amp;

public:
    virtual void sendInput() = 0;
    void setAmplifier(Amplifier *amp)
    {
        this->amp = amp;
    }
    void showIn()
    {
        this->amp->showIn();
    }
};

class Guitar : public InputDevices
{
public:
    void sendInput() override
    {
        this->amp->SetInput("Jreeng");
    }
};

class Microphone : public InputDevices
{
public:
    void sendInput() override
    {
        this->amp->SetInput("Tes");
    }
};

class Person
{
    InputDevices *devices;

public:
    Person(InputDevices *in) : devices(in) {}
    void show()
    {
        if (devices != NULL)
        {
            this->devices->showIn();
        }
        else
            cout << "you dont have devices" << endl;
    }
};

int main()
{
    InputDevices *in = new Microphone;
    // InputDevices *in = new Guitar;
    in->setAmplifier(new Marshall("marshall"));
    in->sendInput();
    Person p(in);
    p.show();
}