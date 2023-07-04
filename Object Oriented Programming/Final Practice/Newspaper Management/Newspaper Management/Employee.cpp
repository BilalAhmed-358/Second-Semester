#include "stdafx.h"
#include "Employee.h"


Employee::Employee()
{
}


Employee::Employee(string id, string name)
{
	this->id =  id;
	this->name = name;
}

string Employee::getID()
{
	return id;
}

string Employee::getName()
{
	return name;
}