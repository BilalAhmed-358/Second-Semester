#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
template <typename T>
void swaP(T &n1, T &n2)
{
    T temp; // here we are making temporary variable or swapping
    temp = n1;
    n1 = n2;
    n2 = temp;
}

int main()
{   cout<<"Dealing with characters first\n";
    char ch1 = 'A', ch2 = 'B';
    cout << "Values before swapping\n";
    cout << "Ch1= " << ch1 << " Ch2= " << ch2 << ".\n";
    swaP(ch1, ch2);
    cout << "Values after swapping\n";
    cout << "Ch1= " << ch1 << " Ch2= " << ch2 << ".\n";
    cout<<endl<<endl;
    cout<<"Dealing with integers\n";
    int int1 = 2, int2 = 3;
    cout << "Values before swapping\n";
    cout << "int1= " << int1 << " int2= " << int2 << ".\n";
    swaP(int1, int2);
    cout << "Values after swapping\n";
    cout << "int1= " << int1 << " int2= " << int2 << ".\n";
    cout<<endl<<endl;
    cout<<"Dealing with Doubles\n";
    double double1 = 10.99, double2 = 5.85;
    cout << "Values before swapping\n";
    cout << "double1= " << double1 << " double2= " << double2 << ".\n";
    swaP(double1, double2);
    cout << "Values after swapping\n";
    cout << "double1= " << double1 << " double2= " << double2 << ".\n";

    // cout << "int1= " << int1 << " int2= " << int2 << ".\n";
}