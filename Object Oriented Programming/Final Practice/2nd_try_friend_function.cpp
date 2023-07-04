#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
class B;
class frand
{
public:
    void display(B obj);
};
class B
{
public:
    int x, y;
    B(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    B()
    {
        this->x = 0;
        this->y = 0;
    }
    friend void frand::display(B obj);
};

void frand::display(B obj)
{
    cout << "The values of the objects of Class B are as follows\n";
    cout << "The value of x of the B class object is " << obj.x << "." << endl;
    cout << "The value of x of the B class object is " << obj.y << "." << endl;
}

int main()
{
    B obB(3, 4);
    frand fr1;
    fr1.display(obB);
}