#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

// class
// {

// };

int main()
{
    ofstream out;
    out.open("Text.txt");
    string st1;
    cout<<"Enter the string you wanna write in the file\n";
    getline(cin,st1);
    out<<st1;
    out.close();
    ifstream in;
    in.open("Text.txt");
    string st2;
    getline(in,st2);
    cout<<"The data stored in the file is as follows\n"<<st2<<endl;
    in.close();
}