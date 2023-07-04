#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char string[100];
	int count=0;
	ifstream fin;
	fin.open("story.txt");
	while(!fin.eof())
	{
		fin.getline(string,100);
		if(string[0]=='a'|| string[0]=='A')
		{
			count++;
		}
	}
	cout<<"Number of lines start with 'A' are : "<<count<<endl;
}
