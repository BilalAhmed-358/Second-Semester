#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

// class
// {

// };
template <class T> T divide(T a, T b)
{
    T c;
    cout<<"The type of c is "<<sizeof(c)<<endl;
    try
    {
        if (b == 0)
            throw b;

        c = a / b;
        return c;
    }
    catch (int x)
    {
        cout << "You are trying to divide a nubmer with 0, which is not possible\n";
        exit(0);
    }

}

int main()
{
    int a,b;
    cout<<"Enter the value of a\n";fflush(stdin);
    cin>>a;
    cout<<"Enter the value of b\n";fflush(stdin);

    cin>>b;
    cout<<divide(a,b)<<endl;
}