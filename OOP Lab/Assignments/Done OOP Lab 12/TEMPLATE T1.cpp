#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

template <typename T>
void Swap(T &n1, T &n2)
{   
        T temp; // here we are making temporary variable or swapping 
        temp = n1;
        n1 = n2;
        n2 = temp;
}

int main()
{
        int in1 = 10, in2 = 20; // initializing integers.
        
        float fl1 = 9.5, fl2 = 2.5; // initialing floats
        
        char char1 = 'Z', char2 = 'B'; // initialing charcter

        cout << "BEFORE SWAPPING NUMBERS DISPLAYS AS FOLLOW: ";
        cout << "\nINTEGERS:"<<endl;
        cout   << "in1 = " << in1;
		cout   << "\nin2 = " << in2;
		cout   << "\nFLOATS :"<<endl;
        cout   << "\nfl1 = " << fl1; 
		cout   << "\nfl2 = " << fl2;
		cout   <<"\nCHARACTERS :"<<endl;;
        cout   << "\nchar1 = " << char1; 
		cout   << "\nchar2 = " << char2;
//swap function
        Swap(in1, in2);
        Swap(fl1, fl2);
        Swap(char1, char2);

        cout << "\n\nAFTER PASSING DATA TO TEMPLATE FUNCTION....\n";
        cout << "\nINTEGERS:"<<endl;
        cout << "in1 = " << in1 << "\nin2 = " << in2;
        cout << "\nFLOATS :"<<endl;
        cout << "\nfl1 = " << fl1 << "\nfl2 = " << fl2;
        cout << "\nCHARACTERS:"<<endl;
        cout << "\nchar1 = " << char1 << "\nchar2 = " << char2;

        return 0;
}
