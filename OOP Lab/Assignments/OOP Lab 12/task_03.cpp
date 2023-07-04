#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;


class person
{
    public:
    string name;
    int age;
    person(string name, int age)
    {
        this->name=name;
        this->age=age;
    }
    person()
    {
        this->name="abc";
        this->age=0;
    }
    void Display()
    {
        cout<<"The name of the person is "<<name<<".\n";
        cout<<"The age of the person is "<<age<<".\n";
        
    }
};


int main()
{
    person p1("Bilal Ahmed Khan",18);
    // p1.Display();
    ofstream out("03i.bin");
    out.write((char*)&p1,sizeof(p1));
    out.close();
    ifstream in("03i.bin");
    in.read((char*)&p1,sizeof(p1));
    p1.Display();
    in.close();
    return 0;
}