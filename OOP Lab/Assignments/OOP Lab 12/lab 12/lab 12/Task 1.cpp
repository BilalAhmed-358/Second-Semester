#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
	char string[50],cha;
	cout<<"ENTER A STRING"<<endl;
	gets(string);
	int length=strlen(string);
	cout<<"Length : "<<length<<endl;
	ofstream fout;
	fout.open("1.txt",ios::out);
	for(int i=0;i<length;i++)
	{
		fout.put(string[i]);
}
    fout.close();
    ifstream fin;
    fin.open("1.txt",ios::in);
    fin>>cha;
    while(!fin.eof())
    {
    	getline (in,st1);
		cout<<st1;
    	
	}
	fin.close();
	
}
