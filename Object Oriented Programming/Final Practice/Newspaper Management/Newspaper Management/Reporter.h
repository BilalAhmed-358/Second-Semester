#pragma once
#include "employee.h"

#ifndef REPORTER_H
#define REPORTER_H

class Reporter :
	public Employee
{

public:
	Reporter();
	Reporter(string, string);

	string submitNews();
};

#endif