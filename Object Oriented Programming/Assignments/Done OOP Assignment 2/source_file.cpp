//                                                                  Implementation of each requirement of the problem has been described with comments
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Reader
{ //This is the baseclass this will only hold only the name, favorite books and reader type of the reader. It will also keep a count of the number of freeders so that their numbers can be kept with in the limit
public:
    string reader_name;
    string reader_type;
    string favorite_books[3];
    int static num_of_freaders;
    Reader(string reader_name, string reader_type)
    {
        this->reader_name = reader_name;
        this->reader_type = reader_type;
        //Freader counting mechanism
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
};
int Reader ::num_of_freaders = 0;
//1st inherent class
class Mangaworm : virtual public Reader
{
public:
    char set1, set2, set3;
    int num_of_manga_books;
    float annual_fee;
    //Structure to hold the info about a book
    struct Mangabook
    {
        string Mangabook_name;
        string Mangabook_author;
        string artsyle;
    } * Mangabook_lib;
    Mangaworm(string reader_name, float annual_fee) : Reader(reader_name, "Mangaworm")
    {
        this->annual_fee = annual_fee;
        cout << "How many Mangas are avialable in the store?\n";
        fflush(stdin);
        cin >> num_of_manga_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 67 will be used to take input of books from the user about the name of the book, its author as well as the rating of the book so that the reader can also rate it.
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
    Mangaworm(string reader_name) : Reader(reader_name, "Freader")
    {
        cout << "How many Mangas are avialable in the store?\n";
        fflush(stdin);
        cin >> num_of_manga_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 67 will be used to take input of books from the user about the name of the book, its author as well as the rating of the book so that the reader can also rate it.
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
    //This function enables the user to set his favorite books, the array of these books is defined in the base class
    void setFavbooks(string book1, string book2, string book3)
    {

        for (int i = 0; i < num_of_manga_books; i++)
        {
            if (book1 == Mangabook_lib[i].Mangabook_name)
            {
                favorite_books[0] = book1;
                cout << "Book 01 added in Favbook list\n";
                set1 = 'y';
            }
            else if (i == num_of_manga_books)
            {
                cout << "The first book you entered does not exist\n";
                set1 = 'n';
            }
        }
        for (int i = 0; i < num_of_manga_books; i++)
        {
            if (book2 == Mangabook_lib[i].Mangabook_name)
            {
                favorite_books[1] = book2;
                cout << "Book 02 added in Favbook list\n";
                set2 = 'y';
            }
            else if (i == num_of_manga_books)
            {
                set2 = 'n';
                cout << "The second book you entered does not exist\n";
            }
        }
        for (int i = 0; i < num_of_manga_books; i++)
        {
            if (book3 == Mangabook_lib[i].Mangabook_name)
            {
                favorite_books[2] = book3;
                cout << "Book 03 added in Favbook list\n";
                set3 = 'y';
            }
            else if (i == num_of_manga_books)
            {
                cout << "The third book you entered does not exist\n";
                set3 = 'n';
            }
        }
    }
    //This function displays the info about a reader
    void Display_info_about_reader()
    {
        cout << "The name of the reader is " << reader_name << ".\n";
        cout << "The reader type is " << reader_type << ".\n";
        cout << "The annaul fee the reader pays is " << annual_fee << ".\n"
             << endl;
        Display_Fav_Books();
    }
    //This function displays the Favorite books of the reader
    void Display_Fav_Books()
    {
        cout << "The list of Favorite books of " << reader_name << " is:\n";
        if (set1 == 'y')
            cout << "Book: " << favorite_books[0] << ".\n";
        if (set2 == 'y')
            cout << "Book: " << favorite_books[1] << ".\n";
        if (set3 == 'y')
            cout << "Book: " << favorite_books[2] << ".\n";
    }
    //This function allows the user to select a book for reading
    void selectbooks(string book1)
    {
        for (int i = 0; i < num_of_manga_books; i++)
        {
            if (book1 == Mangabook_lib[i].Mangabook_name)
            {
                cout << "Book selected\n";
            }
            else if (i == num_of_manga_books)
                cout << "No such book exists try again!\n";
        }
    }
    //This function serves as the Mangameter and determines whether the user will be awarded or not.
    void Mangameter_val(float val)
    {
        if (val > 50 && val <= 100)
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
    char set1, set2, set3;
    int num_of_comin_books;
    float annual_fee;
    struct Comicbook
    {
        string Comicbook_name;
        string Comicbook_author;
        string panelsize;
    } * Cominbook_lib;
    Comicnerd(string reader_name, float annual_fee) : Reader(reader_name, "Comicnerd")
    {
        this->annual_fee = annual_fee;
        cout << "How many comics are available in the store?\n";
        fflush(stdin);
        cin >> num_of_comin_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 67 will be used to take input of books from the user about the name of the book, its author as well as the rating of the book so that the reader can also rate it.
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
    Comicnerd(string reader_name) : Reader(reader_name, "Freader")
    {
        cout << "How many comics are available in the store?\n";
        fflush(stdin);
        cin >> num_of_comin_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 67 will be used to take input of books from the user about the name of the book, its author as well as the rating of the book so that the reader can also rate it.
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
    //This function enables the user to set his favorite books, the array of these books is defined in the base class
    void setFavbooks(string book1, string book2, string book3)
    {

        for (int i = 0; i < num_of_comin_books; i++)
        {
            if (book1 == Cominbook_lib[i].Comicbook_name)
            {
                favorite_books[0] = book1;
                cout << "Book 01 added in Favbook list\n";
                set1 = 'y';
            }
            else if (i == num_of_comin_books)
            {
                cout << "The first book you entered does not exist\n";
                set1 = 'n';
            }
        }
        for (int i = 0; i < num_of_comin_books; i++)
        {
            if (book2 == Cominbook_lib[i].Comicbook_name)
            {
                favorite_books[1] = book2;
                cout << "Book 02 added in Favbook list\n";
                set2 = 'y';
            }
            else if (i == num_of_comin_books)

            {
                set2 = 'n';
                cout << "The second book you entered does not exist\n";
            }
        }
        for (int i = 0; i < num_of_comin_books; i++)
        {
            if (book3 == Cominbook_lib[i].Comicbook_name)
            {
                favorite_books[2] = book3;
                cout << "Book 03 added in Favbook list\n";
                set3 = 'y';
            }
            else if (i == num_of_comin_books)

            {
                cout << "The third book you entered does not exist\n";
                set3 = 'n';
            }
        }
    }
    //This function displays the info about a reader
    void Display_info_about_reader()
    {
        cout << "The name of the reader is " << reader_name << ".\n";
        cout << "The reader type is " << reader_type << ".\n";
        cout << "The annaul fee the reader pays is " << annual_fee << ".\n"
             << endl;
        Display_Fav_Books();
    }
    //This function displays the Favorite books of the reader
    void Display_Fav_Books()
    {
        cout << "The list of Favorite books of " << reader_name << " is:\n";
        if (set1 == 'y')
            cout << "Book: " << favorite_books[0] << ".\n";
        if (set2 == 'y')
            cout << "Book: " << favorite_books[1] << ".\n";
        if (set3 == 'y')
            cout << "Book: " << favorite_books[2] << ".\n";
    }
    //This function allows the user to select a book for reading

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
    //This function serves as the Comicfactor and determines whether the user will be awarded or not.

    void Comicfactor_val(float val)
    {
        if (val > 8 && val <= 10)
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
    char set1, set2, set3;
    int num_of_course_books;
    float annual_fee;
    struct Coursebook
    {
        string Coursebook_name;
        string Coursebook_author;
        string learning_value;
    } * Coursebook_lib;

    Studygeek(string reader_name, float annual_fee) : Reader(reader_name, "Studygeek")
    {
        this->annual_fee = annual_fee;
        cout << "How many Course books are available in the store?\n";
        fflush(stdin);
        cin >> num_of_course_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 67 will be used to take input of books from the user about the name of the book, its author as well as the rating of the book so that the reader can also rate it.
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
    Studygeek(string reader_name) : Reader(reader_name, "Freader")
    {
        cout << "How many Course books are available in the store?\n";
        fflush(stdin);
        cin >> num_of_course_books;
        //Form here on I would take the input of books form the user which will be available in the Store's library, the user can select these books.
        //I know this isn't an ideal solution since an ideal solution would've been a database for which filing was required and since we haven't learnt filing so far hence I have to individually take the input
        //of the books available from the user. The code from here to line number 67 will be used to take input of books from the user about the name of the book, its author as well as the rating of the book so that the reader can also rate it.
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
    //This function enables the user to set his favorite books, the array of these books is defined in the base class
    void setFavbooks(string book1, string book2, string book3)
    {

        for (int i = 0; i < num_of_course_books; i++)
        {
            if (book1 == Coursebook_lib[i].Coursebook_name)
            {
                favorite_books[0] = book1;
                cout << "Book 01 added in Favbook list\n";
                set1 = 'y';
            }
            else if (i == num_of_course_books)
            {
                cout << "The first book you entered does not exist\n";
                set1 = 'n';
            }
        }
        for (int i = 0; i < num_of_course_books; i++)
        {
            if (book2 == Coursebook_lib[i].Coursebook_name)
            {
                favorite_books[1] = book2;
                cout << "Book 02 added in Favbook list\n";
                set2 = 'y';
            }
            else if (i == num_of_course_books)
            {
                set2 = 'n';
                cout << "The second book you entered does not exist\n";
            }
        }
        for (int i = 0; i < num_of_course_books; i++)
        {
            if (book3 == Coursebook_lib[i].Coursebook_name)
            {
                favorite_books[2] = book3;
                cout << "Book 03 added in Favbook list\n";
                set3 = 'y';
            }
            else if (i == num_of_course_books)
            {
                cout << "The third book you entered does not exist\n";
                set3 = 'n';
            }
        }
    }
    //This function displays the info about a reader

    void Display_info_about_reader()
    {
        cout << "The name of the reader is " << reader_name << ".\n";
        cout << "The reader type is " << reader_type << ".\n";
        cout << "The annaul fee the reader pays is " << annual_fee << ".\n"
             << endl;
        Display_Fav_Books();
    }
    //This function displays the Favorite books of the reader

    void Display_Fav_Books()
    {
        cout << "The list of Favorite books of " << reader_name << " is:\n";
        if (set1 == 'y')
            cout << "Book: " << favorite_books[0] << ".\n";
        if (set2 == 'y')
            cout << "Book: " << favorite_books[1] << ".\n";
        if (set3 == 'y')
            cout << "Book: " << favorite_books[2] << ".\n";
    }
    //This function allows the user to select a book for reading

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
    //This function serves as the StudyScale and determines whether the user will be awarded or not.

    void StudyScale_val(float val)
    {
        if (val > 0.6 && val <= 1)
        {
            cout << "Your StudyScale value is greater than 0.6 you'll get 10% discount.\n";
        }
        else
            cout << "Sorry no discount available for your current rating\n.";
    }
};

class Freader : public Mangaworm, public Comicnerd, public Studygeek
{
public:
    float monthly_fee;
    static int number_of_books;
    char setManga, setComic, setStudy;
    char set1, set2, set3;
    Freader(string reader_name, float monthly_fee) : Reader(reader_name, "Freader"), Mangaworm(reader_name), Comicnerd(reader_name), Studygeek(reader_name)
    {
        this->monthly_fee = monthly_fee;
    }
    //This function enables the user to set his favorite books, the array of these books is defined in the base class
    void setFavbooks(string book1, string book2, string book3)
    {
        //For book 01
        {
            for (int i = 0; i < num_of_manga_books; i++)
            {
                if (book1 == Mangabook_lib[i].Mangabook_name)
                {
                    favorite_books[0] = book1;
                    cout << "Book 01 added in Favbook list\n";
                    setManga = 'y';
                    set1 = 'y';
                }
                else
                {
                    // cout << "The first book you entered does not exist\n";
                    setManga = 'n';
                }
            }
            for (int i = 0; i < num_of_comin_books; i++)
            {
                if (book1 == Cominbook_lib[i].Comicbook_name)
                {
                    favorite_books[0] = book1;
                    cout << "Book 01 added in Favbook list\n";
                    setComic = 'y';
                    set1 == 'y';
                }
                else if (i == num_of_comin_books)
                {
                    // cout << "The first book you entered does not exist\n";
                    setComic = 'n';
                }
            }
            for (int i = 0; i < num_of_course_books; i++)
            {
                if (book1 == Coursebook_lib[i].Coursebook_name)
                {
                    favorite_books[0] = book1;
                    cout << "Book 01 added in Favbook list\n";
                    setStudy = 'y';
                    set1 == 'y';
                }
                else if (i == num_of_course_books)
                {
                    // cout << "The first book you entered does not exist\n";
                    setStudy = 'n';
                    set1 == 'y';
                }
            }
            if (setManga == 'n' && setStudy == 'n' && setComic == 'n')
            {
                cout << "Book 1 not found.\n";
                set1 = 'n';
            }
        }

        //For book 2
        {
            for (int i = 0; i < num_of_manga_books; i++)
            {
                if (book2 == Mangabook_lib[i].Mangabook_name)
                {
                    favorite_books[1] = book2;
                    cout << "Book 02 added in Favbook list\n";
                    setManga = 'y';
                    set2 == 'y';
                }
                else if (i == num_of_manga_books)
                {
                    setManga = 'n';
                    // cout << "The second book you entered does not exist\n";
                }
            }
            for (int i = 0; i < num_of_comin_books; i++)
            {
                if (book2 == Cominbook_lib[i].Comicbook_name)
                {
                    favorite_books[1] = book2;
                    cout << "Book 02 added in Favbook list\n";
                    setComic = 'y';
                    set2 == 'y';
                }
                else if (i == num_of_comin_books)

                {
                    setComic = 'n';
                    // cout << "The second book you entered does not exist\n";
                }
            }
            for (int i = 0; i < num_of_course_books; i++)
            {
                if (book2 == Coursebook_lib[i].Coursebook_name)
                {
                    favorite_books[1] = book2;
                    cout << "Book 02 added in Favbook list\n";
                    setStudy = 'y';
                    set2 == 'y';
                }
                else if (i == num_of_course_books)
                {
                    setStudy = 'n';
                    // cout << "The second book you entered does not exist\n";
                }
            }
            if (setManga == 'n' && setStudy == 'n' && setComic == 'n')
            {
                cout << "Book 2 not found.\n";
                set2 = 'n';
            }
        }
        //For book 3
        {
            for (int i = 0; i < num_of_manga_books; i++)
            {
                if (book3 == Mangabook_lib[i].Mangabook_name)
                {
                    favorite_books[2] = book3;
                    cout << "Book 03 added in Favbook list\n";
                    setManga = 'y';
                    set3 = 'y';
                }
                else if (i == num_of_manga_books)
                {
                    // cout << "The third book you entered does not exist\n";
                    setManga = 'n';
                }
            }
            for (int i = 0; i < num_of_comin_books; i++)
            {
                if (book3 == Cominbook_lib[i].Comicbook_name)
                {
                    favorite_books[2] = book3;
                    cout << "Book 03 added in Favbook list\n";
                    setComic = 'y';
                    set3 = 'y';
                }
                else if (i == num_of_comin_books)

                {
                    cout << "The third book you entered does not exist\n";
                    setComic = 'n';
                }
            }
            for (int i = 0; i < num_of_course_books; i++)
            {
                if (book3 == Coursebook_lib[i].Coursebook_name)
                {
                    favorite_books[2] = book3;
                    cout << "Book 03 added in Favbook list\n";
                    setStudy = 'y';
                    set3 = 'y';
                }
                else if (i == num_of_course_books)
                {
                    cout << "The third book you entered does not exist\n";
                    setStudy = 'n';
                }
            }
            if (setManga == 'n' && setStudy == 'n' && setComic == 'n')
            {
                cout << "Book 3 not found.\n";
                set3 = 'n';
            }
        }
    }
    //This function displays the info about a reader

    void Display_info_about_reader()
    {
        cout << "The name of the reader is " << reader_name << ".\n";
        cout << "The reader type is " << reader_type << ".\n";
        cout << "The annaul fee the reader pays is " << monthly_fee << ".\n"
             << endl;
        Display_Fav_Books();
    }
    //This function displays the Favorite books of the reader

    void Display_Fav_Books()
    {
        cout << "The list of Favorite books of " << reader_name << " is:\n";
        if (set1 == 'y')
            cout << "Book: " << favorite_books[0] << ".\n";
        if (set2 == 'y')
            cout << "Book: " << favorite_books[1] << ".\n";
        if (set3 == 'y')
            cout << "Book: " << favorite_books[2] << ".\n";
    }
    //This function allows the user to select a book for reading

    void selectbooks(string book1)
    {
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
            }
            else
            {
                setManga = 'n';
                // cout << "No such book exists try again!\n";
            }
        }
        for (int i = 0; i < num_of_comin_books; i++)
        {
            if (book1 == Cominbook_lib[i].Comicbook_name)
            {
                cout << "Book selected\n";
                number_of_books++;
            }
            else
            {
                setComic = 'n';
                // cout << "No such book exists try again!\n";
            }
        }
        for (int i = 0; i < num_of_course_books; i++)
        {
            if (book1 == Coursebook_lib[i].Coursebook_name)
            {
                cout << "Book selected\n";
                number_of_books++;
            }
            else
            {
                setStudy = 'n';
                // cout << "No such book exists try again!\n";
            }
        }
        if (setManga == 'n' && setStudy == 'n' && setComic == 'n')
            cout << "No such book exists.\n";
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
    //This function serves as the decider and determines whether the user will be awarded or not.

    void Freader_reward(float Mangameter_val, float Comicfactor_Val, float StudyScale_val)
    {
        if ((Mangameter_val > 50 && Mangameter_val <= 100) && (Comicfactor_Val > 8 && Comicfactor_Val <= 10) && (StudyScale_val > 0.6 && StudyScale_val <= 1))
        {
            cout << "Your Mangameter Val is greater than 50, Comicfactor val is greater than 8 and StudyScale Val is greater than 0.6.\nYou will get a 10% discount on the next purchase you make.\n";
        }
        else
            cout << "You are not eligible to avial disocunt.\n";
    }
    //copy constructor of freader
    Freader(Freader &ob) : Reader(ob.reader_name, "Freader"), Mangaworm(ob.reader_name), Comicnerd(ob.reader_name), Studygeek(ob.reader_name)
    {
        reader_name = ob.reader_name;
        reader_type = ob.reader_type;
        num_of_manga_books = ob.num_of_manga_books;
        num_of_comin_books = ob.num_of_comin_books;
        num_of_course_books = ob.num_of_course_books;
        monthly_fee = ob.monthly_fee;
        setManga = ob.setManga;
        setComic = ob.setComic;
        setStudy = ob.setStudy;
        set1 = ob.set1;
        set2 = ob.set2;
        set3 = ob.set3;
        num_of_freaders = ob.num_of_freaders;
        number_of_books = ob.number_of_books;
        for (int i = 0; i < ob.num_of_manga_books; i++)
        {
            Mangabook_lib[i].Mangabook_name = ob.Mangabook_lib[i].Mangabook_name;
            Mangabook_lib[i].Mangabook_author = ob.Mangabook_lib[i].Mangabook_author;
            Mangabook_lib[i].artsyle = ob.Mangabook_lib[i].artsyle;
        }
        for (int i = 0; i < num_of_comin_books; i++)
        {
            Cominbook_lib[i].Comicbook_name = ob.Cominbook_lib[i].Comicbook_name;
            Cominbook_lib[i].Comicbook_author = ob.Cominbook_lib[i].Comicbook_author;
            Cominbook_lib[i].panelsize = ob.Cominbook_lib[i].panelsize;
        }
        for (int i = 0; i < num_of_course_books; i++)
        {
            Coursebook_lib[i].Coursebook_author = ob.Coursebook_lib[i].Coursebook_author;
            Coursebook_lib[i].Coursebook_name = ob.Coursebook_lib[i].Coursebook_name;
            Coursebook_lib[i].learning_value = ob.Coursebook_lib[i].learning_value;
        }

        for (int i = 0; i < 3; i++)
        {
            favorite_books[i] = ob.favorite_books[i];
        }
    }
};
int Freader::number_of_books = 0;
int main()
{
}