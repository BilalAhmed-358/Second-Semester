#include<iostream>
#include<fstream>
using namespace std;

class Person{
	public:
	string name;
	int age;
	
	public:
		Person(string name, int age)
		{
			this->name = name;
			this->age = age;
		}
		void WriteData()
		{
			fstream os("person.bin");
			os.write((char*)this, sizeof(this)); 
			os.close();
			cout << "\n\nYour data has been successfully written.";
		}
	//	void display()
	//	{
	//		cout << "name of person: " << name;
	//		cout << "\nage of person: " << age;
	//		cout << "\n\nYour data has been successfully written.";
	//	}
};


int main()
{
	Person p1("kamran", 20);
	p1.WriteData();
}
