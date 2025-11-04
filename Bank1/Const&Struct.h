#pragma once
#include <iostream>
#include <string>

using namespace std;


namespace Damoni1337
{
	struct stClient
	{
		string AccountNumber = "";
		string PinCode = "";
		string Name = "";
		string Phone = "";
		double AccountBalance = 0.0;
	};

	extern const string Separator;
	extern const string ClientFile;
}
