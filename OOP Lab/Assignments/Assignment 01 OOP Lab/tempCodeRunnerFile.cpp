#include<iostream>
#include<stdio.h>
using namespace std;
struct movie_info
{
	string movie_name;
	int adult_ticket_price;
	int child_ticket_price;
	int adult_ticket_sold;
	int child_ticket_sold;
	float percentage;
};
movie_info movie;
int main()
{
	cout<<"Enter the name of the movie:"<<endl;fflush(stdin);
	cin>>movie.movie_name;
	cout<<"Enter adult ticket price:"<<endl;
	cin>>movie.adult_ticket_price;
	cout<<"Enter child ticket price:"<<endl;
	cin>>movie.child_ticket_price;
	cout<<"Enter number of adult tickets sold"<<endl;
	cin>>movie.adult_ticket_sold;
	cout<<"Enter number of child tickets sold"<<endl;
	cin>>movie.child_ticket_sold;
	cout<<"Enter percentage"<<endl;
	cin>>movie.percentage;
	cout<<endl<<endl;
    system("CLS");
	cout<<"_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*"<<endl;
	cout<<"Movie Name:................................."<<movie.movie_name<<endl;
	cout<<"Number of tickets sold:....................."<<movie.adult_ticket_sold+movie.child_ticket_sold<<endl;
	cout<<"Gross Amount:..............................$"<<(movie.adult_ticket_price*movie.adult_ticket_sold)+(movie.child_ticket_price*movie.child_ticket_sold)<<endl;
	cout<<"Percentage of Gross Amount Donated:........."<<movie.percentage<<"%"<<endl;
	cout<<"Amount Donated:............................$"<<((movie.adult_ticket_price*movie.adult_ticket_sold)+(movie.child_ticket_price*movie.child_ticket_sold))*(movie.percentage/100)<<endl;
	cout<<"Net Sale:..................................$"<<((movie.adult_ticket_price*movie.adult_ticket_sold)+(movie.child_ticket_price*movie.child_ticket_sold))-(((movie.adult_ticket_price*movie.adult_ticket_sold)+(movie.child_ticket_price*movie.child_ticket_sold))*(movie.percentage/100))<<endl;
}

