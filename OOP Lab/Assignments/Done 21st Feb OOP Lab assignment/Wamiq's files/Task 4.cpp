#include<iostream>
#include<math.h>
using namespace std;
float radius(float x1,float y1,float x2,float y2)
{
	float rad;
	cout << "Enter the centre points of the circle" <<endl;
	cin >> x1 >> y1 ;
	cout << " Enter another point that lies on the circle " <<endl;
	cin >> x2 >> y2;
	rad=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return rad;
}
float diameter(float rad)
{
	float diameter;
	diameter=rad*2;
	return diameter;
}
float Circumference(float rad)
{
	float circum;
	circum=2*3.1416*rad;
	return circum;
}
float Area(float rad)
{
	float area;
	area=3.1416*pow(rad,2);
	return area;
}
int main()
{
	int x1,y1,x2,y2;
	float r=radius(x1,y1,x2,y2);
	

	cout << "Circle Radius        : " << r<<endl;
	
	cout << "Circle Diameter      : " << diameter(r) <<endl;
	cout << "Circle Circumference : " <<  Circumference(r)<<endl;
	cout << "Circle Area          : " <<  Area(r)<<endl;
	
}
