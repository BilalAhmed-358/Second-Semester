//                                                                  Implementation of each requirement of the problem has been described with comments
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class Reader
{
public:
    //the structure of each reading material is defined in the base class and these will be further used in their respective child classes except in the case of Freader which will use all types of reading material
    string reader_name;
    string reader_type;
    string favorite_books[3];
    int static num_of_freaders;
    //This will be used for Mangaworms and Freader
    struct Mangabook
    {
        string Mangabook_name;
        string Mangabook_author;
        string artsyle;
    } * Mangabook_lib;
    int num_of_manga_books;
    //This will be used for Comicnerds and Freader
    struct Comicbook
    {
        string Comicbook_name;
        string Comicbook_author;
        string panelsize;
    } * Cominbook_lib;
    int num_of_comin_books;
    //This will be used for Studygeeks and Freader
    struct Coursebook
    {
        string Coursebook_name;
        string Coursebook_author;
        string learning_value;
    } * Coursebook_lib;

    int num_of_course_books;
//This is the constructor of base class it only stores the reader name and reader type and checks the number of freeders to keep them under the prescribed limit i.e.15
    Reader(string reader_name, string reader_type)
    {
        this->reader_name = reader_name;
        this->reader_type = reader_type;
        if (reader_type == "Freader")
        {
            num_of_freaders++;
            if (num_of_freaders > 5)
            {
                cout << "Maximum number of freaders reached you cannot make another freader\n";
                delete this;
            }
        }
    }
    //Function for the Fav books of a common reader this will be overriden in the child classes
    void SetFavBooks(string FavBook1, string FavBook2, string FavBook3)
    {
        FavBook1 = favorite_books[0];
        FavBook2 = favorite_books[1];
        FavBook3 = favorite_books[2];
    }
};
//Static data member to keep a count of Freaders
int Reader ::num_of_freaders = 0;

class Mangaworm : virtual public Reader
{
public:
    float annual_fee;
    Mangaworm(string reader_name, float annual_fee) : Reader(reader_name, "Mangaworm")
    {
        this->annual_fee = annual_fee;
        cout << "How many Mangas are avialable in the store?\n";
        fflush(stdin);
        cin >> num_of_manga_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 25 will be used to take input of books from the user.
        Mangabook *Mangabook_lib = new Mangabook[num_of_manga_books];
        for (int i = 0; i < num_of_manga_books; i++)
        {
            cout << "Enter the name of Manga no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Mangabook_lib[i].Mangabook_name);
            cout << "Enter the name of author of Manga no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Mangabook_lib[i].Mangabook_author);
            cout << "Rate Manga no." << i + 1 << " on the basis of artsyle.\n";
            fflush(stdin);
            getline(cin, Mangabook_lib[i].artsyle);
        }
    }
    //Function to store the Favorite books of the Mangaworm
    void SetFavBooks(string FavBook1, string FavBook2, string FavBook3)
    {
        FavBook1 = favorite_books[0];
        FavBook2 = favorite_books[1];
        FavBook3 = favorite_books[2];
    }
    //Function to display the Favorite books of the Mangaworm. This function is also the overriden function
    void Disp_Favbooks()
    {
        cout << "The Favorite books of " << reader_name << " are.\n";
        cout << "1." << favorite_books[0] << " \n.";
        cout << "2." << favorite_books[1] << " \n.";
        cout << "3." << favorite_books[2] << " \n.";
    }
    //Function which enables the user to select a book for reading
    void selectbooks(string book1)
    {
        for (int i = 0; i < num_of_manga_books; i++)
        {
            if (book1 == Mangabook_lib[i].Mangabook_name)
            {
                cout << "Book selected\n";
            }
            else
                cout << "No such book exists try again!\n";
        }
    }
    //Function which checks the mangameter value of the Mangaworm and determines whether he will be rewarded or not
    void Mangameter_val(float val)
    {
        if (val > 50)
        {
            cout << "Your mangameter value is greater than 50 you'll get 10% discount.\n";
        }
        else
            cout << "Sorry no discount available for your current rating\n.";
    }
};

