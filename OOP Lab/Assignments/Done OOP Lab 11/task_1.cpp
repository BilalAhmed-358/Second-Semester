#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
class Employee
{
public:
    string Name, Code;

    Employee(string Name, string Code)
    {
        this->Name = Name;
        this->Code = Code;
    }
};
class Consultant : virtual public Employee
{
public:
    int years_of_experience;

    Consultant(int years_of_experience, string Name, string Code) : Employee(Name, Code)
    {
        this->years_of_experience = years_of_experience;
    }
};
class Manager : virtual public Employee
{
public:
    int NumOfTeams;

    Manager(int NumOfTeams, string Name, string Code) : Employee(Name, Code)
    {
        this->NumOfTeams = NumOfTeams;
    }
};
class ConsultantManager : public Manager, public Consultant
{
public:
    ConsultantManager(string Name, string Code, int years_of_experience, int NumOfTeams) : Manager(NumOfTeams, Name, Code), Consultant(years_of_experience, Name, Code), Employee(Name, Code)
    {
    }
    void Display()
    {
        cout << "The name of the Consultant Manager is " << Name << " .\n";
        cout << "His/Her code is " << Code << " .\n";
        cout << "He/She has " << years_of_experience << " years of experience.\n";
        cout << "He has " << NumOfTeams << " teams working for him.\n";
    }
};
int main()
{
    ConsultantManager obj("Bilal Ahmed Khan", "1234", 5, 2);
    obj.Display();
    return 0;
}
