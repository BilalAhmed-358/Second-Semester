#include <iostream>
#include <stdio.h>
#include <iomanip>
#include<stdlib.h>
using namespace std;

struct Player_info
{
    string Player_name;
    int no_of_homeruns;
    int no_of_hits;
    int id;
} players[10];
void menu();
int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        cout << "Enter the name of player no." << i + 1 << endl;
        fflush(stdin);
        getline(cin, players[i].Player_name);
        cout << "Enter the number of homeruns of player no." << i + 1 << endl;
        cin >> players[i].no_of_homeruns;
        cout << "Enter the number of hits of player no." << i + 1 << endl;
        cin >> players[i].no_of_hits;
        cout << endl;
        players[i].id = i + 1;
    }
    menu();
}

void menu()
{
    int choice, i, id;
    cout << "1-View records of existing players\n2-Modify the records of existing players\n3-Exit" << endl;
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
    {   char choice;
        for (i = 0; i < 10; i++)
        {
            cout << "Player Id: " << players[i].id << endl;
            cout << "Player " << i + 1 << " Name: " << players[i].Player_name << endl;
            cout << "Number of homeruns by Player " << i + 1 << ": " << players[i].no_of_homeruns << endl;
            cout << "Number of hits by Player " << i + 1 << ": " << players[i].no_of_hits << endl
                 << endl;
        }
        cout<<"Want to continue? Y/N"<<endl;
        cin>>choice;
        if (choice=='Y')
        {
            menu();
        }
        else
        exit(0);
        
    }
    case 02:
    {   char choice;
        cout << "Enter the ID of the player you want to modify" << endl;
        cin >> id;
        for (i = 0; i < 10; i++)
        {
            if (id == players[i].id)
            {
                cout << "Enter the name of player"<<endl;
                fflush(stdin);
                getline(cin, players[i].Player_name);
                cout << "Enter the number of homeruns of player"<< endl;
                cin >> players[i].no_of_homeruns;
                cout << "Enter the number of hits of player"<< endl;
                cin >> players[i].no_of_hits;
                cout << endl;
            }
        }
        cout<<"Want to continue? Y/N"<<endl;
        cin>>choice;
        if (choice=='Y')
        {
            menu();
        }
        else
        exit(0);
    }
    default:
        break;
    }
}