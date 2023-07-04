#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    string student_name;
    float marks[5];
    float sum;
    cout<<"Enter the name of the student"<<endl;
    getline(cin, student_name);
    int i;
    cout<<"Enter the marks in 5 subjects of the student"<<endl;
    for ( i = 0; i < 5; i++)
    {
        cin>>marks[i];
    }
    cout<<fixed;
    cout<<setprecision(2);
    cout<<endl<<"Student Name: "<<student_name<<endl;
    cout<<"Test Scores: ";
    for ( i = 0; i < 5; i++)
    {
        cout<<marks[i]<<"   " ;
        sum+=marks[i];
    }
    cout<<endl<<"Average Test Score: "<< sum/5<<endl;
    
    
}