#include<iostream>
#include<stdio.h>
using namespace std;
void metersAndCentTofeetAndInches();
void feetAndInchesToMetersAndCent();
void Select();

int main()
{
Select();
}
void Select()
{
	int choice;
	cout << "What do u want to convert" << endl;
	cout << "1- Convert feet and inches to metre and centimeters" <<endl;
	cout << "2- Convert metre and centimeters to feet and inches" <<endl;
	cin >> choice;
	if(choice==1)
	{
		feetAndInchesToMetersAndCent();
		
	}
	else
	{
		metersAndCentTofeetAndInches();
	}
}
void feetAndInchesToMetersAndCent()
{
	int choice;
	char ch;
	float feet,inches,meters,cmeters;
	cout << "SELECT CONVERSION" << endl;
	cout << "1- Feet to metres" <<endl;
	cout << "2- Inches to Centimetres" <<endl;
	cin >> choice;
	if(choice==1)
	{
		cout << "Enter the value in Feet" << endl;
		cin >> feet;
		meters=feet*0.3048;
		cout << " Value in Meters : " << meters <<endl;
		
	}
	else if(choice==2)
	{
	cout << "Enter the value in Inches" << endl;
	cin >> inches;
	cmeters=inches*2.54;
	cout << " Value in centimeters : " << cmeters <<endl;}
	cout << "Do u want to continue (Y/N)" <<endl;
	cin >> ch;
	if(ch=='Y' || ch=='y')
	{
		Select();
	}
	
}
void metersAndCentTofeetAndInches()
{
	int choice;
	char ch;
	float feet,inches,meters,cmeters;
	cout << "SELECT CONVERSION" << endl;
	cout << "1- Meters to feet" <<endl;
	cout << "2- Centimeters to Inches" <<endl;
	cin >> choice;
	if(choice==1)
	{
		cout << "Enter the value in Meters" << endl;
		cin >> meters;
		feet=meters*3.28084;
		cout << " Value in feet : " << feet <<endl;
		
	}
	else if(choice==2)
	{
	cout << "Enter the value in Centimeters" << endl;
	cin >> cmeters;
	inches=cmeters*0.393701;
	cout << " Value in Inches : " << inches <<endl;}
	cout << "Do u want to continue (Y/N)" <<endl;
	cin >> ch;
	if(ch=='Y' || ch=='y')
	{
		Select();
	}
	
	
	
}
