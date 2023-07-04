#include<iostream>
using namespace std;
class P {
public:
void print()
{ cout <<" Inside P::"; }
};
class Q : public P {
public:
void print()
{ cout <<" Inside Q"; }
};
class R: public Q {
};
int main(void)
{
R r;
r.print();
return 0;
}