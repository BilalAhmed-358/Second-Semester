#include <iostream>
using namespace std;
#include <math.h>

class Invoice
{
    public:
    string part_number;
    string part_description;
    int quantity_of_items_purchased;
    double item_price;

    Invoice()
    {
        part_number="abc";
        part_description="abc";
        quantity_of_items_purchased=0;
        item_price=0;
    }
    void invoice_info()
    {
        cout<<"Enter the part number of the product."<<endl;
        getline(cin,part_number);
        cout<<"Enter the part description."<<endl;
        getline(cin,part_description);
        cout<<"Enter the quantity of items purchased."<<endl;
        cin>>quantity_of_items_purchased;
        cout<<"Enter the price of a single piece."<<endl;
        cin>>item_price;

    }
    double getInvoiceAmount(double item_price,int quantity_of_items_purchased )
    {   if ((item_price*quantity_of_items_purchased)<0)
    {
        return 0.0;
    }
    
        return item_price*quantity_of_items_purchased;
    }
};

int main()
{
    Invoice Invoice_01;
    Invoice_01.invoice_info();
    cout<<"The total bill is Rs "<<Invoice_01.getInvoiceAmount(Invoice_01.item_price,Invoice_01.quantity_of_items_purchased)<<" ."<<endl;
}