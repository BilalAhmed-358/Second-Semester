#include<iostream>
using namespace std;
float TAX_assistance();
int main()
{
	float t;
	t=TAX_assistance();
	cout << "Bill : $ " << t;
	
}
float TAX_assistance()
{
	int hr;
	float time_con;
	float bill=0;
	char choice;
	cout << "Enter the hourly rate" <<endl;
    cin >> hr;
    cout << " Enter the total consulting time in minutes" << endl;
    cin>> time_con;
    cout << "Do u have low income(less than 25,000)"<<endl << "Press L if yes and H if No"<<endl;;
    cin>>choice;
    if(choice=='L' || choice=='l')
    {
    	if(time_con<=30)
    	{
		bill= (time_con/60)*hr;
	}
    
		else if(time_con>30)
    {
		bill=hr*0.40*((time_con-30)/60);
	}
}
     else
	 {
	 	if(time_con<=20)
	 	{
	 		bill=hr*(time_con/60);
		 }
		 else if(time_con>20)
		 {
		 	bill=hr*70*((time_con-20)/60);
		 }
	 }
	
	 return bill;
}
