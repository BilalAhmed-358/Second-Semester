#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Car
{
public:
    string model;
    float price;
    virtual void set_Price(float price) = 0;
};

class Company:public Car
{
    public:
    string Company_name;
    Company(string Company_name, string model)
    {
        this->Company_name=Company_name;
        this->model=model;
    }
    void set_Price(float price)
    {
        this->price=price;
    }
    void Display_info()
    {
        cout<<"\nThe company name is "<<Company_name<<".\n";
        cout<<"The model "<<Company_name<<" Company manufactures is "<<model<<".\n";
        cout<<"The price of the model is "<<price<<" Rupees only/-.";
    }
};

class Color: public Car
{
    public:
    string color;
    Color(string color, string model)
    {
        this->color=color;
        this->model=model;
    }
    void set_Price(float price)
    {
        this->price=price;
    }
    void Display_info()
    {
        cout<<"\n\nThe model of the car is "<<model<<".\n";
        cout<<"The price of the car is "<<price<<".\n";
        cout<<"The color of the car is"<<color<<".\n";
    }

};


int main()
{
    Company Company1("Ford Ltd","Hummer V");
    Company1.set_Price(5000);
    Company1.Display_info();
    Color ColoredCar1("Red","Model S");
    ColoredCar1.set_Price(180000);
    ColoredCar1.Display_info();
}