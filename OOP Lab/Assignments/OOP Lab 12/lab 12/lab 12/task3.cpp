,#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Person
{
	string name;
	int age;
	public:
		Person(string name,int age)
		{
			this->age=age;
			this->name=name;
		}
		void display()
		{
			cout<<"Name : "<<name<<endl;
			cout<<"Age  : "<<age<<endl;
		}
};
int main()
{
	Person person1("Wamiq",19);
	ofstream fout;
	fout.open("task3.txt");
	fout.write((char*)&person1,sizeof(person1));
	cout<<"Object copied to File.."<<endl;
	fout.close();
	ifstream fin;
	fin.open("task3.txt");
		fin.read((char*)&person1,sizeof(person1));
		cout<<"press any key to display data.."<<endl;
		getch();
		person1.display();
		fin.close();
}
