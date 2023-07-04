#include<iostream>
using namespace std;
float  residentional()
{   
    float billpf= 4.50,BSF = 20.50,PC =7.5,total_fee;
    int channels,acc;
		cout<< "How many channels do u want" << endl;
		cin >> channels;
		cout << "Enter account no" <<endl;
        cin >> acc;
	    cout << "Businessman's account no :" <<acc<< endl;
		total_fee= billpf +BSF + channels* PC;
		return total_fee;
}
float business()
{
	int channels,acc;
	float billpf= 15.00,BSFA=5.00,BSF10 =75.00,PC =50.00,total_fee;
	cout<< "How many connection do you have" << endl;
	cin >> channels;
	cout << "Enter account no" <<endl;
	cin >> acc;
	cout << "Resident account no :" << acc<< endl;
	if(channels <=10)
	{
		total_fee= channels*BSF10;
		return total_fee;
	}
	else
	
	total_fee = billpf+ BSF10 + ((channels-10)*BSFA)+(PC*channels);
	return total_fee;
}
int main()
{   char code;
    float r,b;
	cout<< "Enter your Costumer code" << endl << "R for resident" << endl << "B for business"<< endl;
	cin >> code;
    if(code== 'R')
	 {
	 r=residentional();
	 cout << "Resident total fee : $"<< r << endl;
     }
	 else if(code=='B')
	 {
	 b=business();
	 cout << "Business man total fee : $" << b << endl;
	 }
	 else
	 cout <<"Invalid choice";
	 
}

