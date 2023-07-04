#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
//	char Nfile1[20],Nfile2[20];
	string file1,Nfile1,Nfile2;
	cout<<"Enter 1st filename to open"<<endl;
	cin>>Nfile1;
	ifstream fin;
	fin.open(Nfile1);
	if(!fin)
	{
		cout<<"Error opening file 1"<<endl;
	exit(0);
    }

	cout<<"Enter the file name where you want to copy"<<endl;
	cin>>Nfile2;
	ofstream fout;
	fout.open(Nfile2);
	if(!fout)
	{
		cout<<"Error opening file 2 "<<endl;
		exit(0);
	}
	
	while(!fin.eof())
	{
		getline(fin,file1);
		fout<<file1<<endl;
	}
	fin.close();
	fout.close();
}
