#include "stdafx.h"
#include "Editor.h"
#include <string>


Editor::Editor()
{
}


Editor::Editor(string id, string name): Employee(id, name)
{
}


void Editor::receiveNews(Reporter r, string n)
{
	cout << "\n\n>> " << getName() << " received news from " << r.getName();

	sed = new SubEditor("s1", "Mushfiq");
	news = sed->editNews(n);
}

void Editor::approveNews()
{
	if(!news.find("COVID-19"))
		cout << "\n\n\n>>>> Status: News approved.";
	else
		cout << "\n\n\n>>>> Status: News rejected";
}