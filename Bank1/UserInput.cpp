#include <iostream>
#include <string>
#include "Const&Struct.h"
#include "UserInput.h"

using namespace std;


namespace Damoni1337
{
	short ReadChoise(short From, short To)
	{
		short Number;
		do
		{
			cout << "\nChoose What do you want to do ? [" << From << " To " << To << "] ?  ";
			cin >> Number;

		} while (Number < From || Number > To);

		return Number;
	}

	string ReadAccountNumber()
	{
		string Acc;
		cout << "Enter Account Number : ";
		getline(cin >> ws, Acc);
		return Acc;
	}

	stClient ReadUpdateInfos()
	{
		stClient Client;

		cout << "Pin Code : ";
		cin >> Client.PinCode;

		cout << "Name : ";
		getline(cin >> ws, Client.Name);

		cout << "Phone : ";
		getline(cin >> ws, Client.Phone);

		cout << "Account Balance : ";
		cin >> Client.AccountBalance;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Client;
	}
}