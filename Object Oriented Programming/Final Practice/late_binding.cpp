#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Editor
{
public:
    virtual void work()
    {
        cout << "I am an editor.\n";
    }
    virtual void type_of_object()
    {
        cout<<"This is an editor object\n";
    }
    
};
class Sub_Editor : public Editor
{
public:
    void work()
    {
        cout << "I am a sub-editor.\n";
    }
    void type_of_object()
    {
        cout<<"This is a sub-editor object\n";
    }
};
int main()
{
    Editor *edi;
    Sub_Editor sub;
    edi = &sub;
    edi->work();
    edi->type_of_object();
    // edi->
    //The text printed depends on the type of obj not on the type of pointer
    //Here the obj is sub-editor and the function called is sub-editor bcoz of late binding
    Sub_Editor *sub1;
    Editor Edi1;
    sub1 =(Sub_Editor*) &Edi1;
    sub1->work();
    sub1->type_of_object();
    //Here the obj is editor and the function called is also sub-editor bcoz of late binding
}