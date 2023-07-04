#include <iostream>
using namespace std;


class printclass;
class perimeter
{
    friend class printclass;
    float length, breadth;
    float perimeter_val;

public:
    void perimeter_calculator(float length, float breadth)
    {
        
        perimeter_val = (2 * length) + (2 * breadth);
        
    }
    perimeter(float length, float breadth)
    {
        this->breadth = breadth;
        this->length = length;
        perimeter_calculator(breadth,length);
    }
};

class printclass
{
    public:
    void Display(perimeter ob)
    {
         cout<<"The perimeter of the shape is "<<ob.perimeter_val;
    }

};

int main()
{
    perimeter shape1(5,4);
    printclass print_for_shape_1;
    print_for_shape_1.Display(shape1);
}