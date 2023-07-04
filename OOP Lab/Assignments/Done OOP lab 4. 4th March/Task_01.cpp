#include <iostream>
using namespace std;
#include <math.h>

class circle
{
public:
float radius;
    circle()
    {

        
        cout << "Enter the radius of the circle (in centimeters)" << endl;
        cin >> radius;
    }
    void getArea()
    {
        cout << "The area of the circle is " << 3.142 * radius * radius << " cm^2."<<endl;
    }
    void get_Perimeter()
    {
        cout<<"The perimeter(circumference) of the circle is "<<radius*2*3.142<<" cm.";
    }
};

int main()
{
    circle cirlce_01;
    cirlce_01.getArea();
    cirlce_01.get_Perimeter();
}