#include<iostream>
using namespace std;


class shape
{
    public:
    float length;
    float width;
    float area;
    shape(float length, float width)
    {
        this->length=length;
        this->width=width;
        area=width*length;
    }
    shape()
    {
        this->length=0;
        this->width=0;
        area=width*length;
    }
    float Area(float length, float width)
    {
        this->length=length;
        this->width=width;
        area =width*length;
        return area;
    }
    float Area()
    {
        return area;
    }
    shape operator +(shape obj)
    {
        shape temp;
        temp.area=area+obj.area;

        
        return temp;
    }
};

int main()
{
    shape s1(5,7);
    cout<<"The area of shape 1 is "<<s1.Area()<<"cm^2.\n";
    shape s2(4,10);
    cout<<"The area of shape 2 is "<<s2.Area()<<"cm^2.\n";
    shape s3;
    s3=s1+s2;
    cout<<"The area of shape 3 (which is the sum of shape 1 and shape 2) is "<<s3.Area()<<"cm^2.\n";
}