class Comicnerd : virtual public Reader
{
public:
    float annual_fee;
    Comicnerd(string reader_name, float annual_fee) : Reader(reader_name, "Comicnerd")
    {
        this->annual_fee = annual_fee;
        cout << "How many comics are available in the store?\n";
        fflush(stdin);
        cin >> num_of_comin_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 25 will be used to take input of books from the user.
        Comicbook *Cominbook_lib = new Comicbook[num_of_comin_books];
        for (int i = 0; i < num_of_comin_books; i++)
        {
            cout << "Enter the name of Comic no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Cominbook_lib[i].Comicbook_name);
            cout << "Enter the name of author of Comic no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Cominbook_lib[i].Comicbook_name);
            cout << "Rate Comic no." << i + 1 << " on the basis of Panel size.\n";
            fflush(stdin);
            getline(cin, Cominbook_lib[i].panelsize);
        }
    }
    //Function to select Fav books
    void SetFavBooks(string FavBook1, string FavBook2, string FavBook3)
    {
        FavBook1 = favorite_books[0];
        FavBook2 = favorite_books[1];
        FavBook3 = favorite_books[2];
    }
    //Function to display Fav books
    void Disp_Favbooks()
    {
        cout << "The Favorite books of " << reader_name << " are.\n";
        cout << "1." << favorite_books[0] << " \n.";
        cout << "2." << favorite_books[1] << " \n.";
        cout << "3." << favorite_books[2] << " \n.";
    }
    //Function to select books for reading
    void selectbooks(string book1)
    {
        for (int i = 0; i < num_of_comin_books; i++)
        {
            if (book1 == Cominbook_lib[i].Comicbook_name)
            {
                cout << "Book selected\n";
            }
            else
                cout << "No such book exists try again!\n";
        }
    }
    //Function to determine if the user will be rewarded or not based on his comicfactor
    void Comicfactor_val(float val)
    {
        if (val > 8)
        {
            cout << "Your Comic factor value is greater than 8 you'll get 10% discount.\n";
        }
        else
            cout << "Sorry no discount available for your current rating\n.";
    }
};
class Studygeek : virtual public Reader
{
public:
    float annual_fee;
    Studygeek(string reader_name, float annual_fee) : Reader(reader_name, "Studygeek")
    {
        this->annual_fee = annual_fee;
        cout << "How many Course books are available in the store?\n";
        fflush(stdin);
        cin >> num_of_course_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 25 will be used to take input of books from the user.
        Coursebook *Coursebook_lib = new Coursebook[num_of_course_books];
        for (int i = 0; i < num_of_course_books; i++)
        {
            cout << "Enter the name of book no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Coursebook_lib[i].Coursebook_name);
            cout << "Enter the name of author of book no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Coursebook_lib[i].Coursebook_author);
            cout << "Rate book no." << i + 1 << " on the basis of learing value.\n";
            fflush(stdin);
            getline(cin, Coursebook_lib[i].learning_value);
        }
    }
    //Function to set Fav books
    void SetFavBooks(string FavBook1, string FavBook2, string FavBook3)
    {
        FavBook1 = favorite_books[0];
        FavBook2 = favorite_books[1];
        FavBook3 = favorite_books[2];
    }
    //Function to Display Fav books
    void Disp_Favbooks()
    {
        cout << "The Favorite books of " << reader_name << " are.\n";
        cout << "1." << favorite_books[0] << " \n.";
        cout << "2." << favorite_books[1] << " \n.";
        cout << "3." << favorite_books[2] << " \n.";
    }
    //Function to select books for reading
    void selectbooks(string book1)
    {
        for (int i = 0; i < num_of_course_books; i++)
        {
            if (book1 == Coursebook_lib[i].Coursebook_name)
            {
                cout << "Book selected\n";
            }
            else
                cout << "No such book exists try again!\n";
        }
    }
    //Function to determine whether the studygeek will be rewarded or not based on his Studyscale value
    void StudyScale_val(float val)
    {
        if (val > 0.6)
        {
            cout << "Your StudyScale value is greater than 0.6 you'll get 10% discount.\n";
        }
        else
            cout << "Sorry no discount available for your current rating\n.";
    }
};

