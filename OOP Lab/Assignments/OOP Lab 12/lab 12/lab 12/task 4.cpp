#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
class Participant
{
	int ID[3];
	string name[3];
	float score[3];
	public:
		
		void input()
		{
			Participant p1;
			ofstream fout;
			fout.open("task4.txt",ios::out);
			for(int i=0;i<3;i++)
			{
				cout<<endl<<"PARTICIPANT  "<<i+1<<endl;
			cout<<"Enter Name  : ";fflush(stdin);
			getline(cin,name[i]);
			cout<<"Enter ID    : ";
			cin>>ID[i];
			cout<<"Enter Score : ";
			cin>>score[i];
			
			fout.write((char*)this,sizeof(*this));
		    }
			fout.close();
		}
		void Output()
		{
			Participant p1;
			ifstream fin;
			fin.open("task4.txt",ios::in);
			for(int i=0;i<3;i++)
			{
			  fin.read((char*)this,sizeof(*this));
			  cout<<endl<<"Name : "<<name[i]<<endl;
			  cout<<"Score : "<<score[i]<<endl;
			  cout<<"ID   : "<<ID[i]<<endl;
			  
		    }
			fin.close();
			
			
		}
		void Highest_Rank()
		{
			Participant p1;
			float highest=0;
			string h_name;
			ifstream fin;
			fin.open("task4.txt");
			for(int i=0;i<3;i++)
			{
				fin.read((char*)this,sizeof(*this));
				if(p1.score[i]>highest)
				{
					highest=score[i];
					h_name=name[i];
				}
			}
			cout<<"Participant who scores the highest is ... : "<<endl;
			cout<<endl<<"Name : "<<h_name<<endl;
			cout<<endl<<"Score: "<<highest<<endl;
		}
		
};
int main()
{
	Participant p1;
	cout<<"Writing to a file.."<<endl;
	p1.input();
	cout<<endl<<"Reading from a file.."<<endl;
	p1.Output();
	cout<<endl<<"Highest Score.."<<endl;
	p1.Highest_Rank();
}
