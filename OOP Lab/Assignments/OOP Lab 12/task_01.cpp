#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

// class
// {

// };
int strlen(string st1)
{
    int i;
    for (i = 0; st1[i] != '\0'; i++)
    {
    }

    return i;
}
void Write_in_file()
{
    string st1;
    cout << "Enter a sentence\n";
    getline(cin, st1);
    cout << "The length of the string you entered is " << strlen(st1) << ".\n";
    ofstream out("01.txt");
    out << st1 << "\n";
    out.close();
    cout << "Text entered in file successfully.\n";
}
void Read_from_file()
{
    string st1;
    cout << "The contents read from the file are as follows\n";
    ifstream in("01.txt");
    while (in)
    {
        getline(in, st1);
        cout << st1;
    }
}
int main()
{
    Write_in_file();
    Read_from_file();
}