#pragma once
#include "employee.h"

#ifndef SUBEDITOR_H
#define SUBEDITOR_H

class SubEditor :
	public Employee
{
public:
	SubEditor();
	SubEditor(string, string);

	string editNews(string);
};

#endif