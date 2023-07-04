#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Area
{
public:
    string shape_name;
    virtual void getArea() = 0;
};

class Rectangle
{
public:
    float length;
    float width;
    float getArea(float length, float width)
    {
        return length * width;
    }
    float getArea()
    {
        return length * width;
    }
    Rectangle(float length, float width)
    {
        this->length = length;
        this->width = width;
    }
};

class Triangle
{
public:
    float breadth;
    float length;
    Triangle(float breadth, float length)
    {
        this->breadth = breadth;
        this->length = length;
    }
    float getArea(float length, float breadth)
    {
        return 0.5 * breadth * length;
    }
    float getArea()
    {
        return 0.5 * breadth * length;
    }
};

int main()
{
    Rectangle Rectangle1(4,5);
    cout<<"The area of Rectangle 1 is "<<Rectangle1.getArea()<<".\n";
    Triangle Triangle1(5,10);
    cout<<"The area of Triangle 1 is "<<Triangle1.getArea()<<".\n";
}