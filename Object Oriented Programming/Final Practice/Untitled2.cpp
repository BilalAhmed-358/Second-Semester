#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Staff
{
		public:
			virtual void show_details()=0;
			
			Staff()
			{
				
			}
};

class Guards:public Staff
{
	public:
		int ID;
		string G_name;
		int block_no;
		double salary;
		string address;
		int experience;
		
		Guards()
		:Staff()
		{
			
		}
		
		virtual void show_details() override
		{
			
		 } 
};

class Admin:virtual public Staff
{
	public:
		int admin_id;
		string A_name;
		double salary;
		string address;
		int experince;
		string department;
		
		Admin()
		:Staff()
		{
			
		}
		
		virtual void show_details() override
		{
			
		 }
};

class Block : public Guards
{
	public:
		int prisoners;
		int no_of_prison;
		double budget;
		string block_incharge;
		string cell_id;
		
		Block()
		:Guards()
		{
			
		}
		
		virtual void show_details() override
		{
			
		 }
	
};

class Prisoners:virtual public Block
{
	public:
		int inmate_id;
		string P_name;
		string city;
		string crime;
		string sentence;	
		char *block_lockedup_in;
		char *cell_lockedup_in;
		static int no_of_prisoners;
		
		Prisoners()
		:Block()
		{
			no_of_prisoners++;
		}
		
		virtual void show_details() override
		{
			
		 }
		 
		 ~Prisoners(){
		 	--no_of_prisoners;
		 }
};
int Prisoners::no_of_prisoners=0;


class Super:public Prisoners,public Admin
{
	public:
		
		string S_name;
		
		
		Super()
		{
			
		}
		
		void terminates()
		{
			cout << "Enter ID of personel to terminate: ";
			cin >> admin_id;
			
			cout << admin_id<<" " << A_name << "Has been terminated" << endl;
		}
		
		void assign_guards()
		{
			cout << "Enter guard name: ";
			cin >> G_name;
			cout << "To block: ";
			cin >> block_no;
		}
		
		void set_incharge()
		{
			cout << "Enter the name of new incharge: ";
			cin >> block_incharge;
		}
		
		void terminate()
		{
			cout << "Enter name of guard to terminate: ";
			cin >> G_name;
			
			cout << G_name << " Has been terminated" << endl;
		}
		
		void Move()
		{
			cout << "Enter the ID of prisoner to move: ";
			cin >> inmate_id;
			cout << "enter block NO: ";
			cin >> *block_lockedup_in;
			cout << "Enter cell locked up in: ";
			cin >> *cell_lockedup_in;
			
			cout << inmate_id << " Has been transfferred to block " << *block_lockedup_in << " and cell " << *cell_lockedup_in << endl;
		}
		
		void admit_prisoner()
		{
			cout << "enter prisoner ID: ";
			cin >> inmate_id;
			cout << "Enter name: ";
			cin >> P_name;
			cout << "city: ";
			cin >> city;
			cout << "crime: ";
			getline(cin>>ws,crime);
			cout << "Sentence: ";
			getline(cin>>ws,sentence);
			
			block_lockedup_in = new char[20];
			cin >> block_lockedup_in;
			
			cell_lockedup_in= new char[20];
			cin >> *cell_lockedup_in;
			
			ofstream out_file("prisoners.txt");
			if(!out_file)
			{
				cerr << "File not opened";
			}
			
			out_file << inmate_id;
			out_file << P_name ;
			out_file << city ;
			out_file << crime ;
			out_file << sentence;
			
			out_file.close();
		}
		
		virtual void show_details() override
		{
			
		 }
};

class Auditor:public Super{
	
	public:
		Auditor()
		:Super()
		{
		}
		
		void no_of_prisoners()
		{
			cout << "Number of prisoners in prisons are: " << Prisoners::no_of_prisoners << endl;	
		}
		
		virtual void show_details() override
		{
			
		 }
};

int main()
{
	Super obj;
	obj.admit_prisoner();
}
