#pragma once
#include "employee.h"
#include "Reporter.h"
#include "SubEditor.h"

#ifndef EDITOR_H
#define EDITOR_H

class SubEditor;

class Editor :
	public Employee
{
	string news;
	SubEditor* sed;

public:
	Editor();
	Editor(string, string);

	void receiveNews(Reporter, string);
	void approveNews();
};

#endif