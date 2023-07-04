#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;
class Lib
{
public:
    char bookname[100], authorname[50], book_id[20], student_id[50];
    int quantity_of_book, Type_of_book_id, price_of_books;
    Lib()
    {
        strcpy(bookname, "Nill");
        strcpy(authorname, "Nill");
        strcpy(book_id, "Nill");
        strcpy(student_id, "Nill");
        quantity_of_book = 0;
        Type_of_book_id = 0;
        price_of_books = 0;
    }
    void mainmenu()
    {
        system("cls");
        int i;
        cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"
             << "\n\t\t\t    Made By:\n"
             << "\n\t\t    Bilal Ahmed Khan (20k-0183)\n"
             << "\n\t\t    Zulnoor Siddiqui (20k-1090)\n"
             << "\n\t\t    Mohammad Wamiq Akram (20k-1857)\n";
        cout << "\n\t\t>>Please Choose Any Option To login \n";
        cout << "\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
        cout << "\n\t\tEnter your choice : ";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            system("cls");
            studentmenu();
            break;
        }
        case 2:
        {
            pass();
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }

        default:
        {
            cout << "\n\t\tPlease choose a valid option\n";
            getch();
            system("CLS");
            mainmenu();
            break;
        }
        }
    }
    void studentmenu()
    {
        int i;
        cout << "\n\t************ WELCOME STUDENT ************\n";
        cout << "\n\t\t>>Please Choose One Option:\n";
        cout << "\n\t\t1.View Available books\n\n\t\t2.Search for the required book\n\n\t\t3.Return to main menu\n\n\t\t4.EXIT\n";
        cout << "\n\t\tEnter your choice : ";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            booklist(1);
            break;
        }
        case 2:
        {
            search_for_book(1);
            break;
        }
        case 3:
        {
            system("cls");
            mainmenu();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            studentmenu();
            break;
        }
        }
    }
    void pass()
    {
        int i = 0;
        char ch, st[21], ch1[21] = {"pass"};
        cout << "\n\t\tEnter Password : ";
        while (1)
        {
            ch = getch();
            if (ch == 13) //ASCII value of ENTER is 13 therefore it stops taking input when we press ENTER and store \0 in the last slot of the password array
            {
                st[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0) //ASCII value of BACKSPACE is 8 therefore if the user presses backspace there is a decrement in the count of the array
            {
                i--;
                cout << "\type_of_book_chosen_by_user \type_of_book_chosen_by_user";
            }
            else
            {
                cout << "*";
                st[i] = ch;
                i++;
            }
        }
        ifstream inf("password.txt");
        inf >> ch1;
        inf.close();
        for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
            ;
        if (st[i] == '\0' && ch1[i] == '\0')
        {
            system("cls");
            Librarian_Menu();
        }
        else
        {
            cout << "\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
            getch();
            system("cls");
            mainmenu();
        }
    }
    void Librarian_Menu()
    {
        int i;
        cout << "\n\t************ WELCOME LIBRARIAN ************\n";
        cout << "\n\t\t>>Choose any of the options below\n";
        cout << "\n\t\t1.View Available books\n\n\t\t2.Search for a required book\n\n\t\t3.Modify or Add a book to the booklist\n\n\t\t4.Issue Book to a Student\n\n\t\t5.Change current password\n\n\t\t6.Return to main menu\n\n\t\t7.EXIT\n";
        cout << "\n\t\tEnter your choice : ";
        cin >> i;
        switch (i)
        {
        case 1:
            booklist(2);
            break;
        case 2:
            search_for_book(2);
            break;
        case 3:
            modify();
            break;
        case 4:
            book_issue();
            break;
        case 5:
            password();
            break;
            
        case 6:
            system("cls");
            mainmenu();
            break;
        case 7:
            exit(0);
        default:
            cout << "\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            Librarian_Menu();
        }
    }
    void password()
    {
        int i = 0, j = 0;
        char ch, st[21], ch1[21] = {"12345"};
        system("cls");
        cout << "\n\n\t\tEnter Old Password : ";
        while (1)
        {
            ch = getch();
            if (ch == 13)
            {
                st[i] = '\0';
                break;
            }
            else if (ch == 8 && i > 0)
            {
                i--;
                cout << "\type_of_book_chosen_by_user \type_of_book_chosen_by_user";
            }
            else
            {
                cout << "*";
                st[i] = ch;
                i++;
            }
        }
        ifstream intf("password.txt");
        intf >> ch1;
        intf.close();
        for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
            ;
        if (st[i] == '\0' && ch1[i] == '\0')
        {
            system("cls");
            cout << "\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
            cout << "\n\t\tEnter New Password : ";
            fflush(stdin);
            i = 0;
            while (1)
            {
                j++;
                ch = getch();
                if (ch == 13)
                {
                    for (i = 0; st[i] != ' ' && st[i] != '\0'; i++)
                        ;
                    if (j > 20 || st[i] == ' ')
                    {
                        cout << "\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                        getch();
                        system("cls");
                        password();
                        Librarian_Menu();
                    }
                    st[i] = '\0';
                    break;
                }
                else if (ch == 8 && i > 0)
                {
                    i--;
                    cout << "\type_of_book_chosen_by_user \type_of_book_chosen_by_user";
                }
                else
                {
                    cout << "*";
                    st[i] = ch;
                    i++;
                }
            }
            ofstream outf("password.txt");
            outf << st;
            outf.close();
            cout << "\n\n\t\tYour Password has been changed Successfully.";
            cout << "\n\t\tPress any key to continue......";
            getch();
            system("cls");
            Librarian_Menu();
        }
        else
        {
            cout << "\n\n\t\tPassword is incorrect.....\n";
            cout << "\n\t\tEnter 1 for retry or 2 for menu";
            cin >> i;
            if (i == 1)
            {
                system("cls");
                password();
            }
            else
            {
                system("cls");
                Librarian_Menu();
            }
        }
    }
    void getdata()
    {
        int i;
        fflush(stdin);
        cout << "\n\t\tEnter the details :-\n";
        cout << "\n\t\tEnter Book's Name : ";
        cin.getline(bookname, 100);
        for (i = 0; bookname[i] != '\0'; i++)
        {
            if (bookname[i] >= 'a' && bookname[i] <= 'z')
                bookname[i] -= 32;
        }
        cout << "\n\t\tEnter Author's Name : ";
        cin.getline(authorname, 50);
        cout << "\n\t\tEnter Publication name : ";
        cin.getline(student_id, 50);
        cout << "\n\t\tEnter Book's ID : ";
        cin.getline(book_id, 20);
        cout << "\n\t\tEnter Book's Price : ";
        cin >> price_of_books;
        cout << "\n\t\tEnter Book's Quantity : ";
        cin >> quantity_of_book;
    }
    void show_book_info(int i)
    {
        cout << "\n\t\tBook Name : " << bookname << endl;
        cout << "\n\t\tBook's Author Name : " << authorname << endl;
        cout << "\n\t\tBook's ID : " << book_id << endl;
        cout << "\n\t\tBook's Publication : " << student_id << endl;
        if (i == 2)
        {
            cout << "\n\t\tBook's Price : " << price_of_books << endl;
            cout << "\n\t\tBook's Quantity : " << quantity_of_book << endl;
        }
    }
    void booklist(int i)
    {
        int type_of_book_chosen_by_user, count = 0;
        system("cls");
        type_of_book_chosen_by_user = booktype_choose(i);
        system("cls");
        ifstream intf("Booksdata.txt", ios::binary);
        if (!intf)
            cout << "\n\t\tFile Not Found.";
        else
        {
            cout << "\n\t    ************ Book List ************ \n\n";
            intf.read((char *)this, sizeof(*this));
            while (!intf.eof())
            {
                if (type_of_book_chosen_by_user == Type_of_book_id)
                {
                    if (quantity_of_book == 0 && i == 1)
                    {
                    }
                    else
                    {
                        count++;
                        cout << "\n\t\t********** " << count << ". ********** \n";
                        show_book_info(i);
                    }
                }
                intf.read((char *)this, sizeof(*this));
            }
        }
        cout << "\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        if (i == 1)
            studentmenu();
        else
            Librarian_Menu();
    }
    void modify()
    {
        char ch, st1[100];
        int i = 0, type_of_book_chosen_by_user, cont = 0;
        system("cls");
        cout << "\n\t\t>>Please Choose one option :-\n";
        cout << "\n\t\t1.Modification In Current Books\n\n\t\t2.Add New Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n";
        cout << "\n\n\t\tEnter your choice : ";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            system("cls");
            type_of_book_chosen_by_user = booktype_choose(2);
            ifstream intf1("Booksdata.txt", ios::binary);
            if (!intf1)
            {
                cout << "\n\t\tFile Not Found\n";
                cout << "\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                Librarian_Menu();
            }
            intf1.close();
            system("cls");
            cout << "\n\t\tPlease Choose One Option :-\n";
            cout << "\n\t\t1.Search By Book Name\n\n\t\t2.Search By Book's ID\n";
            cout << "\n\t\tEnter Your Choice : ";
            cin >> i;
            fflush(stdin);
            if (i == 1)
            {
                system("cls");
                cout << "\n\t\tEnter Book Name : ";
                cin.getline(st1, 100);
                system("cls");
                fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
                intf.seekg(0);
                intf.read((char *)this, sizeof(*this));
                while (!intf.eof())
                {
                    for (i = 0; type_of_book_chosen_by_user == Type_of_book_id && bookname[i] != '\0' && st1[i] != '\0' && (st1[i] == bookname[i] || st1[i] == bookname[i] + 32); i++)
                        ;
                    if (bookname[i] == '\0' && st1[i] == '\0')
                    {
                        cont++;
                        getdata();
                        intf.seekp(intf.tellp() - sizeof(*this));
                        intf.write((char *)this, sizeof(*this));
                        break;
                    }
                    intf.read((char *)this, sizeof(*this));
                }
                intf.close();
            }
            else if (i == 2)
            {
                cout << "\n\t\tEnter Book's ID : ";
                cin.getline(st1, 100);
                system("cls");
                fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
                intf.seekg(0);
                intf.read((char *)this, sizeof(*this));
                while (!intf.eof())
                {
                    for (i = 0; type_of_book_chosen_by_user == Type_of_book_id && book_id[i] != '\0' && st1[i] != '\0' && st1[i] == book_id[i]; i++)
                        ;
                    if (book_id[i] == '\0' && st1[i] == '\0')
                    {
                        cont++;
                        getdata();
                        intf.seekp(intf.tellp() - sizeof(*this));
                        intf.write((char *)this, sizeof(*this));
                        break;
                    }
                    intf.read((char *)this, sizeof(*this));
                }

                intf.close();
            }
            else
            {
                cout << "\n\t\tIncorrect Input.....:(\n";
                cout << "\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                modify();
            }
            if (cont == 0)
            {
                cout << "\n\t\tBook Not Found.\n";
                cout << "\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                modify();
            }
            else
                cout << "\n\t\tUpdate Successful.\n";

            break;
        }
        case 2:
        {
            system("cls");
            Type_of_book_id = booktype_choose(2);
            system("cls");
            getdata();
            ofstream outf("Booksdata.txt", ios::app | ios::binary);
            outf.write((char *)this, sizeof(*this));
            outf.close();
            cout << "\n\t\tBook added Successfully.\n";

            break;
        }
        case 3:
        {
            system("cls");
            type_of_book_chosen_by_user = booktype_choose(2);
            ifstream intf1("Booksdata.txt", ios::binary);
            if (!intf1)
            {
                cout << "\n\t\tFile Not Found\n";
                cout << "\n\t\tPress any key to continue.....";
                getch();
                intf1.close();
                system("cls");
                Librarian_Menu();
            }
            intf1.close();
            system("cls");
            cout << "\n\t\tPlease Choose One Option for deletion:-\n";
            cout << "\n\t\t1.By Book Name\n\n\t\t2.By Book's ID\n";
            cout << "\n\t\tEnter Your Choice : ";
            cin >> i;
            fflush(stdin);
            if (i == 1)
            {
                system("cls");
                cout << "\n\t\tEnter Book Name : ";
                cin.getline(st1, 100);
                ofstream outf("temp.txt", ios::app | ios::binary);
                ifstream intf("Booksdata.txt", ios::binary);
                intf.read((char *)this, sizeof(*this));
                while (!intf.eof())
                {
                    for (i = 0; type_of_book_chosen_by_user == Type_of_book_id && bookname[i] != '\0' && st1[i] != '\0' && (st1[i] == bookname[i] || st1[i] == bookname[i] + 32); i++)
                        ;
                    if (bookname[i] == '\0' && st1[i] == '\0')
                    {
                        cont++;
                        intf.read((char *)this, sizeof(*this));
                    }
                    else
                    {
                        outf.write((char *)this, sizeof(*this));
                        intf.read((char *)this, sizeof(*this));
                    }
                }

                intf.close();
                outf.close();
                remove("Booksdata.txt");
                rename("temp.txt", "Booksdata.txt");
            }
            else if (i == 2)
            {
                cout << "\n\t\tEnter Book's ID : ";
                cin.getline(st1, 100);
                ofstream outf("temp.txt", ios::app | ios::binary);
                ifstream intf("Booksdata.txt", ios::binary);
                intf.read((char *)this, sizeof(*this));
                while (!intf.eof())
                {
                    for (i = 0; type_of_book_chosen_by_user == Type_of_book_id && book_id[i] != '\0' && st1[i] != '\0' && st1[i] == book_id[i]; i++)
                        ;
                    if (book_id[i] == '\0' && st1[i] == '\0')
                    {
                        cont++;
                        intf.read((char *)this, sizeof(*this));
                    }
                    else
                    {
                        outf.write((char *)this, sizeof(*this));
                        intf.read((char *)this, sizeof(*this));
                    }
                }
                outf.close();
                intf.close();
                remove("Booksdata.txt");
                rename("temp.txt", "Booksdata.txt");
            }
            else
            {
                cout << "\n\t\tIncorrect Input.....:(\n";
                cout << "\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                modify();
            }
            if (cont == 0)
            {
                cout << "\n\t\tBook Not Found.\n";
                cout << "\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                modify();
            }
            else
                cout << "\n\t\tDeletion Successful.\n";
            break;
        }
        case 4:
        {
            system("cls");
            Librarian_Menu();
            break;
        }
        default:
        {
            cout << "\n\t\tWrong Input.\n";
            cout << "\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            modify();
            break;
        }
        }

        cout << "\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        Librarian_Menu();
    }
    void search_for_book(int x)
    {
        int i, type_of_book_chosen_by_user, cont = 0;
        char ch[100];
        system("cls");
        type_of_book_chosen_by_user = booktype_choose(x);
        ifstream intf("Booksdata.txt", ios::binary);
        if (!intf)
        {
            cout << "\n\t\tFile Not Found.\n";
            cout << "\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if (x == 1)
                studentmenu();
            else
                Librarian_Menu();
        }

        system("cls");
        cout << "\n\t\tPlease Choose one option :-\n";
        cout << "\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
        cout << "\n\t\tEnter Your Choice : ";
        cin >> i;
        fflush(stdin);
        intf.read((char *)this, sizeof(*this));
        if (i == 1)
        {
            cout << "\n\t\tEnter Book's Name : ";
            cin.getline(ch, 100);
            system("cls");
            while (!intf.eof())
            {
                for (i = 0; type_of_book_chosen_by_user == Type_of_book_id && quantity_of_book != 0 && bookname[i] != '\0' && ch[i] != '\0' && (ch[i] == bookname[i] || ch[i] == bookname[i] + 32); i++)
                    ;
                if (bookname[i] == '\0' && ch[i] == '\0')
                {
                    cout << "\n\t\tBook Found :-\n";
                    show_book_info(x);
                    cont++;
                    break;
                }
                intf.read((char *)this, sizeof(*this));
            }
        }
        else if (i == 2)
        {
            cout << "\n\t\tEnter Book's ID : ";
            cin.getline(ch, 100);
            system("cls");
            while (!intf.eof())
            {
                for (i = 0; type_of_book_chosen_by_user == Type_of_book_id && quantity_of_book != 0 && book_id[i] != '\0' && ch[i] != '\0' && ch[i] == book_id[i]; i++)
                    ;
                if (book_id[i] == '\0' && ch[i] == '\0')
                {
                    cout << "\n\t\tBook Found :-\n";
                    show_book_info(x);
                    cont++;
                    break;
                }
                intf.read((char *)this, sizeof(*this));
            }
        }
        else
        {
            cont++;
            cout << "\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            search_for_book(x);
        }
        intf.close();
        if (cont == 0)
            cout << "\n\t\tThis Book is not available :( \n";

        cout << "\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        if (x == 1)
            studentmenu();
        else
            Librarian_Menu();
    }
    int booktype_choose(int x)
    {
        int i;
        cout << "\n\t\t>>Please Choose one type of book :-\n";
        cout << "\n\t\t1.BIT\n\n\t\t2.EE\n\n\t\t3.EC\n\n\t\t4.CIVIL\n\n\t\t5.MECHANICAL\n\n\t\t6.1ST YEAR\n\n\t\t7.Go to menu\n";
        cout << "\n\t\tEnter youur choice : ";
        cin >> i;
        switch (i)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 4;
            break;
        case 5:
            return 5;
            break;
        case 6:
            return 6;
            break;
        case 7:
            system("cls");
            if (x == 1)
                studentmenu();
            else
                Librarian_Menu();
        default:
            cout << "\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            booktype_choose(x);
        }
    }
    void book_issue()
    {
        char st[50], st1[20];
        int type_of_book_chosen_by_user, i, j, d, m, y, dd, mm, yy, cont = 0;
        system("cls");
        cout << "\n\t\t->Please Choose one option :-\n";
        cout << "\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search studentmenu who isuued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return Book\n\n\t\t6.Go back to menu\n\n\t\tEnter Your Choice : ";
        cin >> i;
        fflush(stdin);
        if (i == 1)
        {
            system("cls");
            type_of_book_chosen_by_user = booktype_choose(2);
            system("cls");
            fflush(stdin);
            cout << "\n\t\t->Please Enter Details :-\n";
            cout << "\n\t\tEnter Book Name : ";
            cin.getline(bookname, 100);
            cout << "\n\t\tEnter Book's ID : ";
            cin.getline(book_id, 20);
            //strcpy(st,book_id);
            der(book_id, type_of_book_chosen_by_user, 1);
            cout << "\n\t\tEnter Student Name : ";
            cin.getline(authorname, 100);
            cout << "\n\t\tEnter Student's ID : ";
            cin.getline(student_id, 20);
            cout << "\n\t\tEnter date : ";
            cin >> quantity_of_book >> Type_of_book_id >> price_of_books;
            ofstream outf("studentmenu.txt", ios::binary | ios::app);
            outf.write((char *)this, sizeof(*this));
            outf.close();
            cout << "\n\n\t\tIssue Successfully.\n";
        }
        else if (i == 2)
        {
            ifstream intf("studentmenu.txt", ios::binary);
            system("cls");
            cout << "\n\t\t->The Details are :-\n";
            intf.read((char *)this, sizeof(*this));
            i = 0;
            while (!intf.eof())
            {
                i++;
                cout << "\n\t\t********** " << i << ". ********** \n";
                cout << "\n\t\tStudent Name : " << authorname << "\n\t\t"
                     << "Student's ID : " << student_id << "\n\t\t"
                     << "Book Name : " << bookname << "\n\t\t"
                     << "Book's ID : " << book_id << "\n\t\t"
                     << "Date : " << quantity_of_book << "/" << Type_of_book_id << "/" << price_of_books << "\n";
                intf.read((char *)this, sizeof(*this));
            }
            intf.close();
        }
        else if (i == 3)
        {
            system("cls");
            fflush(stdin);
            cout << "\n\t\t->Please Enter Details :-\n";
            cout << "\n\n\t\tEnter Student Name : ";
            cin.getline(st, 50);
            cout << "\n\n\t\tEnter Student's ID : ";
            cin.getline(st1, 20);
            system("cls");
            ifstream intf("studentmenu.txt", ios::binary);
            intf.read((char *)this, sizeof(*this));
            cont = 0;
            while (!intf.eof())
            {
                for (i = 0; student_id[i] != '\0' && st1[i] != '\0' && st1[i] == student_id[i]; i++)
                    ;
                if (student_id[i] == '\0' && st1[i] == '\0')
                {
                    cont++;
                    if (cont == 1)
                    {
                        cout << "\n\t\t->The Details are :-\n";
                        cout << "\n\t\tStudent Name : " << authorname;
                        cout << "\n\t\tStudent's ID : " << student_id;
                    }
                    cout << "\n\n\t\t******* " << cont << ". Book details *******\n";
                    cout << "\n\t\tBook Name : " << bookname;
                    cout << "\n\t\tBook's ID : " << book_id;
                    cout << "\n\t\tDate : " << quantity_of_book << "/" << Type_of_book_id << "/" << price_of_books << "\n";
                }
                intf.read((char *)this, sizeof(*this));
            }
            intf.close();
            if (cont == 0)
                cout << "\n\t\tNo record found.";
        }
        else if (i == 4)
        {
            system("cls");
            fflush(stdin);
            cout << "\n\t\t->Please Enter Details :-\n";
            cout << "\n\n\t\tEnter Student's ID : ";
            cin.getline(st, 50);
            cout << "\n\t\tEnter Book's ID : ";
            cin.getline(st1, 20);
            fstream intf("studentmenu.txt", ios::in | ios::out | ios::ate | ios::binary);
            intf.seekg(0);
            intf.read((char *)this, sizeof(*this));
            while (!intf.eof())
            {
                for (i = 0; book_id[i] != '\0' && st1[i] != '\0' && st1[i] == book_id[i]; i++)
                    ;
                for (j = 0; student_id[j] != '\0' && st[j] != '\0' && st[j] == student_id[j]; j++)
                    ;
                if (book_id[i] == '\0' && student_id[j] == '\0' && st[j] == '\0' && st1[i] == '\0')
                {
                    d = quantity_of_book;
                    m = Type_of_book_id;
                    y = price_of_books;
                    cout << "\n\t\tEnter New Date : ";
                    cin >> quantity_of_book >> Type_of_book_id >> price_of_books;
                    fine(d, m, y, quantity_of_book, Type_of_book_id, price_of_books); //fn1
                    intf.seekp(intf.tellp() - sizeof(*this));                         //fn3
                    intf.write((char *)this, sizeof(*this));                          //fn5
                    cout << "\n\n\t\tReissue successfully.";                          //fn3
                    break;
                }
                intf.read((char *)this, sizeof(*this));
            }
            intf.close();
        }
        else if (i == 5)
        {
            system("cls");
            type_of_book_chosen_by_user = booktype_choose(2);
            system("cls");
            fflush(stdin);
            cout << "\n\t\t->Please Enter Details :-\n";
            cout << "\n\t\tEnter Book's ID : ";
            cin.getline(st1, 20);
            der(st1, type_of_book_chosen_by_user, 2);
            cout << "\n\n\t\tEnter Student's ID : ";
            cin.getline(st, 20);
            cout << "\n\t\tEnter Present date : ";
            cin >> d >> m >> y;
            ofstream outf("temp.txt", ios::app | ios::binary);
            ifstream intf("studentmenu.txt", ios::binary);
            intf.read((char *)this, sizeof(*this));
            while (!intf.eof())
            {
                for (i = 0; book_id[i] != '\0' && st1[i] != '\0' && st1[i] == book_id[i]; i++)
                    ;
                for (j = 0; student_id[j] != '\0' && st[j] != '\0' && st[j] == student_id[j]; j++)
                    ;
                if (book_id[i] == '\0' && student_id[j] == '\0' && st[j] == '\0' && st1[i] == '\0' && cont == 0)
                {
                    cont++;
                    intf.read((char *)this, sizeof(*this));
                    fine(quantity_of_book, Type_of_book_id, price_of_books, d, m, y);
                    cout << "\n\t\tReturned successfully.";
                }
                else
                {
                    outf.write((char *)this, sizeof(*this));
                    intf.read((char *)this, sizeof(*this));
                }
            }

            intf.close();
            outf.close();
            getch();
            remove("studentmenu.txt");
            rename("temp.txt", "studentmenu.txt");
        }
        else if (i == 6)
        {
            system("cls");
            Librarian_Menu();
        }
        else
            cout << "\n\t\tWrong Input.\n";

        cout << "\n\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        Librarian_Menu();
    }
    void der(char st[], int type_of_book_chosen_by_user, int x)
    {
        int i, cont = 0;
        fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
        intf.seekg(0);
        intf.read((char *)this, sizeof(*this));
        while (!intf.eof())
        {
            for (i = 0; type_of_book_chosen_by_user == Type_of_book_id && book_id[i] != '\0' && st[i] != '\0' && st[i] == book_id[i]; i++)
                ;
            if (book_id[i] == '\0' && st[i] == '\0')
            {
                cont++;
                if (x == 1)
                {
                    quantity_of_book--;
                }
                else
                {
                    quantity_of_book++;
                }
                intf.seekp(intf.tellp() - sizeof(*this));
                intf.write((char *)this, sizeof(*this));
                break;
            }
            intf.read((char *)this, sizeof(*this));
        }
        if (cont == 0)
        {
            cout << "\n\t\tBook not found.\n";
            cout << "\n\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            book_issue();
        }
        intf.close();
    }
    void fine(int d, int m, int y, int dd, int mm, int yy)
    {
        long int n1, n2;
        int years, l, i;
        const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        n1 = y * 365 + d;
        for (i = 0; i < m - 1; i++)
            n1 += monthDays[i]; //fn1353
        years = y;
        if (m <= 2)
            years--;
        l = years / 4 - years / 100 + years / 400;
        n1 += l;
        n2 = yy * 365 + dd;
        for (i = 0; i < mm - 1; i++)
            n2 += monthDays[i];
        years = yy;
        if (m <= 2)
            years--;
        l = years / 4 - years / 100 + years / 400;
        n2 += l;
        n1 = n2 - n1;
        n2 = n1 - 15;
        if (n2 > 0)
            cout << "\n\t\tThe Total Fine is : " << n2;
    }
};

int main()
{
    Lib obj;
    obj.mainmenu();
    getch();
    return 0;
}