class Freader : public Reader
{
public:
    float monthly_fee;
    //static data member which will count the number of books issued to the Freader and warn him and ask for bill when he reaches the limit of 15 books
    static int number_of_books;
    Freader(string readername, float monthly_fee) : Reader(reader_name, "Freader")
    {   //Here I have taken the input of all the types of material since a Freader has access to all kinds of reading material
        this->monthly_fee = monthly_fee;
        cout << "How many Mangas are avialable in the store?\n";
        fflush(stdin);
        cin >> num_of_manga_books;
        cout << "How many comics are available in the store?\n";
        fflush(stdin);
        cin >> num_of_comin_books;
        cout << "How many Course books are available in the store?\n";
        fflush(stdin);
        cin >> num_of_course_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 25 will be used to take input of books from the user.
        Mangabook *Mangabook_lib = new Mangabook[num_of_manga_books];
        for (int i = 0; i < num_of_manga_books; i++)
        {
            cout << "Enter the name of Manga no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Mangabook_lib[i].Mangabook_name);
            cout << "Enter the name of author of Manga no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Mangabook_lib[i].Mangabook_author);
            cout << "Rate Manga no." << i + 1 << " on the basis of artsyle.\n";
            fflush(stdin);
            getline(cin, Mangabook_lib[i].artsyle);
        }

        Comicbook *Cominbook_lib = new Comicbook[num_of_comin_books];
        for (int i = 0; i < num_of_comin_books; i++)
        {
            cout << "Enter the name of Comic no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Cominbook_lib[i].Comicbook_name);
            cout << "Enter the name of author of Comic no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Cominbook_lib[i].Comicbook_name);
            cout << "Rate Comic no." << i + 1 << " on the basis of Panel size.\n";
            fflush(stdin);
            getline(cin, Cominbook_lib[i].panelsize);
        }

        Coursebook *Coursebook_lib = new Coursebook[num_of_course_books];
        for (int i = 0; i < num_of_course_books; i++)
        {
            cout << "Enter the name of book no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Coursebook_lib[i].Coursebook_name);
            cout << "Enter the name of author of book no." << i + 1 << ".\n";
            fflush(stdin);
            getline(cin, Coursebook_lib[i].Coursebook_author);
            cout << "Rate book no." << i + 1 << " on the basis of learing value.\n";
            fflush(stdin);
            getline(cin, Coursebook_lib[i].learning_value);
        }
    }
    //Function to set Favorite books
    void SetFavBooks(string FavBook1, string FavBook2, string FavBook3)
    {
        FavBook1 = favorite_books[0];
        FavBook2 = favorite_books[1];
        FavBook3 = favorite_books[2];
    }
    //Function to display Fav books
    void Disp_Favbooks()
    {
        cout << "The Favorite books of " << reader_name << " are.\n";
        cout << "1." << favorite_books[0] << " \n.";
        cout << "2." << favorite_books[1] << " \n.";
        cout << "3." << favorite_books[2] << " \n.";
    }
    //Function to select books, Here I have to search in all kinds of books since the Freader can read all kinds of books
    void selectbooks(string book1)
    {
        char st1, st2, st3;
        if (number_of_books == 15)
        {
            cout << "Maximum number of books reached now you'll have to pay a fee to access further books.\n";
            cout << "Do you want to pay a fee? (Y/N)\n";
            char choice;
            fflush(stdin);
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                payfee();
            }
            else
            {
                cout << "Thanks for choosing our store\n";
                exit(0);
            }
        }
        for (int i = 0; i < num_of_comin_books; i++)
        {
            if (book1 == Cominbook_lib[i].Comicbook_name)
            {
                cout << "Book selected\n";
                number_of_books++;
                st1 = 'y';
            }
            else
                st1 = 'n';
        }
        for (int i = 0; i < num_of_manga_books; i++)
        {
            if (book1 == Mangabook_lib[i].Mangabook_name)
            {
                cout << "Book selected\n";
                number_of_books++;
                st2 = 'y';
            }
            else
                st2 = 'n';
        }

        for (int i = 0; i < num_of_course_books; i++)
        {
            if (book1 == Coursebook_lib[i].Coursebook_name)
            {
                cout << "Book selected\n";
                number_of_books++;
                st3 = 'y';
            }
            else
                st3 = 'n';
        }
        if (st1 == 'n' && st2 == 'n' && st3 == 'n')
        {
            cout << "Book not found.\n";
        }
    }
    //This function will ask the Freader to pay a $15 fee when he reaches the limit of 15 books
    void payfee()
    {
        cout << "Thank you for upgrading your package! Enter Y to pay $15 to keep reading\n";
        char choice;
        fflush(stdin);
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            cout << "Enjoy your reading!\n";
        }
        else
        {
            cout << "Thanks for using our service!\n";
            exit(0);
        }
    }
    //Function to calculate the reward of the freader on the basis of his mangameter, studyscace and comicfactor
    void Freader_reaward_val(float Mangameter_val, float comicfactor_val, float studyscale_val)
    {
        if (Mangameter_val > 50 && comicfactor_val > 8 && studyscale_val > 0.6)
        {
            cout << "Your mangameter value is greater than 50, Comicfactor value is greater than 8 and Study scale value is greater than 0.6 you'll get 10% discount.\n";
        }
        else
            cout << "Sorry no discount available for your current rating\n.";
    }
//copy constructor to make the copy of a freader
    Freader(Freader &obj) : Reader(this->reader_name, "freader")
    {

        this->monthly_fee = obj.monthly_fee;
        this->reader_type = obj.reader_type;
    }
};
int Freader::number_of_books = 0;

int main()
{
    
}
