#include "stdafx.h"
#include "SubEditor.h"
#include <string>


SubEditor::SubEditor()
{
}


SubEditor::SubEditor(string id, string name): Employee(id, name)
{
}

string SubEditor::editNews(string n)
{
	// editing news logic

	cout << "\n\n>>> " << getName() << " is editing news report...";
	cout << "\n>>> Submitted edited news for review.";
	return n;
}
