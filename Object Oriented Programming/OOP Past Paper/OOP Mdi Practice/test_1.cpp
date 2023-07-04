#include <iostream>
#include <stdio.h>
#define N 5
using namespace std;

class Test
{
    int x, y;

public:
    Test(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Test(){};

    void print()
    {
        cout << x << " " << y << endl;
    }
};

int main()
{
    int number_of_objects;
    cout << "Enter the nubmer of object you want to create\n";
    cin >> number_of_objects;

    Test *arr = new Test[number_of_objects];
    for (int i = 0; i < number_of_objects; i++)
    {
        arr[i] = Test(i, i + 1);
    }
    for (int i = 0; i < number_of_objects; i++)
    {
        arr[i].print();
    }
    
}