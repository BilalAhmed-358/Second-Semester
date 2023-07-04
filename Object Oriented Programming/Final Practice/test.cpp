#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

template <class T>
class list
{
public:
    int no_of_elements;
    T *array;
    list(int no_of_elements)
    {
        this->no_of_elements = no_of_elements;
        array = new T[no_of_elements];
    }
    void put_value()
    {
        for (int i = 0; i < no_of_elements; i++)
        {
            cout << "Enter the value of element nubmer " << i + 1 << endl;
            cin >> array[i];
        }
    }
    void show_values()
    {
        cout << "The values of the elements stored in the array are as follows\n";
        for (int i = 0; i < no_of_elements; i++)
        {
            cout << array[i]<<endl;
        }
    }
    void sort_values()
    {
        cout << "Values before sorting\n";
        show_values();
        T temp;
        for (int i = 0; i < no_of_elements; i++)
        {
            for (int j = i + 1; j < no_of_elements; j++)
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
    list <float> obj(5);
    obj.put_value();
    obj.show_values();
    obj.sort_values();
}