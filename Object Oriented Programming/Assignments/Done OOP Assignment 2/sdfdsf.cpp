#include<iostream>
using namespace std;

class test
{   public:
    int a,b;
    test(int a=NULL,int b=NULL)
    {
        if (a==NULL||b==NULL)
        {
            return NULL;
        }
        else 
        {
            this->a=a;
            this->b=b;
        }
        
    }
};

int main()

{
    test ob;
}