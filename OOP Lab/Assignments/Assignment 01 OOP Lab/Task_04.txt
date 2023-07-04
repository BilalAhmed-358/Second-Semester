#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
struct menuItemType
{
    string menuitem;
    double menu_price;
} menuList;

int main()
{
    double total_bill;
    int item;
    char choice = 'Y';
    cout << "Welcome to Johnny's Restraunt! Here is our Menu" << endl
         << endl
         << endl;
    cout << "1-Plain Egg \t\t\t$1.45\n2-Bacon and Egg\t\t\t$2.45\n3-Muffin\t\t\t$0.99\n4-French Toast\t\t\t$1.99\n5-Fruit Basket\t\t\t$2.49\n6-Cereal\t\t\t$0.69\n7-Coffee\t\t\t$0.50\n8-Tea\t\t\t\t$0.75\n";
    while (choice == 'Y'||choice == 'y')
    {

        cout << "Select any of the give items above" << endl;
        cin >> item;
        switch (item)
        {
        case 1:
            cout << "Plain Egg \t\t\t$1.45" << endl;
            total_bill += 1.45;
            cout << "Want to continue? Y/N"<<endl;
            cin >> choice;
            if (choice == 'N'||choice == 'n')
            {
                break;
            }
            else
            {
                continue;
            }
        case 2:
            cout << "Bacon and Egg \t\t\t$2.45" << endl;
            total_bill += 2.45;
            cout << "Want to continue? Y/N"<<endl;
            cin >> choice;
            if (choice == 'N'||choice == 'n')
            {
                break;
            }
            else
            {
                continue;
            }
        case 3:
            cout << "Muffin \t\t\t$0.99" << endl;
            total_bill += 0.99;
            cout << "Want to continue? Y/N"<<endl;
            cin >> choice;
            if (choice == 'N'||choice == 'n')
            {
                break;
            }
            else
            {
                continue;
            }
        case 4:
            cout << "French Toast\t\t\t$1.99" << endl;
            total_bill += 1.99;
            cout << "Want to continue? Y/N"<<endl;
            cin >> choice;
            if (choice == 'N'||choice == 'n')
            {
                break;
            }
            else
            {
                continue;
            }
        case 5:
            cout << "Fruit Basket \t\t\t$2.49" << endl;
            total_bill += 2.49;
            cout << "Want to continue? Y/N"<<endl;
            cin >> choice;
            if (choice == 'N'||choice == 'n')
            {
                break;
            }
            else
            {
                continue;
            }
        case 6:
            cout << "Cereal \t\t\t$0.69" << endl;
            total_bill += 0.69;
            cout << "Want to continue? Y/N"<<endl;
            cin >> choice;
            if (choice == 'N'||choice == 'n')
            {
                break;
            }
            else
            {
                continue;
            }
        case 7:
            cout << "Coffee \t\t\t$0.50" << endl;
            total_bill += 0.50;
            cout << "Want to continue? Y/N"<<endl;
            cin >> choice;
            if (choice == 'N'||choice == 'n')
            {
                break;
            }
            else
            {
                continue;
            }
        case 8:
            cout << "Tea\t\t\t$0.75" << endl;
            total_bill += 0.75;
            cout << "Want to continue? Y/N"<<endl;
            cin >> choice;
            if (choice == 'N'||choice == 'n')
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<fixed<<setprecision(2);
    cout<<"Gross Total\t\t\t$"<<total_bill<<endl;
    cout<<"Tax\t\t\t\t5%"<<endl;
    cout<<"Amount Due\t\t\t$"<<total_bill*1.05;
}