#include<iostream>
using namespace std;

class vector
{
    public:
    int x,y;
    vector(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    vector()
    {
        this->x=0;
        this->y=0;
    }
    void Display()
    {
        cout<<"\nThe value of x is "<<x<<".\n";
        cout<<"The value of y is "<<y<<".\n";
    }
    vector operator--()
    {   
        x=x*4;
        y=y*4;
    }
    vector operator--(int)
    {
        x=x/4;
        y=y/4;
    }
};


int main()
{
    vector v1(5,6);
    v1.Display();
    --v1;
    cout<<"\nAfter Multiplication by 4";
    v1.Display();

    vector v2(12,20);
    v2.Display();
    v2--;
    cout<<"\nAfter Division by 4";
    v2.Display();


    
}