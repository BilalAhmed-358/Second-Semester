#include <iostream>

using namespace std;

class A; // forward declaration of A needed by B

class B
{
public:
    void display(A obj); //no body declared
};

class A
{
    int x;

public:
    A()
    {
        x = 4;
    }
    friend void B::display(A obj);
};



int main()
{
    A a;
    B b;
    b.display(a);
    return 0;
}