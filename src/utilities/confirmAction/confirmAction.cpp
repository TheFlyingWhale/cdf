#include "confirmAction.hpp"
#include "../color/color.hpp"
#include <iostream>
#include <string>
using namespace std;

string yesNo = " y/n - Yes/No";

int confirmAction()
{
	cout << "Do you wish to proceed?" << yesNo << endl;
	return determineConfirmation();
}

int confirmAction(string prompt)
{
	cout << prompt << yesNo << endl;
	return determineConfirmation();
}

int determineConfirmation()
{
	string input = "";
	getline(cin, input);
	if (input == "y" || input == "Yes" || input == "yes")
	{

		cout << green("Yes confirmed") << endl;
		return 1;
	}
	cout << red("Not confirmed") << endl;
	return 0;
}