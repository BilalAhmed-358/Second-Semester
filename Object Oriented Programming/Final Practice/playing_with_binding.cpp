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
    void exclusive()
    {
        cout<<"This function is exclusively available for Sub-Editors only\n";
    }
};
int main()
{
    Editor *edi;
    Editor ed1;
    edi=&ed1;
    edi->type_of_object();
    edi->work();
    edi=dynamic_cast<Sub_Editor> edi;
    

}