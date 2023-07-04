#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Editor
{
public:
    void work()
    {
        cout << "I am an editor.\n";
    }
};
class Sub_Editor : public Editor
{
public:
    void work()
    {
        cout << "I am a sub-editor.\n";
    }
};
int main()
{
    Editor *edi;
    Sub_Editor sub;
    edi = &sub;
    edi->work();
    //The text printed depends on the type of pointer not on the type of object
    //Here the obj is sub-editor while the function called is editor bcoz of the poiter type
    Sub_Editor *sub1;
    Editor Edi1;
    sub1 =(Sub_Editor*) &Edi1;
    sub1->work();
    //Here the obj is editor while the function called is sub-editor bcoz of the pointer type
}