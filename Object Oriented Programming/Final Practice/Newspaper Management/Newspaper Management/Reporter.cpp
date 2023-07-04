#include "stdafx.h"
#include "Reporter.h"
#include <string>


Reporter::Reporter()
{
}


Reporter::Reporter(string id, string name): Employee(id, name)
{
}


string Reporter::submitNews()
{
	string n = "COVID-19 is causing a lot of damange to economy.";
	
	cout << "> " << getName() << " submitting this news: " << endl;
	cout << n;
	return n;
}