#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class person
{
public:
    string name;
    string designation;
    virtual void setdata(string name, float salary) = 0;
    virtual void displaydata() = 0;
    virtual float bonus(float salary) = 0;
};

class admin : public person
{
    public:
    float salary;
    virtual void setdata(string name, float salary)
    {
        this->name=name;
        this->designation="Admin";
        this->salary=salary;
    }
    virtual void displaydata()
    {
        cout<<"The name of the admin is "<<name<<".\n";
        cout<<"His salary is."<<salary<<" .\n";
        cout<<"His bonus wil be 10% of his salary i.e."<<admin::bonus(salary)<<" .\n";

    }
    virtual float bonus(float salary){
        return salary*0.1;
    }
};

class account : public person
{
    public:
    float salary;
    string designation = "Accountant";
    void setdata(string name, float salary)
    {
        this->name=name;
        this->designation="Accountant";
        this->salary=salary;
    }
    void displaydata() 
    {
        cout<<"The name of the admin is "<<name<<".\n";
        cout<<"His salary is."<<salary<<" .\n";
        cout<<"His bonus wil be 7.5% of his salary i.e."<<account::bonus(salary)<<" .\n";
    }
    float bonus(float salary)
    {
        return salary*0.075;
    }
};

class master : public admin, public account
{
    public:
    //setting data of accountant and admin using the function of account and admin
    void setdata(string account_name, string admin_name, float account_salary, float admin_salary)
    {
        account::setdata(account_name,account_salary);
        admin::setdata(admin_name,admin_salary);
    }

    //diplaying data of accountant and admin using the function of account and admin
    void displaydata()
    {
        account::displaydata();
        admin::displaydata();
    }
};

int main()
{
    master master1;
    master1.setdata("Bilal Ahmed","Wamiq AKram",500000,600000);
    master1.displaydata();
}