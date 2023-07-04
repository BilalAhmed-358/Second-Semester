#include <iostream>
using namespace std;

class Sales
{
    int SaleID;
    string ItemName;
    int Qauntity;
public:
    Sales()
    {
        Set_SaleID(123);
        Set_ItemName("abc");
        Set_Quantity(123);
    }

    void Set_SaleID(int SaleID)
    {
        this->SaleID = SaleID;
    }
    void Set_ItemName(string ItemName)
    {
        this->ItemName = ItemName;
    }
    void Set_Quantity(int Quantity)
    {
        this->Qauntity = Quantity;
    }
    int get_SaleID() { return SaleID; }
    string get_ItemName() { return ItemName; }
    int get_Quantity() { return Qauntity; }
    Sales(int SaleID, string ItemName, int Quantity)
    {
        Set_ItemName(ItemName);
        Set_SaleID(SaleID);
        Set_Quantity(Quantity);
        cout << "The Sale ID of the Sale deed is " << get_SaleID() << "." << endl;
        cout << "The Item name of the Sale deed is " << get_ItemName() << "." << endl;
        cout << "The Quantity of the Sale deed is " << get_Quantity() << "." << endl;
    }
    public:
    void Display_info()
    {
        cout << "The Sale ID of the Sale deed is " << get_SaleID() << "." << endl;
        cout << "The Item name of the Sale deed is " << get_ItemName() << "." << endl;
        cout << "The Quantity of the Sale deed is " << get_Quantity() << "." << endl;
    }
    int test;
};

int main()
{ //making this object for display the random value assigned by a constructor which takes no arguments
    Sales Sale_deed_01;
    Sale_deed_01.Display_info();
//making this object for display the value assigned by a constructor which takes 3 arguments
    Sales Sale_deed_02(5600,"Tooth Paste",40);
}