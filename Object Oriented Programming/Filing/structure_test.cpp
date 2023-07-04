#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

int main()
{

    struct student
    {
        string name;
        int Rollno;
        string ID;
    };
    struct student student1;
    student1.name="Bilal";
    student1.ID="20k-0183";
    student1.Rollno=56;
    ofstream out;
    out.open("Student Data.txt");
    

    
}