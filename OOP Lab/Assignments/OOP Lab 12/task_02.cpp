#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;


// class
// {

// };


int main()
{   
    string st1;
    ifstream in("01.txt");
    ofstream out("02.txt");
    while (!in.eof())
    {
        getline(in,st1);
        out<<st1;
    }
    in.close();
    out.close();
    cout<<"Contents copied successfully\n";
    
    
}