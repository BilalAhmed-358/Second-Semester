// C++ program to show passing
// of objects to a function

#include <bits/stdc++.h>
using namespace std;

class Example {
public:
	int a;

	// This function will take
	// object as arguments and
	// return object
	Example add(Example Ea, Example Eb)
	{
		Example Ec;
		Ec.a = Ea.a + Eb.a;

		// returning the object
		return Ec;
	}
};
int main()
{
	Example E1, E2, E3;

	// Values are initialized
	// for both objects
	E1.a = 50;
	E2.a = 100;
	E3.a = 0;

	cout << "Initial Values \n";
	cout << "Value of object 1: " << E1.a
		<< ", \nobject 2: " << E2.a
		<< ", \nobject 3: " << E3.a
		<< "\n";

	// Passing object as an argument
	// to function add()
	E3 = E3.add(E1, E2);

	// Changed values after
	// passing object as an argument
	cout << "New values \n";
	cout << "Value of object 1: " << E1.a
		<< ", \nobject 2: " << E2.a
		<< ", \nobject 3: " << E3.a
		<< "\n";

	return 0;
}
