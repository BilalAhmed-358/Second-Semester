#include <iostream>
#include <cmath>
#include <cctype>
#include<windows.h>
#include<unistd.h>
using namespace std;
void bill_calculation(char service_type,int acc_number,int customer_code,int prem_channel,int basic_connections);
int main ()
{	system("CLS");
	int acc_number,customer_code,prem_channel,basic_connections;
	char service_type;
	cout<<"Enter account type"<<endl<<"1)B for Business"<<endl<<"2)R for Residential"<<endl;
	cin>>service_type;
	if(service_type=='B')
	{
		cout<<"Enter the account nubmer"<<endl;
		cin>>acc_number;
		cout<<"Enter the customer code"<<endl;
		cin>>customer_code;
		cout<<"Enter the number of premium channels"<<endl;
		cin>>prem_channel;
		cout<<"Enter the number of basic service connections"<<endl;
		cin>>basic_connections;
		bill_calculation(service_type,acc_number,customer_code,prem_channel,basic_connections);
	}
	else if(service_type=='R')
	{	
		cout<<"Enter the account nubmer"<<endl;
		cin>>acc_number;
		cout<<"Enter the customer code"<<endl;
		cin>>customer_code;
		cout<<"Enter the number of premium channels"<<endl;
		cin>>prem_channel;
		bill_calculation(service_type,acc_number,customer_code,prem_channel,basic_connections);
	}
	else
	
	{
		cout<<"Please select a valid option!"<<endl;
		sleep(1);
		main();
	}
	
	
}

void bill_calculation(char service_type,int acc_number,int customer_code,int prem_channel,int basic_connections)
{	float total_bill=0,price_basic_connection,price_premium_channel;
	if(service_type=='B')
	{	system("CLS");
	cout<<"========================================================"<<endl;
		cout<<"|              Account number:"<<acc_number<<"                     |"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"Bill processing fee: $15"<<endl;
		total_bill+=15;
		if(basic_connections<=10)
		{
			price_basic_connection=(75*basic_connections);
			total_bill+=price_basic_connection;
		}
		else
		{
			price_basic_connection=(basic_connections-10)*5+750;
			total_bill+=price_basic_connection;
		}
		cout<<"Nubmer of basic connections: "<<basic_connections<<endl;
		cout<<"Price of basic connections:"<<" $75.00 for first 10 connections, $5.00 "<<endl<<"for each additional connection"<<endl;
		cout<<"Basic service charges: $"<<price_basic_connection<<endl;
		price_premium_channel=50*prem_channel;
		total_bill+=price_premium_channel;
		cout<<"Price of premium channels: $50"<<endl;
		cout<<"Number of premium channels: "<<prem_channel<<endl;
		cout<<"Premium channel charges: $"<<price_premium_channel<<endl;
		cout<<"Total Bill: $"<<total_bill<<endl;
	}
	else
	{	system("CLS");
		cout<<"========================================================"<<endl;
		cout<<"|              Account number:"<<acc_number<<"                     |"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"Bill processing fee: $4.5"<<endl;
		total_bill+=4.5;
//		if(basic_connections<=10)
//		{
			price_basic_connection=20.5;
			total_bill+=price_basic_connection;
//		}
//		else
//		{
//			price_basic_connection=(basic_connections-10)*5+750;
//			total_bill+=price_basic_connection;
//		}
		cout<<"Basic service fee: $"<<price_basic_connection<<endl;
		price_premium_channel=7.5*prem_channel;
		total_bill+=price_premium_channel;
		cout<<"Price of premium channels: $7.50 per channel."<<endl;
		cout<<"Number of premium channels: "<<prem_channel;
		cout<<"Premium channel charges: $"<<price_premium_channel<<endl;
		cout<<"Total Bill: $"<<total_bill<<endl;	
	}
}
