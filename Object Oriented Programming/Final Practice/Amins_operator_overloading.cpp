#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class Student
{
public:
    string name;
    string roll_no;
    string id;
    Student(string name, string roll_no, string id)
    {
        this->name = name;
        this->roll_no = roll_no;
        this->id = id;
    }
    Student()
    {
        this->name = "null";
        this->roll_no = "null";
        this->id = "null";
    }
    void show(){
    	cout<<name<<endl<<roll_no<<endl<<id;
	}
	friend fstream& operator<<(fstream &bilal,Student obj);
	friend ifstream& operator>>(ifstream &bilal,Student &obj);
};
 fstream& operator<<(fstream &bilal,Student obj){
	bilal<<obj.name<<endl<<obj.roll_no<<endl<<obj.id<<endl;
	return bilal;
}
 ifstream& operator>>(ifstream &bilal,Student &obj){
	getline(bilal,obj.name);
	getline(bilal,obj.roll_no);
	getline(bilal,obj.id);
	return bilal;
}
int main()
{
    Student st1("Bilal Ahmed", "20k-0183", "567");
    //for write
    fstream fout("file.txt",ios::app);
    fout<<st1;
    fout.close();
    //for read
    Student st2;
    ifstream fin("file.txt");
    fin>>st2;
    st2.show();
    fin.close();
    
}