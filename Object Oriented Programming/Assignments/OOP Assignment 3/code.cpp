#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class encrypter
{
public:
    string st1, st2, doubledigit[2];
    void input_string()
    {
        ofstream out("input.txt");
        cout << "Enter the text you want to encrypt\n";
        getline(cin, st1);
        out << st1;
        out.close();
        cout << "Text input in file successfully.\n";
    }
    void read_from_encrypted_file()
    {
        cout << "The contents of the encrypted file are as follows:\n";
        ifstream in1("deifiniaz.txt");
        getline(in1, st1);
        cout << st1;
        in1.close();
    }
    void encrypt_string()
    {
        ifstream in("input.txt");
        ofstream out("deifiniaz.txt");
        getline(in, st2);
        for (int i = 0; st2[i] != '\0'; i++)
        {
            if ((st2[i] > 47 && st2[i] < 58) && (st2[i + 1] > 47 && st2[i + 1] < 58) && (st2[i + 2] > 47 && st2[i + 2] < 58) && (st2[i + 3] > 47 && st2[i + 3] < 58)) //This deals with positive 4 digit numbers
            {
                //cout << "4 digit number\n";
                out << 'Z';
                i = i + 3;
            }
            else if ((st2[i] > 47 && st2[i] < 58) && (st2[i + 1] > 47 && st2[i + 1] < 58) && (st2[i + 2] > 47 && st2[i + 2] < 58)) //This deals with positive 3 digit numbers
            {
                // cout << "3 digit number\n";
                out << 'Z';
                i = i + 2;
            }
            else if ((st2[i] > 48 && st2[i] < 58) && (st2[i + 1] > 48 && st2[i + 1] < 58)) //This deals with positive 2 digit numbers
            {
                // cout << "2 digit number\n";
                if (st2[i] == '1' && st2[i + 1] == '0')
                    out << 'K';
                else if (st2[i] == '1' && st2[i + 1] == '1')
                    out << 'J';
                else if (st2[i] == '1' && st2[i + 1] == '2')
                    out << 'L';
                else if (st2[i] == '1' && st2[i + 1] == '3')
                    out << 'M';
                else if (st2[i] == '1' && st2[i + 1] == '4')
                    out << 'N';
                else if (st2[i] == '1' && st2[i + 1] == '5')
                    out << 'O';
                else if (st2[i] == '1' && st2[i + 1] == '6')
                    out << 'P';
                else if (st2[i] == '1' && st2[i + 1] == '7')
                    out << 'Q';
                else if (st2[i] == '1' && st2[i + 1] == '8')
                    out << 'R';
                else if (st2[i] == '1' && st2[i + 1] == '9')
                    out << 'S';
                else if (st2[i] == '2' && st2[i + 1] == '0')
                    out << 'T';
                else if (st2[i] == '2' && st2[i + 1] == '1')
                    out << 'U';
                else if (st2[i] == '2' && st2[i + 1] == '2')
                    out << 'V';
                else if (st2[i] == '2' && st2[i + 1] == '3')
                    out << 'W';
                else if (st2[i] == '2' && st2[i + 1] == '4')
                    out << 'X';
                else if (st2[i] == '2' && st2[i + 1] == '5')
                    out << 'Y';
                else if (st2[i] == '1' && st2[i + 1] == '6')
                    out << 'Z';
                else
                    out << 'Z';
                i++;
            }
            else if ((st2[i] > 47 && st2[i] < 58)) //This deals with positive 1-digit numbers
            {
                // cout << "1 digit number\n";
                if (st2[i] == '0')
                {
                    // cout << "this ran\n";
                    out << 'Z';
                }
                else if (st2[i] == '1')
                    out << 'A';
                else if (st2[i] == '2')
                    out << 'B';
                else if (st2[i] == '3')
                    out << 'C';
                else if (st2[i] == '4')
                    out << 'D';
                else if (st2[i] == '5')
                    out << 'E';
                else if (st2[i] == '6')
                    out << 'F';
                else if (st2[i] == '7')
                    out << 'G';
                else if (st2[i] == '8')
                    out << 'H';
                else if (st2[i] == '9')
                    out << 'I';
            }
            else if (st2[i] == '-' && (st2[i + 1] > 47 && st2[i + 1] < 58) && (st2[i + 2] > 47 && st2[i + 2] < 58) && (st2[i + 3] > 47 && st2[i + 3] < 58) && (st2[i + 4] > 47 && st2[i + 4] < 58)) //This deals with negative 4 digit numbers
            {
                // cout << "-ve 4 digit number\n";
                out << 'Z';
                i = i + 4;
            }
            else if (st2[i] == '-' && (st2[i + 1] > 47 && st2[i + 1] < 58) && (st2[i + 2] > 47 && st2[i + 2] < 58) && (st2[i + 3] > 47 && st2[i + 3] < 58)) //This deals with negative 3 digit numbers
            {
                // cout << "-ve 3 digit number\n";
                out << 'Z';
                i = i + 3;
            }
            else if (st2[i] == '-' && (st2[i + 1] > 47 && st2[i + 1] < 58) && (st2[i + 2] > 47 && st2[i + 2] < 58)) //This deals with negative 2 digit numbers
            {
                // cout << "-ve 2 digit number\n";
                out << 'Z';
                i = i + 2;
            }
            else if (st2[i] == '-' && (st2[i + 1] > 48 && st2[i + 1] < 58)) //This deals with negative 1 digit numbers
            {
                // cout << "-ve number 1 digit number\n";
                out << 'Z';
                i++;
            }
        }
        in.close();
        out.close();
        read_from_encrypted_file();
    }
};

int main()
{
    encrypter obj;
    obj.input_string();
    obj.encrypt_string();
}