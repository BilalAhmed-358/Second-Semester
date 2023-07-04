#include<iostream>
using namespace std;
void regular_service()
{
	int acc_no,min;
	float bill;
	cout << "Enter Your account number" << endl;
	cin >> acc_no;
	cout << " How many minutes u have used" <<endl;
	cin >> min;
	cout << "Account no : " << acc_no <<endl;
	cout << "Minutes used : " <<min<<endl;
	if(min <=50)
	{
		
		cout << "Your bill is : $ 10";
	}
	else if(min>50)
	{
	bill= 10+ (50+(min-50)*0.20);
    }
    
    
	cout << "Your Bill is : $ " << bill <<endl;
	
}
void premium_service()
{
	int acc_no,min1,min2;
	float bill1=0,bill2=0,bill=0;
	cout << "Enter Your account number" << endl;
	cin >> acc_no;
	cout << " How many minutes u have used in day" <<endl;
	cin >> min1;
	

	if(min1<=75)
	{
		bill1=25;
		
	}
	else if( min1 >75)
	{
		bill1= 25 +(75+(min1-75)*0.10);
	}
	cout << "How many minutes u have used in night" <<endl;
	cin >> min2;
	if(min2<=100)
	{
		bill2=25;
		
	}
	else if( min2 >100)
	{
		bill2= 25 +(100+(min2-100)*0.05);
	}
	cout << "Account no : " << acc_no <<endl;
	cout << "Minutes used : " <<min1+min2<<endl;
	bill=bill1+bill2;
	cout << "Bill : $ " << bill <<endl;
}
int main()
{
	char choice;
	cout << "Which service are u using" << endl << "1- R for regular service" <<endl<<"2- P for premium service" << endl;
	
	cin >> choice;
	if(choice=='R' || choice=='r')
	{
		regular_service();
		
	}
	else if(choice=='P' || choice=='p')
	{
		premium_service();
	}
	else
	cout <<"Invalid choice" <<endl;
	
}
