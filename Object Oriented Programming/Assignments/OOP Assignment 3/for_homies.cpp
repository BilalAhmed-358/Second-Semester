#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
string string1, string2;
void input()
{
    ofstream out("input.txt");
    cout << "Enter the text you want to encrypt\n";
    getline(cin, string1);
    out << string1;
    out.close();
    cout << "Text input in file successfully\n";
}
void encrypt()
{
    ifstream in("input.txt");
    ofstream out("deifiniaz.txt");
    getline(in, string2);
    for (int i = 0; string2[i] != '\0'; i++)
    {

        if ((string2[i] > 48 && string2[i] < 58) && (string2[i + 1] > 48 && string2[i + 1] < 58)) 
        {
            if (string2[i] == '1' && string2[i + 1] == '0')
                out << 'K';
            else if (string2[i] == '1' && string2[i + 1] == '1')
                out << 'J';
            else if (string2[i] == '1' && string2[i + 1] == '2')
                out << 'L';
            else if (string2[i] == '1' && string2[i + 1] == '3')
                out << 'M';
            else if (string2[i] == '1' && string2[i + 1] == '4')
                out << 'N';
            else if (string2[i] == '1' && string2[i + 1] == '5')
                out << 'O';
            else if (string2[i] == '1' && string2[i + 1] == '6')
                out << 'P';
            else if (string2[i] == '1' && string2[i + 1] == '7')
                out << 'Q';
            else if (string2[i] == '1' && string2[i + 1] == '8')
                out << 'R';
            else if (string2[i] == '1' && string2[i + 1] == '9')
                out << 'S';
            else if (string2[i] == '2' && string2[i + 1] == '0')
                out << 'T';
            else if (string2[i] == '2' && string2[i + 1] == '1')
                out << 'U';
            else if (string2[i] == '2' && string2[i + 1] == '2')
                out << 'V';
            else if (string2[i] == '2' && string2[i + 1] == '3')
                out << 'W';
            else if (string2[i] == '2' && string2[i + 1] == '4')
                out << 'X';
            else if (string2[i] == '2' && string2[i + 1] == '5')
                out << 'Y';
            else if (string2[i] == '1' && string2[i + 1] == '6')
                out << 'Z';
            else
                out << 'Z';
            i++;
        }
        else if ((string2[i] > 47 && string2[i] < 58))
        {
            if (string2[i] == '0')
            {
                out << 'Z';
            }
            else if (string2[i] == '1')
                out << 'A';
            else if (string2[i] == '2')
                out << 'B';
            else if (string2[i] == '3')
                out << 'C';
            else if (string2[i] == '4')
                out << 'D';
            else if (string2[i] == '5')
                out << 'E';
            else if (string2[i] == '6')
                out << 'F';
            else if (string2[i] == '7')
                out << 'G';
            else if (string2[i] == '8')
                out << 'H';
            else if (string2[i] == '9')
                out << 'I';
        }
    }
    in.close();
    out.close();
    ifstream in1("deifiniaz.txt");
    getline(in1, string1);
    cout << string1;
    in1.close();
}

int main()
{
    input();
    encrypt();
}