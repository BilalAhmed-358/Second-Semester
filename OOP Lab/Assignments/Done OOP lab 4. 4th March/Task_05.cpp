#include <stdio.h>
#include <iostream>
using namespace std;
class CoffeeShop
{
public:
    string CoffeeShop_name;
    struct Menuitem
    {
        string name_of_item;
        string type_of_item;
        double price;
    } Menu[10];

    char addOrder(int item_serial_number, string item_name, Menuitem Orders[])
    {
        char status;
        int i;
        for (i = 0; i < 10; i++)
        {
            if (item_name == Menu[i].name_of_item)
            {
                status = 'Y';
                cout << "Item added!" << endl;
                Orders[item_serial_number].name_of_item = Menu[i].name_of_item;
                Orders[item_serial_number].type_of_item = Menu[i].type_of_item;
                Orders[item_serial_number].price = Menu[i].price;
            }
        }
        if (i == 10 && status != 'Y')
        {
            status = 'N';
            cout << "Item does not exist" << endl;
            return status;
        }
    }

    void ListOrder(Menuitem Orders[], int number_of_items)
    {
        cout << endl
             << "Following is the list of your orders" << endl;
        for (int i = 0; i < number_of_items; i++)
        {
            cout << "Name: " << Orders[i].name_of_item << endl;
            cout << "Type: " << Orders[i].type_of_item << endl;
            cout << "Price: " << Orders[i].price << endl;
            cout << "Status: ";
            fulfillOrder();cout<<endl;
        }
    }

    void fulfillOrder()
    {
        cout << "Order Completed" << endl;
    }

    double dueAmount(Menuitem Orders[], int number_of_items)
    {
        double total;
        for (int i = 0; i < number_of_items; i++)
        {
            total += Orders[i].price;
        }
        return total;
    }

    string cheapestItem(Menuitem Orders[], int number_of_items)
    {
        string cheap_item;
        double min = 99999;
        for (int i = 0; i < number_of_items; i++)
        {
            if (Orders[i].price < min)
            {
                min = Orders[i].price;
                cheap_item = Orders[i].name_of_item;
            }
        }
        return cheap_item;
    }

    void drinksOnly(Menuitem Orders[], int number_of_items)
    {
        for (int i = 0; i < number_of_items; i++)
        {
            if (Orders[i].type_of_item == "Drink")
            {
                cout << "Name: " << Orders[i].name_of_item << endl;
                //cout << "Type: " << Orders[i].type_of_item << endl;
                cout << "Price: " << Orders[i].price << endl;
            }
        }
        cout<<endl;
    }
    
    void foodOnly(Menuitem Orders[], int number_of_items)
    {
        for (int i = 0; i < number_of_items; i++)
        {
            if (Orders[i].type_of_item == "Food")
            {
                cout << "Name: " << Orders[i].name_of_item << endl;
                //cout << "Type: " << Orders[i].type_of_item << endl;
                cout << "Price: " << Orders[i].price << endl;
            }
        }
        cout<<endl;
    }
    CoffeeShop()
    {
        Menu[0].name_of_item = "Tea";
        Menu[0].type_of_item = "Drink";
        Menu[0].price = 30;
        Menu[1].name_of_item = "Coffee";
        Menu[1].type_of_item = "Drink";
        Menu[1].price = 50;
        Menu[2].name_of_item = "Sandwich";
        Menu[2].type_of_item = "Food";
        Menu[2].price = 100;
        Menu[3].name_of_item = "Mayo-Roll";
        Menu[3].type_of_item = "Food";
        Menu[3].price = 80;
        Menu[4].name_of_item = "Pizza (small)";
        Menu[4].type_of_item = "Food";
        Menu[4].price = 80;
        Menu[5].name_of_item = "Cake";
        Menu[5].type_of_item = "Food";
        Menu[5].price = 60;
        Menu[6].name_of_item = "Cold Drink";
        Menu[6].type_of_item = "Drink";
        Menu[6].price = 50;
        Menu[7].name_of_item = "Biscuits";
        Menu[7].type_of_item = "Food";
        Menu[7].price = 20;
        Menu[8].name_of_item = "Samosa";
        Menu[8].type_of_item = "Food";
        Menu[8].price = 20;
        Menu[9].name_of_item = "Garlic Roll";
        Menu[9].type_of_item = "Food";
        Menu[9].price = 70;

        cout << "Enter the name of the shop" << endl;
        getline(cin, CoffeeShop_name);
        cout << endl
             << endl
             << "Welcome to " << CoffeeShop_name << endl
             << "Following items are available at our cafe!." << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << endl;
            cout << "Name: " << Menu[i].name_of_item << endl;
            cout << "Type: " << Menu[i].type_of_item << endl;
            cout << "Price: " << Menu[i].price << endl;
        }
    }
};

int main()
{
    CoffeeShop Shop_01;
    int items;
    cout << "How many items you want to buy?" << endl;
    cin >> items;
    string item_name;
    CoffeeShop::Menuitem Orders[items];
    for (int i = 0; i < items; i++)
    {
        cout << "Enter the name of Product " << i + 1 << endl;
        fflush(stdin);
        getline(cin, item_name);
        if (Shop_01.addOrder(i, item_name, Orders) == 'N')
        {
            i--;
        }
    }
    Shop_01.ListOrder(Orders, items);
    cout << "You total bill is " << Shop_01.dueAmount(Orders, items) << "/- Rupees only" << endl<<endl;
    cout << "The cheapest item you bought is " << Shop_01.cheapestItem(Orders, items) << "." << endl<<endl;
    cout << "The items in your order which are Drinks are as follows" << endl;
    Shop_01.drinksOnly(Orders, items);
    cout << "The items in your order which are Foods are as follows" << endl;
    Shop_01.foodOnly(Orders, items);
}