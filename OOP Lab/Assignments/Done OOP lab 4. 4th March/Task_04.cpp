#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
#include <windows.h> 

class Books
{
public:
    string author;
    string title;
    int price;
    string publisher;
    int stock_position;
    string book_required;

    Books()
    {
        cout << "Enter the author of the book" << endl;fflush(stdin);
        getline(cin, author);
        cout << "Enter the title of the book" << endl;fflush(stdin);
        getline(cin, title);
        cout << "Enter the price of the book" << endl;fflush(stdin);
        cin >> price;
        cout << "Enter the name of the publisher" << endl;fflush(stdin);
        getline(cin, publisher);
        cout << "Enter the stock position of the book" << endl;fflush(stdin);
        cin >> stock_position;
    }
};

int main()
{
    string book_required;string required_book_author;
    Books Book_01;
    cout << "Enter the name of the book you want?";fflush(stdin);
    getline(cin, book_required);
    cout<<"Enter the name of the author of the book";fflush(stdin);
    getline(cin,required_book_author);
    

    if (book_required == Book_01.title)
    {
        int number_of_books_required;
        cout << "There are " << Book_01.stock_position << " pieces available of the book, How many do you require?" << endl;fflush(stdin);
        cin >> number_of_books_required;
        if (number_of_books_required > Book_01.stock_position)
        {
            cout << "Not enough books avaiable try again!" << endl;fflush(stdin);
            Sleep(1000);
            system("CLS");
            main();
        }
        else
        {
            cout << "Your total bill is " << Book_01.price * number_of_books_required << " rupees only." << endl;
        }
    }
    else
    {
        cout<<"No such book exists in the database, kindly try agian and enter a valid title\n";
        Sleep(1000);
        system("CLS");
        main();
    }
    
}