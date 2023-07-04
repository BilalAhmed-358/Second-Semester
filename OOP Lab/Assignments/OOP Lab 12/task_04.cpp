#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
// IDs 1 and 2 are already taken if you are testing this program kindly enter any other ID than 1 and 2 to avoid repetition;
class Participant
{
public:
    int ID;
    string name;
    float score;
    void Input()
    {
        cout << "Enter the ID of the Participant\n";
        fflush(stdin);
        cin >> ID;
        cout << "Enter the name of the Participant\n";
        fflush(stdin);
        getline(cin, name);
        cout << "Enter the score of the Participant\n";
        fflush(stdin);
        cin >> score;
        ofstream out("04.txt", ios::app);
        out.write((char *)this, sizeof(this));
        out.close();
    }
    void Output(int ID)
    {
        int count = 0;
        ifstream in("04.txt");
        while (!in.eof())
        {
            in.read((char *)this, sizeof(this));
            if (this->ID == ID)
            {
                count++;
                cout << "The ID of the participant is " << ID << ".\n";
                cout << "The name of the participant is " << name << ".\n";
                cout << "The score of the participant is " << score << ".\n";
                break;
            }
        }
        if (count == 0)
        {
            cout << "Record not found!\n";
        }
        in.close();
    }
    void Max_val()
    {
        ifstream in("04.txt");
        float Max = -9999;
        while (!in.eof())
        {
            in.read((char *)this, sizeof(this));
            if (this->score > Max)
            {
                Max = this->score;
            }
        }
        if(Max==-9999)
        cout<<"There was no record found in file\n";
        else
        cout<<"The maximum score among all the participants is "<<Max<<".\n";
    }
    Participant()
    {
        Input();
    }
};

int main()
{
    Participant p1;
    Participant p2;
    p1.Output(1);
    p2.Output(2);
    p1.Max_val();
}