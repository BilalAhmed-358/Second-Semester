#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

// class Ofstream:public ofstream
// {
// public:

// };

class Student
{
public:
    string name;
    string roll_no;
    string id;
    Student(string name, string roll_no, string id)
    {
        this->name = name;
        this->roll_no = roll_no;
        this->id = id;
    }
    Student()
    {
        this->name = "null";
        this->roll_no = "null";
        this->id = "null";
    }
    void operator<<(Student obj)
    {
        ofstream out("student_data.txt");
        out.write((char *)this, sizeof(this));
    }
    void operator>>(Student obj)
    {
        ifstream in("student_data.txt");
        in.read((char *)this, sizeof(this));fflush(stdin);
        // cout<<name<<endl;
        cout<<"The Roll No of the student is "<<this->roll_no<<endl;
        cout<<"The name of the student is "<<this->name<<endl;
        cout<<"The id of the student is "<<this->id<<endl;
    }
};

int main()
{
    Student st1("Bilal Ahmed", "20k-0183", "567");
    st1<<st1;
    st1>>st1;
}