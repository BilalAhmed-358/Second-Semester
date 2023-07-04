#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

template <class T,int size>
class list
{
public:
    // int size;
    T array[size];
    // list(int size)
    // {
    //     this->size = size;
    //     array = new T[size];
    // }
    void put_value()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the value of element nubmer " << i + 1 << endl;
            cin >> array[i];
        }
    }
    void show_values()
    {
        cout << "The values of the elements stored in the array are as follows\n";
        for (int i = 0; i < size; i++)
        {
            cout << array[i]<<endl;
        }
    }
    void sort_values()
    {
        cout << "Values before sorting\n";
        show_values();
        T temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (array[i] > array[j])
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        cout<<"values after sorting\n";
        show_values();
    }
};

int main()
{
    list <int,5> obj;
    obj.put_value();
    obj.show_values();
    obj.sort_values();
}