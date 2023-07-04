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
			Person p1("kamran", 20);
			fstream os("person.bin", ios::out);
			os.write((char*)&p1, sizeof(p1)); 
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
//	fstream os("person.bin", ios::out);
//	os.write((char*)&p1, sizeof(p1)); //writing in main without calling a function
	fstream is("person.bin", ios::in);
	is.seekg(0);
	is.read((char*)&p1, sizeof(p1));
	cout << "name of person: " << p1.name;
	cout << "\nage of person: "<< p1.age;
	is.close();
	
	//char c;
//	while(!os.eof())
	//{
//		os.get(c);
//		cout << c;
//	}
	/*since objects are stored as garbage values in files, hence using while or getline wil print that garbage value
	instead of what was input in class and stored in file.*/
}
