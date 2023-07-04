#include <iostream>
using namespace std;
#include <math.h>

class Account
{   public:
    float account_balance;
    Account()
    {
        cout<<"Enter the account balance."<<endl;
        cin>>account_balance;
    }
    void Credit(int increment)
    {
        account_balance+=increment;
        cout<<"The updated account balance is "<<account_balance<<".";
    }
    void Debit(int decrement)
    {
        cout<<"Account balance before withdrawl: "<<account_balance<<"."<<endl;
        account_balance-=decrement;
        cout<<"Account balance after withdrawl: "<<account_balance<<"."<<endl;
    }

    float Balance()
    {
        return account_balance;
    }
};


int main()
{
    Account Account_01;
    cout<<"The current balance in the bank account is "<<Account_01.Balance()<<"."<<endl;
    int increment;
    cout<<"Enter the amount of money you want to add in your bank balance"<<endl;
    cin>>increment;
    Account_01.Credit(increment);
    int decrement;
    cout<<"Enter the amount of money you want to withdraw\n";
    cin>>decrement;
    Account_01.Debit(decrement);
}