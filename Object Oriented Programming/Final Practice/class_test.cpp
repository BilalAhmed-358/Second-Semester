#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class A
{
public:
    int x;
    A(int x)
    {
        this->x = x;
    }
};

class B : protected A
{
public:
    B(int x) : A(x)
    {
    }
};

class C : protected B
{
public:
    C(int x) : B(x)
    {
    }
    void display()
    {
        cout << "The value of x is " << x << "." << endl;
    }
};

int main()
{
    C cobj(9);
    cobj.display();
}