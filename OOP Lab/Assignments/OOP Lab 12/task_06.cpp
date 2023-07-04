#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

void Input()
{
    ofstream out("STORY.txt");
    out<<"If the file ""STORY.TXT"" contains the following lines,\n";
    out<<"The rose is red.\n";
    out<<"A girl is playing there.\n";
    out<<"There is a playground.\n";
    out<<"An aeroplane is in the sky.\n";
    out<<"Numbers are not allowed in the password.\n";
    out<<"The function should display the output as 3.\n";
    out.close();

}
int A_checker()
{
    ifstream in("STORY.txt");
    cout<<"The lines in the given text file which donot start with an 'A' are as follows:\n\n";
    int count=0;string st1;
    while (!in.eof())
    {
        getline(in,st1);
        if(st1[0]!='A'&&st1[0]!='\0')
        {
            count++;
        cout<<count<<". "<<st1<<endl<<endl;
            // cout<<"This worked\n\n";
        }
    }
    in.close();
    return count;
}

int main()
{
    Input();
    cout<<"The number of sentences in the given text that do no start with an 'A' are "<<A_checker()<<".\n";

}